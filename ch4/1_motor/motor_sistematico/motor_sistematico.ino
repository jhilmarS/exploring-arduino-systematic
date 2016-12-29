// My world program  (make this more specific)

// =================
// Constants:
const int MOTOR = 9;

int r = 0;
int SPEED = 1;

void setup()
{
	pinMode(MOTOR, OUTPUT);
}
// =================
// Data definitions:

// Rotacion es integer[0, 255]
// interp. giro del motor
int r1 = 0;    // inicio
int r2 = 127;  // medio
int r3 = 255;  // final 

void fn_for_rotacion(int r){
	if(0 <= r && r <= 255){
	    // r
	} else {
	    // r
	}
}

// Template Rules used:
// - atomico no-distinto: integer[0, 255]

// =================
// Functions:

// Rotacion -> Rotacion
// start the world with ...

void loop()
{
	r = sigRotacion(r);     // Rotacion -> Rotacion
    render(r);   // Rotacion -> Image
}

// Rotacion -> Rotacion
// produce the next Rotacion en el sentido de giro correcto.
// sigRotacion(-1) // r = 0; 
int sigRotacion(int r){
	if(0 > r){
	    SPEED = -1 * SPEED;
	} else if (r > 255){
	    SPEED = -1 * SPEED;
	}
	return r + SPEED;
}

// Rotacion -> Image
// render el giro del motor. 
// !!!

void render(int r){
	if(0 <= r && r <= 255){
	    analogWrite(MOTOR, r);
	}
}



