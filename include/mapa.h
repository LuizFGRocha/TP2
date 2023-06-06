#include "par.h"
#include "lista.h"

template <typename T, typename U>
class mapa {
  public:

    U& operator[](T chave) {
        for (int i = 0; i < lista_m.tamanho(); ++i)
            if (chave == lista_m[i].primeiro())
                return lista_m[i].segundo();

        lista_m.push_back(par<T, U>(chave, U()));
        return lista_m.get_back();
    }

  private:
    
    lista<par<T, U>> lista_m;
};