#define DEBUG 0

//sensor ultrasonico izquierdo//
const int echoPin1 = 7; // Echo Pin
const int trigPin1 = 8; // Trig Pin
long duracion1;
long distancia1; // Variables utilizadas para calcular la distancia de los objetos detectados
//sensor ultrasonido derecho //
const int echoPin2 = 10; // Echo Pin
const int trigPin2 = 9;  // Trig Pin
long duracion2;
long distancia2; // Variables utilizadas para calcular la distancia de los objetos detectados
bool detectado1;
bool detectado2;

////////////////
///motores/////
//////////////
int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;

int cny1 = 0;
int cny2 = 0;
//int cny3;
////////////////////////////////////////
/////// ULTRA_SONIDO_1/////////////////
//////////////////////////////////////
void Ultrasonic() {// El siguiente ciclo trigPin/echoPin1 se utiliza para determinar la distancia del objeto más cercano haciendo rebotar ondas sonoras en él.
    digitalWrite(trigPin1,HIGH); // Establece trigPin en ALTA durante 10 micro segundos
    delayMicroseconds(10); 
    digitalWrite(trigPin1, LOW); 

    duracion1 = pulseIn(echoPin1, HIGH); //Lee el echoPin1, devuelve el tiempo de viaje de la onda de sonido en microsegundos
    distancia1 = duracion1/59; //Calcule la distancia en cm en función de la velocidad del sonido en el aire en STP.

    digitalWrite(trigPin2 ,HIGH); // Establece trigPin en ALTA durante 10 micro segundos
    delayMicroseconds(10); 
    digitalWrite(trigPin2 , LOW); 

    duracion2 = pulseIn(echoPin2, HIGH); //Lee el echoPin2, devuelve el tiempo de viaje de la onda de sonido en microsegundos
    distancia2 = duracion2/59; //Calcule la distancia en cm en función de la velocidad del sonido en el aire en STP

    detectado1 = distancia1 < 10 ;
    detectado2 = distancia2 < 10 ;
}
/*
void Motor(int pina, int pinb, int estado)
{
  if(estado == 1)
  {
    digitalWrite(pina,1);
    digitalWrite(pinb,0);
  }
  else if(estado == 0)
  {
    digitalWrite(pina,0);
    digitalWrite(pinb,1);  
  }
  else if(estado == 2)
  {
    digitalWrite(pina,0);
    digitalWrite(pinb,0);
  }
}
*/
void Adelante() {
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
}

void Izquierda() {
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
}

void Derecha() {
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
}

void Atras() {
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
}

void Nada() {
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 0);
}

void Cny70() {
 cny1 = analogRead(A0);  
 cny2 = analogRead(A1);
 //cny3 = analogRead(A2);
  if (cny1 <= 500)
  {
    Atras();
    delay(1000);
  }
  if (cny2 <= 500)
  {
    Atras();
    delay(1000);
  }
 /* if (cny3 <= 500)
  {
    Adelante();
    delay(1000);
  }*/
}

void ControlMovimiento(){
  if (detectado1  &&  detectado2) {
    Adelante();
  }
  else if (detectado1) 
  {
    Derecha();    
  }
  else if (detectado2)
  {
    Izquierda();
  }
  else {
    Nada();
  }
}

void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin1,OUTPUT);
  pinMode(echoPin1,INPUT);
  digitalWrite(trigPin1, LOW);//Inicializamos el pin con 0
  pinMode(trigPin2,OUTPUT);
  pinMode(echoPin2,INPUT);
  digitalWrite(trigPin2, LOW);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  //pinMode(A2, INPUT);
}

void loop() 
{
  Ultrasonic();
  Cny70();
  ControlMovimiento();
}


/*int factorialComun(int n){
  int resultado;
  if(n == 0){
    resultado = 1; 
  }
  else {
    for(int i = 1; i <= n; i++){
      resultado *= n;
    }
  }
  
  return resultado;
}


int factorialRecursiva(int n){
  int resultado;
  if(n == 0){
    resultado = 1; 
  }
  else {
    resultado = n * factorialRecursiva(n-1);
  }

  return resultado;
}
*/
/*int factorialComun(int n){
  int resultado;
  if(n == 0){
    resultado = 1; 
  }
  else {
    for(int i = 1; i <= n; i++){
      resultado *= n;
    }
  }
  
  return resultado;
}


int factorialRecursiva(int n){
  int resultado;
  if(n == 0){
    resultado = 1; 
  }
  else {
    resultado = n * factorialRecursiva(n-1);
  }

  return resultado;
}
*/