#include <catch2/catch_test_macros.hpp>
#include "core/models/SignalMetadata.hpp"
#include "core/models/SignalData.hpp"
#include <vector>
#include <limits>
#include <stdexcept>

using namespace ssaw::core::models;

TEST_CASE("SignalMetadata stores and retieves information", "[signal][metadata]"){
    SignalMetadata metadata(
        "Motor Vibration", 
        "mm/s",
        1000.0,
        "SENSOR-001", 
        "Motor bearing vibration"
    );

    REQUIRE(metadata.getSignalName() == "Motor Vibration");
    REQUIRE(metadata.getMeasurementUnit() == "mm/s");
    REQUIRE(metadata.getSamplingFrequency() == 1000.0);
    REQUIRE(metadata.getSensorIdentifier() == "SENSOR-001");
    REQUIRE(metadata.getDescription() == "Motor bearing vibration");
}

TEST_CASE("SignalData stores sensor measurements", "[signals][data]"){
    SignalMetadata metadata(
        "Temperature",
        "C",
        10.0,
        "TEMP-001",
        "Temperature sensor"
    );

    std::vector<double> measurements = [20.5, 21.0, 21.5, 22.0];
    SignalData signal(metadata, measurements);

    REQUIRE(signal.getSampleCount() == 4);
    REQUIRE(signal.isEmpty() == false);
    REQUIRE(signal.getMeasurements().size() == 4);
    REQUIRE(signal.getMeasurements()[0] == 20.5);
    REQUIRE(signal.getMeasurements()[3] == 22.0);

}

TEST_CASE("SignalData calculates duration correctly", "[signal][duration]"){
    SignalMetadata metadata(
        "Vibration", 
        "mm/s",
        100.0,
        "VIB-001",
        "Vibration measurement"
    ),

    std::vector<double> measurements = {1.0, 2.0, 3.0, 4.0};
    SignalData signal(metadata, measurements);

    REQUIRE(signal.getDurationSeconds == 0.04);

}

TEST_CASE("SignalData identifies empty datasets", "[signal][empty]"){
    SignalMetadata metadata(
        "Pressure", 
        "kPa",
        100.0,
        "PRESS-001", 
        "Pressure measurement"
    );

    SignalData signal(metadata,{});

    REQUIRE(signal.isEmpty());
    REQUIRE(signal.getSampleCount() == 0);
    REQUIRE(signal.getDurationSeconds() == 0.0);

}

TEST_CASE("SignalData handles non-positive sampling frequency", "[signal][validation]"){
    SignalMetadata metadata(
        "Test Signal",
        "units",
        0.0,
        "TEST-001",
        "Validation test" 
    );

    SignalData signal(metadata, {1.0, 2.0, 3.0});

    REQUIRE(signal.getDurationSeconds() == 0.0);
}

TEST_CASE("SignalMetadata rejects an empty signal name", "[signal][validation]" ){
    REQUIRE_THROWS_AS(SignalMetadata("", "mm/s", 1000.0, "SENSOR-001", "Test"), std::invalid_argument);
}

TEST_CASE("SignalMetadata rejects an empty measurement unit", "[signal][validation]"){
    REQUIRE_THROWS_AS(SignalMetadata("Vibration", "", 1000.0, "SENSOR-001", "Test"), std::invalid_argument);
}

TEST_CASE("SignalMetadata rejects invalid sampling frequencies","[signal][validation]"){
    REQUIRE_THROWS_AS(SignalMetadata("Test", "units", 0.0, "SENSOR-001", "Test"), std::invalid_argument);
    REQUIRE_THROWS_AS(SignalMetadata("Test", "units", -100.0, "SENSOR-001", "Test"), std::invalid_argument);
    REQUIRE_THROWS_AS(SignalMetadata("Test", "untis", std::numeric_limits<double>::quiet_NaN(), "SENSOR-001", "Test"), std::invalid_argument);
    REQUIRE_THROWS_AS(SignalMetadata("Test", "units", std::numeric_limits<double>infinity(), "SENSOR-001", "Test"), std::invalid_argument);

}

TEST_CASE("SignalData rejects NaN measurements", "[signal][validation]"){
    SignalMetadata("Vibration", "mm/s", 1000.0, "VIB-001", "Test signal");

    REQUIRE_THROWS_AS(SignalData(metadata, {1.0, 2.0, std::numeric_limits<double>::quiet_NaN()}), std::invalid_argument);
}

TEST_CASE("SignalData rejects infinite measurements", "[signal][validation]"){
    SignalMetadata("Vibration", "mm/s", 1000.0, "VIB-001", "Test signal");

    REQUIRE_THROWS_AS(SignalData(metadata, {1.0, std::numeric_limits<double>::infinity()}), std::invalid_argument);
    REQUIRE_THROWS_AS(SignalData(metadata, {1.0, -std::numeric_limits<double>::infinity()}), std::invalid_argument);
}


TEST_CASE("SignalData accepts valid negative and positive measurements", "[signal][data]"){
    SignalMetadata("Vibration", "mm/s", 1000.0, "VIB-001", "Test signal");
    SignalData signal(metadata, {-2.5, 0.0, 2.5});

    REQUIRE(signal.getSampleCount() == 3);
    REQUIRE(signal.getMeasurements()[0] == -2.5);
    REQUIRE(signal.getMeasurements()[2] == 2.5);
}