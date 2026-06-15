export module Interaction;

#define ExitCommon 0
#define ExitFailure 1

import Console;
import Command;
import ConfigCheck;

export class Interaction {
	int is_exit, _1;
	Console console;
	CommandLine commandLine;
	ConfigCheck config;
public:
	Interaction(int argc, char **argv)
		:is_exit(ExitFailure),
		console(argc,argv,Console::codePage_UTF8),
		commandLine(console)  {

		if (!commandLine.isOK()) {
			console.print(commandLine.getErrorMsg()).endl();
			return;
		}

		config.init(commandLine.getConfigPath());
		if (!config.isOK()) {
			console.print(config.getErrorMsg()).endl();
			return;
		}

		config.setLogBook();
		if (!config.check())return;

		is_exit = ExitCommon;
	}
	int isExit() const {
		return is_exit; 
	}
private:

public:
	~Interaction() {
		if(commandLine.isOK() && config.isOK())config.logbook.printAll(console);
	}
	struct FilesLine {
		std::string output;
		std::vector<std::string> inputs;
	};
	template<typename _F> void forEachFiles(const _F &_f) {
		config.forEachLineByKey("File", [&_f, this](const ConfigCheck::VecStr &paths)->bool {
			FilesLine fl;
			if (paths.empty()) {
				config.logbook.W1002("File");
				return 0;
			}
			if (paths.size() <= 1) {
				config.logbook.W1002(paths[0]);
				return 0;
			}
			fl.output = paths[0];
			fl.inputs.insert(fl.inputs.end(), paths.begin() + 1, paths.end());
			_f(fl, config);
			return 0;
		}, [](const ConfigCheck::VecStr &) {}, []() {}, [this]() {
			config.logbook.I1002();
		});
	}
};