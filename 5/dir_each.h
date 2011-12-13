#include <dirent.h>
#include <stdarg.h>

typedef void (*pDirentVisitor)(struct dirent * dp,char *dir_name, va_list args);

extern void each(pDirentVisitor visitor, char *dir_name, ...);