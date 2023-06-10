#ifndef PAR_H
#define PAR_H

/// @brief Representa um par
/// @tparam T O tipo do primeiro elemento do par
/// @tparam U O tipo do segundo elemento do par
template <typename T, typename U>
class par {

  public:

    par() {
        primeiro_m = T();
        segundo_m = U();
    }

    /// @brief Constrói o par e inicializa os valores
    /// @param primeiro Valor do primeiro elemento
    /// @param segundo Valor do segundo elemento
    par(T primeiro, U segundo) {
        primeiro_m = primeiro;
        segundo_m = segundo;
    }

    /// @brief Retorna uma referência para o primeiro elemento do par
    T& primeiro() {
        return primeiro_m;
    }

    /// @brief Retorna uma referência para o segundo elemento do par
    U& segundo() {
        return segundo_m;
    }

    /// @brief Compara o segundo elemento dos pares
    /// @param rhs O par da direita
    /// @return true se o segundo elemento do par da esquerda é maior
    /// que o segundo elemento do par da direita, false caso contrário
    bool operator>(par<T, U>& rhs) const {
      return segundo_m > rhs.segundo_m;
    }

    /// @brief Compara o segundo elemento dos pares
    /// @param rhs O par da direita
    /// @return true se o segundo elemento do par da esquerda é maior ou
    /// igual ao segundo elemento do par da direita, false caso contrário
    bool operator>=(par<T, U>& rhs) const {
      return segundo_m >= rhs.segundo_m;
    }

    /// @brief Compara o segundo elemento dos pares
    /// @param rhs O par da direita
    /// @return true se o segundo elemento do par da esquerda é menor
    /// que o segundo elemento do par da direita, false caso contrário
    bool operator<(par<T, U>& rhs) const {
      return segundo_m < rhs.segundo_m;
    }

    /// @brief Compara o segundo elemento dos pares
    /// @param rhs O par da direita
    /// @return true se o segundo elemento do par da esquerda é menor ou
    /// igual ao segundo elemento do par da direita, false caso contrário
    bool operator<=(par<T, U>& rhs) const {
      return segundo_m <= rhs.segundo_m;
    }

    /// @brief Compara o segundo elemento dos pares
    /// @param rhs O par da direita
    /// @return true se o segundo elemento do par da esquerda é igual 
    /// ao segundo elemento do par da direita, false caso contrário
    bool operator==(par<T, U>& rhs) const {
      return segundo_m == rhs.segundo_m;
    }

  private:

    T primeiro_m;
    U segundo_m;
};

#endif // PAR_H