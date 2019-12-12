#ifndef MEMBROS_H
#define MEMBROS_H

#include "horario.h"
#include "Arduino.h"
#include <IOXhop_FirebaseESP32.h> 
//#include <vector>

using namespace std;

class Membros{
    public:
        vector<Horario*> horario;
        String get_nome();
        String get_ID();
        String get_id_telegram();
        bool get_entrou();
        unsigned long get_last_pass();
        unsigned long get_hours();
        void set_last_pass(unsigned long _last_pass);
        void set_hours(unsigned long time);
        void set_entrou(bool ativo);
        void add_entrada(String Hora);
        void add_saida(String Hora);
        void zerar_horario();
        void cadastra_membros();
        Membros();
        Membros(String _nome, String _ID, String _id_telegram, String _nome_firebase);
    private:
        String nome_firebase;    
        String nome;
        String ID;
        String id_telegram;
        int entrada_qtd;
        bool entrou;
        unsigned long last_pass;
        unsigned long hours;
};



#endif
