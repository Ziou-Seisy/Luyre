export module Console;
import<iostream>;
import<windows.h>;

export class Console {
	struct CommandLineArguments {
	private:
		int count;
		int _;
		char **args;
	public:
		CommandLineArguments(int argc, char **argv)
			:count(argc), args(argv) {}
		int length() const {
			return count;
		}
		const char *operator[](int iter) const {
			if (iter < 0 || iter >= count)return nullptr;
			return args[iter];
		}
	};
public:
	const CommandLineArguments arg;
	Console(int argc, char **argv) :arg(argc, argv) {}
	template<typename _Ty> Console &print(const _Ty &text) {
		std::cout << text;
		return *this;
	}
	Console &endl() {
		std::cout << std::endl;
		return *this;
	}
	Console(const Console &) = delete;
	Console &operator = (const Console &) = delete;
	void setOutputCodePage(int code_page) {
		SetConsoleOutputCP(code_page);
	}
	Console(int argc, char **argv, int code_page)
		:Console(argc, argv) {
		setOutputCodePage(code_page);
	}
	static constexpr const int codePage_UTF8 = 65001;
};