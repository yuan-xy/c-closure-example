#include <dir_each.h>
#include <stdio.h>

void ls(char *dir_name){
	void print_name(struct dirent * dp){
		printf("%s\n",dp->d_name);
	}
	each(print_name, dir_name);
}


int main(int argc, char *argv[]){
	if(argc<=1) ls(".");
	else ls(argv[1]);
	return 1;
}

