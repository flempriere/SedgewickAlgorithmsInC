/**
 * @file NumberParse.h
 * @author Felix Lempriere
 * @brief Contains variants of the strtol an strtof family with inbuilt
 * error checking and default arguments.
 * @version 0.1
 * @date 2025-03-28
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once

#include "DefaultArguments.h"
#include "TraceMacro.h"
#include "Utility.h"

#include <errno.h>
#include <limits.h>
#include <stdlib.h>

/* Integer Parsing variants */

#define NUMPARSEstrtoul(...) CALL3(strtoul, "0", nullptr, 0, __VA_ARGS__)
#define NUMPARSEstrtoull(...) CALL3(strtoull, "0", nullptr, 0, __VA_ARGS__)
#define NUMPARSEstrtol(...) CALL3(strtol, "0", nullptr, 0, __VA_ARGS__)
#define NUMPARSEstrtoll(...) CALL3(strtoll, "0", nullptr, 0, __VA_ARGS__)

/* Float Parsing variants */
#define NUMPARSEstrtof(...) CALL2(strtof, "0", nullptr, __VA_ARGS__)
#define NUMPARSEstrtod(...) CALL2(strtod, "0", nullptr, __VA_ARGS__)
#define NUMPARSEstrtold(...) CALL2(strtold, "0", nullptr, __VA_ARGS__)

// Parsing functions to encapsulate error handling.

// Unsigned versions

bool NUMPARSEtoull(unsigned long long* out, char s[static 1], char** end,
                   int base) {
    char* stop;
    auto prev_errno = errno;
    errno = 0;
    const unsigned long long ull = strtoull(s, &stop, 0);

    if (end) *end = stop;
    if (stop == s) {
        TRACE_VALUE("Not interpretable as a number", s);
        errno = prev_errno;
    } else if (ull == ULLONG_MAX && errno == ERANGE) {
        TRACE_VALUE("Out of range of type unsigned long long", s);
    } else {
        errno = prev_errno;
        if (out) *out = ull;
        return true;
    }
    return false;
}

bool NUMPARSEtoul(unsigned long* out, char s[static 1], char** end, int base) {
    char* stop;
    auto prev_errno = errno;
    errno = 0;
    const unsigned long ul = strtoul(s, &stop, 0);

    if (end) *end = stop;
    if (stop == s) {
        TRACE_VALUE("Not interpretable as a number", s);
        errno = prev_errno;
    } else if (ul == ULONG_MAX && errno == ERANGE) {
        TRACE_VALUE("Out of range of type unsigned long", s);
    } else {
        errno = prev_errno;
        if (out) *out = ul;
        return true;
    }
    return false;
}

bool NUMPARSEtoui(unsigned* out, char s[static 1], char** end, int base) {
    char* stop;
    unsigned long l;
    if (NUMPARSEtoul(&l, s, &stop, base)) {
        if (end) *end = stop;
        if ((l < UINT_MAX)) {
            if (out) *out = CAST(unsigned) l;
            return true;
        }
        TRACE_VALUE("Out of range of type unsigned", l);
    }
    return false;
}

bool NUMPARSEtous(unsigned short* out, char s[static 1], char** end, int base) {
    char* stop;
    unsigned long l;
    if (NUMPARSEtoul(&l, s, &stop, base)) {
        if (end) *end = stop;
        if ((l < USHRT_MAX)) {
            if (out) *out = CAST(unsigned short) l;
            return true;
        }
        TRACE_VALUE("Out of range of type unsigned short", l);
    }
    return false;
}

bool NUMPARSEtouc(unsigned char* out, char s[static 1], char** end, int base) {
    char* stop;
    unsigned long l;
    if (NUMPARSEtoul(&l, s, &stop, base)) {
        if (end) *end = stop;
        if ((l < UCHAR_MAX)) {
            if (out) *out = CAST(unsigned char) l;
            return true;
        }
        TRACE_VALUE("Out of range of type unsigned char", l);
    }
    return false;
}

bool NUMPARSEtoll(long long* out, char s[static 1], char** end, int base) {
    char* stop;
    auto prev_errno = errno;
    errno = 0;
    const long long ll = strtoll(s, &stop, 0);

    if (end) *end = stop;
    if (stop == s) {
        TRACE_VALUE("Not interpretable as a number", s);
        errno = prev_errno;
    } else if ((ll == LLONG_MIN || ll == LLONG_MAX) && errno == ERANGE) {
        TRACE_VALUE("Out of range of type long long", s);
    } else {
        errno = prev_errno;
        if (out) *out = ll;
        return true;
    }
    return false;
}

