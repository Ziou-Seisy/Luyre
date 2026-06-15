export module LogMsg;
import LogBook;
import TheMsg;

import<string>;
using CStringR = const std::string &;
template<typename _NTy> std::string toString(const _NTy& num) {
	return std::to_string(num);
}
export class LogMsgBook : public LogMsg {
public:
	void I1000() {
		add(LogBook::Info, 1000, theName);
	}
	void W1000(CStringR line) {
		add(LogBook::Warn, 1000,line);
	}
	void F1001(CStringR version) {
		add(LogBook::Fatal, 1001, version);
	}
	void E1001(CStringR config_version, CStringR app_version) {
		add(LogBook::Error, 1001,
			config_version, app_version);
	}
	void W1001(CStringR config_version, CStringR app_version) {
		add(LogBook::Warn, 1001,
			config_version, app_version);
	}
	void I1001(CStringR config_version, CStringR app_version) {
		add(LogBook::Info, 1001,
			config_version, app_version);
	}
	void W1002(CStringR text) {
		add(LogBook::Warn, 1002, text);
	}

	void E2001(CStringR path) {
		add(LogBook::Error, 2001, path);
	}
	void E2002(CStringR path) {
		add(LogBook::Error, 2002, path);
	}
	void E2003(CStringR path, size_t col, size_t row) {
		add(LogBook::Error, 2003, path, toString(col), toString(row));
	}
	void I1002() {
		add(LogBook::Info, 1002);
	}
};