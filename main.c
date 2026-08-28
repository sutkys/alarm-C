#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int main() {
    time_t currtime;
    bool played = false;
    currtime = time(NULL);
    struct tm *tim = localtime(&currtime);
    int min = 39;

    while (tim->tm_min < min) {
        currtime = time(NULL);
        tim = localtime(&currtime);
        printf("mins %d & secs %d\n", tim->tm_min, tim->tm_sec);
        if (tim->tm_min == min || tim->tm_min > min && !played) {
            printf("meow\n");
            played = true;
            break;
        }
    }
    printf("its so over\n");
    return 0;
}
