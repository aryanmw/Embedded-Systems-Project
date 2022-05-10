/*
Code by Satyamurti, Aryan, Advai, Harsh, Manav
*/

bool isLowWaterInTank, isLowWaterInContainer;
void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT); 
  pinMode(6,INPUT);
  pinMode(7, INPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600);
}


void loop() {
    float innerTankSensor , outContainerSensor, pirSensorStatus;
    innerTankSensor = analogRead(A0);
    outContainerSensor = analogRead(A1);
    pirSensorStatus = digitalRead(2);
    
    isLowWaterInTank = innerTankSensor < 300;
    isLowWaterInContainer = outContainerSensor < 30; 

    if(isLowWaterInContainer ){
        digitalWrite(3, HIGH);
    }
    if(isLowWaterInTank){
        digitalWrite(7, LOW);
        digitalWrite(6, HIGH);
    }
    if(pirSensorStatus == HIGH){
    
        Serial.println("Bird has been detected");
        Serial.println("Fill water in the outer container");
        digitalWrite(3,HIGH);
    }else{
        Serial.println("There is no bird");
        digitalWrite(3,LOW);
    }
  
}