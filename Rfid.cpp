#include "Rfid.h"
//#include <LiquidCrystal_I2C.h>

MFRC522 mfrc522(SDA, RST);
//LiquidCrystal_I2C Leitor(0x27,16,2);


void Rfid::init(){
  SPI.begin(); // Init SPI bus 
  mfrc522.PCD_Init(); // Init each MFRC522 card
  
  //Leitor.init();   
  //Leitor.backlight();
}
  

void Rfid::handle(vector <Membros*> memb, NTPClient ntp){
    String conteudo;
    String Nome;
    
    //Leitor.setCursor(0,0);
    //Leitor.print("IDENTIFIQUE-SE");
    //Serial.println("IDENTIFIQUE-SE:");
    // Aguarda a aproximacao do cartao
      if ( ! mfrc522.PICC_IsNewCardPresent()) 
      {
        return;
      }
      // Seleciona um dos cartoes
      if ( ! mfrc522.PICC_ReadCardSerial()) 
      {
        return;
      }

  // Prepara chave de segurança no formato FFFFFFFFFFFFh
    MFRC522::MIFARE_Key key;
    for (byte i = 0; i < 6; i++){
        key.keyByte[i] = 0xFF;
    }

    for (byte i = 0; i < mfrc522.uid.size; i++)
    {
        conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
        conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  
    }
    Serial.println();
    conteudo.toUpperCase(); // Converte a String em Letras maiúsculas

    //Variável para controlar os blocos de memórias
    byte block;
    //Variável para acessar as linhas
    byte len;
    
    //Verifica o status de leitura
    MFRC522::StatusCode status;

    //Quando encontrar alguma informação escreve no monitor serial
    Serial.println(F("----Informações Encontradas----"));
    mfrc522.PICC_DumpDetailsToSerial(&(mfrc522.uid));
    
    //--- LEITURA VARIÁVEL RG ---
    byte buffer2[18];
    //Direciona a leitura ao bloco 1
    block = 1;
    // Coleta as informações armazenadas no bloco 1
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 1, &key, &(mfrc522.uid)); //line 834
    status = mfrc522.MIFARE_Read(block, buffer2, &len);

    delay(500);
    
    // Se tiver finalizado a leitura
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();

   

    String hora;

    for(int i=0; i<memb.size(); i++){     
        if(conteudo == memb[i]->get_ID()){
            
            //VERIFICA SE TEM 5 SEGUNDOS QUE O USUÁRIO PASSOU O CARTÃO PELA ÚLTIMA VEZ
            if( (memb[i]->get_last_pass() - millis()) > 5000){ 
                Nome = memb[i]->get_nome() ;     
                //ABRE A PORTA
                  digitalWrite(RELE, HIGH);
                  delay(50);
                  digitalWrite(RELE, LOW);
                  delay(10);
                  //Leitor.clear();
                  //Leitor.setCursor(0,0);
                  //Leitor.print("BEM VINDO!!!");
                  //Leitor.setCursor(0,1);
                  //Leitor.print(Nome);
                  delay(1400);
                  Serial.print(memb[i]->get_hours()/60000);
                  //Leitor.clear();
                hora = String(ntp.getFormattedTime());
                //REGISTRA A HORA DE ENTRADA OU SAÍDA
                if(!memb[i]->get_entrou()){
                    memb[i]->add_entrada(hora);
                    memb[i]->set_entrou(true);
                }else{
                    memb[i]->add_saida(hora);
                    memb[i]->set_entrou(false);
                }
            }
        }else{
            //Leitor.clear();
            //Leitor.setCursor(1,0);
          //  Leitor.print("ACESSO NEGADO");
            delay(1400);
            //Leitor.clear();
          }
        
    }

 
}