bool NUMPARSEtol(long* out, char s[static 1], char** end, int base) {
    char* stop;
    auto prev_errno = errno;
    errno = 0;
    const long l = strtol(s, &stop, 0);

    if (end) *end = stop;
    if (stop == s) {
        TRACE_VALUE("Not interpretable as a number", s);
        errno = prev_errno;
    } else if ((l == LONG_MIN || l == LONG_MAX) && errno == ERANGE) {
        TRACE_VALUE("Out of range of type long", s);
    } else {
        errno = prev_errno;
        if (out) *out = l;
        return true;
    }
    return false;
}

bool NUMPARSEtoi(int* out, char s[static 1], char** end, int base) {
    char* stop;
    long l;
    if (NUMPARSEtol(&l, s, &stop, base)) {
        if (end) *end = stop;
        if ((l < INT_MIN) || (l > INT_MAX)) {
            TRACE_VALUE("Out of range of type int", l);
        } else {
            if (out) *out = CAST(int) l;
            return true;
        }
    }
    return false;
}

bool NUMPARSEtos(short* out, char s[static 1], char** end, int base) {
    char* stop;
    long l;
    if (NUMPARSEtol(&l, s, &stop, base)) {
        if (end) *end = stop;
        if ((l < SHRT_MIN) || (l > SHRT_MAX)) {
            TRACE_VALUE("Out of range of type short", l);
        } else {
            if (out) *out = CAST(short) l;
            return true;
        }
    }
    return false;
}

bool NUMPARSEtosc(signed char* out, char s[static 1], char** end, int base) {
    char* stop;
    long l;
    if (NUMPARSEtol(&l, s, &stop, base)) {
        if (end) *end = stop;
        if ((l < SCHAR_MIN) || (l > SCHAR_MAX)) {
            TRACE_VALUE("Out of range of type signed char", l);
        } else {
            if (out) *out = CAST(signed char) l;
            return true;
        }
    }
    return false;
}

bool NUMPARSEtoc(char* out, char s[static 1], char** end, int base) {
    char* stop;
    long l;
    if (NUMPARSEtol(&l, s, &stop, base)) {
        if (end) *end = stop;
        if ((l < CHAR_MIN) || (l > CHAR_MAX)) {
            TRACE_VALUE("Out of range of type char", l);
        } else {
            if (out) *out = CAST(char) l;
            return true;
        }
    }
    return false;
}

bool NUMPARSEtof(float* out, char s[static 1], char** end) {
    char* stop;
    auto prev_errno = errno;
    errno = 0;
    const float f = strtof(s, &stop);

    if (end) *end = stop;
    if (stop == s) {
        TRACE_VALUE("Not interpretable as a number", s);
        errno = prev_errno;
    } else if (errno == ERANGE) {
        TRACE_VALUE("Out of range of type float", s);
    } else {
        errno = prev_errno;
        if (out) *out = f;
        return true;
    }
    return false;
}

bool NUMPARSEtod(double* out, char s[static 1], char** end) {
    char* stop;
    auto prev_errno = errno;
    errno = 0;
    const double f = strtod(s, &stop);

    if (end) *end = stop;
    if (stop == s) {
        TRACE_VALUE("Not interpretable as a number", s);
        errno = prev_errno;
    } else if (errno == ERANGE) {
        TRACE_VALUE("Out of range of type double", s);
    } else {
        errno = prev_errno;
        if (out) *out = f;
        return true;
    }
    return false;
}

bool NUMPARSEtold(long double* out, char s[static 1], char** end) {
    char* stop;
    auto prev_errno = errno;
    errno = 0;
    const long double f = strtold(s, &stop);

    if (end) *end = stop;
    if (stop == s) {
        TRACE_VALUE("Not interpretable as a number", s);
        errno = prev_errno;
    } else if (errno == ERANGE) {
        TRACE_VALUE("Out of range of type long double", s);
    } else {
        errno = prev_errno;
        if (out) *out = f;
        return true;
    }
    return false;
}

/**
 * @brief Parse  a number from a given string and store it in the variable
 * pointed to by out. Ensures that the read value fits in the bounds.
 *
 * @param out pointer to store extracted value in.
 *
 * @return true if value successfully extracted, else
 * @return false.
 */
