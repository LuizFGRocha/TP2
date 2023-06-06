#include "time_measure.h"

std::chrono::_V2::system_clock::time_point time_measure_tempo_inicial;

void marca_inicio() {
    time_measure_tempo_inicial = std::chrono::high_resolution_clock::now();
}

double fim_da_medida() {
    return std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now()-time_measure_tempo_inicial).count();
}