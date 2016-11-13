#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>

extern void eprintf(char *, ...);
extern void weprintf(char *, ...);
extern char *estrdup(const char *);
extern void *emalloc(size_t);
extern void *erealloc(void *, size_t);
extern char *progname(void);
extern void setprogname(const char *);
