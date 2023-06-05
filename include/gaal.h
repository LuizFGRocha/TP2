#include <string>
#include <iostream>

struct excecao_pontos_iguais{};

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

    void imprime_ponto();

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

bool nao_vira_para_a_esquerda(ponto p, ponto q, ponto r);