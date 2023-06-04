#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"

#include "sorting.h"
#include <time.h>
#include <cstdlib>
#include <iostream>

TEST_CASE("Merge sort") {
    srand(time(NULL));

    vetor<int> teste;
    for (int i = 0; i < 20; ++i)
        teste.push_back(rand());

    teste = mergesort(teste);

    bool verificacao = true;

    std::cerr << teste[0] << " ";
    for (int i = 1; i < teste.size(); ++i) {
        std::cerr << teste[i] << " ";
        if (teste[i] < teste[i-1]) {
            verificacao = false;
            break;
        }
    }

    CHECK(verificacao);
}

TEST_CASE("Insertion sort") {
    srand(time(NULL));

    vetor<int> teste;
    for (int i = 0; i < 20; ++i)
        teste.push_back(rand());

    teste = insertionsort(teste);

    bool verificacao = true;

    std::cerr << teste[0] << " ";
    for (int i = 1; i < teste.size(); ++i) {
        std::cerr << teste[i] << " ";
        if (teste[i] < teste[i-1]) {
            verificacao = false;
            break;
        }
    }

    CHECK(verificacao);
}