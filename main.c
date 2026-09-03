#include <SDL3/SDL_audio.h>
#include <SDL3/SDL_init.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "SDL3/SDL.h"

#define AUDIO_FILE "./audio/sound.wav"

int main() {
    SDL_Init(SDL_INIT_AUDIO);
    SDL_AudioSpec audioSpec;
    Uint8* audioStart;
    Uint32 audioLength;

    char buffer[110];
    char othr[20]; //uhhhm stuff that I'll just throw away, I'll put it here; may be overflowing (yikes)
    time_t currtime;
    bool played = false;
    int checkd;
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
        if(checkd <= 2 && fgets(buffer, sizeof(buffer), timefile) != NULL) {
            if (tim->tm_wday != 0 && tim->tm_wday <= 5) {
                if (strncmp(buffer, "WEEKDAY", 7) == 0) {
                    int res = sscanf(buffer, "%s %d %c %d ", othr, &hrs, othr, &mins);
                    // printf("weekday result - %d\n", res);
                }
            }
            else {
                strncmp(buffer, "WEEKEND", 7);
                int res = sscanf(buffer, "%s %d %c %d ", othr, &hrs, othr, &mins);
                // printf("weekend result - %d\n", res);
            }
            checkd++;
        }
        if (tim->tm_hour == hrs && tim->tm_min == mins) { // I may add re-playing later, as it may no longer be needed for me.
            printf("time came\n"); // will replace with sound playing logic later aswell.
            if (!SDL_LoadWAV(AUDIO_FILE, &audioSpec, &audioStart, &audioLength)) {
                perror("failed to load audio file");
            }
            played = true;
        }
        continue;
    }

    fclose(timefile);
    return 0;
}
