/**
 * @file Access control in restricted environments  
 * @brief Access control in restricted environments 
 * by means of RFID that activates a magnetic 
 * lock through a relay, thus opening the lock if 
 * access is allowed.
 *
 * Performs access control through microcontroller 
 * (Arduino UNO). The access control is performed 
 * when the program receives the information on the 
 * serial port informing that a face was detected by 
 * another microcontroller, then a TEG RFID must be 
 * presented in the reader, if the face data are the 
 * same as the TEG data, the relay a triggered by 
 * opening the magnetic lock and freeing access to 
 * the desired environment.
 *
 * @author Hyuri Maciel
 * @date 15 May 2016
 *
 */


#include <SPI.h>
#include <MFRC522.h> // library RFID
#include <LiquidCrystal.h>

#define SS_PIN 8
#define RST_PIN 9

int rele = 2;
int num;
int input;
char st[20];
String face = "";

/* Pin configuration RFID
 * pin 10- SDA
 * pin 11 -MOSI
 * pin 12 - MISO
 * pin 12 - MISO
 * pin 9- RST
 */


// inicia o leitor RFID
MFRC522 mfrc522(SS_PIN, RST_PIN);

//Configuraçao dos pinos de comunicaçao arduino e LCD
LiquidCrystal lcd(14, 15, 16, 17, 18, 19);

/* Teg's cadastradas para acesso*/
String Hyuri = "21 2F D4 0E";
String Bruno = "44 1B 32 C3";
String Randy = "84 6A 30 C3";
String Matheus = "84 A5 35 C3";
String Isadora = "14 E5 2A C3";

/*pronta para acionamento do relé*/
int rele = 8;

void setup(){
  
  Serial.begin(9600);   // Inicia a serial
  
  SPI.begin();      // Inicia  SPI bus

  mfrc522.PCD_Init();   // Inicia MFRC522

  lcd.begin(16,2);
  //Define pinos para o rele como saída
  pinMode(rele, OUTPUT); 

  mensageminicial();  
}

void loop(){
  String aux = "";

  if ( ! mfrc522.PICC_IsNewCardPresent()){
    return;
  }

  if ( ! mfrc522.PICC_ReadCardSerial()){
    return;
  }

/*verifica se alguma face foi detectada e libera acesso*/
  if(Serial.available()>0){
   face = Serial.read();  
  }
  
  aux = getUid();
  Serial.println(face);
  /*verifica se a teg está cadastrada e libera ou não acesso*/
  if ((aux.substring(1) == Hyuri || aux.substring(1) == Bruno 
        || aux.substring(1) == Randy||aux.substring(1) == Matheus 
        || aux.substring(1) == Isadora) && face == "Hyuri"){
          
    Serial.println("Acesso Liberado!");
    lcd.clear();
    lcd.setCursor(0,0);

    lcd.print("Bem Vindo");
    lcd.setCursor(0,1);
    lcd.print(aux);

    digitalWrite(rele,HIGH);  //Liga rele 
    Serial.println();
    delay(5000);
    digitalWrite(rele,LOW);  //Desliga Rele
    num = 0;

  }
  
  else{
    
    Serial.println("Sem Acesso!");
    Serial.println(num);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Sem Acesso");
    delay(2000);
  }

  mensageminicial();
} 

/*Ler RFID, retornando uma string com a UID*/
String getUid(){

  Serial.print("UID da tag :");
  String conteudo= "";
  byte letra;

  for (byte i = 0; i < mfrc522.uid.size; i++){
    
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
    
  }
  Serial.println();
  conteudo.toUpperCase();
  return (conteudo);
}

/*funçao da mensagem inicial do display*/
void mensageminicial(){
  
  lcd.clear();
  lcd.print("LaCCAN-UFAL");  
  lcd.setCursor(0,1);
  lcd.print("LAB: 16"); 
  
}
/*funçao que converte ascii para o numero inteiro*/
int convert(int num){
 int aux;
 aux= num-48;
 return (aux);  
}
