#ifndef DEBUG_H
#define DEBUG_H

#include <inttypes.h>
#include <stdio.h>

#ifdef LOG_ENABLE_DEBUG
#define debugmsg(x) \
    do { \
        fprintf(stdout, x); \
        fflush(stdout); \
    } while (0);
#else
#define debugmsg(x)
#endif

#define logmsg(...) \
    do { \
        fprintf(stdout, __VA_ARGS__); \
        fflush(stdout); \
    } while (0);

#endif // DEBUG_H
