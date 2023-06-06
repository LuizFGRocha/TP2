#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "lista.h"

TEST_CASE("push_back, push_front, pop_back, pop_front, vazia") {
    lista<int> teste;

    teste.push_back(1).push_back(2).push_back(3).push_back(4);

    CHECK(teste.pop_back() == 4);
    CHECK(teste.pop_back() == 3);
    CHECK(teste.pop_back() == 2);
    CHECK(teste.pop_back() == 1);

    teste.push_back(1).push_back(2).push_back(3).push_back(4);

    CHECK(teste.pop_front() == 1);
    CHECK(teste.pop_front() == 2);
    CHECK(teste.pop_front() == 3);
    CHECK(teste.pop_front() == 4);

    teste.push_front(4).push_front(3).push_front(2).push_front(1);

    CHECK(teste.pop_back() == 4);
    CHECK(teste.pop_back() == 3);
    CHECK(teste.pop_back() == 2);
    CHECK(teste.pop_back() == 1);

    teste.push_front(4).push_front(3).push_front(2).push_front(1);

    CHECK(teste.pop_front() == 1);
    CHECK(teste.pop_front() == 2);
    CHECK(teste.pop_front() == 3);
    CHECK(teste.pop_front() == 4);

    CHECK(teste.vazia());
}

TEST_CASE("operator[]") {
    lista<int> teste;

    for (int i = 0; i < 20; ++i) {
        teste.push_back(i);
    }

    auto correto = true;
    for (int i = 0; i < 20; ++i) {
        if (teste[i] != i) 
            correto = false;
    }

    CHECK(correto);

    correto = true;

    teste[10] = 40;

    correto = teste[10] == 40;

    CHECK(correto);

    teste[10] = 10;

    correto = true;
    for (int i = 0; i < 20; ++i) {
        if (teste.at(i) != i) 
            correto = false;
    }

    CHECK(correto);
}

TEST_CASE("operator=") {
    lista<int> teste1, teste2;

    teste1.push_front(4).push_front(3).push_front(2).push_front(1);

    teste2 = teste1;

    bool correto = true;

    for (int i = 0; i < teste1.tamanho(); ++i) {
        CHECK(teste1[i] == teste2[i]);
    }
}