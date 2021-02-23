#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int open_sys_calls(int argc, char* argv[]){

    if( argc <= 2){
        fprintf(stderr, "No path was introduced\n");
        return 1;
    } else {
        int fd1 = open(argv[2], O_RDONLY), fd2, res;
        if(argc > 3) fd2 = open(argv[3], O_WRONLY);
        void * buffer = malloc(sizeof(char));
        while((res = read(fd1, buffer, 1)) == 1){
            if(argc > 3) write(fd2, buffer, 1);
            else printf("%c", ((char*) buffer)[0]);
        }
        if(res != -1){
            if(argc > 3) printf("Successful write.");
            printf("\n");
        }
        free(buffer);
        return res;
    }

    return 0;
}

int open_c_libraries(int argc, char* argv[]){
    
    if( argc <= 2){
        fprintf(stderr, "No path was introduced\n");
        return 1;
    } else {
        FILE* filer = fopen(argv[2],"r");
        FILE* filew = NULL;
        if(filer == NULL) return 1;
        if(argc > 3){
            filew = fopen(argv[3], "w");
        }
        while(!feof(filer)){
            char c = fgetc(filer);
            if(argc > 3) fprintf(filew, "%c", c);
            else fprintf(stdout, "%c", c);
        }
        fclose(filer);
        if(filew != NULL){
            fprintf(stdout, "Successful write.");
            fclose(filew);
        }
        return 0;
    }

    return 0;
}

int main(int argc, char* argv[]){
    if(argc <= 1){
        fprintf(stderr, "Invalid call (-c or -sys parameter)\n");
        return 1;
    }else{
        if(strcmp(argv[1], "-c") == 0) return open_c_libraries(argc, argv);
        else if(strcmp(argv[1], "-sys") == 0) return open_sys_calls(argc,argv);
        else{
            fprintf(stderr, "Invalid call (-c or -sys parameter)\n");
            return 1;
        }
    }

}