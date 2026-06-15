export module StreamContext;

export template<typename _Ty, typename _Tag> struct StreamContext {
	using Index = size_t;
	using Tag = _Tag;
	_Ty data;
	Tag tag;
	Index row, col;
	Index file;
};

export enum class Base_CharTag : int {
	common, lineBreak, endFile, end
};