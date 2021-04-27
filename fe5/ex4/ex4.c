#include <stdio.h>
#include <time.h>

int main() {
    printf("Number of clock interruptions per second: %d\n", CLOCKS_PER_SEC);
    printf("time: %lu\n", time(NULL));

    time_t epoch = 0;
    struct tm* t = localtime(&epoch);
    printf("date: %d/%d/%d\n", t->tm_yday + 1, t->tm_mon + 1, t->tm_year + 1900);
    printf("size = %d", sizeof(time(NULL)));

    return 0;
}