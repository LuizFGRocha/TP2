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

ponto ponto::operator-(const ponto& rhs) {
    return ponto(x_m - rhs.x_m, y_m - rhs.y_m);
}

ponto ponto::operator+(const ponto& rhs) {
    return ponto(x_m + rhs.x_m, y_m + rhs.y_m);
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

double comprimento(ponto p, ponto q) {
    ponto vetor_diferenca = q - p;
    return (sqrt(pow(vetor_diferenca.coordenada_x(), 2) + 
                pow(vetor_diferenca.coordenada_y(), 2)));
}

bool gira_sentido_horario(ponto p, ponto q, ponto r) {
    int valor = (q.coordenada_y() - p.coordenada_y()) * (r.coordenada_x() - q.coordenada_x()) -
                (q.coordenada_x() - p.coordenada_x()) * (r.coordenada_y() - q.coordenada_y());

    if (valor == 0)
        return false;

    if (valor > 0)
        return true;

    else return false;
}