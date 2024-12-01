#include <iostream>
#include <fstream>
#include <vector>
#include <cmath> // For sin() e cos()
#include <cstdlib> // For rand()
#include <ctime>   // For srand()

class SignalGenerator {

  private:
    uint64_t size = 0;
    double frequency = 0;
    double amplitude = 0;
    double noise_level = 0;

  public:
    SignalGenerator();
    ~SignalGenerator();
    SignalGenerator(uint64_t size, double frequency, double amplitude, double noise_level = 0);
    std::vector<double> generateSignal();
    void printSignal(const std::string& file_name, const std::vector<double>& signal);

};



/*
#include <iostream>
#include <vector>
#include <cmath> // Per sin() e cos()
#include <cstdlib> // Per rand()
#include <ctime>   // Per srand()

// Funzione per generare un segnale sinusoidale con rumore
std::vector<double> generateSignal(int size, double frequency, double amplitude, double noiseLevel) {
    std::vector<double> signal(size);
    std::srand(std::time(nullptr)); // Inizializza il generatore di numeri casuali
    for (int i = 0; i < size; ++i) {
        double t = static_cast<double>(i) / size; // Tempo normalizzato [0, 1]
        double noise = noiseLevel * ((std::rand() % 100) / 100.0 - 0.5); // Rumore casuale [-noiseLevel/2, +noiseLevel/2]
        signal[i] = amplitude * std::sin(2 * M_PI * frequency * t) + noise;
    }
    return signal;
}

// Funzione per stampare un segnale
void printSignal(const std::vector<double>& signal, const std::string& label) {
    std::cout << label << ":\n";
    for (const auto& value : signal) {
        std::cout << value << " ";
    }
    std::cout << "\n";
}

int main() {
    // Parametri del segnale
    int size = 100; // Numero di punti
    double frequency = 5; // Frequenza del segnale
    double amplitude = 1.0; // Ampiezza del segnale
    double noiseLevel = 0.5; // Livello di rumore

    // Genera il segnale
    std::vector<double> signal = generateSignal(size, frequency, amplitude, noiseLevel);

    // Stampa il segnale originale
    printSignal(signal, "Segnale originale");

    return 0;
}



*/
