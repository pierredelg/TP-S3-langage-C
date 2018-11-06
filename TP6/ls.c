#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main(){

	struct stat * buf;

	buf = malloc(sizeof(struct stat));

	if(buf != NULL){

		stat("Bureau",buf);
		printf("%ld\n",buf-> st_dev);

		if(S_ISDIR(buf->st_mode)){

			DIR * rep = opendir("Bureau");
			
			if (rep != NULL){
			
				struct dirent * ent = readdir(rep);
			
				while(ent != NULL){

					printf("%s\n",ent->d_name);
					ent = readdir(rep);
				}
			
				closedir(rep);
			}
		}
	}

	return 0;
}