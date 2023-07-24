#include <SDL2/SDL_mixer.h>
#include <memory>
#include <string>

class AudioFile
{
    public:
        AudioFile(const std::string &FILE_PATH, int volume);
        ~AudioFile();
        void play();
    private:
        std::unique_ptr<Mix_Chunk, void (*)(Mix_Chunk *)> chunk;
};
