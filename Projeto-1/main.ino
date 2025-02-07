#define BUTTON_PIN 2
#define LED_PIN 3

bool button = 0, led = 0;
//bool/digital: 0/1, false/true, LOW/HIGH

//Configurações
void setup()
{
    // dizendo como o Pino vai funcionar
    pinMode(BUTTON_PIN,INPUT_PULLUP);
    pinMode(LED_PIN,OUTPUT);
}

//Logica
void loop()
{
    // I/O's
    button = !digitalRead(BUTTON_PIN);
    digitalWrite(LED_PIN, led);
    //botão recebe o sinal do botão 

    if(button == HIGH){//se o botão tiver 1 o led vai ligar se não ele desliga
        led = 1;
    }
    else{
        led = 0;
    }
}