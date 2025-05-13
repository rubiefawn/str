#pragma once
#include <stddef.h>

// strncpy, except result is always guaranteed to be null-terminated
// returns remaining free space, which will be negative if the string was truncated
ptrdiff_t strzcpy(char *restrict dest, const char *restrict src, size_t size);

// strncat, except result is always guaranteed to be null-terminated
// returns remaining free space, which will be negative if the string was truncated
ptrdiff_t strzcat(char *restrict dest, const char *restrict src, size_t size);
