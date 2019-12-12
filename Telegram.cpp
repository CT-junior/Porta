#include "Telegram.h"

WiFiClientSecure client;     //Cliente para conexões seguras
UniversalTelegramBot bot(BOT_TOKEN, client);

int Telegram::numNewMessages(){
  return bot.getUpdates(bot.last_message_received + 1);
}

void Telegram::handleNewMessages(int numNewMessages, vector<Membros*> m, NTPClient ntp) {
    int position;
    //Serial.println("Inicio telegram");
    for (int i=0; i<numNewMessages; i++) //para cada mensagem nova
    {
        String chatId = String(bot.messages[i].chat_id); //id do chat
        String senderId = String(bot.messages[i].from_id); //id do contato
        String hora;
        
        Serial.println("senderId: " + senderId); //mostra no monitor serial o id de quem mandou a mensagem
    
        position = validateSender(senderId, m); //verifica se é o id de um remetente da lista de remetentes válidos

        //VERIFICA SE O REMETENTE É VÁLIDO
        if(position < 0){
            bot.sendMessage(chatId, "Desculpe mas você não tem permissão", "HTML"); //envia mensagem que não possui permissão e retorna sem fazer mais nada
            continue; //continua para a próxima iteração do for (vai para próxima mensgem, não executa o código abaixo)
        }
        
        String text = bot.messages[i].text; //texto que chegou
    
        if (text.equalsIgnoreCase(START)){
            handleStart(chatId, bot.messages[i].from_name); //mostra as opções
        } else if (text.equalsIgnoreCase(ABRIR_PORTA)){
            handleAbrirPorta(chatId); //Aciona o relé da porta e manda chat para o usuário
            hora = ntp.getFormattedTime(); //Armazena o horário do acionamento do relé
            if(!m[position]->get_entrou()){
                m[position]->add_entrada(hora);
                m[position]->set_entrou(true);
            } else{
                m[position]->add_saida(hora);
                m[position]->set_entrou(false);
            }
         } else if(text.equalsIgnoreCase(NA_CT)){
            handle_presentes(chatId, m);
         } else if (text.equalsIgnoreCase(HORAS)){
            handle_horas_na_empresa(chatId, m);
         } else{
            handleNotFound(chatId); //mostra mensagem que a opção não é válida e mostra as opções
        }
        //Serial.println("FIM telegram");
    }//for
}


//Se o id do remetente faz parte do array retornamos algum valor > 0
int Telegram::validateSender(String senderId, vector<Membros*> m){
    for (int i=0; i<m.size(); i++){
        if(senderId == m[i]->get_id_telegram()){
            return i;
        }
    }
    return -10;
}
//########################################################################## 

void Telegram::handleStart(String chatId, String fromName){
    //Mostra Olá e o nome do contato seguido das mensagens válidas
    String message = "<b>Olá " + fromName + ".</b>\n";
    message += getCommands();
    bot.sendMessage(chatId, message, "HTML");
}

//########################################################################## 
        
String Telegram::getCommands(){
    //String com a lista de mensagens que são válidas e explicação sobre o que faz
    String message = "Os comandos disponíveis são:\n\n";
    message += "<b>" + ABRIR_PORTA + "</b>: Para abrir a porta\n";
    message += "<b>" + NA_CT + "</b>: Para ver quem está na CT no momento\n";
    return message;
}   


//########################################################################## 

void Telegram::handleAbrirPorta(String chatId){
    //Liga o relê e envia mensagem confirmando a operação
    digitalWrite(RELE, HIGH);  
    bot.sendMessage(chatId, "a portlude Arduina está <b>aberta</b>", "HTML");
    delay(10);
    digitalWrite(RELE, LOW);
}

//##########################################################################

void Telegram::handle_presentes(String chatId, vector<Membros*> m){
    //Liga o relê e envia mensagem confirmando a operação
    String message = "Os membros presentes na CT agora são:";
    for(int i = 0; i < m.size(); i++){
        if(m[i]->get_entrou()){
            message += "<b>" + String(i) + ". " + m[i]->get_nome() + "</b>\n";
        }
    }
    bot.sendMessage(chatId, message, "HTML");
}

//##########################################################################

void Telegram::handle_horas_na_empresa(String chatId, vector<Membros*> m){
    String message = "O total de minutos trabalhados são de:\n";
    for(int i = 0; i < m.size(); i++){
        message += "<b>" + String(i) + ". " + m[i]->get_nome() + ": " + String(m[i]->get_hours()/60000) + " minutos.</b>\n";
    }
    bot.sendMessage(chatId, message, "HTML");
}

//########################################################################## 

void Telegram::handleNotFound(String chatId){
    //Envia mensagem dizendo que o comando não foi encontrado e mostra opções de comando válidos
    String message = "Comando não encontrado\n";
    message += getCommands();
    bot.sendMessage(chatId, message, "HTML");
}
