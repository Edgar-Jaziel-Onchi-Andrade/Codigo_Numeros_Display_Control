// Pin donde se conectara el Potenciómetro
#define Pot A0

// Pines del display conectados al Arduino
#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8

//Definimos los numeros
int numeros[10][7] = {
  {HIGH, HIGH, HIGH, HIGH, HIGH, LOW, HIGH},   // 0
  {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW},       // 1
  {HIGH, HIGH, LOW, HIGH, HIGH, HIGH, LOW},    // 2
  {HIGH, HIGH, HIGH, HIGH, LOW, HIGH, LOW},    // 3
  {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH},     // 4
  {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH},    // 5
  {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH},   // 6
  {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW},      // 7
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},  // 8
  {HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH}    // 9
};

void setup() {
  // Configurar los pines del display como salida
  for (int i = A; i <= G; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // Leer el valor del potenciómetro
  int potValue = analogRead(Pot);
  int numero = map(potValue, 0, 1023, 0, 9);

  // Mostrar el número en el display
  mostrarNumero(numero);
  delay(100);
}

void mostrarNumero(int numero) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(A + i, numeros[numero][i]);
  }
}
