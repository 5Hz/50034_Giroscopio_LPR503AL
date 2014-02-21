
int gyroPin = 2;               //El girómetro es conectado al pin A2
float gyroVoltage = 3.3;         //El funciona a 3.3V
float gyroZeroVoltage = 1.23;   //El cero del sensor es 1.23V
float gyroSensitivity = .0333;  //La sensibilidad es 33.3mV/°/s
float rotationThreshold = 2;   //Mínimo °/s para posible ruido presente
float gyroVel = 0;
void setup() {
  //esta linea baja el voltaje de referencia de las entradas analógicas
  analogReference(EXTERNAL);
  Serial.begin (9600);
}

void loop() {
  //Esta linea convierte el valor de 0-1023 a 0-3.3V
  float gyroRate = (analogRead(gyroPin) * gyroVoltage) / 1023;
 Serial.print(gyroRate);
 Serial.print(" Volts        ");

  //Esta linea encuentra el offset entre el voltaje en reposo y el voltaje en rotación
  gyroRate -= gyroZeroVoltage;


  //Esta linea divide el offset entre la sensibilidad
  gyroRate /= gyroSensitivity;
  

  //La salida se ignora si la velocidad es muy pequeña psiblemente ruido
 if (gyroRate >= rotationThreshold || gyroRate <= -rotationThreshold) {
  gyroVel = gyroRate;
  Serial.print(gyroVel);
  Serial.println(" grados/s ");

  }
  else
  {
    Serial.println("       ");
  }
  delay(10);
}
