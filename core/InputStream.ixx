export module InputStream;

import<fstream>;
import<string>;
import<vector>;
using String = std::string;
using Index = unsigned long long int;
using Size = unsigned long long int;

import StreamBase;
import StreamContext;
import FileID;
import ConfigCheck;

export class InputStream_Files : public InputStream<StreamContext<char,Base_CharTag>> {
	struct FileItem {
		std::ifstream fin;
		Index id, row, col; 
		FileItem(const String &path, Index _id, Index _row, Index _col) :
			fin(path), id(_id), row(_row), col(_col) {}
	};
	std::vector<FileItem> fv;
	ConfigCheck &config;
public:
	using Context = StreamContext<char, Base_CharTag>;
	InputStream_Files(const std::vector<std::string> &paths, ConfigCheck& _config):
		config(_config) {
		for (auto it = paths.rbegin(); it != paths.rend(); ++it) {
			const auto &path = *it;
			fv.push_back({ path,fileIdMapper.getID(path),0,0 });
			auto &p = fv.back();
			if (!p.fin.is_open()) {
				config.logbook.E2002(path);
			}
		}
	}
	virtual bool isEOF() override { return fv.empty(); }
	virtual Context getNext() override { 
		if (fv.empty())return { '\0', Context::Tag::end, 0, 0, 0 };
		auto &fi = fv.back();
		char c = 0;
		fi.col++;
		if (fi.fin.get(c)) {
			if (/*setting.lineAdd.find(c)*/'\n' != String::npos) {
				Context temp = { c, Context::Tag::lineBreak, fi.row, fi.col, fi.id };
				fi.row++; fi.col = 0;
				return temp;
			}

			return { c, Context::Tag::common, fi.row, fi.col, fi.id };
		}
		if (fi.fin.eof()) {
			Context temp = { '\0', Context::Tag::endFile, fi.row, fi.col, fi.id };
			fv.pop_back();
			return temp;
		}
		config.logbook.E2003(fileIdMapper.getName(fi.id), fi.col, fi.row);
		fv.clear();
		return { '\0', Context::Tag::end, 0, 0, 0 };
	}
};