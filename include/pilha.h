#ifndef PILHA_H
#define PILHA_H

struct excecao_pilha_vazia{};
struct excecao_tamanho_insuficiente{};

template <typename Tipo>
struct elemento_pilha {
    elemento_pilha* prox;
    Tipo chave;
};

template <typename Tipo>
class pilha {
  public:
    pilha() : tamanho_m(0) {
        topo_m = nullptr;
    }

    pilha(const pilha<Tipo>& rhs) {
        tamanho_m = 0;
        topo_m = nullptr;

        elemento_pilha<Tipo>* p = rhs.topo_m;
        Tipo vetor[rhs.tamanho()];

        for (int i = 0; i < rhs.tamanho(); ++i) {
            vetor[i] = p->chave;
            p = p->prox;
        }
        
        for (int i = rhs.tamanho() - 1; i >= 0; --i) {
            elemento_pilha<Tipo>* novo_topo = new elemento_pilha<Tipo>;
            novo_topo->prox = topo_m;
            novo_topo->chave = vetor[i];
            topo_m = novo_topo;
            tamanho_m++;
        }

        tamanho_m = rhs.tamanho();
    }

    pilha<Tipo>& empilha(Tipo elemento) {
        elemento_pilha<Tipo>* novo_topo = new elemento_pilha<Tipo>;
        novo_topo->prox = topo_m;
        novo_topo->chave = elemento;
        topo_m = novo_topo;
        tamanho_m++;
        return *this;
    }

    Tipo desempilha() {
        if (vazia()) 
            throw excecao_pilha_vazia{};
        Tipo valor = topo_m->chave;
        elemento_pilha<Tipo>* prox = topo_m->prox;
        delete topo_m;
        tamanho_m--;
        topo_m = prox;
        return valor;
    }

    Tipo espia() const {
        if (vazia()) 
            throw excecao_pilha_vazia{};
        return topo_m->chave;
    }

    Tipo espia_segundo() const {
        if (tamanho() < 2) 
            throw excecao_tamanho_insuficiente{};
        return topo_m->prox->chave;
    }

    bool vazia() const {
        return topo_m == nullptr;
    }

    int tamanho() const {
        return tamanho_m;
    }

    pilha<Tipo>& operator=(const pilha<Tipo>& rhs) {
        elemento_pilha<Tipo>* p = rhs.topo_m;
        Tipo vetor[rhs.tamanho()];

        limpa();

        for (int i = 0; i < rhs.tamanho(); ++i) {
            vetor[i] = p->chave;
            p = p->prox;
        }
        
        for (int i = rhs.tamanho() - 1; i >= 0; --i) {
            empilha(vetor[i]);
        }

        tamanho_m = rhs.tamanho();

        return *this;
    }

    void limpa() {
        while (!vazia())
            desempilha();
    }

    ~pilha() {
        limpa();
    }

  private:
    int tamanho_m;
    elemento_pilha<Tipo>* topo_m;
};

#endif