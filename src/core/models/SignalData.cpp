#include "SignalData.hpp"

#include <utility>

namespace ssaw::core::models{
    SignalData::SignalData(SignalMetadata metadata, std::vector<double> measurements)
        : metadata_(std::move(metadata)), measurements_(std::move(measurements))
    {}

    const SignalMetadata& SignalData::getMetadata() const{
        return metadata_;
    }
    const std::vector<double>& SignalData::getMeasurements() const{
        return measurements_;
    }
    std::size_t SignalData::getSampleCount() const{
        return measurements_.size();
    }
    bool SignalData::isEmpty() const{
        return measurements_.empty();
    }
    double SignalData::getDurationSeconds() const{
        const double samplingFrequency = metadata_.getSamplingFrequency();
        
        if(samplingFrequency <= 0.0 || measurements_.empty()){
            return 0.0;
        }

        return static_cast<double>(measurements_.size()) / samplingFrequency;
        
    }


}