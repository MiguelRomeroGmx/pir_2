const int LEDPin = 4;        // pin para el LED
const int PIRPin = 3;         // pin de entrada (for PIR sensor)
 
int pirState = LOW;           // de inicio no hay movimiento
int val = 0;                  // estado del pin
 
void setup() 
{
  pinMode(LEDPin, OUTPUT); 
  pinMode(PIRPin, INPUT);
  Serial.begin(9600);
}
 
void loop()
{
  val = digitalRead(PIRPin);
  if (val == HIGH)   //si está activado
  { 
    digitalWrite(LEDPin, HIGH);  //LED ON
    if (pirState == LOW)  //si previamente estaba apagado
    {
      Serial.println("Sensor Activado");
      pirState = HIGH;
    }
  } 
  else   //si esta desactivado
  {
    digitalWrite(LEDPin, LOW); // LED OFF
    if (pirState == HIGH)  //si previamente estaba encendido
    {
      Serial.println("Sensor Desactivado");
      pirState = LOW;
    }
  }
}
