#ifndef _HSTRING_H
#define _HSTRING_H

char *hstrcpy(char *dst, const char *src);
char *hstrcat(char *s1, char *s2);
unsigned int hstrlen(char *str);
void *hmemset(void *s, int c, unsigned int n);
int hstrcmp(char *s1, char *s2);

#endif /* _HSTRING_H */
