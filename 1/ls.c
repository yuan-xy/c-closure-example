#include <dirent.h>
#include <stdio.h>

void ls(char *dir_name){
    struct dirent * dp;
    DIR * dirp = opendir(dir_name);
    if(dirp==NULL) return;
    while ((dp = readdir(dirp)) != NULL){
		printf("%s\n",dp->d_name);
    }
    closedir(dirp); 
}

int main(int argc, char *argv[]){
	if(argc<=1) ls(".");
	else ls(argv[1]);
	return 1;
}

