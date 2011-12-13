#include "dir_each.h"
#include <stdio.h>

void each(pDirentVisitor visitor, char *dir_name, ...){
	va_list args,args2;
	struct dirent * dp;
    DIR * dirp = opendir(dir_name);
    if(dirp==NULL) return;
	va_start (args, dir_name);
    while ((dp = readdir(dirp)) != NULL){
		va_copy(args2,args);
		(*visitor)(dp, dir_name, args2);
		va_end(args2);
    }
    closedir(dirp);
	va_end(args);
}