#ifndef CORE_STRING_H
#define CORE_STRING_H

void split(char const *line, char const *sep, char ***out, int *outsize, int *outcap);
void strip(char *s);

#endif
