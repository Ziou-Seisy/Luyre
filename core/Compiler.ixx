export module Compiler;
import Lexer;
import Parser;
import Semantics;
import Intermediate;
import Optimization;
import Target;
import StreamBase;
import StreamContext;

export class Compiler {
	Lexer lexer;
	Parser parser;
	Semantics semantics;
	Intermediate intermediate;
	Optimization optimization;
	Target target;
	using InputContext = StreamContext<char, Base_CharTag>;
public:
	Compiler(InputStream<InputContext> & fin, OutputStream<char> & fout) {
		do{
			const auto &p = fin.getNext();
			if (fin.isEOF())break;
			if (p.tag == Base_CharTag::end)break;
			if (p.tag == Base_CharTag::endFile)continue;
			fout.put(p.data);
		} while (!fin.isEOF());
	}
};