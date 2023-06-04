/// @brief Representa um ponto com duas coordenadas inteiras
class ponto {
  public:

    /// @brief Acessa a coordenada x
    /// @return Retorna uma referência para a coordenada x
    int& coordenada_x();

    /// @brief Acessa a coordenada y
    /// @return Retorna uma referência para a coordenada y
    int& coordenada_y();

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

/// @brief Calcula a norma n de um vetor de coordenadas iguais às
/// do ponto passado.
/// @param p O ponto cujas coordenadas serão utilizadas.
/// @param n Determina qual norma será tomada.
/// @return Retorna o double com o valor da normal calculado.
double norma(ponto p, int n);

/// @brief Calcula o ângulo entre dois pontos
/// @param p O primeiro ponto
/// @param q O segundo ponto
/// @return Retorna o double correspondente ao ângulo
double angulo(ponto p, ponto q);

bool vira_para_a_esquerda(ponto p, ponto q);