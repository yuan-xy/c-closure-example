#include <dir_each.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

void find(char *dir_name, char *find_str, int min_byte){
    void compare_name_and_size(struct dirent * dp){
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
	each(compare_name_and_size, dir_name);
}

int main(int argc, char *argv[]){
	if(argc<=3) find("./","a",10);
	else find(argv[1],argv[2],atoi(argv[3]));
	return 1;
}

