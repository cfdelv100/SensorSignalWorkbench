#include "SignalData.hpp"

#include <utility>
using namespace std;

namespace ssaw::core::models{
    SignalData::SignalData(SignalMetadata metadata, vector<double> measurements)
    : metadata_(move(metadata)), measurements_(move(measurements))
    {

    }

    const SignalMetadata& SignalData::getMetadata() const{
        return metadata_;
    }
    const vector<double>& SignalData::getMeasurements() const{
        return measurements_;
    }
    size_t SignalData::getSampleCount() const{
        return measurements_.size();
    }
    bool SignalData::isEmpty() const{
        return measurements_,empty();
    }
    double SignalData::getDurationSeconds() const{
        const double samplingFrequency = metadata_.getSamplingFrequency();
        
        if(samplingFrequency <= 0.0 || measurements_.empty()){
            return 0.0;
        }

        return static_cast<double>(measurements_.size()) / samplingFrequency;
        
    }


}