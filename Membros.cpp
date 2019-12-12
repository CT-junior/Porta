#include "Membros.h"
//#include "string.h"
#include <vector>

String Membros::get_nome(){
    return nome;
}

String Membros::get_ID(){
    return ID;
}

String Membros::get_id_telegram(){
    return id_telegram;
}

bool Membros::get_entrou(){
    return entrou;
}

unsigned long Membros::get_last_pass(){
    return last_pass;
}

unsigned long Membros::get_hours(){
    return hours;
}

void Membros::set_last_pass(unsigned long _last_pass){
    last_pass = _last_pass;
}

void Membros::set_hours(unsigned long time){
    unsigned long _hours = millis() - last_pass;
    hours += _hours;
    Firebase.setFloat(nome_firebase, float(hours/60000));
}

void Membros::set_entrou(bool ativo){
    entrou = ativo;
};

void Membros::add_entrada(String hora){
    Horario *h = new Horario(hora, "");
    horario.push_back(h);
    last_pass = millis();
}

void Membros::add_saida(String hora){
    horario[horario.size()-1]->set_saida(hora);
    set_hours(millis());
}

void Membros::zerar_horario(){
    horario.clear();
}

Membros::Membros(String _nome, String _ID, String _id_telegram, String _nome_firebase){
    nome = _nome;
    ID = _ID;
    id_telegram = _id_telegram;
    entrou = 0;
    //hours = Firebase.getFloat(_nome_firebase)*60000;
    last_pass = 0;
    nome_firebase = _nome_firebase;
}
