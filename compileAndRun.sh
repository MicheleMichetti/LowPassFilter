cd build/
echo +++ Build SignalGenerator +++
g++ -c ../SignalGenerator/SignalGenerator.cpp
echo +++ Build LowPassFilter +++
g++ -c ../LowPassFilter/LowPassFilter.cpp
echo +++ Build main +++
cd ..
g++ -o LowPassFilter.out main.cpp build/LowPassFilter.o build/SignalGenerator.o

echo +++ Run LowPassFilter.out +++
./LowPassFilter.out
