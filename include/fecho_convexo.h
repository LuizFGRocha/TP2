#include "vetor.h"
#include "pilha.h"
#include "gaal.h"
#include "par.h"
#include "sorting.h"
#include <cmath>

#define k_mergesort 0
#define k_insertionsort 1
#define k_linearsort 2

struct excecao_metodo_de_ordenacao_invaido{};

class fecho_convexo {
    vetor<reta> retas_m;
};

fecho_convexo varredura_de_graham(vetor<ponto> Q, int metodo_de_ordenacao) {
    pilha<ponto> S;

    ponto p0 = extrai_y_minima(Q); // p0 é identificado e removido de Q

    vetor<par<ponto, double>> vetor_ponto_angulo; // Vetor de pares ponto-ângulo
    for (int i = 0; i < Q.size(); ++i)
        vetor_ponto_angulo.push_back(par<ponto, double>(Q[i], angulo(p0, Q[i])));

    switch (metodo_de_ordenacao) {
        case 0:
            mergesort(vetor_ponto_angulo);
            break;
        case 1:
            insertionsort(vetor_ponto_angulo);
            break;
        case 2:
            linearsort(vetor_ponto_angulo);
            break;
        default:
            throw excecao_metodo_de_ordenacao_invaido{};
    }
}

/// @brief Encontra o ponto com a menor coordenada y e remove esse
/// ponto do vetor.
/// @param Q Vetor de pontos no qual a menor coordenada y será procurada.
/// @return Retorna o ponto com a menor coordenada y.
ponto extrai_y_minima(vetor<ponto>& Q) {
    if (Q.empty())
        throw excecao_vetor_vazio{};

    ponto menor = Q[0];
    int posicao_menor = 0;
    for (int i = 1; i < Q.size(); ++i) {
        if (Q[i].coordenada_y() < menor.coordenada_y())
            menor = Q[i];
            posicao_menor = i;
    }

    Q.remove(posicao_menor);

    return menor;
}
