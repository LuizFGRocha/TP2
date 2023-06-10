#ifndef FECHO_CONVEXO_H
#define FECHO_CONVEXO_H

#include "vetor.h"
#include "gaal.h"
#include "par.h"
#include <iostream>
#include <cmath>

#define k_mergesort 0
#define k_insertionsort 1
#define k_bucketsort 2

struct excecao_metodo_de_ordenacao_invaido{};

/// @brief Representa um fecho convexo
class fecho_convexo {

  public:

    fecho_convexo() : vetor_m() {}

    /// @brief Cria o fecho a partir de um vetor de pontos
    fecho_convexo(vetor<ponto>& vetor);

    /// @brief Imprime o fecho na tela
    void imprime();

  private:
    /// @brief Vetor com os pontos no fecho
    vetor<ponto> vetor_m;
};

/// @brief Encontra o ponto com a menor coordenada y e remove esse
/// ponto do vetor.
/// @param Q Vetor de pontos no qual a menor coordenada y será procurada.
/// @return Retorna o ponto com a menor coordenada y.
ponto extrai_y_minima(vetor<ponto>& Q);

/// @brief Encontra e retorna o ponto com a menor coordenada X
/// @param Q O vetor de pontos em que esse ponto será encontrado
ponto x_minima(vetor<ponto>& Q);

/// @brief Usa a varredura de graham para encontrar o fecho convexo de um vetor de pontos. Implementação
/// do pseudocódigo do Cormen.
/// @param Q O vetor de pontos
/// @param metodo_de_ordenacao Opção de método de ordenação (k_mergesort, k_insertionsort, k_bucketsort)
/// @return Retorna um objeto fecho convexo com os pontos que montam o fecho
fecho_convexo varredura_de_graham(vetor<ponto> Q, int metodo_de_ordenacao);


/// @brief Usa a marcha de Jarvis para achar o fecho convexo de um vetor de pontos.
/// @param Q O vetor de pontos
/// @return Retorna um objeto fecho convexo com os pontos que montam o fecho
fecho_convexo marcha_de_jarvis(vetor<ponto> Q);

#endif // FECHO_CONVEXO_H