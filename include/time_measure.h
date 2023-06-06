#ifndef TIME_MEASURE_H
#define TIME_MEASURE_H

#include <chrono>

extern std::chrono::_V2::system_clock::time_point time_measure_tempo_inicial;

void marca_inicio();

double fim_da_medida();

#endif // TIME_MEASURE_H