/// @brief Representa um par
/// @tparam T O tipo do primeiro elemento do par
/// @tparam U O tipo do segundo elemento do par
template <typename T, typename U>
class par {

  public:

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

  private:

    T primeiro_m;
    U segundo_m;
};