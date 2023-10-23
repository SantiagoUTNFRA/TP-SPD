/*
A, B, C, D, E, F, G: Estos son pines asociados a los segmentos de un display de 7 segmentos.
UNIDAD y DECENA: Estos son pines que determinan cuál dígito del display de dos dígitos (unidades o decenas) está siendo utilizado.
RESET, AUMENTA, DISMINUYE: Estos son pines asociados a botones que permiten restablecer, aumentar o disminuir un contador.
*/
#define A 10
#define B 11
#define C 5
#define D 6
#define E 7
#define F 9
#define G 8

#define UNIDAD A4
#define DECENA A5

#define RESET 4
#define AUMENTA 3
#define DISMINUYE 2

int counter = 0;
int estadoResetAnterior = HIGH;
int estadoAumentarAnterior = HIGH;
int estadoDisminuirAnterior = HIGH;


void setup()
{
  initializePins();
  Serial.begin(9600);
}

void loop()
{
  handleButtons();
  displayNumber(counter);
}

/*
    Configura los pines como entradas o salidas según su función.
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
  pinMode(RESET, INPUT_PULLUP);
  pinMode(AUMENTA, INPUT_PULLUP);
  pinMode(DISMINUYE, INPUT_PULLUP);
}

/*
    Lee el estado de los botones y realiza acciones en función de su estado.
    Si se presiona el botón de RESET, restablece el contador a 0.
    Si se presiona el botón de AUMENTA, aumenta el contador.
    Si se presiona el botón de DISMINUYE, disminuye el contador.
*/
void handleButtons() 
{
  int lecturaReset = digitalRead(RESET);
  int lecturaAumentar = digitalRead(AUMENTA);
  int lecturaDisminuir = digitalRead(DISMINUYE);

  if(lecturaReset == LOW && estadoResetAnterior == HIGH)
  {
    counter = 0;
  } 
  else if(lecturaAumentar == LOW && estadoAumentarAnterior == HIGH) 
  {
	UpdateCounter(1);
  } 
  else if(lecturaDisminuir == LOW && estadoDisminuirAnterior == HIGH) 
  {
    UpdateCounter(-1);
  }

  estadoResetAnterior = lecturaReset;
  estadoAumentarAnterior = lecturaAumentar;
  estadoDisminuirAnterior = lecturaDisminuir;
}
/*
    Actualiza el valor del contador
    (change): Valor entero para aumentar o disminuir el contador.
    Modifica el contador según el valor de cambio.
    Se asegura de que el contador se encuentre en el rango de 0-99.
*/
void UpdateCounter(int change) 
{
  counter += change;
  if(counter > 99) 
  {
    counter = 0;
  }
  else if(counter < 0) 
  {
    counter = 99;
  }
}

/*
    Muestra un número en un display de dos dígitos.
    (number): Número que se quiere mostrar (0-99).
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