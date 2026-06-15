export module LogPrint;
import LogMsg;
import Console;
import <string>;

export class LogPrint : public LogMsgBook {
public:
	void printAll(Console& console) {
		I1000();
		for (const auto &p : internalWarning) {
			W1000(p);
		}
		forEachByMode(
			[&console,this](Type ty, char c, unsigned id, std::string text) {
			const auto& r = get(ty, 0, std::to_string(id), text);
			if (!r.empty()) {
				console.print(r).endl();
				return;
			}
			console.print("[").print(c).print("-")
					.print(id).print("] ").print(text).endl();
		}, []() {});
	}
};