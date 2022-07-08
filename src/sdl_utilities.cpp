#include "vubi/sdl_utilities.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace vubi {
namespace sdl_utilities {

bool initialize_video() {
    return SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == 0;
}

bool initialize_image() {
    const int flags = IMG_INIT_PNG | IMG_INIT_JPG;
    return (IMG_Init(flags) & flags) == flags;
}

}  // namespace sdl_utilities
}  // namespace vubi