# 🧵 str

**This repository has been moved to [Codeberg](https://codeberg.org/rubiefawn/str).**

Common string utilities for C I'm sick of rewriting:

- Utilities for string "slices" (also known as "views" or "spans"), which are a pointer + length. Useful for substring references.
- `strzcat()` and `strzcpy()`, sane alternatives to `strcat()` and `strcpy()`.
- Polyfill implementations for `strdup()` and `strndup()`

None of these are tested, optimized, or otherwise fit for use.
