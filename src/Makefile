main : detect.o AudioFile.o
	g++ detect.o AudioFile.o -o main -lSDL2 -lSDL2_mixer `pkg-config --cflags --libs opencv4`

detect.o : detect.cpp detect.h
	g++ -c detect.cpp `pkg-config --cflags --libs opencv4`

AudioFile.o : AudioFile.cpp AudioFile.h
	g++ -c AudioFile.cpp `pkg-config --cflags --libs sdl2`
