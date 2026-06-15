export module MathLog;

import <intrin.h>;
export unsigned int _log2Add(unsigned int n) {
	unsigned long index;
	_BitScanReverse(&index, n);
	return index + 1;
}