#include <ctype.h>
#include <stdarg.h>
#include <string.h>
#include "str.h"

str str_from_cstr(char *sz) { return (str){ sz, strlen(sz) }; }

str str_strip_whitespace(str it) {
	if (it.len < 1) return it;
	while (isspace(it.data[0])) { ++it.data; --it.len; }
	while (isspace(it.data[it.len - 1])) { --it.len; }
	return it;
}

str str_strip_whitespace_pre(str it) {
	if (it.len < 1) return it;
	while (isspace(it.data[0])) { ++it.data; --it.len; }
	return it;
}

str str_strip_whitespace_post(str it) {
	if (it.len < 1) return it;
	while (isspace(it.data[it.len - 1])) { --it.len; }
	return it;
}

str str_strip_prefix_str(str it, str prefix) {
	if (strncmp(it.data, prefix.data, prefix.len)) return it;
	it.data += prefix.len;
	it.len -= prefix.len;
	return it;
}

str str_strip_postfix_str(str it, str postfix) {
	if (strncmp(&it.data[it.len - 1 - postfix.len], postfix.data, postfix.len)) return it;
	it.len -= postfix.len;
	return it;
}

str str_strip_prefix_cstr(str it, const char *prefix) {
	const size_t len = strlen(prefix);
	if (strncmp(it.data, prefix, len)) return it;
	it.data += len;
	it.len -= len;
	return it;
}

str str_strip_postfix_cstr(str it, const char *postfix) {
	const size_t len = strlen(postfix);
	if (strncmp(&it.data[it.len - 1 - len], postfix, len)) return it;
	it.len -= len;
	return it;
}

bool str_is_sz(str it) { return it.data[it.len - 1] == 0; }

int str_cmp_str(str a, str b) {
	const int d = a.len - b.len;
	if (d) { return (0 < d) - (d < 0); }
	return strncmp(a.data, b.data, a.len);
}

int str_cmp_cstr(str a, const char *b) {
	const int d = a.len - strlen(b);
	if (d) { return (0 < d) - (d < 0); }
	return strncmp(a.data, b, a.len);
}

int cstr_cmp_str(const char *a, str b) {
	const int d = strlen(a) - b.len;
	if (d) { return (0 < d) - (d < 0); }
	return strncmp(a, b.data, b.len);
}

bool str_eq_str(str a, str b) {
	return a.len == b.len && !strncmp(a.data, b.data, a.len);
}

bool str_eq_cstr(str a, const char *b) {
	const auto blen = strlen(b);
	return a.len == blen && !strncmp(a.data, b, a.len);
}

bool cstr_eq_str(const char *a, str b) {
	const auto alen = strlen(a);
	return alen == b.len && !strncmp(a, b.data, b.len);
}

bool cstr_eq_cstr(const char *a, const char *b) { return !strcmp(a, b); }

bool str_eq_str_any(str it, int count, ...) {
	va_list args;
	va_start(args, count);
	bool result = false;
	for (int i = 0; i < count; ++i) {
		result = result || str_eq_str(it, va_arg(args, str));
		if (result) { break; }
	}
	va_end(args);
	return result;
}

bool str_eq_cstr_any(str it, int count, ...) {
	va_list args;
	va_start(args, count);
	bool result = false;
	for (int i = 0; i < count; ++i) {
		result = result || str_eq_cstr(it, va_arg(args, const char*));
		if (result) { break; }
	}
	va_end(args);
	return result;
}

bool cstr_eq_str_any(const char *it, int count, ...) {
	va_list args;
	va_start(args, count);
	bool result = false;
	for (int i = 0; i < count; ++i) {
		result = result || cstr_eq_str(it, va_arg(args, str));
		if (result) { break; }
	}
	va_end(args);
	return result;
}

bool cstr_eq_cstr_any(const char *it, int count, ...) {
	va_list args;
	va_start(args, count);
	bool result = false;
	for (int i = 0; i < count; ++i) {
		result = result || cstr_eq_cstr(it, va_arg(args, const char*));
		if (result) { break; }
	}
	va_end(args);
	return result;
}
