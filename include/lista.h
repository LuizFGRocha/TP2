#ifndef LISTA_H
#define LISTA_H

template <typename T>
struct nodo_lista {
    nodo_lista() {
        prox_m = prev_m = nullptr;
    }

    nodo_lista(T chave, nodo_lista* prev=nullptr, nodo_lista* prox=nullptr) {
        chave_m = chave;
        prev_m = prev;
        prox_m = prox;
    }

    T chave_m;
    nodo_lista* prox_m;
    nodo_lista* prev_m;
};

struct LISTA_excecao_posicao_invalida{};
struct LISTA_excecao_lista_vazia{};

template <typename T>
class lista {

  public:

    /// @brief Construtor vazio da lista. Cria uma lista vazia.
    lista() {
        inicio_m = final_m = nullptr;
        tamanho_m = 0;
    }

    /// @brief Cria uma lista a partir de outra lista, copiando seus valores.
    /// @param rhs A lista que será copiada.
    lista(const lista& rhs) {
        for (int i = 0; i < rhs.tamanho(); ++i)
            push_back(rhs.at(i));
    } 

    /// @brief Insere no final da lista.
    /// @param chave A chave a ser inserida.
    /// @return Retorna uma referência para a lista, o que permite encadeamento.
    lista& push_back(T chave) {
        if (vazia()) {
            inicio_m = final_m = new nodo_lista<T>(chave);
            tamanho_m++;
            return *this;
        }

        nodo_lista<T>* tmp = final_m;
        final_m = new nodo_lista<T>(chave, final_m);
        tmp->prox_m = final_m;
        tamanho_m++;

        return *this;
    }

    /// @brief Insere no início da lista.
    /// @param chave A chave a ser inserida.
    /// @return Retorna uma referência para a lista, o que permite encadeamento.
    lista& push_front(T chave) {
        if (vazia()) {
            inicio_m = final_m = new nodo_lista<T>(chave);
            tamanho_m++;
            return *this;
        }

        nodo_lista<T>* tmp = inicio_m;
        inicio_m = new nodo_lista<T>(chave, nullptr, inicio_m);
        tmp->prev_m = inicio_m;
        tamanho_m++;

        return *this;
    }

    /// @brief Tira o último elemento do final da lista.
    /// @return Retorna o elemento tirado.
    T pop_back() {
        if (vazia())
            throw LISTA_excecao_lista_vazia{};

        T chave = final_m->chave_m;

        if (tamanho() == 1) {
            delete inicio_m;
            inicio_m = final_m = nullptr;
            tamanho_m--;
            return chave;
        }

        final_m = final_m->prev_m;
        delete final_m->prox_m;
        final_m->prox_m = nullptr;
        tamanho_m--;
        return chave;
    }

    /// @brief Tira o último elemento do início da lista.
    /// @return Retorna o elemento tirado.
    T pop_front() {
        if (vazia())
            throw LISTA_excecao_lista_vazia{};
            
        T chave = inicio_m->chave_m;

        if (tamanho() == 1) {
            delete inicio_m;
            inicio_m = final_m = nullptr;
            tamanho_m--;
            return chave;
        }

        inicio_m = inicio_m->prox_m;
        delete inicio_m->prev_m;
        inicio_m->prev_m = nullptr;
        tamanho_m--;
        return chave;
    }

    /// @brief Retorna uma cópia do valor em uma posição.
    /// @param posicao A posição cujo valor será retornado.
    T at(int posicao) const {
        if (posicao >= tamanho() || posicao < 0)
            throw LISTA_excecao_posicao_invalida{};

        if (posicao < tamanho() / 2) {
            nodo_lista<T>* ptr = inicio_m;
            for (int i = 0; i < posicao; ++i) {
                ptr = ptr->prox_m;
            }
            return ptr->chave_m;
        } else {
            nodo_lista<T>* ptr = final_m;
            for (int i = tamanho_m - 1; i > posicao; --i) {
                ptr = ptr->prev_m;
            }
            return ptr->chave_m;
        }
    }

    /// @brief Retorna uma referência para o último valor da lista.
    T& get_back() {
        return final_m->chave_m;
    }

    /// @brief Retorna uma referência para o primeiro valor da lista.
    T& get_front() {
        return inicio_m->chave_m;
    }

    /// @brief Retorna uma referência para o valor na posição requisitada.
    T& operator[](int posicao) {
        if (posicao >= tamanho() || posicao < 0)
            throw LISTA_excecao_posicao_invalida{};

        if (posicao < tamanho() / 2) {
            nodo_lista<T>* ptr = inicio_m;
            for (int i = 0; i < posicao; ++i) {
                ptr = ptr->prox_m;
            }
            return ptr->chave_m;
        } else {
            nodo_lista<T>* ptr = final_m;
            for (int i = tamanho_m - 1; i > posicao; --i) {
                ptr = ptr->prev_m;
            }
            return ptr->chave_m;
        }
    }

    /// @brief Serve para atribuir uma lista a outra.
    /// @param rhs A lista à direita na atribuição.
    /// @return Retorna uma referência para *this, permite encadeamento.
    lista& operator=(const lista& rhs) {
        for (int i = 0; i < rhs.tamanho(); ++i)
            push_back(rhs.at(i));

        return *this;
    }

    /// @brief Retorna o tamanho da lista 
    int tamanho() const {
        return tamanho_m;
    }

    /// @brief Checa se a lista está vazia.
    /// @return Retorna true se sim e falso caso contrário.
    bool vazia() const {
        return tamanho() == 0;
    } 

    /// @brief Destrói a lista.
    ~lista() {
        if (tamanho() == 0)
            return;

        if (tamanho() == 1) {
            delete inicio_m;
            tamanho_m--;
            return;
        }

        nodo_lista<T>* ptr = inicio_m;
        for (int i = 0; i < tamanho() - 1; ++i) {
            ptr = ptr->prox_m;
            delete ptr->prev_m;
            ptr->prev_m = nullptr;
        }
        
        tamanho_m = 0;
        delete ptr;
    }

  private:

    nodo_lista<T>* inicio_m;
    nodo_lista<T>* final_m;
    int tamanho_m;

};

#endif // LISTA_H