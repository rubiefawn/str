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

#if !defined(__unix__) && !defined(__STDC_ALLOC_LIB__) && __STDC_WANT_LIB_EXT2__ != 1
#include <stdlib.h>

char *strdup(const char *src) {
	const size_t len = strlen(src) + 1;
	char *dest = calloc(1, len);
	if (!dest) return nullptr;
	memcpy(dest, src, len);
	return dest;
}

char *strndup(const char *src, size_t size) {
	char *dest = calloc(1, size + 1);
	if (!dest) return nullptr;
	const size_t src_len = strlen(src);
	const size_t cpy_len = src_len < size ? src_len : size;
	memcpy(dest, src, cpy_len);
	return dest;
}
#endif
