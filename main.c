#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char buffer[100];
    char othr[20]; //uhhhm stuff that I'll just throw away, I'll put it here
    time_t currtime;
    bool played = false;
    bool isChecked;
    struct tm *tim;
    int hrs;
    int mins;
    currtime = time(NULL);
    tim = localtime(&currtime);

    FILE *timefile = fopen("alarm.time", "r");
    if (timefile == NULL) {
        perror("file could not be found or is corrupted.");
        return 1;
    }

    while (!played) {
        currtime = time(NULL);
        tim = localtime(&currtime);
        if(!isChecked && fgets(buffer, sizeof(buffer), timefile) != NULL) {
            if (tim->tm_wday != 0 && tim->tm_wday <= 5) {
                if (strncmp(buffer, "WEEKDAY", 7) == 0) {
                    int res = sscanf(buffer, "%s %d %c %d ", othr, &hrs, othr, &mins);
                    //printf("resulllll %d\n", res);
                }
            }
            else if (strncmp(buffer, "WEEKEND", 7) == 0) {
                sscanf(buffer, "%s %d %c %d ", othr, &hrs, othr, &mins);
            }
            isChecked = true;
            printf("waited\n");
        }
        if (tim->tm_hour == hrs && tim->tm_min == mins) { // yes, there will be re-playing later.
            printf("meows\n"); // will replace with sound playing logic and stuff
        }
        continue;
    }
    fclose(timefile);
    return 0;
}
