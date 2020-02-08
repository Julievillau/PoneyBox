int Switch = 13;
int bras = 8 ;


void setup() {
  pinMode(Switch,INPUT);
  pinMode (bras,OUTPUT);
  Serial.begin(9600);
  
  
}

void PrendLaPiece(){
  digitalWrite(bras,HIGH);
  delay(1000);
  while (digitalRead(Switch) != 1){
    Serial.println(digitalRead(Switch));
  }
   
    
  delay(3   00);
  digitalWrite(bras,LOW);
  
}
  

void loop() {
  // put your main code here, to run repeatedly:
  
  
  PrendLaPiece();
  delay(5000);
  
  
  

}
