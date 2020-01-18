long microsNow;

int deux = 2 ;
int un = 3 ;
//.....

int vieu2 =1;
int vieu1 =1;
//......

int total =0 ;
int tot2 =0 ;
int tot1 =0 ;
//........

// bluetooth
#include<SoftwareSerial.h>
#define RX 5
#define TX 6
SoftwareSerial BlueT(RX,TX);

char changement;


void setup() {
  
  pinMode (deux,INPUT);
  pinMode (un,INPUT); 
  //......
  
  Serial.begin(9600);
  delay(500);
  Serial.println("pret!");
  BlueT.begin(9600);
  delay(500);
  
  microsNow = micros();

}

void loop() {
  
  changement=char(BlueT.read());
  
  if (changement=='o'){
    total=0;
    tot1=0;
    tot2=0;
    //..........
  }
  if (changement=='D'){
    tot2-=1;
    total-=2;}
  if (changement=='U'){
    tot1-=1;
    total-=1;}
  
  
  
  if (vieu2==1 && digitalRead(deux)==0){
    total+=2;
    tot2+=1;}

  if (vieu1==1 && digitalRead(un)==0){
      total+=1;
      tot1+=1;}

  //.......

  
  vieu2 = digitalRead(deux);
  vieu1 = digitalRead(un);
  //.......

  
  BlueT.write("*&");
  BlueT.print(total);
  BlueT.write("*");
  //Serial.println(total);

  BlueT.write("*2");
  BlueT.print(tot2);
  BlueT.write("*");
  //Serial.println(tot2);

  BlueT.write("*1");
  BlueT.print(tot1);
  BlueT.write("*");
  //Serial.println(tot1);
  
  while(micros() - microsNow < 38400);
  microsNow = micros();
  Serial.println(microsNow);

}
  // put your main code here, to run repeatedly:

}
