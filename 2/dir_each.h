#include <dirent.h>

typedef void (*pDirentVisitor)(struct dirent * dp);

extern void each(pDirentVisitor visitor, char *dir_name);