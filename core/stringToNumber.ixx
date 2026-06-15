export module stringToNumber;

import<string>;
import<charconv>;
export template<typename NumType>
int stringToNumber(std::string sv, NumType &r) {
	NumType value;
	auto result = std::from_chars(sv.data(), sv.data() + sv.size(), value);
	if (result.ec == std::errc()) {
		r = value;
		sv = std::string_view(result.ptr, sv.size() - (result.ptr - sv.data()));
		return 0;
	}
	else {
		return  static_cast<int>(result.ec);
	}
}