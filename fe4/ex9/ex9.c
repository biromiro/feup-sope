#include <stdio.h>
#include <string.h>

int main(void) {
    char buff[15];
    int pass = 0;

    printf("\n Enter the password : \n");
    fgets(buff, 15, stdin);  // man gets -> never use this function
    buff[strcspn(buff, "\n")] = 0;
    printf("%s", buff);
    if (strcmp(buff, "thegeekstuff")) {
        printf("\n Wrong Password. \n");
    } else {
        printf("\n Correct Password.\n");
        pass = 1;
    }

    if (pass) {  // do somelhing priviledged stuff
        printf("\n Root privileges given to the user.\n");
    }
    return 0;
}