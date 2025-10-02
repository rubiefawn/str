#pragma once

typedef struct str { char *data; int len; } str;

// Constructs a non-owning `str` from a `char*`.
str str_from_cstr(char *sz);

// Returns a non-owning copy of a `str` with all leading and trailing whitespace removed.
str str_strip_whitespace(str it);

// Returns a non-owning copy of a `str` with all leading whitespace removed.
str str_strip_whitespace_pre(str it);

// Returns a non-owning copy of a `str` with all trailing whitespace removed.
str str_strip_whitespace_post(str it);

// Returns a non-owning copy of a `str` with a given `str` prefix removed, if it is present.
str str_strip_prefix_str(str it, str prefix);

// Returns a non-owning copy of a `str` with a given `str` postfix removed, if it is present.
str str_strip_postfix_str(str it, str postfix);

// Returns a non-owning copy of a `str` with a given `char*` prefix removed, if it is present.
str str_strip_prefix_cstr(str it, const char *prefix);

// Returns a non-owning copy of a `str` with a given `char*` postfix removed, if it is present.
str str_strip_postfix_cstr(str it, const char *postfix);

#define str_strip_prefix(IT, PREFIX) _Generic((PREFIX), str: str_strip_prefix_str, char *: str_strip_prefix_cstr)((IT), (PREFIX))

#define str_strip_postfix(IT, POSTFIX) _Generic((POSTFIX), str: str_strip_postfix_str, char *: str_strip_postfix_cstr)((IT), (POSTFIX))

// Checks if a `str` is null-terminated.
bool str_is_sz(str it);

// Compares two `str` lexicographically.
int str_cmp_str(str a, str b);

// Compares a `str` and a `char*` lexicographically.
int str_cmp_cstr(str a, const char *b);

// Compares a `str` and a `char*` lexicographically.
int cstr_cmp_str(const char *a, str b);

#define cstr_cmp_cstr strcmp

#define str_cmp(LHS, RHS) _Generic((LHS), str: _Generic((RHS), str: str_cmp_str, char *: str_cmp_cstr), char *: _Generic((RHS), str: cstr_cmp_str, char *: strcmp))((LHS), (RHS))

// Compares two `str` to see if their contents are equal.
bool str_eq_str(str a, str b);

// Compares a `str` and a `char*` to see if their contents are equal.
bool str_eq_cstr(str a, const char *b);

// Compares a `str` and a `char*` to see if their contents are equal.
bool cstr_eq_str(const char *a, str b);

// Compares two `char*` to see if their contents are equal.
bool cstr_eq_cstr(const char *a, const char *b);

#define str_eq(LHS, RHS) _Generic((LHS), str: _Generic((RHS), str: str_eq_str, char *: str_eq_cstr), char *: _Generic((RHS), str: cstr_eq_str, char *: cstr_eq_cstr))((LHS), (RHS))

// Compares a `str` to several other `str`s to see if its contents are equal to any of those options.
bool str_eq_str_any(str it, int count, ...);

// Compares a `str` to several `char*`s to see if its contents are equal to any of those options.
bool str_eq_cstr_any(str it, int count, ...);

// Compares a `char*` to several `str`s to see if its contents are equal to any of those options.
bool cstr_eq_str_any(const char *it, int count, ...);

// Compares a `char*` to several other `char*`s to see if its contents are equal to any of those options.
bool cstr_eq_cstr_any(const char *it, int count, ...);

#define str_eq_any(LHS, COUNT, RHS, ...) _Generic((LHS), str: _Generic((RHS), str: str_eq_str_any, char *: str_eq_cstr_any), char *: _Generic((RHS), str: cstr_eq_str_any, char *: cstr_eq_cstr_any))((LHS), (COUNT), (RHS) __VA_OPT(, __VA_ARGS__))
