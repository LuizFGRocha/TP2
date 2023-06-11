#include "fecho_convexo.h"
#include "time_measure.h"
#include <getopt.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct excecao_erro_ao_abrir_arquivo{};

struct excecao_erro_ao_ler_argumentos{};

struct args {
    string arquivo_entrada;

    bool f_experimento;
    int tamanho_experimento;
    string arquivo_saida_experimento; 
    bool salvar;
};

void parse_args(args& argumentos, int argc, char** argv) {
    int c;
    bool f_tam = false, f_ent = false, f_sai = false;

    argumentos.f_experimento = false;
    argumentos.tamanho_experimento = 0;
    argumentos.salvar = false;

    while ((c = getopt(argc, argv, "p:xt:o:i")) != EOF) {
        switch (c) {
            case 'p':
                argumentos.arquivo_entrada = optarg;
                f_ent = true;
                break;
            case 'x':
                argumentos.f_experimento = true;
                break;
            case 't':
                argumentos.tamanho_experimento = stoi(optarg);
                f_tam = true;
                break;
            case 'o':
                argumentos.arquivo_saida_experimento = optarg;
                f_sai = true;
                break;
            case 'i':
                argumentos.salvar = true;
            case '?':
                cerr << "Erro ao ler os argumentos." << endl;
                throw excecao_erro_ao_ler_argumentos{};
                exit(1);
            default:
                abort();
        }
    }

    if (argumentos.f_experimento && !f_tam)
        argumentos.tamanho_experimento = 100;

    if (argumentos.f_experimento && !f_sai)
        argumentos.arquivo_saida_experimento = "./resultado_experimento.csv";

    if (!f_ent)
        argumentos.arquivo_entrada = "/home/luiz/estruturas_de_dados/TP2/entrada.txt";
}

void gera_vetor_aleatorio(vetor<ponto>& vetor_entrada, int tamanho) {
    srand(time(NULL));
    
    vetor_entrada.clean();
    for (int i = 0; i < tamanho; ++i) {
        vetor_entrada.push_back(ponto(rand(), rand()));
    }
} 

void le_de_arquivo_para_vetor(string arquivo, vetor<ponto>& vetor_entrada) {
    ifstream entrada(arquivo);
    if (!entrada.is_open())
        throw excecao_erro_ao_abrir_arquivo{};

    string comando;
    while (getline(entrada, comando)) {
        if (comando == "" || comando == "\n" )
            continue;

        stringstream sstream_entrada(comando);

        string coordenada_x, coordenada_y;

        sstream_entrada >> coordenada_x;
        sstream_entrada >> coordenada_y;

        vetor_entrada.push_back(ponto(stoi(coordenada_x), stoi(coordenada_y)));
    }
}

int main(int argc, char** argv) {

    args argumentos;
    parse_args(argumentos, argc, argv);

    vetor<ponto> vetor_de_pontos;

    if (argumentos.f_experimento || argumentos.tamanho_experimento > 0) {
        if (argumentos.tamanho_experimento > 0) {
            vetor_de_pontos.set_capacity(argumentos.tamanho_experimento);
            gera_vetor_aleatorio(vetor_de_pontos, argumentos.tamanho_experimento);

            if (argumentos.salvar) {
                ofstream vetor_aleatorio("./vetor_utilizado.txt");
                for (int i = 0; i < vetor_de_pontos.size(); ++i) 
                    vetor_aleatorio << vetor_de_pontos[i].coordenada_x() << " " << vetor_de_pontos[i].coordenada_y() << std::endl; 
            }
        }
        else 
            le_de_arquivo_para_vetor(argumentos.arquivo_entrada, vetor_de_pontos);
    } else 
        le_de_arquivo_para_vetor(argumentos.arquivo_entrada, vetor_de_pontos);

    fecho_convexo resultado_jarvis, resultado_graham_merge, resultado_graham_insertion, resultado_graham_bucket;

    marca_inicio();
    resultado_jarvis = marchar_de_jarvis(vetor_de_pontos);
    double tempo_jarvis = fim_da_medida();

    marca_inicio();
    resultado_graham_insertion = varredura_de_graham(vetor_de_pontos, k_insertionsort);
    double tempo_insertion = fim_da_medida();

    marca_inicio();
    resultado_graham_merge = varredura_de_graham(vetor_de_pontos, k_mergesort);
    double tempo_merge = fim_da_medida();

    marca_inicio();
    resultado_graham_bucket = varredura_de_graham(vetor_de_pontos, k_bucketsort);
    double tempo_bucket = fim_da_medida();

    if (!argumentos.f_experimento) {
        resultado_graham_bucket.imprime();

        cout << setprecision(3) << fixed;

        cout << "GRAHAM+MERGESORT: " << tempo_merge / 1000 << "s" << endl;
        cout << "GRAHAM+INSERTIONSORT: " << tempo_insertion / 1000 << "s" << endl;
        cout << "GRAHAM+LINEAR: " << tempo_bucket / 1000 << "s" << endl;
        cout << "JARVIS: " << tempo_jarvis / 1000 << "s" << endl;
    } else {
        ofstream saida(argumentos.arquivo_saida_experimento, ios_base::app);

        saida << argumentos.tamanho_experimento << ',' << tempo_merge << ',' << tempo_insertion
              << ',' << tempo_bucket << ',' << tempo_jarvis << endl;
    }

    return 0;
}