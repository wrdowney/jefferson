main : detect.o play_wav.o
	g++ detect.o play_wav.o -o main `pkg-config --cflags --libs opencv4 sdl2`

detect.o : detect.cpp detect.h
	g++ -c detect.cpp `pkg-config --cflags --libs opencv4`

play_wav.o : play_wav.cpp play_wav.h
	g++ -c play_wav.cpp `pkg-config --cflags --libs sdl2`
