#ifndef HORARIO_H
#define HORARIO_H

//#include "string.h"
#include "Arduino.h"

class Horario{
    public:
        String get_entrada();
        String get_saida();
        void set_entrada(String hora);
        void set_saida(String hora);
        Horario();
        Horario(String hora, String saida);
    private:
        String entrada; // HORA QUE A PESSOA ENTROU
        String saida;   // HORA QUE A PESSOA SAIU
};

#endif