#include "vetor.h"
#include "pilha.h"
#include "gaal.h"
#include "par.h"
#include "sorting.h"
#include <iostream>
#include <cmath>
#include <iostream>

#define k_mergesort 0
#define k_insertionsort 1
#define k_bucketsort 2

struct excecao_metodo_de_ordenacao_invaido{};

class fecho_convexo {

  public:

    fecho_convexo() : pilha_m() {}

    fecho_convexo(pilha<ponto>& pilha) {
        pilha_m = pilha;
    }

    void imprime_e_apaga() {
        while (!pilha_m.vazia()) {
            ponto atual = pilha_m.desempilha();
            std::cout << "(" << atual.coordenada_x() << ", " << atual.coordenada_y() << ")" << std::endl;
        }
    }

    void imprime_e_apaga() {
        while (!pilha_m.vazia()) {
            ponto atual = pilha_m.desempilha();
            std::cout << "(" << atual.coordenada_x() << ", " << atual.coordenada_y() << ")" << std::endl;
        }
    }

  private:
    pilha<ponto> pilha_m;
};

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
        if (Q[i].coordenada_y() < menor.coordenada_y()) {
            menor = Q[i];
            posicao_menor = i;
        }
    }

    Q.remove(posicao_menor);

    return menor;
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

fecho_convexo varredura_de_graham(vetor<ponto> Q, int metodo_de_ordenacao) {

    // Passo 1 do pseudocódigo
    ponto p0 = extrai_y_minima(Q); // p0 é identificado e removido de Q

    // Passo 2 do pseudocódigo
    vetor<par<ponto, double>> vetor_ponto_angulo; // Vetor de pares ponto-ângulo
    for (int i = 0; i < Q.size(); ++i)
        vetor_ponto_angulo.push_back(par<ponto, double>(Q[i], angulo(Q[i], p0)));

    switch (metodo_de_ordenacao) {
        case k_mergesort:
            mergesort(vetor_ponto_angulo);
            break;
        case k_insertionsort:
            insertionsort(vetor_ponto_angulo);
            break;
        /* case k_bucketsort:
            bucketsort(vetor_ponto_angulo);
            break; */
        default:
            throw excecao_metodo_de_ordenacao_invaido{};
    }

    std::cout << "(" << p0.coordenada_x() << ", " << p0.coordenada_y() << ")" << std::endl;
    for (int i = 0; i < vetor_ponto_angulo.size(); ++i)
        std::cout << "(" << vetor_ponto_angulo[i].primeiro().coordenada_x() << ", " << vetor_ponto_angulo[i].primeiro().coordenada_y() << ") " << vetor_ponto_angulo[i].segundo() << std::endl;

    // Passo 3 do pseudocódigo
    pilha<ponto> S;

    // Passo 4 do pseudocódigo
    S.empilha(p0);
    std::cout << "Primeiro ponto adicionado: ";
    p0.imprime_ponto();

    // Passo 5 do pseudocódigo
    S.empilha(vetor_ponto_angulo[0].primeiro());

    // Passo 6 do pseudocódigo
    if (vetor_ponto_angulo.size() >= 3)
        S.empilha(vetor_ponto_angulo[1].primeiro());

    // Passo 7 do pseudocódigo
    for (int i = 2; i < vetor_ponto_angulo.size(); ++i) {

        // Passo 8 do pseudocódigo
        while (gira_sentido_horario(S.espia_segundo(), S.espia_segundo(), vetor_ponto_angulo[i].primeiro())) {
            
            // Passo 9 do psedocódigo
            ponto p = S.desempilha();
            std::cout << "Ponto removido: ";
            p.imprime_ponto();
        }

        // Passo 10 do pseudocódigo
        S.empilha(vetor_ponto_angulo[i].primeiro());
        std::cout << "Ponto adicionado: ";
        vetor_ponto_angulo[i].primeiro().imprime_ponto();
    }

    // Passo 11 do pseudocódigo
    return S;
}
