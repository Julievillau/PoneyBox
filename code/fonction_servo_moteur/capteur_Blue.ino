long microsNow;

int deux = 2 ;
int un = 3 ;
int cinquante =4;
int vingt =7;
int dix = 8;
int cinq = 9;
//bon

int vieu2 =0;
int vieu1 =0;
int vieu50 =0;
int vieu20=0;
int vieu10=0;
int vieu5=0;
//bon

double total =0.0 ;
int tot2 =0 ;
int tot1 =0 ;
int tot50 =0;
int tot20 =0;
int tot10=0;
int tot5=0;
//bon

// bluetooth
#include<SoftwareSerial.h>
#define RX 5
#define TX 6
SoftwareSerial BlueT(RX,TX);

char changement;


void setup() {
  
  pinMode (deux,INPUT);
  pinMode (un,INPUT); 
  pinMode (cinquante,INPUT);
  pinMode (vingt,INPUT);
  pinMode (dix,INPUT);
  pinMode (cinq,INPUT);
  //bon
  
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
    total=0.0;
    tot1=0;
    tot2=0;
    tot50 =0;
    tot20 =0;
    tot10=0;
    tot5=0;
    //bon
  }

  
  if (changement=='D'){
    tot2-=1;
    total-=2.0;}
  if (changement=='U'){
    tot1-=1;
    total-=1.0;}
  if (changement=='C'){
    tot50-=1;
    total-=0.50;}
  if (changement=='V'){
    tot20-=1;
    total-=0.20;}
  if (changement=='d'){
    tot10-=1;
    total-=0.10;}
  if (changement=='c'){
    tot5-=1;
    total-=0.05;}

  //bon

  
  
  
  if (vieu2==1 && digitalRead(deux)==0){
    total+=2;
    tot2+=1;}
  if (vieu1==1 && digitalRead(un)==0){
      total+=1;
      tot1+=1;}      
  if (vieu50==1 && digitalRead(cinquante)==0){
      total+=0.50;
      tot50+=1;}
  if (vieu20==1 && digitalRead(vingt)==0){
      total+=0.20;
      tot20+=1;}
  if (vieu10==1 && digitalRead(dix)==0){
      total+=0.10;
      tot10+=1;}
  if (vieu5==1 && digitalRead(cinq)==0){
      total+=0.05;
      tot5+=1;}

  //bon

  vieu2 = digitalRead(deux);
  vieu1 = digitalRead(un);
  vieu50 = digitalRead(cinquante);
  vieu20 = digitalRead(vingt);
  vieu10 = digitalRead(dix);
  vieu5 = digitalRead(cinq);
  //bon

  
  

  
  BlueT.write("*&");
  BlueT.print(total);
  BlueT.write("*");
  //Serial.println(total);

  BlueT.write("*2");
  BlueT.print(tot2);
  BlueT.write("*");
  Serial.println(tot2);

  BlueT.write("*1");
  BlueT.print(tot1);
  BlueT.write("*");
  //Serial.println(tot1);

  BlueT.write("*5");
  BlueT.print(tot50);
  BlueT.write("*");

  BlueT.write("*v");
  BlueT.print(tot20);
  BlueT.write("*");

  BlueT.write("*d");
  BlueT.print(tot10);
  BlueT.write("*");

  BlueT.write("*c");
  BlueT.print(tot5);
  BlueT.write("*");
  
  while(micros() - microsNow < 38400);
  microsNow = micros();
  //Serial.println(microsNow);

}
  // put your main code here, to run repeatedly:
