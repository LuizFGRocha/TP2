#include "fecho_convexo.h"
#include "time_measure.h"
#include <getopt.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

struct excecao_erro_ao_abrir_arquivo{};

int main() {
    ifstream entrada("/home/luiz/estruturas_de_dados/TP2/entrada.txt");
    if (!entrada.is_open())
        throw excecao_erro_ao_abrir_arquivo{};

    vetor<ponto> vetor_de_pontos;

    string comando;
    while (getline(entrada, comando)) {
        stringstream sstream_entrada(comando);

        string coordenada_x, coordenada_y;

        sstream_entrada >> coordenada_x;
        sstream_entrada >> coordenada_y;

        vetor_de_pontos.push_back(ponto(stoi(coordenada_x), stoi(coordenada_y)));
    }

    fecho_convexo resultado;

    marca_inicio();
    resultado = varredura_de_graham(vetor_de_pontos, k_insertionsort);
    double tempo_insertion = fim_da_medida();
    resultado.imprime();

    marca_inicio();
    varredura_de_graham(vetor_de_pontos, k_mergesort);
    double tempo_merge = fim_da_medida();

    cout << "GRAHAM+MERGESORT: " << tempo_merge << endl;
    cout << "GRAHAM+INSERTIONSORT: " << tempo_insertion << endl;

    return 0;
}