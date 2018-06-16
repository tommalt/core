#include <ctype.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core.h"

/* base */
void warn(char const *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	vfprintf(stdout, fmt, args);
	va_end(args);
}
void die(char const *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	vfprintf(stdout, fmt, args);
	va_end(args);
	exit(1);
}
int32_t nextpowerof2(int32_t n)
{
	n--;
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n++;
	return n;
}

/* string */
#define SPLIT_TOKEN_SIZE 256
void split(char const *line, char const *sep, char ***out, int *outsize, int *outcap)
{
	char const *begin, *end;
	int i;
	
	if (!*out) {
		*out = malloc(8 * sizeof **out);
		for (int i = 0; i < 8; i++) {
			(*out)[i] = malloc(SPLIT_TOKEN_SIZE);
		}
		*outcap = 8;
	}
	begin = end = line;
	i = 0;
	do {
		/* enough memory? */
		if (i >= *outcap) {
			int newsize = *outcap + 2;
			*out = realloc(*out, newsize * sizeof **out);
			if (!*out) { die("Out of memory\n"); }
			for (int k = *outcap; k < newsize; k++) {
				(*out)[k] = malloc(SPLIT_TOKEN_SIZE);
			}
			*outcap = newsize;
		}
		/* do copy */
		while (*end && !strchr(sep, *end)) {
			end++;
		}
		int size = end - begin;
		strncpy((*out)[i], begin, size);
		(*out)[i][size] = '\0';
		/* advance */
		begin = end;
		while (*begin && strchr(sep, *begin)) {
			begin++;
		}
		end = begin;
		i++;
	} while (*begin);
	*outsize = i; /* tell caller how many elements were split */
}
void lstrip(char *s)
{
	char *p;
	for (p = s; *p && isspace(*p); p++)
		;
	if (p != s)
		memmove(s, p, strlen(p) + 1);
}
void rstrip(char *s)
{
	char *end = s + strlen(s);
	while (--end >= s && isspace(*end))
		;
	end++;
	*end = '\0';
}
void strip(char *s)
{
	rstrip(s);
	lstrip(s);
}

