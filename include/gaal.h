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
