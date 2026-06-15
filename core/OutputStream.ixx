export module OutputStream;

import StreamBase;
import File;

import<iostream>;

export class OutputStream_File : public OutputStream<char> {
	OutputFile fout;
public:
	OutputStream_File(const std::string &path) : fout(path) {}
	bool isOpen() {
		return fout.isOpen();
	}
	virtual void put(const char &c) override {
		fout.putChar(c);
	}
};