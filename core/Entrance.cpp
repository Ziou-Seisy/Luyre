import Interaction;
import InputStream;
import OutputStream;
import Compiler;

int main(int argc, char** argv) {
	Interaction ia { argc,argv };
	if (auto r = ia.isExit())return r;

	ia.forEachFiles([](const Interaction::FilesLine& fileLine, ConfigCheck& config) {
		OutputStream_File fout{ fileLine.output };
		if (!fout.isOpen()) {
			config.logbook.E2001(fileLine.output);
			return;
		}
		InputStream_Files fin{ fileLine.inputs, config };
		Compiler compiler{fin,fout};
	});

	return 0;
}