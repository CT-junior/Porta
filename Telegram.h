#ifndef TELEGRAM_H
#define TELEGRAM_H

#include "Membros.h"
#include "WifiManager.h"
#include <NTPClient.h> //lib relogio
#include <UniversalTelegramBot.h> //lib para comunicação telegram
#include <WiFiClientSecure.h>
#include "Arduino.h"
#include <vector>

#define RELE 2
#define BOT_TOKEN "799101767:AAGY8EbTKTqt2O6mZWRN9GVT0auqGWN_AoU" //Token do seu bot. Troque pela que o BotFather te mostrar
const String ABRIR_PORTA = "abrir a porta";
const String NA_CT = "Na CT";
const String START = "/start";
const String HORAS = "Horas";


class Telegram{
     public:
          void handleNewMessages(int numNewMessages, vector<Membros*> m, NTPClient ntp);
          int validateSender(String senderId, vector<Membros*> m);
          void handleStart(String chatId, String fromName);
          String getCommands();
          void handleAbrirPorta(String chatId);
          void handleNotFound(String chatId);
          int numNewMessages();
          void handle_presentes(String chatId, vector<Membros*> m);
          void handle_horas_na_empresa(String chatId, vector<Membros*> m);
};

#endif
