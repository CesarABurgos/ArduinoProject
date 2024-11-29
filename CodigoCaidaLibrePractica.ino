// Pines de los sensores (Cambia el numero por el pin que utilizarás)
const int sensor1 = 5; 
const int sensor2 = 4; 
const int sensor3 = 14;
const int reinicio = 12; //Con este pin se reiniciará el código para tomar una nueva medida

// Variables para almacenar los tiempos (Almacena el momento cuando un sensor detecta algo)
unsigned long Tiempo1 = 0;
unsigned long Tiempo2 = 0;
unsigned long Tiempo3 = 0;

// Estados de los sensores (Almacena si el sensor detecto algo)
bool activado1 = false;
bool activado2 = false;
bool activado3 = false;

void setup() {
  // Configurar pines de los sensores
  pinMode(sensor1Pin, INPUT);
  pinMode(sensor2Pin, INPUT);
  pinMode(sensor3Pin, INPUT);
  pinMode(sensor4Pin, INPUT);

  // Inicializar comunicación serie
  Serial.begin(115200);
}

void loop() {
  // Lee el estado de los sensores
  int sensor1State = digitalRead(sensor1);
  int sensor2State = digitalRead(sensor2);
  int sensor3State = digitalRead(sensor3);
  int sensor4State = digitalRead(sensor4);

  if (sensor1State == LOW && !activado1) {
    sensorTime1 = millis(); // Guardar el tiempo de inicio 
    Serial.println("1. " + String(sensorTime1));
    activado1 = true;
  }

  // Si el sensor 2 detecta algo y el timer está corriendo
  if (sensor2State == LOW && activado1 && !activado2) {
    sensorTime2 = millis(); // Guarda cuando el objeto pasa enfrente del segundo sensor
    Serial.println("2. " + String(sensorTime2));
    activado2 = true;
  }

  // Si el sensor 3 detecta algo y el timer está corriendo
  if (sensor3State == LOW &&  activado2 && !activado3) {
    sensorTime3 = millis(); // Guarda cuando el objeto pasa enfrente del tercer sensor
    Serial.println("3. " + String(sensorTime3));
    activado3=true;
  
 
  // Si detecta la pulsación de un botón de reiniciará el codigo para tomar una nueva
  if (sensor4State == LOW) { 
      ESP.reset();
  }

  

}