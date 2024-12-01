#include <stdint.h>
#include <vector>

class LowPassFilter {

    private:
	uint16_t window_size;

    public:
	LowPassFilter(uint16_t window_size);
	void setWindowSize(uint16_t window_size);
	uint16_t getWindowSize();
	std::vector<double> applyLowPassFilter(const std::vector<double>& signal);

};

/*

// Funzione per applicare un filtro passa-basso (media mobile)
std::vector<double> applyLowPassFilter(const std::vector<double>& signal, int windowSize) {
    std::vector<double> filteredSignal(signal.size(), 0.0);
    int halfWindow = windowSize / 2;

    for (size_t i = 0; i < signal.size(); ++i) {
        double sum = 0.0;
        int count = 0;

        // Somma i valori nella finestra
        for (int j = -halfWindow; j <= halfWindow; ++j) {
            if (i + j >= 0 && i + j < signal.size()) {
                sum += signal[i + j];
                count++;
            }
        }

        // Calcola la media
        filteredSignal[i] = sum / count;
    }

    return filteredSignal;
}

*/
