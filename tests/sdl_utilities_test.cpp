#include "vubi/sdl_utilities.h"

#include <SDL2/SDL.h>
#include <gtest/gtest.h>

class InitializedSDLFixture : public ::testing::Test {
   public:
    void SetUp() { ASSERT_TRUE(vubi::sdl_utilities::initialize_video()); }
    void TearDown() { SDL_Quit(); }
};

TEST_F(InitializedSDLFixture, initialize_image) {
    ASSERT_TRUE(vubi::sdl_utilities::initialize_image());
}