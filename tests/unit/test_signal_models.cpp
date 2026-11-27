#include <catch2/catch_test_macros.hpp>
#include "core/models/SignalMetadata.hpp"
#include "core/models/SignalData.hpp"
#include <vector>

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