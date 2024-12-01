#include "SignalGenerator/SignalGenerator.hpp"
#include "LowPassFilter/LowPassFilter.hpp"

int main() {

    uint64_t size = 100; // Numero di punti
    double frequency = 5; // Frequenza del segnale
    double amplitude = 1.0; // Ampiezza del segnale
    double noise_level = 0.5; // Livello di rumore

    SignalGenerator generator(size, frequency, amplitude, noise_level);
	std::cout<<"1";
    // Genera il segnale
    std::vector<double> signal = generator.generateSignal();
	std::cout<<"2";
    // Stampa il segnale originale
    generator.printSignal("Sinusoidal.txt", signal);

    return 0;
    
}
