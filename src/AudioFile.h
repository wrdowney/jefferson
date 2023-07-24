#include <SDL2/SDL_mixer.h>
#include <memory>

class AudioFile
{
    public:
        AudioFile(const char * FILE_PATH);
        void play();
    private:
        std::unique_ptr<Mix_Chunk, void (*)(Mix_Chunk *)> chunk;
};