#define NUMPARSE(out, s, ...)                                                 \
    _Generic(CAST(typeof(out)) nullptr,                                       \
        unsigned char*: CALL4_ND2(NUMPARSEtouc,                               \
                                  _Generic(CAST(typeof(out)) nullptr,         \
                                      unsigned char*: out,                    \
                                      default: nullptr),                      \
                                  s, nullptr, 0 __VA_OPT__(, ) __VA_ARGS__),  \
        unsigned short*: CALL4_ND2(NUMPARSEtous,                              \
                                   _Generic(CAST(typeof(out)) nullptr,        \
                                       unsigned short*: out,                  \
                                       default: nullptr),                     \
                                   s, nullptr, 0 __VA_OPT__(, ) __VA_ARGS__), \
        unsigned int*: CALL4_ND2(NUMPARSEtoui,                                \
                                 _Generic(CAST(typeof(out)) nullptr,          \
                                     unsigned int*: out,                      \
                                     default: nullptr),                       \
                                 s, nullptr, 0 __VA_OPT__(, ) __VA_ARGS__),   \
        unsigned long*: CALL4_ND2(NUMPARSEtoul,                               \
                                  _Generic(CAST(typeof(out)) nullptr,         \
                                      unsigned long*: out,                    \
                                      default: nullptr),                      \
                                  s, nullptr, 0 __VA_OPT__(, ) __VA_ARGS__),  \
        unsigned long long*: CALL4_ND2(NUMPARSEtoull,                         \
                                       _Generic(CAST(typeof(out)) nullptr,    \
                                           unsigned long long*: out,          \
                                           default: nullptr),                 \
                                       s, nullptr,                            \
                                       0 __VA_OPT__(, ) __VA_ARGS__),         \
        char*: CALL4_ND2(NUMPARSEtoc,                                         \
                         _Generic(CAST(typeof(out)) nullptr,                  \
                             char*: out,                                      \
                             default: nullptr),                               \
                         s, nullptr, 0 __VA_OPT__(, ) __VA_ARGS__),           \
        signed char*: CALL4_ND2(NUMPARSEtosc,                                 \
                                _Generic(CAST(typeof(out)) nullptr,           \
                                    signed char*: out,                        \
                                    default: nullptr),                        \
                                s, nullptr, 0 __VA_OPT__(, ) __VA_ARGS__),    \
        short*: CALL4_ND2(NUMPARSEtos,                                        \
                          _Generic(CAST(typeof(out)) nullptr,                 \
                              short*: out,                                    \
                              default: nullptr),                              \
                          s, nullptr, 0 __VA_OPT__(, ) __VA_ARGS__),          \
        int*: CALL4_ND2(NUMPARSEtoi,                                          \
                        _Generic(CAST(typeof(out)) nullptr,                   \
                            int*: out,                                        \
                            default: nullptr),                                \
                        s, nullptr, 0 __VA_OPT__(, ) __VA_ARGS__),            \
        long*: CALL4_ND2(NUMPARSEtol,                                         \
                         _Generic(CAST(typeof(out)) nullptr,                  \
                             long*: out,                                      \
                             default: nullptr),                               \
                         s, nullptr, 0 __VA_OPT__(, ) __VA_ARGS__),           \
        long long*: CALL4_ND2(NUMPARSEtoll,                                   \
                              _Generic(CAST(typeof(out)) nullptr,             \
                                  long long*: out,                            \
                                  default: nullptr),                          \
                              s, nullptr, 0 __VA_OPT__(, ) __VA_ARGS__),      \
        float*: CALL3_ND2(NUMPARSEtof,                                        \
                          _Generic(CAST(typeof(out)) nullptr,                 \
                              float*: out,                                    \
                              default: nullptr),                              \
                          s, nullptr __VA_OPT__(, ) __VA_ARGS__),             \
        double*: CALL3_ND2(NUMPARSEtod,                                       \
                           _Generic(CAST(typeof(out)) nullptr,                \
                               double*: out,                                  \
                               default: nullptr),                             \
                           s, nullptr __VA_OPT__(, ) __VA_ARGS__),            \
        long double*: CALL3_ND2(NUMPARSEtold,                                 \
                                _Generic(CAST(typeof(out)) nullptr,           \
                                    long double*: out,                        \
                                    default: nullptr),                        \
                                s, nullptr __VA_OPT__(, ) __VA_ARGS__))
