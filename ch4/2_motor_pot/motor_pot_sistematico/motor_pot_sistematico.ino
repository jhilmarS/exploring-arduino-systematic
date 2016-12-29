// My world program  (make this more specific)

// =================
// Constants:
const int MOTOR = 9;
const int POT = 0;

int w = 0;

void setup()
{
	pinMode(MOTOR, OUTPUT);
	pinMode(POT, INPUT);
}

// =================
// Data definitions:

// Velocidad es Natural[0, 255]
// interp. es la velocidad de giro del motor
int w1 = 0;     // sin velocidad
int w2 = 127;   // velocidad media
int w3 = 255;   // toda la velocidad

void fn_for_velocidad(int w){
    // w
}

// Template rules used:
// - atomico no-distinto: Natural[0, 255]

// =================
// Functions:

// Velocidad -> Velocidad
// start the world with ...

void loop()
{
	w = sigVelocidad();     // Velocidad -> Velocidad
    render(w);   // Velocidad -> Image
 
}

// Velocidad -> Velocidad
// produce the next lectura de velocidad de giro del motor segun la lectura en el POT
// sigVelocidad(0) // analogRead(POT);
int sigVelocidad(){
	return analogRead(POT);
}


// Velocidad -> Image
// render el motor con una velocidad adecuada. 
// render(127) // analogWrite(MOTOR, map_de_127)
void render(int w){
    return analogWrite(MOTOR, map(w, 0, 1023, 0, 255));
}



