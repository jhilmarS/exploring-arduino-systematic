// Un led que cambia su nivel de brillo segun la Luz medida.

// =================
// Constants:
const int BLED=11;           // Blue LED on pin 11
const int LUZ=0;             // Luz Sensor is on pin A0
const int LUZ_MIN=200;       // Lower Threshold
const int LUZ_MAX=900;       // Upper Threshold

int lz = 0;

void setup()
{
  pinMode(BLED, OUTPUT);
  Serial.begin(9600);
}
// =================
// Data definitions:

// Luz es Natural[200, 900]
// interp. Luz que varia entre este rango de nivel de brillo de luz.
int L1 = 200; // luz minima
int L2 = 550; // luz media
int L3 = 900; // luz maxima

void fnForLuz(int *lz)
{
   *lz = map(*lz, LUZ_MIN, LUZ_MAX, 255, 0);
   *lz = constrain(*lz, 0, 255);
  // *lz
}

// Luzlate rules used:
//  atomico no-distinto: Natural[200, 900]

// =================
// Functions:

void loop()
{
// Luz -> Luz
// start the world with ...
  Serial.println(analogRead(LUZ));
  siguienteLuz(&lz);     // Luz -> Luz
  render(&lz);            // Luz -> Image
}

// Luz -> Luz
// produce the next 
// siguienteLuz(200) // return analogRead(200)

int siguienteLuz(int* lz)
{
  *lz = analogRead(LUZ);
  return *lz;
}

// Luz -> Image
// render el nivel de brillo en el led
// render(550) // return 
void render(int *lz)
{
  *lz = map(*lz, LUZ_MIN, LUZ_MAX, 255, 0);
  *lz = constrain(*lz, 0, 255);
  analogWrite(BLED, *lz);
} 