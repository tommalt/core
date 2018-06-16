#ifndef CORE_BASE_H
#define CORE_BASE_H

#include <stdint.h>

void warn(char const *fmt, ...);
void die(char const *fmt, ...);
int32_t nextpowerof2(int32_t n);

#endif
