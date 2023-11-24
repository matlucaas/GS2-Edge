#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <DHT.h>
#include <ArduinoJson.h>    // Lib to format JSON Document
#include "EspMQTTClient.h"  // Lib to comunicate MQTT from ESP

#define TFT_DC 2
#define TFT_CS 15
#define I2C_ADDR    0x27
#define LCD_COLUMNS 16
#define LCD_LINES   2
#define BTN_PIN1 25
#define BTN_PIN2 26
#define BTN_PIN3 27
#define BTN_PIN4 14
bool sair = false;
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

DHT dht(33, DHT22);

char *enfermidades[3]= {
  "Dor de cabeca",
  "Dor de estomago",
  "Dor nas pernas"
};

char bufferJson[100];

EspMQTTClient client{
  "Wokwi-GUEST", //SSID do WiFi
  "",     // Senha do wifi
  "mqtt.tago.io",  // Endereço do servidor
  "Default",       // Usuario
  "c1b2580f-8b61-405f-870b-be0c01a9c5cb",         // Token do device
  "esp",           // Nome do device
  1883             // Porta de comunicação
};

void setup() {
  Serial.begin(115200);

  pinMode(BTN_PIN1, INPUT_PULLUP);
  pinMode(BTN_PIN2, INPUT_PULLUP);
  pinMode(BTN_PIN3, INPUT_PULLUP);
  pinMode(BTN_PIN4, INPUT_PULLUP);

  Serial.println("Conectando WiFi");
  while(!client.isWifiConnected()){
    Serial.print('.');
    client.loop();
    delay(1000);
  }
  Serial.println("Conectado!");

  Serial.println("Conectando com o broker MQTT");
  while(!client.isMqttConnected()){
    Serial.print('.');
    client.loop();
    delay(1000);
  }
  Serial.println("Conectado!");

  // Inicializa o display
  tft.begin();
  dht.begin();
  delay(2000);

}

void onConnectionEstablished()
{}

