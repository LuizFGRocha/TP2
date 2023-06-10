#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"

#include "../include/sorting.h"
#include <time.h>
#include <cstdlib>
#include <iostream>

TEST_CASE("Merge sort") {
    srand(time(NULL));

    vetor<int> teste;
    for (int i = 0; i < 50000; ++i)
        teste.push_back(rand());

    mergesort(teste);

    bool verificacao = true;

    for (int i = 1; i < teste.size(); ++i) {
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
    for (int i = 0; i < 50000; ++i)
        teste.push_back(rand());

    insertionsort(teste);

    bool verificacao = true;

    for (int i = 1; i < teste.size(); ++i) {
        if (teste[i] < teste[i-1]) {
            verificacao = false;
            break;
        }
    }

    CHECK(verificacao);
}

TEST_CASE("Counting sort") {
    srand(time(NULL));

    vetor<int> teste;
    for (int i = 0; i < 50000; ++i)
        teste.push_back(rand() % 10000);

    countingsort(teste);

    bool verificacao = true;

    for (int i = 1; i < teste.size(); ++i) {
        if (teste[i] < teste[i-1]) {
            verificacao = false;
            break;
        }
    }

    CHECK(verificacao);
}

TEST_CASE("Bucket sort") {
    srand(time(NULL));

    vetor<par<ponto,double>> teste;
    for (int i = 0; i < 50000; ++i)
        teste.push_back(par<ponto, double>(ponto(0, 0), (double) rand() / RAND_MAX));

    bucketsort(teste);

    bool verificacao = true;

    for (int i = 1; i < teste.size(); ++i) {
        if (teste[i] < teste[i-1]) {
            verificacao = false;
            break;
        }
    }

    CHECK(verificacao);
}