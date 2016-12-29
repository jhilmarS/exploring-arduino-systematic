// Programa que utiliza un puente h y un potenciomentro para controlar la 
// velocidad y direccion de giro de un motor.

// =================
// Constants:

const int POT = 0; //Potenciometro en Pin Analogo 0
const int EN = 9;  //Habilitador de medio puente 1
const int MC1=3;   //Motor Control 1
const int MC2=2;   //Motor Control 2

int m = 512;

void setup()
{
	pinMode(POT, INPUT);
	pinMode(EN, OUTPUT);
    pinMode(MC1, OUTPUT);
    pinMode(MC2, OUTPUT);
    pararMotor(); //Initialize with motor stopped
}
// =================
// Data definitions:

// Motor es uno de;
//				Natural[0, 462]
//              Number = 512
//              Natural[562, 1023]
// interp. es la direccion y velocidad de giro del motor 
//				Natural[0, 462]     es velocidad y giro en reversa
//              Number = 512        es motor detenido
//              Natural[562, 1023]  es velocidad y giro en directo

int m1 = 0;
int m2 = 512;
int m3 = 1023;

/*
int fn_for_motor(int m){
	if( m > 0 && m < 462){
	    return m;
	} else if( m > 562 && m < 1024){
	    return m;
	} else {
		return m;
	}
}
*/

// Template rules used:
// - uno de 3 casos:
// - atomico no-distinto: Natural[0, 49]
// - atomico distinto: Number = 50
// - atomico no-distinto: Natural[51, 100]

// =================
// Functions:

// Motor -> Motor
// start the world with ...

void loop()
{

  m = sigLectura(m);     // Motor -> Motor
  render(m);         // Motor -> Image
  //(stop-when ...)      // Motor -> Boolean
 
}

// Motor -> Motor
// produce the next ...
// !!!
int sigLectura(int m)
{
	m = analogRead(POT);
	return m;
}

// Motor -> Image
// render ... 
// !!!
void render(int m)
{
	if( m >= 0 && m < 462)
	{		
		reversa(map(m, 461, 0, 0, 255));    
	} 
	else if( m > 561 && m < 1024)
	{
	    directo(map(m, 563, 1023, 0, 255));
	} 
	else 
	{		
		pararMotor();	
	}
}

// Integer -> Imagen
// configurar las salidas para girar el motor en reversa.
// !!!
void reversa (int rate)
{
	digitalWrite(EN, LOW);
	digitalWrite(MC1, LOW);
	digitalWrite(MC2, HIGH);
	analogWrite(EN, rate);
}

// Integer -> Imagen
// configurar las salidas para girar el motor en directo.
// !!!
void directo(int rate)
{
	digitalWrite(EN, LOW);
	digitalWrite(MC1, HIGH);
	digitalWrite(MC2, LOW);
	analogWrite(EN, rate);
}

// Image -> Image
// detiene el motor
// !!!
void pararMotor()
{
	digitalWrite(EN, LOW);
	digitalWrite(MC1, LOW);
	digitalWrite(MC2, LOW);
	analogWrite(EN, HIGH);
}