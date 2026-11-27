#include "SignalMetadata.hpp"
#include <utility>
#include <string>
#include <cmath>
#include <stdexcept>


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
        {
            if(signalName_.empty()){
                throw invalid_argument("Signal name cannot be empty.");
            }
            if(measurementUnit_.empty()){
                throw invalid_argument("Measurement unit cannnot be empty.");
            }
            if(!isfinite(samplingFrequency_) || samplingFrequency_ <= 0.0){
                throw invalid_argument("Sampling frequency must be a finite positive value.");
            }
        }


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