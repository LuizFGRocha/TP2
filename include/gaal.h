/// @brief Representa um ponto com duas coordenadas inteiras
class ponto {
  public:

    ponto();

    ponto(int x, int y);

    /// @brief Acessa a coordenada x
    /// @return Retorna uma referência para a coordenada x
    int& coordenada_x();

    /// @brief Acessa a coordenada y
    /// @return Retorna uma referência para a coordenada y
    int& coordenada_y();

    /// @brief Operador de soma de pontos
    /// @param rhs O ponto a ser somado com esse
    /// @return Retorna o ponto resultante da soma de *this com rhs
    ponto operator+(const ponto& rhs);

    /// @brief Operador de subtração de pontos
    /// @param rhs O ponto a ser subtraído desse
    /// @return Retorna o ponto resultante da subtração de *this com rhs
    ponto operator-(const ponto& rhs);

  private:
    int x_m;
    int y_m;
};

/// @brief Representa reta na forma ax + b = y
class reta {
  private:
    int a_m;
    int b_m;
};

/// @brief Calcula o ângulo entre dois pontos
/// @param p O primeiro ponto
/// @param q O segundo ponto
/// @return Retorna o double correspondente ao ângulo
double angulo(ponto p, ponto q);

/// @brief Retorna o comprimento do segmento de reta que liga p e q
double comprimento(ponto p, ponto q);

/// @brief Verifica se o menor giro para que a reta que vai de 
/// p a q tenha a mesma inclinação que a reta que vai de q a r
/// é no sentido horário.
/// @param p O primeiro ponto
/// @param q O segundo ponto
/// @param r O terceiro ponto
/// @return Retorna true se o giro for no sentido horário, false 
/// caso contrário.
bool gira_sentido_horario(ponto p, ponto q, ponto r);