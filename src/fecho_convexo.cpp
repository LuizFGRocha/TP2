#include "fecho_convexo.h"
#include "sorting.h"

fecho_convexo::fecho_convexo(vetor<ponto>& vetor) {
    vetor_m = varredura_de_graham(vetor, k_bucketsort);
}

fecho_convexo& fecho_convexo::operator=(vetor<ponto> vetor_pontos) {
    vetor_m = vetor_pontos;
    return *this;
}

void fecho_convexo::imprime() {
    for (int i = 0; i < vetor_m.size(); i++)
        std::cout << vetor_m[i].coordenada_x() << " "
                  << vetor_m[i].coordenada_y() << std::endl;
}

ponto extrai_y_minima(vetor<ponto>& Q) {
    if (Q.empty())
        throw excecao_vetor_vazio{};

    ponto menor = Q[0];
    int posicao_menor = 0;
    for (int i = 1; i < Q.size(); ++i) {

        if (Q[i].coordenada_y() < menor.coordenada_y()) {
            menor = Q[i];
            posicao_menor = i;

        } else if (Q[i].coordenada_y() == menor.coordenada_y()) {

            if (Q[i].coordenada_x() < menor.coordenada_x())
                menor = Q[i];
                posicao_menor = i;
        }
    }

    Q.remove(posicao_menor);

    return menor;
}

ponto x_minima(vetor<ponto>& Q) {
    if (Q.empty())
        throw excecao_vetor_vazio{};

    ponto menor = Q[0];
    int posicao_menor = 0;
    for (int i = 1; i < Q.size(); ++i) {

        if (Q[i].coordenada_x() < menor.coordenada_x()) {
            menor = Q[i];
            posicao_menor = i;

        } else if (Q[i].coordenada_x() == menor.coordenada_x()) {

            if (Q[i].coordenada_y() < menor.coordenada_y())
                menor = Q[i];
                posicao_menor = i;
        }
    }

    return menor;
}

vetor<ponto> varredura_de_graham(vetor<ponto> Q, int metodo_de_ordenacao) {

    // Passo 1
    ponto p0 = extrai_y_minima(Q); // p0 é identificado e removido de Q

    // Passo 2
    vetor<par<ponto, double>> vetor_ponto_angulo; // Vetor de pares ponto-ângulo
    vetor_ponto_angulo.set_capacity(Q.size());
    for (int i = 0; i < Q.size(); ++i)
        vetor_ponto_angulo.push_back(par<ponto, double>(Q[i], angulo(p0, Q[i])));

    switch (metodo_de_ordenacao) {
        case k_mergesort:
            mergesort(vetor_ponto_angulo);
            break;
        case k_insertionsort:
            insertionsort(vetor_ponto_angulo);
            break;
        case k_bucketsort:
            bucketsort(vetor_ponto_angulo);
            break;
        default:
            throw excecao_metodo_de_ordenacao_invaido{};
    }

    // Remove empates
    for (int i = 0; i < vetor_ponto_angulo.size() - 1; ++i)
        if (vetor_ponto_angulo[i].segundo() == vetor_ponto_angulo[i + 1].segundo())
            comprimento(p0, vetor_ponto_angulo[i].primeiro()) > comprimento(p0, vetor_ponto_angulo[i + 1].primeiro()) ? vetor_ponto_angulo.remove(i + 1) : vetor_ponto_angulo.remove(i);

    // Passo 3
    vetor<ponto> S;

    // Passo 4
    S.push_back(p0);

    // Passo 5
    S.push_back(vetor_ponto_angulo[0].primeiro());

    // Passo 6
    if (vetor_ponto_angulo.size() >= 2)
        S.push_back(vetor_ponto_angulo[1].primeiro());

    // Passo 7
    for (int i = 2; i < vetor_ponto_angulo.size(); ++i) {

        // Passo 8
        while (gira_sentido_horario(S[S.size() - 1], S[S.size() - 2], vetor_ponto_angulo[i].primeiro(), true)) {
            
            // Passo 9
            ponto p = S.pop_back();

        }

        // Passo 10
        S.push_back(vetor_ponto_angulo[i].primeiro());
        
    }

    // Remove pontos colineares
    for (int i = 0; i < S.size(); ++i)
        while (sao_colineares(S[i], S[(i+1) % S.size()], S[(i+2) % S.size()]))
            S.remove((i + 1) % S.size());

    // Passo 11
    return S;
}

vetor<ponto> marchar_de_jarvis(vetor<ponto> Q) {
    vetor<ponto> fecho;

    ponto ponto_no_fecho = x_minima(Q);

    int index_ponto = 0;
    ponto ponto_final = Q[index_ponto];
    do {
        fecho.push_back(ponto_no_fecho);
        ponto_final = Q[0];
        for (int i = 0; i < Q.size(); ++i) {
            if (ponto_final == ponto_no_fecho || !gira_sentido_horario(ponto_no_fecho, Q[i], ponto_final))
                ponto_final = Q[i];
        }
        index_ponto++;
        ponto_no_fecho = ponto_final;
    } while (fecho[0] != ponto_final);

    for (int i = 0; i < fecho.size(); ++i)
        while (sao_colineares(fecho[i], fecho[(i+1) % fecho.size()], fecho[(i+2) % fecho.size()]))
            fecho.remove((i + 1) % fecho.size());

    return fecho;
}