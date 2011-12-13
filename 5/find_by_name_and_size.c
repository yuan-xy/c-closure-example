#include <dir_each.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

void compare_name_and_size(struct dirent * dp, char *dir_name, va_list args){
	char *find_str =va_arg(args, char *);
	int min_byte =va_arg(args, int);
	if(strncmp(dp->d_name, find_str, strlen(find_str))==0){
		struct stat	statbuf;
		char buf[1024]={0};
		strcat(buf,dir_name); 
		strcat(buf,dp->d_name);
		if (stat(buf, &statbuf) !=-1){
			if(statbuf.st_size>=min_byte) printf("%s, %d\n",dp->d_name, (int)statbuf.st_size);
		}
	}
}

void find(char *dir_name, char *find_str, int min_byte){
	each(compare_name_and_size, dir_name, find_str, min_byte);
}

int main(int argc, char *argv[]){
	if(argc<=3) find("./","a",10);
	else find(argv[1],argv[2],atoi(argv[3]));
	return 1;
}

