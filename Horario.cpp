#include "Horario.h"

Horario::Horario(String hora, String saida){
    entrada = hora;
    saida = saida;
}

String Horario::get_entrada(){
    return entrada;
}

String Horario::get_saida(){
    return saida;
}

void Horario::set_entrada(String hora){
    entrada = hora;
}

void Horario::set_saida(String hora){
    saida = hora;
}