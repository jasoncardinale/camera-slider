/********************************
 * Input Parameters (min (approx), in, in, (true = right, false = left))
 ********************************/
const int printDuration = 55;
const int linDistance = 24; //max 30
const bool linDir = true;
const bool rotDir = false;
const double degree = 90; //max 360
/**************************/

const int linStepPin = 3;
const int linDirPin = 4;
const int rotStepPin = 6;
const int rotDirPin = 7;

const double distPerStep = 0.0074;
//const double distPerStep = 0.000923;
const double steps = linDistance / distPerStep;
const double durationSec = printDuration * 60;
const long linSpeed = (durationSec / steps) * 1000;
const double arcLen = (degree / 360) * 1.477;
const double rotSteps = arcLen / (linDistance / steps);
const long linRotStepRatio = steps / rotSteps;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(durationSec);
  Serial.println(steps);
  Serial.println(linSpeed);
  Serial.println(arcLen);
  Serial.println(rotSteps);
  Serial.print(linRotStepRatio);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  delay(5000);

  if(linDir) {
    digitalWrite(linDirPin, HIGH);
  } else {
    digitalWrite(linDirPin, LOW);
  }

  if(rotDir) {
    digitalWrite(rotDirPin, LOW);
  } else {
    digitalWrite(rotDirPin, HIGH);
  }
//  digitalWrite(rotDirPin, HIGH);
  for(int i = 0; i < steps; i++) {
    digitalWrite(linStepPin, HIGH);
    delayMicroseconds(400);
    digitalWrite(linStepPin, LOW);
    delayMicroseconds(400);

    if(i % linRotStepRatio == 0) {
      digitalWrite(rotStepPin, HIGH);
      delayMicroseconds(400);
      digitalWrite(rotStepPin, LOW);
      delayMicroseconds(400);
    }
    
    delay(linSpeed);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
//  digitalWrite(linDirPin, HIGH);
////  digitalWrite(rotDirPin, HIGH);
//
//  for(int i = 0; i < steps; i++) {
//    digitalWrite(stepPin, HIGH);
//    delayMicroseconds(linSpeed);
//    digitalWrite(stepPin, LOW);
//    delayMicroseconds(linSpeed);
//  }
//  //delay(1000);
//
//  digitalWrite(dirPin, LOW);
//
//  for(int i = 0; i < 500; i++) {
//    digitalWrite(stepPin, HIGH);
//    delayMicroseconds(1000);
//    digitalWrite(stepPin, LOW);
//    delayMicroseconds(1000);
//  }
//  delay(1000);  
}
