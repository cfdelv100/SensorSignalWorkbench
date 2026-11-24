#pragma once
#include <string>
using namespace std;

namespace ssaw::core::models{
    class SignalMetadata{
        public: 
            //default constructor
            SignalMetadata() = default;

            //parameterized constructor
            SignalMetadata(
                string signalName,
                string measurementUnit,
                double samplingFrequency,
                string sensorIdentifier,
                string description
            );

            //getters
            const string& getSignalName() const;
            const string& getMeasurementUnit() const;
            double getSamplingFrequency() const;
            const string& getSensorIdentifier() const;
            const string& getDescription() const;

        private:
            string signalName_;
            string measurementUnit_;
            double samplingFrequency_;
            string sensorIdentifier_;
            string description_;    
        };       
}