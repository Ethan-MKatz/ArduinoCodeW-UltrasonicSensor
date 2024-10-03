#define echoPin 2
#define trigPin 3
#define leftMotorForward = 5;
#define leftMotorBackward = 6;
#define rightMotorForward = 9;
#define rightMotorBackward = 10;

long duration; 
int distance; 

int long_dst = -4;
int lat_dst = -6;

int absoluteLong = abs(long_dst);
int absoluteLat = abs(lat_dst);

char myString[];

void setup()
{
    pinMode(trigPin,OUTPUT); 
    pinMode(echoPin, INPUT); 

    pinMode(leftMotorForward, OUTPUT);
    pinMode(leftMotorBackward, OUTPUT);
    pinMode(rightMotorForward, OUTPUT);
    pinMode(rightMotorBackward, OUTPUT);

    if (long_dst > 0){
        myString[] = "N";
    } else {
      myString[] = "S"
    }
    Serial.begin(9600);
    delay(500);
    
}

void loop()
{
    if (long_dst == 0 && lat_dst != 0) {
      if (absoluteLat > 0){
        turnRight();
        myString[] = "E";
      }else {
        turnLeft();
        myString[] = "W";
      }
    }

    if (lat_dst == 0 && long_dst != 0) {
      if (absoluteLong > 0){
        turnRight();
        myString[] = "N";
      }else {
        turnLeft();
        myString[] = "S";
      }
    }

    if (long_dst != 0 && (myString[] = "N" || myString[] = "S")){
      if(myString[] == "N"){
        moveForward();
      }else{
        moveBackward();
      }
      absoluteLong -= 1
    }

    if (lat_dst != 0 && (myString[] = "E" || myString[] = "W")){
      if(myString[] == "E"){
        moveForward();
      }else{
        moveBackward();
      }
      absoluteLat -= 1;
    }

    distance = Distance();

    if(distance < 20.32) {
      newDirect();
      int i = 0;
      while(i == 0) {
        if(myString[] == "N" || myString[] == "W"){
          moveForward();
          delay(100);
          if(myString[] == "N"){
            absoluteLong -= 1;
          }else{
            absoluteLat -= 1;
          }
        }else{
          moveBackward();
          delay(100);
          if(myString[] == "S"){
            absoluteLong -= 1;
          }else{
            absoluteLat -= 1;
          }
        }
        newDirect();
        distance = Distance();
        if(distance > 20.32){
          i = 1;
        }else {
          newDirect();
        }
      }
    }

    delay(100);
}

void moveForward() {
    digitalWrite(leftMotorForward, HIGH);
    digitalWrite(leftMotorBackward, LOW);
    digitalWrite(rightMotorForward, HIGH);
    digitalWrite(rightMotorBackward, LOW);
}

void moveBackward() {
    digitalWrite(leftMotorForward, LOW);
    digitalWrite(leftMotorBackward, HIGH);
    digitalWrite(rightMotorForward, LOW);
    digitalWrite(rightMotorBackward, HIGH);
}

void turnLeft() {
    digitalWrite(leftMotorForward, LOW);
    digitalWrite(leftMotorBackward, HIGH);
    digitalWrite(rightMotorForward, HIGH);
    digitalWrite(rightMotorBackward, LOW);
    delay(500); 
    stopMotors();
}

void turnRight() {
    digitalWrite(leftMotorForward, HIGH);
    digitalWrite(leftMotorBackward, LOW);
    digitalWrite(rightMotorForward, LOW);
    digitalWrite(rightMotorBackward, HIGH);
    delay(500); 
    stopMotors();
}

void stopMotors() {
    digitalWrite(leftMotorForward, LOW);
    digitalWrite(leftMotorBackward, LOW);
    digitalWrite(rightMotorForward, LOW);
    digitalWrite(rightMotorBackward, LOW);
}

int Distance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2); 

    digitalWrite(
        trigPin,
        HIGH);
    delayMicroseconds(
        10);

    digitalWrite(trigPin,LOW);

    duration = pulseIn(echoPin, HIGH);
    distance
        = duration * 0.0344 / 2;
  } 

void newDirect() {
    if(myString[] == "N" || myString[] == "S"){
      if(lat_dst == 0 || lat_dst > 0){
        myString[] = "E";
        turnRight();
      }else {
        myString[] = "W";
        turnLeft();
      }
    }else{
      if(long_dst == 0 || long_dst > 0){
        myString[] = "N";
        turnRight();
      }else {
        myString[] = "S";
        turnLeft();
      }
    }
}
