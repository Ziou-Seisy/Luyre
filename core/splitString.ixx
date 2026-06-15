export module splitString;

import<string>;
import<array>;
export template<size_t len>
std::array<std::string, len> splitString(const std::string &s, char delim) {
	std::array<std::string, len> result{};
	size_t start = 0;
	for (size_t i = 0; i < len; i++) {
		size_t end = s.find(delim, start);
		if (end == std::string::npos) {
			result[i] = s.substr(start);
			break;
		}
		result[i] = s.substr(start, end - start);
		start = end + 1;
	}
	return result;
}