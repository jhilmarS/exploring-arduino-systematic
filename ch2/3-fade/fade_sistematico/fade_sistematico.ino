// Un LED que toma varios tonos de iluminación.

// =================
// Constants:

const int LED=9;    //Blue LED on Pin 9
boolean BUTTON = 2;
int tonoLED;
boolean ledOn = false;

int SPEED = 5; 

int cambiarColor(int* tonoLED, int* SPEED);
void render(int* tonoLED);
int onKey(int* tonoLED, boolean* BUTTON);

void setup()
{
  pinMode (LED, OUTPUT);   //Set Blue LED as Output
  pinMode (BUTTON, INPUT);
}

// =================
// Data definitions:

// LED es Natural[0, 255]
// interp. el tono de color del LED 
boolean L0 = 0;    // apagado
boolean L1 = 127;  // tono de color medio
boolean L2 = 255;  // blanco

int fnForLED(int led)
{
  return led;  
}

// =================
// Functions:

// LED -> LED
// start the world with ...

void loop()
{
   cambiarColor(&tonoLED, &SPEED);     // LED -> LED
   render(&tonoLED);           // LED -> Image
   onKey(&tonoLED, &BUTTON);   // LED keyEvent -> LED
}
// LED -> LED
// produce the next color del LED, cambiando SPEDD duty cycle en sus tres pines de salida.
// cambiarColor(0)  // return SPEED + 0;
// cambiarColor(256)  // return 256 - SPEED;
int cambiarColor(int* tonoLED, int* SPEED)
{  
    if(0<= *tonoLED && *tonoLED <= 255){
        *tonoLED += *SPEED;            
    }else {
        *tonoLED -= *SPEED;
        *SPEED = -1 * (*SPEED);
    }
    return *tonoLED;   
}
 
// LED -> Image
// render el color del led con el color de led establecido. 
// render(0) // analogWrite(LED, 0);
void render(int *tonoLED)
{
  delay(100);
  analogWrite(LED, *tonoLED);
}

// LED keyEvent -> LED
// reset LED a duty cycle a cero cuando el boton este presionado.
// onKey(127, HIGH); // tonoLED = 0;
int onKey(int* tonoLED, boolean* BUTTON){
   if(digitalRead(*BUTTON) == HIGH){
      *tonoLED = 0;
      return *tonoLED;
   } else {
      return *tonoLED;
   }
   
}



