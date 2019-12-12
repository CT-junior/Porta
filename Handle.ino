
#include "Horario.h"
#include "Membros.h"
#include "WifiManager.h"
//#include "OTAManager.h"
#include "CadastroMemb.h"
#include "Rfid.h"
#include "Telegram.h"
#include "Firebase.h"
#include <WiFiUdp.h> //lib necessária para comunicação network


#define RELE 12
#define INTERVAL 1000
uint32_t lastCheckTime = 0;

static uint8_t taskCoreZero = 0;
static uint8_t taskCoreOne  = 1;

//-------- Configurações de relógio on-line -----------
WiFiUDP udp;
NTPClient ntp(udp, "a.st1.ntp.br", -3 * 3600, 60000); //Cria um objeto "NTP" com as configurações utilizadas no Brasil.


//--------------- Instanciando objetos ----------------
WifiManager wifiManager;
//OTAManager otaManager;
vector<Membros*> membro;
Telegram telegram;
Rfid rfid;
FireBase firebase;
//-----------------------------------------------------
/*
// ############ FUNÇÕES ÚTEIS #################

int verifica_posicao_ID(String ID){
    for (int i=0; i<membro.size(); i++){
        if(ID == membro[i]->get_ID()){
            return i;
        }
    }
    return -1;
}
//#############################################
*/

void setup() {
  Serial.begin(115200);
    delay(1000);


  pinMode(RELE, OUTPUT);
  digitalWrite(RELE, LOW);
  
  wifiManager.init();
  firebase.init();
  Serial.println("Membros sendo cadastrados.");
  membro = cadastra_membros();
  Serial.println("Membros cadastrados.");
//  otaManager.init();
  ntp.begin();               // Inicia o protocolo NTP
  ntp.forceUpdate();          // Atualização do horário
  SPI.begin(); 
  // Inicia o protocolo SPI
  rfid.init();
   xTaskCreatePinnedToCore(
                    coreTelegramOne,   /* função que implementa a tarefa */
                    "coreTaskOne", /* nome da tarefa */
                    10000,      /* número de palavras a serem alocadas para uso com a pilha da tarefa */
                    NULL,       /* parâmetro de entrada para a tarefa (pode ser NULL) */
                    1,          /* prioridade da tarefa (0 a N) */
                    NULL,       /* referência para a tarefa (pode ser NULL) */
                    taskCoreOne);         /* Núcleo que executará a tarefa */
 
    delay(500); //tempo para a tarefa iniciar
}



void loop() {

  // put your main code here, to run repeatedly:
//  otaManager.handle();
  rfid.handle(membro, ntp);
  uint32_t now = millis();

  
 
  /*//Se o tempo passado desde a última checagem for maior que o intervalo determinado
  if (now - lastCheckTime > INTERVAL) 
  {
    //Coloca o tempo de útlima checagem como agora e checa por mensagens
    lastCheckTime = now;
    telegram.handleNewMessages(telegram.numNewMessages(), membro, ntp);
  }*/
}

void coreTelegramOne( void * pvParameters ){
     while(true){
      uint32_t now = millis();
      
      //Se o tempo passado desde a última checagem for maior que o intervalo determinado
      if (now - lastCheckTime > INTERVAL) 
        {
        //Coloca o tempo de útlima checagem como agora e checa por mensagens
        lastCheckTime = now;
        telegram.handleNewMessages(telegram.numNewMessages(), membro, ntp);
       } 
     }
}
