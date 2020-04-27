#include <gtest/gtest.h>
#include <machine/video/videodriver.h>

TEST(VideoDriver, execution) {
    RAM memory;
    VideoDriver vd(&memory);

    vd.Draw();
}
