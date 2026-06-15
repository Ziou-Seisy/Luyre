export module ConfigCheck;
import Config;
import TheMsg;
import splitString;
import stringToNumber;
import LogPrint;
import Version;

export class ConfigCheck : public Config {
public:
	LogPrint logbook;
	ConfigCheck() :Config() {}
	ConfigCheck(const ConfigCheck &) = delete;
	ConfigCheck &operator = (const ConfigCheck &) = delete;
public:
	void setLogBook() {
		forEachByKey("logbook", [this](const std::string & path)->bool {
			logbook.load(path); return 0;
		}, [](const std::string &) {}, []() {}, []() {});
	}
	bool check() {
		return findByKey(theName, [this](const std::string & version)->bool {
			Version v{ 0,0,0 };
			auto arr = splitString<3>(version, '.');
			if (arr[0].empty() || stringToNumber(arr[0], v.major)) {
				logbook.F1001(version); return 1;
			}
			if (arr[1].empty() || stringToNumber(arr[1], v.minor)) {
				logbook.F1001(version); return 1;
			}
			if (arr[2].empty() || stringToNumber(arr[2], v.patch)) {
				logbook.F1001(version); return 1;
			}
			if (theVersion.major != v.major) {
				logbook.E1001(version, theVersionString); return 1;
			}
			if (theVersion.minor != v.minor) {
				logbook.W1001(version, theVersionString);
			}
			else if (theVersion.patch != v.patch) {
				logbook.I1001(version, theVersionString);
			}
			return 0;
		}, [](const std::string &)->bool {return 0; }, []()->bool {return 1; });
	}
};