#include <gtest/gtest.h>

#include "fastlob/fix_parser.hpp"

TEST(Smoke, LibraryLinksAndRuns) {
    EXPECT_TRUE(fastlob::parser_ready());
}

