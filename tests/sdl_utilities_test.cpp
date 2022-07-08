#include "vubi/sdl_utilities.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <gtest/gtest.h>

class InitializedSDLFixture : public ::testing::Test {
   public:
    void SetUp() {
        sdl_initialized_ = vubi::sdl_utilities::initialize_video();
        ASSERT_TRUE(sdl_initialized_);
    }
    void TearDown() {
        if (sdl_initialized_) {
            SDL_Quit();
        }
    }

   private:
    bool sdl_initialized_;
};

TEST_F(InitializedSDLFixture, initialize_image) {
    GTEST_SKIP();
    bool success = vubi::sdl_utilities::initialize_image();
    if (success) {
        IMG_Quit();
    }
    ASSERT_TRUE(success);
}
