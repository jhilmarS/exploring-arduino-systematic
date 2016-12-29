// (require 2htdp/image)
// (require 2htdp/universe)

// Un LED RGB que toma varios colores.

// =================
// Constants:

const int BLED=9;    //Blue LED on Pin 9
const int GLED=10;   //Green LED on Pin 10
const int RLED=11;   //Red LED on Pin 11
const int BUTTON=2;    //The Button is connected to pin 2

boolean lastButton = LOW;    //Last Button State
boolean currentButton = LOW; //Current Button State
int ledMode = 0;             //Cycle between LED states

void setup()
{
  pinMode (BLED, OUTPUT);   //Set Blue LED as Output
  pinMode (GLED, OUTPUT);   //Set Green LED as Output
  pinMode (RLED, OUTPUT);   //Set Red LED as Output
  pinMode (BUTTON, INPUT);  //Set button as input (not required)
}

// =================
// Data definitions:

// Button es boolean
// interp. el estado del boton (ON or OFF)
boolean b1 = HIGH;
boolean b2 = LOW;

boolean fnForBoton(boolean b)
{
  return b;  
}

// LED es Natural[0, 255]
// interp. el tono de color del LED 
boolean L0 = 0;    // apagado
boolean L1 = 127;  // tono de color medio
boolean L2 = 255;  // blanco

int fnForLED(int l)
{
  return l;  
}

// WS is ... (give WS a better name)



// =================
// Functions:

// LED -> LED
// start the world with ...

void loop()
{
/*
(define (main l)
  (big-bang l                   ; WS
            
*/
cambiarColor(ledMode);     // l -> l
render(ledMode);           // l -> Image

}
// LED -> LED
// produce the next color del LED, cambiando el duty cycle en sus tres pines de salida.
// !!! 
int cambiarColor(int l)
{
  return l+1;  
}
 
// LED -> Image
// render el color del led con el color de led establecido. 
// !!!
void render(int l)
{
  delay(100);
  return analogWrite(RLED, l);
}



  



