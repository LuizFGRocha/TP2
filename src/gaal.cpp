#include "gaal.h"
#include <cmath>

ponto::ponto() : x_m(0), y_m(0) {}

ponto::ponto(int x, int y) : x_m(x), y_m(y) {}

int& ponto::coordenada_x() {
    return x_m;
}

int& ponto::coordenada_y() {
    return y_m;
}

double angulo(ponto p, ponto q) {
    if (p.coordenada_x() > q.coordenada_x()) { 
        return atan(
            (p.coordenada_y() - q.coordenada_y()) /
            (p.coordenada_x() - q.coordenada_x())
        ) + M_PI;
    } else {
        return atan(
            (p.coordenada_y() - q.coordenada_y()) /
            (p.coordenada_x() - q.coordenada_x())
        );
    }
}

bool nao_vira_para_a_esquerda(ponto p, ponto q) {
    if (angulo(p, q) < M_PI / 2)
        return true;

    else return false;
}