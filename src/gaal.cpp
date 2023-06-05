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

void ponto::imprime_ponto() {
    std::cout << "(" << x_m << ", " << y_m << ")" << std::endl;
}

double angulo(ponto p, ponto q) {

    double dx = p.coordenada_x() - q.coordenada_x();
    double dy = p.coordenada_y() - q.coordenada_y();

    if (dx > 0) { 
        return atan(dy / dx) + M_PI;

    } else if (dx == 0) {
        if (dy == 0)
            throw excecao_pontos_iguais{};

        return (p.coordenada_y() < q.coordenada_y()) ? M_PI / 2 : 3 * M_PI / 2; // O caso em que os ponto são colineares com o eixo y

    } else {
        return atan(dy / dx);
    }
}

/// @todo Consertar
bool nao_vira_para_a_esquerda(ponto p, ponto q, ponto r) {
    try {
        double q_p = angulo(q, p);
        double q_r = angulo(q, r);
        double dif = q_p - q_r;
        if (q_p - q_r > M_PI)
            return true;
    } catch (excecao_pontos_iguais& e) {
            return true;
    }

    return false;
}