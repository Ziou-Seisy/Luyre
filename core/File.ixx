export module File;
import<fstream>;
import<string>;

class File {
protected:
	std::string path;
public:
	File(const std::string &_path) :path(_path) {}
};

export class InputFile : public File {
	std::ifstream fs;
public:
	InputFile(const std::string &_path) :File(_path), fs(path) {}
	bool isOpen() const {
		return fs.is_open();
	}
	auto &getLine(std::string &ret) {
		return std::getline(fs, ret);
	}
	InputFile(const InputFile &) = delete;
	InputFile &operator = (const InputFile &) = delete;
	auto& getChar(char& c) {
		return fs.get(c);
	}
	bool eof() {
		return fs.eof();
	}
};

export class OutputFile : public File {
	std::ofstream fs;
public:
	OutputFile(const std::string &_path) :File(_path), fs(path) {}
	bool isOpen() const {
		return fs.is_open();
	}
	OutputFile(const OutputFile &) = delete;
	OutputFile &operator = (const OutputFile &) = delete;
	auto& putChar(char c) {
		return fs.put(c);
	}
};