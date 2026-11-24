/*
hi wellcome to POT pomodoro , i hope you enjoy it and if needed change it what ever you like 
and if you have any suggestion or something , you could reach out with my email address : mostafa.moharrami00@gmail.com 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio/miniaudio.h"

void popup_centered(const char *title, const char *msg);
int main () {
    int timer;
    ma_engine engine ;

    printf("\nplease enter your timer countdown (minute) : ");
    scanf("%d", &timer);
    
    timer *= 60 ; 

    time_t start = time(NULL);
    time_t end = start + timer ;

    if(ma_engine_init(NULL, &engine) != MA_SUCCESS){
        printf("audio initial fail ! ");
        return 1;
    }

    while(time(NULL) < end) {
        long remaining = (long)(end - time(NULL));
        int m = remaining/60;
        int s = remaining%60;
        printf("\r%02d:%02d remaining", m, s);
        fflush(stdout);
        sleep(1);
    }
    printf("\ndone !\n\n");
    system("notify-send 'Pomodoro' 'Time is up! Take a break.'");
    ma_engine_play_sound(&engine, "2.mp3", NULL);

    printf("\n┌──────────────────────────┐\n");
    printf("│   TIME IS UP!            │\n");
    printf("│   Take a break           │\n");
    printf("└──────────────────────────┘\n\n");
    
    sleep(10);

    ma_engine_uninit(&engine);

    return 0 ;

}
