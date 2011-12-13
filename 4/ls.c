#include <dir_each.h>
#include <stdio.h>

void print_name(struct dirent * dp, void *context){
	printf("%s\n",dp->d_name);
}

void ls(char *dir_name){
	each(print_name, dir_name,NULL);
}


int main(int argc, char *argv[]){
	if(argc<=1) ls(".");
	else ls(argv[1]);
	return 1;
}

