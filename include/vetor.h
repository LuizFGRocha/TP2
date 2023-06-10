#ifndef VETOR_H
#define VETOR_H

struct excecao_posicao_invalida{};
struct excecao_vetor_vazio{};

template <typename Tipo> 
class vetor {
  public:
    
    /// @brief Inicializa o vetor. Por padrão, com tamanho 0 e capacidade 10.
    vetor() : tamanho_m(0), capacidade_m(10), vetor_m(new Tipo[10]) {};

    /// @brief Inicializa o vetor com opção para tamanho inicial e valor de inicialização
    /// dos elementos.
    /// @param tamanho Tamnho inicial. 
    /// @param valor_inicial Valor de inicialização dos elementos.
    vetor(int tamanho, Tipo valor_inicial) : tamanho_m(tamanho), capacidade_m(2 * tamanho), vetor_m(new Tipo[tamanho]) {
        for (int i = 0; i < tamanho; ++i) {
            vetor_m[i] = valor_inicial;
        }
    };

    /// @brief Construtor de cópia
    /// @param vetor_entrada O construtor a ser copiado
    vetor(const vetor<Tipo>& vetor_entrada) : vetor() {
        operator=(vetor_entrada);
    }

    /// @brief Aumenta a capacidade sem inicializar as novas posições.
    /// @param capacidade Nova capacidade.
    void set_capacity(int capacidade) {
        Tipo* temp = vetor_m;
        vetor_m = new Tipo[capacidade];

        for (int i = 0; i < tamanho_m; ++i) {
            vetor_m[i] = temp[i];
        }

        if (tamanho_m > capacidade)
            tamanho_m = capacidade;

        capacidade_m = capacidade;

        delete [] temp;
    }

    /// @brief Aumenta o tamanho inicializado as novas posições.
    /// @param tamanho Novo tamanho.
    /// @param valor_inicial Valor inicial das novas posições.
    void set_size(int tamanho, Tipo valor_inicial) {
        capacidade_m = 2 * tamanho;
        Tipo* temp = vetor_m;
        vetor_m = new Tipo[capacidade_m];

        int i;
        for (i = 0; i < tamanho_m; ++i) {
            vetor_m[i] = temp[i];
        }

        for (; i < tamanho; ++i) {
            vetor_m[i] = valor_inicial;
        }

        tamanho_m = tamanho;

        delete [] temp;
    }

    /// @brief Adiciona uma posição no final do vetor e coloca um elemento nela.
    /// Se necessário, a capacidade é aumentada.
    /// @param elemento O elemento a ser colocado
    vetor& push_back(Tipo elemento) {

        if (tamanho_m >= capacidade_m) {

            Tipo* temp = vetor_m;

            capacidade_m *= 2;
            vetor_m = new Tipo[capacidade_m];

            int i;
            for (i = 0; i < tamanho_m; ++i) {
                vetor_m[i] = temp[i];
            }
            vetor_m[i] = elemento;

            tamanho_m++;
            delete [] temp;

        } else {
            vetor_m[tamanho_m++] = elemento;
        }

        return *this;
    }

    /// @brief Remove a última posição do vetor e retorna o elemento que a ocupava.
    /// Se o novo tamanho for menor que um quarto da capacidade, a capacidade é
    /// reduzida pela metade.
    /// @return O elemento que ocupava a última posição
    Tipo pop_back() {

        if (tamanho_m == 0) 
            throw excecao_vetor_vazio{};

        tamanho_m--;

        if (4 * tamanho_m <  capacidade_m) {

            Tipo* temp = vetor_m;

            capacidade_m /= 2;
            vetor_m = new Tipo[capacidade_m];
            for (int i = 0; i <= tamanho_m; ++i) {
                vetor_m[i] = temp[i];
            }

            delete [] temp;
        }

        return vetor_m[tamanho_m];
    }

    /// @brief Remove do vetor a posição indicada, movendo todos os
    /// elementos posteriores um passo para trás.
    /// @param posicao Posição a ser removida, contada a partir de 0
    void remove(int posicao) {
        if (size() - 1 < posicao)
            throw excecao_posicao_invalida{};

        for (int i = posicao; i < size() - 1; ++i) {
            (*this)[i] = (*this)[i + 1];
        } 

        tamanho_m--;
    }

    /// @brief clean o vetor, deixando-o como se tivesse acabado de ser criado
    /// com um construtor vazio.
    void clean() {
        operator=(vetor<Tipo>());
    }

    /// @brief Retorna o elemento em uma posição desejada. A posição tem que ter ser
    /// um número não negativo menor que o tamanho.
    /// @param posicao A posição desejada.
    /// @return O elemento que ocupa a posição.
    Tipo& operator [] (int posicao) {
        if (posicao >= tamanho_m || posicao < 0) {
            throw excecao_posicao_invalida{};
        } else {
            return vetor_m[posicao];
        }
    }

    /// @brief Copia os conteúdos de um vetor para outro
    /// @param rhs O vetor cujos conteúdos serão copiados
    /// @return Retorna uma referência para o vetor que recebe a cópia
    vetor<Tipo>& operator=(const vetor<Tipo>& rhs) {
        this->~vetor();
        tamanho_m = 0;
        capacidade_m = rhs.capacidade_m;
        vetor_m = new Tipo[capacidade_m];
        for (int i = 0; i < rhs.size(); ++i)
            push_back(*(rhs.vetor_m + i));

        return *this;
    }

    /// @brief Dá o tamanho do vetor
    /// @return Retorna o inteiro correspondente ao tamanho
    int size() const {
        return tamanho_m;
    }

    /// @brief Dá a capacidade do vetor
    /// @return Retorna o inteiro correspondente à capacidade
    int capacity() {
        return capacidade_m;
    }

    /// @brief Checa se o vetor é vazio
    /// @return Retorna true se estiver vazio e false caso contrário
    bool empty() {
        return tamanho_m == 0;
    }

    ~vetor() {
        delete [] vetor_m;
        vetor_m = nullptr;
    }

  private:

    Tipo* vetor_m;
    int tamanho_m;
    int capacidade_m;
};

#endif