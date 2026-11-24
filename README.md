# POT Pomodoro

A simple CLI Pomodoro timer written in C.

Enter how many minutes you want to focus. It counts down live in your
terminal, then plays a sound and shows a notification when time is up.
Built as a first real project while learning C and Linux.

## Features

- Live countdown display in the terminal (`MM:SS`)
- Terminal bell + popup box when time is up
- Desktop notification via `notify-send`
- Plays an audio file (MP3/WAV) via miniaudio
- Single small C file, easy to read and modify

## Build

```bash
gcc POTpomodoro.c -o POTpomodoro -lpthread -lm -ldl


## HOW TO RUN 

click on it or open terminal in that folder and run : ./POTpomodoro
or just click on execute file.

## Music 
music can be changed , just put the music in the folder and change source
code( "2.mp3" ) with your music track name.


## Platform

Written and tested on Linux.

It *should* be portable to Windows with small changes:
- Replace `unistd.h` / `sleep()` with `windows.h` / `Sleep()`
- Drop the `notify-send` line (no equivalent on Windows)
- Compile with MinGW and link `-lwinmm`

macOS should work with minor tweaks to the notification line
(`osascript` instead of `notify-send`).

Pull requests welcome if you port it.
