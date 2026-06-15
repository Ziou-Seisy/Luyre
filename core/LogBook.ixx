export module LogBook;

import<unordered_map>;
import<string>;
import<vector>;
import File;
import MathLog;

import StringEscape;
static inline std::string preprocesse(std::string text) {
	return unescape(text);
}

constexpr unsigned logNumberMax = 10000;
using UMap_N_S = std::unordered_map<unsigned, std::string>;

class __LogBook {
public:
	enum Type : unsigned int {
		Trace = 1, Debug = 2, Info = 4,
		Warn = 8, Error = 16, Fatal = 32, Other = 64,
		Mode_Off = 0,
		Mode_Error = Error | Fatal,
		Mode_Bad = Warn | Mode_Error,
		Mode_Base = Info | Mode_Bad,
		Mode_Normal = Trace | Debug | Mode_Base,
		Mode_All = Mode_Normal | Other
	};
protected:
	static unsigned _getId(Type type, unsigned int id) {
		return _log2Add(type) * logNumberMax + id;
	}
	static Type _getType(char c) {
		switch (c) {
			case 'I':return Type::Info;
			case 'W':return Type::Warn;
			case 'E':return Type::Error;
			case 'F':return Type::Fatal;
			case 'D':return Type::Debug;
			case 'T':return Type::Trace;
			default:return Type::Other;
		}
	}
	static char getTypeName(Type type) {
		switch (type) {
			case Trace:	return 'T'; break;
			case Debug:	return 'D'; break;
			case Info:	return 'I'; break;
			case Warn:	return 'W'; break;
			case Error:	return 'E'; break;
			case Fatal:	return 'F'; break;
			case Other:return 'O'; break;
			case Mode_Off:return 'O'; break;
			case Mode_Error:return 'O'; break;
			case Mode_Bad:return 'O'; break;
			case Mode_Base:return 'O'; break;
			case Mode_Normal:return 'O'; break;
			case Mode_All:return 'O'; break;
			default:return 'O'; break;
		}
	}
protected:
	static int _getId(const std::string &key) {
		char letter = key[0];
		Type type = _getType(letter);
		if (type == Type::Other)return 0;

		if (key.length() < 2)return 0;
		if (key[1] < '0' || key[1] > '9')return 0;
		const auto &s = key.substr(1);
		size_t pos;
		unsigned number = (unsigned)std::stol(s, &pos);
		if (pos < s.size())return 0;

		return (int)_getId(type, number);
	}
};

class LogBook : public __LogBook {
	UMap_N_S data;
protected:
	std::vector<std::string> internalWarning;
public:
	void load(const std::string &path) {
		InputFile fs(path);
		std::string line;
		while (fs.getLine(line)) {
			if (line.empty())continue;
			if (line[0]=='#')continue;
			auto pos = line.find('=');
			int id = _getId(line.substr(0, pos));
			if (id > 0)data[(unsigned)id] = preprocesse(line.substr(pos + 1));
			else {
				internalWarning.push_back(line);
			}
		}
	}
protected:
	std::string _get(Type type, unsigned int id, 
					 const std::vector<std::string> &vals) const {
		auto it = data.find(_getId(type, id));
		if (it == data.end()) return "";

		const std::string &text = it->second;
		std::string result;
		result.reserve(text.size() + vals.size() * 8);

		size_t i = 0;
		while (i < text.size()) {
			if (text[i] != '{') {
				result += text[i++]; continue;
			}
			if (i+1 < text.size() && text[i+1] == ';') {
				result += text[i++]; i++; continue;
			}
			size_t j = text.find('}', i + 1);
			if (j == std::string::npos) {
				result += text[i++]; continue;
			}
			int idx = std::stoi(text.substr(i + 1, j - i - 1)) - 1;
			if (idx >= 0 && idx < (int)vals.size()) {
				result += vals[(size_t)idx];
			}
			i = j + 1;
		}
		return result;
	}
public:
	template<typename... Args>
	std::string get(Type type, unsigned int id, Args&&... args) const {
		std::vector<std::string> vals = { std::forward<Args>(args)... };
		return _get(type, id, vals);
	}
};

export class LogMsg : public LogBook {
	struct Line {
		Type type;
		unsigned int id;
		std::string text;
	};
	std::list<Line> logs;
protected:
	void _add(Type type, unsigned int number, std::string text) {
		logs.push_back({ type, number, text });
	}
public:
	template<typename Callback, typename _Empty>
	void forEachByMode(const Callback &callback, const _Empty &_empty,
					   Type type = Type::Mode_All) {
		bool isEmpty = 1;
		for (const auto &p : logs) {
			if ((unsigned int)(p.type) & (unsigned int)(type)) {
				isEmpty = 0;
				callback(p.type, getTypeName(p.type), p.id, p.text);
			}
		}
		if (isEmpty)_empty();
	}
	template<typename... Args>
	void add(Type type, unsigned int id, Args&&... args) {
		_add(type, id, get(type, id, args...));
	}
};