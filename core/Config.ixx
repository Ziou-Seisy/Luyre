export module Config;
import File;
import TheErrMsg;
import <unordered_map>;
import <vector>;
import <sstream>;
import <string>;
import normalizeString;

using VecStr = std::vector<std::string>;
using UMap_S_VS = std::unordered_multimap<std::string, VecStr>;

static void setKeyAndValues(const std::string &line, UMap_S_VS &datas) {
	std::istringstream iss(line);
	std::string _input;
	if (!(iss >> _input)) return;
	std::string key = normalize(_input);
	std::vector<std::string> vals;
	while (iss >> _input) {
		vals.push_back(std::move(_input));
	}
	if (!vals.empty()) {
		datas.emplace(key, std::move(vals));
	}
}

export class Config {
	std::string errorMsg;
	UMap_S_VS datas;
	void fileInput(const std::string &path) {
		InputFile fs{ path };
		if (!fs.isOpen()) {
			errorMsg = errorFailedToOpenTheFile[0];
			errorMsg += path;
			errorMsg += errorFailedToOpenTheFile[1];
			return;
		}
		std::string line;
		while (fs.getLine(line)) {
			setKeyAndValues(line, datas);
		}
	}
public:
	using VecStr = ::VecStr;
	bool isOK() {
		return errorMsg.empty();
	}
	const std::string &getErrorMsg() {
		return errorMsg;
	}
	auto getKey(const std::string &key) const {
		std::string nk = normalize(key);
		return datas.equal_range(nk);
	}
	template<typename _F, typename _E, typename _L>
	auto findByKey(const std::string &key, _E ef, _F rf, _L lf) const {
		auto range = getKey(key);
		for (auto it{ range.first };
			 it != range.second; ++it) {
			for (const auto &p : (it->second)) {
				if (ef(p))return rf(p);
			}
		}
		return lf();
	}
	template<typename _F, typename _E, typename _O, typename _L>
	auto forEachByKey(const std::string &key, _E ef, _F rf, _O _of, _L lf) const {
		auto range = getKey(key);
		if (range.first == range.second)return lf();
		for (auto it{ range.first };
			 it != range.second; ++it) {
			for (const auto &p : (it->second)) {
				if (ef(p))return rf(p);
			}
		}
		return _of();
	}
	template<typename _F, typename _E, typename _L>
	auto findLineByKey(const std::string &key, _E ef, _F rf, _L lf) const {
		auto range = getKey(key);
		for (auto it{ range.first };
			 it != range.second; ++it) {
			const auto &p = it->second;
			if (ef(p))return rf(p);
		}
		return lf();
	}
	template<typename _F, typename _E, typename _O, typename _L>
	auto forEachLineByKey(const std::string &key, _E ef, _F rf, _O _of, _L lf) const {
		auto range = getKey(key);
		if (range.first == range.second)return lf();
		for (auto it{ range.first };
			 it != range.second; ++it) {
			const auto& p = it->second;
			if (ef(p))return rf(p);
		}
		return _of();
	}
	Config():errorMsg() {}
	void init(const std::string &path) {
		fileInput(path);
	}
	Config(const Config &) = delete;
	Config &operator = (const Config &) = delete;

};

