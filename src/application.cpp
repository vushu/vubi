#include "vubi/application.h"

#include "vubi/sdl_utilities.h"
namespace vubi {
void Application::enable_log_messages() {}
void Application::run() { sdl_utilities::initialize_video(); }
}  // namespace vubi
