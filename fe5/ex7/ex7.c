// Turn off echoing on screen of keyboard characters: example program.

#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    char c[50];
    int i = 0;
    struct termios tms, tms_ini, tmsout, tmsout_ini;
    setvbuf(stdout, NULL, _IONBF, 0);

    printf("User name: ");
    scanf("%s", c);
    printf("Password: ");

    tcgetattr(STDIN_FILENO, &tms_ini);  // read console's configuration
    tms = tms_ini;

    tms.c_lflag &= ~ECHO;
    tms.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &tms);  // set new configuration

    tcgetattr(STDOUT_FILENO, &tmsout_ini);
    tmsout = tmsout_ini;

    tmsout.c_lflag &= ~ICANON;

    tcsetattr(STDOUT_FILENO, TCSANOW, &tmsout);

    do {
        if (read(STDIN_FILENO, c + i, 1) != 1) perror("read failed");
        if (c[i] == 127) {
            c[i] = 0;
            if (i > 0) {
                c[--i] = 0;
                write(STDOUT_FILENO, "\b\b\b   \b\b\b", 9);
            }
        } else if (c[i] != '\n') {
            write(STDOUT_FILENO, "***", 3);
            i++;
        }
    } while (c[i] != '\n');  // wait for [ENTER]
    c[i] = '\0';

    tcsetattr(STDIN_FILENO, TCSANOW, &tms_ini);      // reset configuration
    tcsetattr(STDOUT_FILENO, TCSANOW, &tmsout_ini);  // reset configuration

    printf("\nInitial console configuration has been reset!\n");
    printf("password received: %s\n", c);

    return 0;
}  // main()