export module StreamBase;

export template<typename _Ty> class InputStream {
public:
	virtual _Ty getNext() = 0;
	virtual bool isEOF() = 0;
};

export template<typename _Ty> class OutputStream {
public:
	virtual void put(const _Ty&) = 0;
};