#ifndef WINDOW_H
#define WINDOW_H
#include <SDL2/SDL.h>
namespace vubi {

class Window {
   public:
    Window();
    ~Window();

   private:
    SDL_Window* sdl_window_;
};
}  // namespace vubi
#endif
