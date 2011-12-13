#include <dirent.h>

typedef void (*pDirentVisitor)(struct dirent * dp, void *context);

extern void each(pDirentVisitor visitor, char *dir_name, void *context);