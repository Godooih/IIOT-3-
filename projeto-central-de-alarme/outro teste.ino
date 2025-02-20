#define BUTTON_LIGA_PIN 9
#define S_INFRA_PIN 1 
#define S_JANELA_1_PIN 2
#define S_JANELA_2_PIN 3 
#define S_SALA_PIN 4
#define S_COZINHA_PIN 5
#define S_QUINTAL_PIN 6
#define S_CORREDOR_PIN 7
#define ALARME_PIN 8

bool button_liga = 0, s_infra = 0, s_janela1 = 0;
bool s_janela2 = 0, s_sala = 0, s_cozinha = 0;
bool s_quintal = 0, s_corredor = 0, alarme = 0;
bool systemOn = 0, onButtonBuffer = 0;

void setup()
{
    pinMode(BUTTON_LIGA_PIN,INPUT_PULLUP);
    pinMode(S_INFRA_PIN, INPUT_PULLUP);
    pinMode(S_JANELA_1_PIN, INPUT_PULLUP);
    pinMode(S_JANELA_2_PIN, INPUT_PULLUP);
    pinMode(S_SALA_PIN, INPUT_PULLUP);
    pinMode(S_COZINHA_PIN, INPUT_PULLUP);
    pinMode(S_QUINTAL_PIN, INPUT_PULLUP);
    pinMode(S_CORREDOR_PIN, INPUT_PULLUP);
    pinMode(ALARME_PIN, OUTPUT);
}

void loop(){

    button_liga = !digitalRead(BUTTON_LIGA_PIN);
    s_infra = !digitalRead(S_INFRA_PIN);
    s_janela1 = !digitalRead(S_JANELA_1_PIN);
    s_janela2 = !digitalRead(S_JANELA_2_PIN);
    s_sala = !digitalRead(S_SALA_PIN);
    s_cozinha = !digitalRead(S_COZINHA_PIN);
    s_quintal = !digitalRead(S_QUINTAL_PIN);
    s_corredor = !digitalRead(S_CORREDOR_PIN);
    digitalWrite(ALARME_PIN, alarme);

    if(button_liga){
        onButtonBuffer = true;
    }

    if(systemOn){
        if (!s_infra || !s_janela1 || !s_janela2 ||
            s_sala || s_cozinha || s_quintal || s_corredor){

            alarme = 1;
        } 

    }else{
        alarme = 0;
    }
}
