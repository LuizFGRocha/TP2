#ifndef SORTING_H
#define SORTING_H

#include "vetor.h"
#include "gaal.h"
#include "par.h"

/// @brief Ordena o vetor para que os itens fiquem na ordem
/// crescente.
/// @tparam T O tipo do elemento do vetor
/// @param vetor_entrada O vetor a ser ordenado
template <typename T>
vetor<T> insertionsort(vetor<T>& vetor_entrada) {
    T aux;
    int i, j;

    for(i = 1; i < vetor_entrada.size(); ++i) {

        aux = vetor_entrada[i];
        j = i - 1;

        while(j >= 0 && aux < vetor_entrada[j]) {

            vetor_entrada[j + 1] = vetor_entrada[j];
            j--;

        }
        vetor_entrada[j + 1] = aux;
    }

    return vetor_entrada;
}

template <typename T>
void mergesort(vetor<T>& vetor_entrada, int esq = 0, int dir = -1) {
    
    if (dir == -1)
        dir = vetor_entrada.size() - 1;
    
    if (esq < dir) {
        int meio = (esq + dir) / 2;
        mergesort(vetor_entrada, esq, meio);
        mergesort(vetor_entrada, meio + 1, dir);

        merge(vetor_entrada, esq, meio, dir);
    }

}

template <typename T>
void merge(vetor<T>& vetor_entrada, int esq, int meio, int dir) {
    vetor<T> resultado;
    resultado.set_capacity(dir - esq + 1);
    int i = esq, j = meio + 1;
    while (i <= meio && j <= dir) {
        if (vetor_entrada[i] < vetor_entrada[j]) {
            resultado.push_back(vetor_entrada[i]);
            i++;
        } else {
            resultado.push_back(vetor_entrada[j]);
            j++;
        }
    }

    if (resultado.size() < vetor_entrada.size()) {
        for (; i <= meio; ++i) {
            resultado.push_back(vetor_entrada[i]);
        }

        for (; j <= dir; ++j) {
            resultado.push_back(vetor_entrada[j]);
        }
    
    }

    for (int i = 0; i < resultado.size(); ++i)
        vetor_entrada[esq++] = resultado[i];
}

/// @brief Algoritmo de ordenação linear inplace. Assume vetor
/// de inteiros não negativos.
/// @param vetor_entrada O vetor a ser ordenado.
vetor<int> countingsort(vetor<int>& vetor_entrada) {
    if (vetor_entrada.size() == 1) return vetor_entrada;

    int limite_superior = vetor_entrada[0];
    for (int i = 1; i < vetor_entrada.size(); ++i)
        if (vetor_entrada[i] > limite_superior)
            limite_superior = vetor_entrada[i];

    vetor<int> vetor_contagem(limite_superior + 1, 0);

    for (int i = 0; i < vetor_entrada.size(); ++i)
        vetor_contagem[vetor_entrada[i]]++;

    vetor_entrada.clean();

    for (int i = 0; i < vetor_contagem.size(); ++i)
        while (vetor_contagem[i] > 0) {
            vetor_entrada.push_back(i);
            vetor_contagem[i]--;
        }

    return vetor_entrada;
}

vetor<par<ponto, double>> bucketsort(vetor<par<ponto, double>>& vetor_entrada, int n_baldes = -1) {
    if (vetor_entrada.size() == 1) return vetor_entrada;

    if (n_baldes < 0)
        n_baldes = vetor_entrada.size() / 10;

    if (n_baldes == 0)
        n_baldes++;

    vetor<vetor<par<ponto, double>>> vetor_de_baldes(n_baldes, vetor<par<ponto, double>>());

    double limite_superior = vetor_entrada[0].segundo();
    double limite_inferior = vetor_entrada[0].segundo();
    for (int i = 1; i < vetor_entrada.size(); ++i) {
        if (vetor_entrada[i].segundo() > limite_superior)
            limite_superior = vetor_entrada[i].segundo();
        else if (vetor_entrada[i].segundo() < limite_inferior)
            limite_inferior = vetor_entrada[i].segundo();
    }

    if (limite_superior == limite_inferior) return vetor_entrada; // Evita a divisão por 0. Se o limite superior for igual ao
                                                                  // inferior, todos os elementos são iguais.

    double range = (limite_superior - limite_inferior) / n_baldes;
    
    for (int i = 0; i < vetor_entrada.size(); ++i) {
        int posicao_de_insercao = (vetor_entrada[i].segundo() - limite_inferior) / range;
        if (posicao_de_insercao == n_baldes)
            posicao_de_insercao--;

        vetor_de_baldes[posicao_de_insercao].push_back(vetor_entrada[i]);
    }

    for (int i = 0; i < vetor_de_baldes.size(); ++i)
        insertionsort(vetor_de_baldes[i]);

    int capacidade = vetor_entrada.capacity();
    vetor_entrada.clean();
    vetor_entrada.set_capacity(capacidade);

    for (int i = 0; i < vetor_de_baldes.size(); ++i)
        for (int j = 0; j < vetor_de_baldes[i].size(); j++)
            vetor_entrada.push_back(vetor_de_baldes[i][j]);

    return vetor_entrada;
}

#endif // SORTING_H