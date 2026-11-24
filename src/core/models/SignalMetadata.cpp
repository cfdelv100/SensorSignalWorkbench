#include "SignalMetadata.hpp"
#include <utility>
#include <string>

using namespace std;


namespace ssaw::core::models{

    SignalMetadata::SignalMetadata(
        string signalName,
        string measurementUnit,
        double samplingFrequency,
        string sensorIdentifier,
        string description
    )   
        : signalName_(move(signalName)),
          measurementUnit_(move(measurementUnit)),
          samplingFrequency_(samplingFrequency),
          sensorIdentifier_(move(sensorIdentifier)),
          description_(move(description))
        {}


    const string& SignalMetadata::getSignalName() const{
        return signalName_;
    }

    const string& SignalMetadata::getMeasurementUnit() const{
        return measurementUnit_;
    }

    double SignalMetadata::getSamplingFrequency() const{
        return samplingFrequency_;
    }

    const string& SignalMetadata::getSensorIdentifier() const{
        return sensorIdentifier_;
    }

    const string& SignalMetadata::getDescription() const{
        return description_;
    }
}