#ifndef CORE_MACROS_H
#define CORE_MACROS_H

#define MAX(a, b) (((a) >= (b)) ? (a) : (b))
#define MIN(a, b) (((a) <= (b)) ? (a) : (b))
#define ARRAY_SIZE(x) (sizeof (x) / sizeof (x)[0])

#endif
