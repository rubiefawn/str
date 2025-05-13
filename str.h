#pragma once

typedef struct str { char *data; int len; } str;

str str_from_cstr(char *sz);

str str_strip_whitespace(str it);
str str_strip_whitespace_pre(str it);
str str_strip_whitespace_post(str it);

str str_strip_prefix_str(str it, str prefix);
str str_strip_postfix_str(str it, str postfix);
str str_strip_prefix_cstr(str it, const char *prefix);
str str_strip_postfix_cstr(str it, const char *postfix);

#define str_strip_prefix(IT, PREFIX) _Generic((PREFIX), str: str_strip_prefix_str, char *: str_strip_prefix_cstr)((IT), (PREFIX))

#define str_strip_postfix(IT, POSTFIX) _Generic((POSTFIX), str: str_strip_postfix_str, char *: str_strip_postfix_cstr)((IT), (POSTFIX))

bool str_is_sz(str it);
bool str_eq_str(str a, str b);
bool str_eq_cstr(str a, const char *b);
bool cstr_eq_str(const char *a, str b);
bool cstr_eq_cstr(const char *a, const char *b);

#define str_eq(LHS, RHS) _Generic((LHS), str: _Generic((RHS), str: str_eq_str, char *: str_eq_cstr), char *: _Generic((RHS), str: cstr_eq_str, char *: cstr_eq_cstr))((LHS), (RHS))

bool str_eq_str_any(str it, int count, ...);
bool str_eq_cstr_any(str it, int count, ...);
bool cstr_eq_str_any(const char *it, int count, ...);
bool cstr_eq_cstr_any(const char *it, int count, ...);

#define str_eq_any(LHS, COUNT, RHS, ...) _Generic((LHS), str: _Generic((RHS), str: str_eq_str_any, char *: str_eq_cstr_any), char *: _Generic((RHS), str: cstr_eq_str_any, char *: cstr_eq_cstr_any))((LHS), (COUNT), (RHS) __VA_OPT(, __VA_ARGS__))
