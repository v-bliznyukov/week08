#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(){
	int ret;
 	struct stat s; 
	struct dirent *file;
 
	DIR *dir;
  dir = opendir("./tmp");
 

      //the programme ouputs files with 2 hard links in tmp directory and outputs them
  		while((file = readdir(dir))!=NULL){
  		
  			if(file->d_name[0]=='.') continue;
        char m[100000] = "tmp/";
        ret= stat(strcat(m, file->d_name), &s);
        puts(file->d_name);
			if (s.st_nlink >= 2){
        
        }
        
				printf(" Inode number: %ld \n", s.st_ino);
				printf(" #hard links : %ld \n", s.st_nlink);
        
				

		}

		closedir(dir);



	return 0;

}

