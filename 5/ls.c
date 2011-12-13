#include <dir_each.h>
#include <stdio.h>

void print_name(struct dirent * dp, char *dir_name, va_list args){
	printf("%s\n",dp->d_name);
}

void ls(char *dir_name){
	each(print_name, dir_name);
}


int main(int argc, char *argv[]){
	if(argc<=1) ls(".");
	else ls(argv[1]);
	return 1;
}

