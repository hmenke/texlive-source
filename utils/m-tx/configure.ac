dnl Process this file with autoconf to produce a configure script.
dnl
dnl   Copyright (C) 2012-2015 Peter Breitenlohner <tex-live@tug.org>
dnl
dnl   This file is free software; the copyright holder
dnl   gives unlimited permission to copy and/or distribute it,
dnl   with or without modifications, as long as this notice is preserved.
dnl
m4_include([version.ac])[] dnl define mtx_version
AC_INIT([m-tx (TeX Live)], mtx_version, [tex-k@tug.org])
AC_PREREQ([2.65])
AC_CONFIG_SRCDIR([mtx-src/analyze.c])
AC_CONFIG_AUX_DIR([../../build-aux])
AC_CONFIG_MACRO_DIR([../../m4])

KPSE_BASIC([m-tx])

dnl Check compiler and flags
AC_PROG_CC

dnl Checks for programs.
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([memory.h stddef.h stdlib.h string.h strings.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([memchr memmove memset strchr strrchr strtol])

AC_SUBST([MTX_TREE], [mtx-src])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
