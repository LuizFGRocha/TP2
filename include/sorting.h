#include "vetor.h"

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

/// @todo
template <typename T>
vetor<T> mergesort(vetor<T> vetor_entrada, int esq = 0, int dir = -1) {
    
    if (dir == -1)
        dir = vetor_entrada.size();
    
    if (esq < dir) {
        int meio = (esq + dir) / 2;
        mergesort(vetor_entrada, esq, meio);
        mergesort(vetor_entrada, meio + 1, dir);

        vetor<T> temp;
        int i = esq, j = meio;
        while (i < meio && j < dir) {
            if (vetor_entrada[i] <= vetor_entrada[j]) {
                temp.push_back(vetor_entrada[i]);
                i++;
            } else {
                temp.push_back(vetor_entrada[j]);
                j++;
            }
        }

        for (; i < meio; ++i) {
            temp.push_back(vetor_entrada[i]);
        }

        for (; j < dir; ++j) {
            temp.push_back(vetor_entrada[j]);
        }

        vetor_entrada = temp;

    }

    return vetor_entrada;
}

template<typename T>
vetor<T> linearsort(vetor<T> vetor_entrada);