#pragma once
#include "SignalMetadata.hpp"
#include <cstddef>
#include <vector>

namespace ssaw::core:models{
    class SignalData{
        public:
            //constructor
            SignalData(SignalMetadata metadata, std::vector<double> measurements);

            //retrieve signal information
            const SignalMetadata& getMetadata() const;
            const std::vector<double>& getMeasurements() const;

            //signal properties
            std::size_t getSampleCount() const;
            bool isEmpty() const;
            double getDurationSeconds() const;

        private:
            SignalMetadata metadata_;
            std::vector<double> measurements_;

    };
}