void loop() {
  sair = false;
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.setCursor(0, 20);
  tft.print("1. ");
  tft.println(enfermidades[0]);
  tft.print("2. ");
  tft.println(enfermidades[1]);
  tft.print("3. ");
  tft.println(enfermidades[2]);
  tft.print("4. Ver minha temperatura");

  while(sair == false){
    int leituraBTN1 = digitalRead(BTN_PIN1);
    int leituraBTN2 = digitalRead(BTN_PIN2);
    int leituraBTN3 = digitalRead(BTN_PIN3);
    int leituraBTN4 = digitalRead(BTN_PIN4);

    if(leituraBTN1 == LOW){
      delay(300);
      int leituraBTN1 = digitalRead(BTN_PIN1);
      int leituraBTN2 = digitalRead(BTN_PIN2);
      int leituraBTN3 = digitalRead(BTN_PIN3);
      int leituraBTN4 = digitalRead(BTN_PIN4);
      tft.setCursor(0, 20);
      tft.fillScreen(ILI9341_BLACK);
      tft.println("Cha de erva-cidreira");
      tft.println("\nIngredientes: 1 xicara de agua e de 1 colher de sobremesa de folhas de hortela picadas");
      tft.println("\nModo de preparo: Ferva a agua, desligue o fogo, adicione as folhas de hortela e abafe por 10 minutos. Voce pode bebe-lo assim ou adoca-lo.");
      tft.println("\nClique em qualquer botao para voltar!");
      while(true){
        delay(100);
        int leituraBTN1 = digitalRead(BTN_PIN1);
        int leituraBTN2 = digitalRead(BTN_PIN2);
        int leituraBTN3 = digitalRead(BTN_PIN3);
        int leituraBTN4 = digitalRead(BTN_PIN4);
        if(leituraBTN1 == LOW || leituraBTN2 == LOW || leituraBTN3 == LOW || leituraBTN4 == LOW){
          delay(500);
          sair = true;
          break;
        }
      }
    }

    if(leituraBTN2 == LOW){
      delay(300);
      int leituraBTN1 = digitalRead(BTN_PIN1);
      int leituraBTN2 = digitalRead(BTN_PIN2);
      int leituraBTN3 = digitalRead(BTN_PIN3);
      int leituraBTN4 = digitalRead(BTN_PIN4);
      tft.setCursor(0, 20);
      tft.fillScreen(ILI9341_BLACK);
      tft.println("Cha de gengibre");
      tft.println("\nIngredientes: 1 colher de cha de gengibre sem casca e 1 xicara de agua");
      tft.println("Modo de preparo: Cozinhar 1 colher de cha de gengibre sem casca em 1 xicara de agua. Depois e so consumi-lo tres vezes ao dia e voce tera um sistema digestivo bem mais calmo.");
      tft.println("\nClique em qualquer botao para voltar!");
      while(true){
        delay(100);
        int leituraBTN1 = digitalRead(BTN_PIN1);
        int leituraBTN2 = digitalRead(BTN_PIN2);
        int leituraBTN3 = digitalRead(BTN_PIN3);
        int leituraBTN4 = digitalRead(BTN_PIN4);
        if(leituraBTN1 == LOW || leituraBTN2 == LOW || leituraBTN3 == LOW || leituraBTN4 == LOW){
          delay(500);
          sair = true;
          break;
        }
      }
    }

    if(leituraBTN3 == LOW){
      delay(300);
      int leituraBTN1 = digitalRead(BTN_PIN1);
      int leituraBTN2 = digitalRead(BTN_PIN2);
      int leituraBTN3 = digitalRead(BTN_PIN3);
      int leituraBTN4 = digitalRead(BTN_PIN4);
      tft.setCursor(0, 20);
      tft.fillScreen(ILI9341_BLACK);
      tft.println("Cha de curcuma");
      tft.println("\nIngredientes: 1 colher rasa (de cha) de curcuma em po (200 mg) e 1 xicara de agua.");
      tft.println("\nColocar a agua para ferver e adicionar curcuma. Deixar ferver por 5 a 10 minutos. Coar o cha e beber 2 a 3 xicaras do cha por dia.");
      tft.println("\nClique em qualquer botao para voltar!");
      while(true){
        delay(100);
        int leituraBTN1 = digitalRead(BTN_PIN1);
        int leituraBTN2 = digitalRead(BTN_PIN2);
        int leituraBTN3 = digitalRead(BTN_PIN3);
        int leituraBTN4 = digitalRead(BTN_PIN4);
        if(leituraBTN1 == LOW || leituraBTN2 == LOW || leituraBTN3 == LOW || leituraBTN4 == LOW){
          delay(500);
          sair = true;
          break;
        }
      }
    }

    if(leituraBTN4 == LOW){
      delay(300);
      int leituraBTN1 = digitalRead(BTN_PIN1);
      int leituraBTN2 = digitalRead(BTN_PIN2);
      int leituraBTN3 = digitalRead(BTN_PIN3);
      int leituraBTN4 = digitalRead(BTN_PIN4);
      tft.setCursor(0, 20);
      tft.fillScreen(ILI9341_BLACK);
      tft.println("TEMPERATURA ATUAL");
      tft.println("(Aperte qualquer botao para voltar ao menu e enviar os dados da temperatura)");
      tft.println("\nSua temp. atual e de:\n");
      while(true){
        float temperatura = dht.readTemperature();
        tft.fillRect(20, 160, tft.width(), 20,ILI9341_BLACK);
        tft.setTextSize(3);
        tft.setCursor(20, 160);
        tft.print(temperatura);
        tft.print(" C");
        
        delay(1000);
        int leituraBTN1 = digitalRead(BTN_PIN1);
        int leituraBTN2 = digitalRead(BTN_PIN2);
        int leituraBTN3 = digitalRead(BTN_PIN3);
        int leituraBTN4 = digitalRead(BTN_PIN4);
        if(leituraBTN1 == LOW || leituraBTN2 == LOW || leituraBTN3 == LOW || leituraBTN4 == LOW){
          delay(500);
          tft.setCursor(20, 180);
          tft.println("Enviando dados de temp.");
          StaticJsonDocument<300> documentoJson;
          documentoJson["variable"] = "temperatura";
          documentoJson["value"] = temperatura;
          serializeJson(documentoJson, bufferJson);
          Serial.println("Enviando dados de temperatura");
          Serial.println(bufferJson);
          
          client.publish("topicoGS2", bufferJson); 
          delay(5000);

          client.loop();
          sair = true;
          break;
        }
      }
    }
  }
}
