#include <string.h>
#include "cstr.h"

ptrdiff_t strzcpy(char *restrict dest, const char *restrict src, size_t size) {
	const size_t src_len = strlen(src);
	const size_t cpy_len = src_len < size - 1 ? src_len : size - 1; // How much of src will actually get copied
	memcpy(dest, src, cpy_len);
	dest[cpy_len] = '\0';
	return size - src_len - 1;
}

ptrdiff_t strzcat(char *restrict dest, const char *restrict src, size_t size) {
	const size_t dest_len = strlen(dest);
	return strzcpy(&dest[dest_len], src, size - dest_len);
}
