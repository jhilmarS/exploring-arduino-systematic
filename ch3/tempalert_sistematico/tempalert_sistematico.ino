// Tres led que cambian de color segun la temperatura medida.

// =================
// Constants:
const int BLED=11;          //Blue LED on pin 9
const int GLED=10;         //Green LED on pin 10
const int RLED=9;         //Red LED on pin 11
const int TEMP=0;          //Temp Sensor is on pin A0
const int LIMITE_INFERIOR=139; //Lower Threshold
const int LIMITE_SUPERIOR=147; //Upper Threshold
const int TIME = 300;

int t = 0;

void setup()
{
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  Serial.begin(9600);
}
// =================
// Data definitions:

// Temp is uno de:
// - Number[< 18]
// - Number[18, 22]
// - Number[> 22]
// interp. Temperatura en ºC donde:
//   Number[< 18]    es considerado frio
//   Number[18, 22]  es considerado aceptable
//   Number[> 22]    es considerado caliente
int T1 = 20;
int T2 = 30;

void fnForTemp(int t)
{
  if(t < 18){
    // t;
  }
  else if(18 <= t && t <= 22){
    // t;
  }
  else{
    // t;
  }
}

// Template rules used:
//  uno de: 3 casos
//  atomico no-distinto: Number[< 18]
//  atomico no-distinto: Number[18, 22]
//  atomico no-distinto: Number[> 22]
 

// =================
// Functions:

void loop()
{
// Temp -> Temp
// start the world with ...
  Serial.println(analogRead(TEMP));
  siguienteTemp(&t);     // Temp -> Temp
  render(&t);            // Temp -> Image
}

// Temp -> Temp
// produce the next 
// siguienteTemp(14) // return analogRead(

int siguienteTemp(int* t)
{
  *t = analogRead(TEMP);
  return *t;
}

// Temp -> Image
// render ... 
// !!!

void render(int *t)
{
  if(*t < LIMITE_INFERIOR){
    digitalWrite(BLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(RLED, LOW);
  }
  else if(LIMITE_INFERIOR <= *t && *t <= LIMITE_SUPERIOR){
    digitalWrite(BLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(RLED, LOW);
  }
  else{
    digitalWrite(BLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(RLED, HIGH);
  }
} 
