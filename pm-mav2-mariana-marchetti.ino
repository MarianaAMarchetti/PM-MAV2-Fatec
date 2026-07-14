//Programação para microcontroladores  MAV2
//Mariana Ament Marchetti - Controle de temperatura 
 
// Biblioteca utilizada 
#include <LiquidCrystal.h>
 
// Importação das variáveis globais 
const int TMP = A0;
float temperatura; 
int ledam = 6;

// Inicialização do display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

// Prototipagem das funções
float le_temperatura(int pino);
void mostra_temperatura(float temperatura);

// Início da comunicação serial, no void setup.
void setup() {

  Serial.begin(9600);
  pinMode(ledam, OUTPUT);

}
 
 
void loop() {
 
  temperatura = le_temperatura(TMP);
  mostra_temperatura(temperatura);
  delay(1000);
 
}
 
 
float le_temperatura(int pino){
 
  int TMP_data;
  float voltagem;
  TMP_data = analogRead(pino);
  voltagem = float(TMP_data)*(5.0/1023.0);
  float temperatura = (voltagem-0.5)/0.01;
  return temperatura;
 
}
 
void mostra_temperatura(float temperatura){
  
  Serial.print("Temperatura: ");
  Serial.println(temperatura); 
  

void texto ();{

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   Chocadeira");
  lcd.setCursor(0, 1);
  lcd.print("Temperatura: ");
  lcd.print(temperatura);
  delay(500);

}

if (temperatura < 36.0) {

  digitalWrite(ledam, HIGH);
}
 
if (temperatura > 38.0){
  
  digitalWrite(ledam, LOW);
  }
 
  
}

 