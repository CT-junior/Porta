#ifndef RFID_H
#define RFID_H

#include <vector>
#include "Membros.h"
#include <NTPClient.h> //lib relogio
#include <MFRC522.h> //lib inicialização tags
#include <SPI.h> //biblioteca para comunicação do barramento SPI

#define RELE 12

#define SDA 5 //Conectado ao pino D5 do ESP32
#define RST 4 //Conectado ao pino VP do ESP32

const byte resetPin = 4;
const byte numLeitores = 1;
const byte ssPins[] = {SDA};

class Rfid{
    public:
        void handle(vector <Membros*> memb, NTPClient ntp);
        void init();
};

#endif
