#define A 10
#define B 11
#define C 5
#define D 6
#define E 7
#define F 9
#define G 8

#define UNIDAD A4
#define DECENA A5
#define INTERRUPTOR 4
#define AUMENTA 3
#define DISMINUYE 2
#define SENSOR A0

int contador = 0;
int estadoAumentarAnterior = HIGH;
int estadoDisminuirAnterior = HIGH;
int temperatura;
int lecturaSensor;

void setup() 
{
  initializePins();
  Serial.begin(9600);
}

void loop() 
{
  int lecturaInterruptor = digitalRead(INTERRUPTOR); 
  switch(lecturaInterruptor) 
  {
    case 0:
      handleButtons();
      break;
    case 1:
      handlePrimeButtons();
      break;
  }
  displayNumber(contador);
  Serial.println(temperatura);
}

/*
    Esta función inicializa y configura los pines del display y los pulsadores como entradas o salidas según su función.
*/
void initializePins() 
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(UNIDAD, OUTPUT);
  pinMode(DECENA, OUTPUT);
  pinMode(INTERRUPTOR, INPUT);
  pinMode(AUMENTA, INPUT_PULLUP);
  pinMode(DISMINUYE, INPUT_PULLUP);
  Serial.begin(9600);
}

/*
    Esta función lee el estado de los botones y realiza acciones en función de su estado. 
    Si se presiona el boton AUMENTA, aumenta el contador. 
    Si se presiona el boton DISMINUYE, disminuye el contador.
*/
void handleButtons() 
{
  int lecturaAumentar = digitalRead(AUMENTA);
  int lecturaDisminuir = digitalRead(DISMINUYE);
  lecturaSensor = analogRead(SENSOR);
  temperatura = map(lecturaSensor, 20, 358, -40, 125);

  if(lecturaAumentar == LOW && estadoAumentarAnterior == HIGH) 
  {
    updateCounter(1);
  } 
  else if(lecturaDisminuir == LOW && estadoDisminuirAnterior == HIGH) 
  {
    updateCounter(-1);
  }

  estadoAumentarAnterior = lecturaAumentar;
  estadoDisminuirAnterior = lecturaDisminuir;
}

/*
    Esta función lee el estado de los botones y realiza acciones en función de su estado. 
    Si se presiona el boton AUMENTA, aumenta el contador en números primos. 
    Si se presiona el boton DISMINUYE, disminuye el contador en números primos.
*/
void handlePrimeButtons() 
{
  int lecturaAumentar = digitalRead(AUMENTA);
  int lecturaDisminuir = digitalRead(DISMINUYE);
  lecturaSensor = analogRead(SENSOR);
  temperatura = map(lecturaSensor, 20, 358, -40, 125);

  if(lecturaAumentar == LOW && estadoAumentarAnterior == HIGH) 
  {
    do 
    {
      updateCounter(1);
    }while(!isPrime(contador));
  } 
  else if(lecturaDisminuir == LOW && estadoDisminuirAnterior == HIGH) 
  {
    do 
    {
      updateCounter(-1);
    } while(!isPrime(contador));
  }

  estadoAumentarAnterior = lecturaAumentar;
  estadoDisminuirAnterior = lecturaDisminuir;
}

/*
    Esta función verifica si un número dado es primo o no.
    number: El número que se va a comprobar si es primo.
    Retorna 1 si el número es primo, 0 si no lo es.
*/
int isPrime(int number) 
{
  if(number <= 1) 
  {
    return 0;
  }
  
  for(int i = 2; i * i <= number; i++) 
  {
    if(number % i == 0) 
    {
      return 0;
    }
  }
  return 1;
}

/*
    Actualiza el valor del contador.
    cambio: Valor entero para aumentar o disminuir el contador.
    Modifica el contador según el valor de cambio.
    Se asegura de que el contador se encuentre en el rango de 0-99.
*/
void updateCounter(int change) 
{
  contador += change;
  if(contador > 99) 
  {
    contador = 0;
  } 
  else if(contador < 0) 
  {
    contador = 99;
  }
}

/*
    Muestra un número en un display de dos dígitos.
    number: Número que se quiere mostrar (0-99).
    Divide el número en unidades y decenas.
    Usa la función printDigit para mostrar cada dígito en el display.
*/
void displayNumber(int number) 
{
  int unidades = number % 10;
  int decenas = number / 10;

  digitalWrite(DECENA, HIGH);
  printDigit(unidades);
  digitalWrite(UNIDAD, LOW);
  delay(1);

  digitalWrite(UNIDAD, HIGH);
  printDigit(decenas);
  digitalWrite(DECENA, LOW);
  delay(1);
}

/*
    Muestra un dígito en un display de 7 segmentos.
    (digit): Dígito que se quiere mostrar (0-9).
    Configura los segmentos del display según el dígito que se quiere mostrar.
*/
void printDigit(int digit)
{
  switch (digit)
  {
    case 0:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, LOW);
      break;

    case 1:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;

    case 2:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, HIGH);
      break;

    case 3:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, HIGH);
      break;

    case 4:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;

    case 5:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, LOW);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;

    case 6:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;

    case 7:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;

    case 8:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;

    case 9:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, LOW);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
  }
}