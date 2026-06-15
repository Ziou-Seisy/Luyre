export module Command;

import<string>;
import Console;
import TheErrMsg;
import TheMsg;

export class CommandLine {
	std::string configPath;
	std::string errorMsg;
public:
	CommandLine(Console &console)
		:configPath(), errorMsg() {
		auto len = console.arg.length();
		if (len < 1) {
			errorMsg = errorTooFewCommand; return;
		}
		if (len == 1) {
			errorMsg = theMessage; return;
		}
		if (len > 2) {
			errorMsg = errorTooManyCommand[0];
			errorMsg += std::to_string(len);
			errorMsg += errorTooManyCommand[1];
			return;
		}
		configPath = console.arg[1];
	}
	const std::string &getConfigPath() {
		return configPath;
	}
	bool isOK() {
		return errorMsg.empty();
	}
	const std::string &getErrorMsg() {
		return errorMsg;
	}
};