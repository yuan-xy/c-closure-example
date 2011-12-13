#include "dir_each.h"
#include <stdio.h>

void each(pDirentVisitor visitor, char *dir_name, void *context){
	struct dirent * dp;
    DIR * dirp = opendir(dir_name);
    if(dirp==NULL) return;
    while ((dp = readdir(dirp)) != NULL){
		(*visitor)(dp, context);
    }
    closedir(dirp);
}