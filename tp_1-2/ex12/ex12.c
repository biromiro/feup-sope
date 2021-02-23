#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>


int main(int argc, char* argv[]){

    if(argc <= 1){
        fprintf(stdout, "Invalid command.");
        return 1;
    }
    DIR* directory_to_search = opendir(argv[1]);
    struct dirent* file_val;

    while((file_val = readdir(directory_to_search)) != NULL){
        struct stat path_stat;
        char * path = malloc(sizeof(argv[1]) + sizeof('/') + sizeof(file_val->d_name));
        sprintf(path, "%s/%s", argv[1], file_val->d_name);
        stat(path, &path_stat);
        if(S_ISREG(path_stat.st_mode)){
            fprintf(stdout, "%s : %d bytes\n", file_val->d_name, path_stat.st_size);
        }
    }

    return 0;

}