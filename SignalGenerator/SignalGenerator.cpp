#include"SignalGenerator.hpp"

SignalGenerator::SignalGenerator() {
    this->size = 0;
    this->frequency = 0;
    this->amplitude = 0;
    this->noise_level = 0;
}

SignalGenerator::~SignalGenerator() {}

SignalGenerator::SignalGenerator(uint64_t size, double frequency, double amplitude, double noise_level) {

    this->size = size;
    this->frequency = frequency;
    this->amplitude = amplitude;
    this->noise_level = noise_level;
    
}

std::vector<double> SignalGenerator::generateSignal() {
    std::vector<double> signal(this->size);
    std::srand(std::time(nullptr)); // Initialize random number generator
    
    for(uint64_t sample = 0; sample < this->size; ++sample) {
        double time = static_cast<double>(sample) / this->size; //Normalized time
        double noise = this->noise_level * ((std::rand() % 100) / 100.0 - 0.5); //Simulated noise [-noise_level/2, +noise_level/2]
        signal[sample] = this->amplitude * std::sin(2 * M_PI * this->frequency * time) + noise;
    }
    
    return signal;
}

void SignalGenerator::printSignal(const std::string& file_name, const std::vector<double>& signal) {

    std::ofstream output_stream(file_name, std::fstream::out);
    if(!output_stream.is_open()) {
    	std::cerr<<"File "<<file_name<<" could not be open"<<std::endl;
    	return;
    }
    for(uint64_t sample = 0; sample<size; ++sample) {
        output_stream << signal[sample] << " ";
    }
    output_stream <<"\n";
    return;
}


