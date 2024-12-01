#include "LowPassFilter.hpp"

LowPassFilter::LowPassFilter(uint16_t window_size) {
	this->window_size = window_size;
}
void LowPassFilter::setWindowSize(uint16_t window_size) {
	this->window_size = window_size;
}
uint16_t LowPassFilter::getWindowSize() {
	return window_size;
}
std::vector<double> LowPassFilter::applyLowPassFilter(const std::vector<double>& signal) {
	std::vector<double> filtered_signal(signal.size(), 0.0);
	int32_t half_window = window_size / 2;
	
	for (std::size_t i = 0; i < signal.size(); ++i) {
        double sum = 0.0;
        int count = 0;

        // Sum of the values in the window
        for (int j = -half_window; j <= half_window; ++j) {
            if (i + j >= 0 && i + j < signal.size()) {
                sum += signal[i + j];
                count++;
            }
        }

        // Compute average
        filtered_signal[i] = sum / count;
    	}
	
	return filtered_signal;
}
