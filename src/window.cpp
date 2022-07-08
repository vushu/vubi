#include "vubi/window.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_video.h>

#include <stdexcept>
namespace vubi {

SDL_Window* initialize_sdl() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        throw std::runtime_error("Failed to initialize SDL");
    }
    const int flags = IMG_INIT_PNG | IMG_INIT_JPG;
    if ((IMG_Init(flags) & flags) != flags) {
        throw std::runtime_error("Failed to init SDL2 IMAGE");
    }
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Succesfully initialized SDL");
    return SDL_CreateWindow("Vulkan app", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, 800, 600,
                            SDL_WINDOW_VULKAN | SDL_WINDOW_SHOWN);
}

Window::Window() { sdl_window_ = initialize_sdl(); }

Window::~Window() { SDL_DestroyWindow(sdl_window_); }

}  // namespace vubi
