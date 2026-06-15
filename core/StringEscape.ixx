export module StringEscape;
import<string>;
using String = std::string;

export std::string unescape(const std::string &s) {
	std::string result;
	result.reserve(s.size());

	for (size_t i = 0; i < s.size(); ++i) {
		if (s[i] != '\\') {
			result += s[i]; continue;
		}
		if (i + 1 >= s.size()) {
			result += s[i]; continue;
		}
		char next = s[++i];
		if (next == 'x' || next == 'X') {
			if (i + 2 >= s.size()) {
				result += '\\';
				result += next;
				continue;
			}
			int val = std::stoi(s.substr(i + 1, 2), nullptr, 16);
			result += static_cast<char>(val);
			i += 2;
			continue;
		}
		if (next >= '1' && next < '8') {
			if (i + 2 >= s.size()) {
				result += '\\';
				result += next;
				continue;
			}
			int val = std::stoi(s.substr(i, 3), nullptr, 8);
			result += static_cast<char>(val);
			i += 2;
			continue;
		}
		if (next == '0') {
			if (i + 1 >= s.size()) {
				result += '\0';
				continue;
			}
			char next_next = s[i + 1];
			if (next_next < '0' || next_next >= '8') {
				result += '\0';
				continue;
			}
			if (i + 2 >= s.size()) {
				result += '\\';
				result += next;
				result += next_next;
				continue;
			}
			int val = std::stoi(s.substr(i + 1, 2), nullptr, 8);
			result += static_cast<char>(val);
			i += 2;
			continue;
		}
		switch (next) {
			case 'n':  result += '\n'; break;
			case 't':  result += '\t'; break;
			case 'r':  result += '\r'; break;
			case '\\': result += '\\'; break;
			case '"':  result += '"';  break;
			case '\'': result += '\''; break;
			default:  result += next;  break;
		}
	}
	return result;
}