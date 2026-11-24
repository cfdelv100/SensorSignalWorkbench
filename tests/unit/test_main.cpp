#include <catch2/catch_test_macros.hpp>

TEST_CASE("Application Verification", "[application]"){
    REQUIRE(2+2 == 4);
}

TEST_CASE("Signal samples values can be compared","[signal]"){
    const double sampleA = 10.5;
    const double sampleB = 10.5;

    REQUIRE(sampleA == sampleB);
}