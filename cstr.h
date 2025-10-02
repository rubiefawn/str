#pragma once
#include <stddef.h>

// Similar to `strncpy()`, except result is always null-terminated
// Returns remaining free space. If the string was truncated, this
// amount will be negative, whose absolute value is equal to the number
// of characters that did not fit.
ptrdiff_t strzcpy(char *restrict dest, const char *restrict src, size_t size);

// Similar to `strncat()`, except result is always null-terminated
// Returns remaining free space. If the string was truncated, this
// amount will be negative, whose absolute value is equal to the number
// of characters that did not fit.
ptrdiff_t strzcat(char *restrict dest, const char *restrict src, size_t size);

#if !defined(__unix__) && !defined(__STDC_ALLOC_LIB__) && __STDC_WANT_LIB_EXT2__ != 1
char *strdup(const char *src);
char *strndup(const char *src, size_t size);
#endif
