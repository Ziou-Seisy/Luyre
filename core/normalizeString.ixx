export module normalizeString;
import <string>;

export std::string normalize(const std::string &key) {
	std::string result;
	result.reserve(key.size());
	for (char c : key) {
		if (c != '-') {
			result += static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
		}
	}
	return result;
}