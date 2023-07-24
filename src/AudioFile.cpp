#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <string>
#include "AudioFile.h"

using namespace std;

AudioFile::AudioFile(const std::string &FILE_PATH, int volume): chunk(Mix_LoadWAV(FILE_PATH.c_str()), Mix_FreeChunk) {
    if (SDL_Init(SDL_INIT_AUDIO) != 0)
    {
        cerr << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != 0)
    {
        cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
    }

    if (!chunk.get())
    {
        cerr << "Could not load sound file " << FILE_PATH << endl;
        cerr << "SDL_mixer Error: " << Mix_GetError() << endl;
    }
}

AudioFile::~AudioFile()
{
    Mix_FreeChunk(chunk.get());
    chunk.release();
}

void AudioFile::play()
{
    int channel = Mix_PlayChannel(-1, chunk.get(), 0);
    if (channel == -1)
    {
        cout << "Could not play sound file " << endl;
        cout << "SDL_mixer Error: " << Mix_GetError() << endl;
    }
}
