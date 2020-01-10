int deux = 2 ;
int un = 3 ;
//.....

int vieu2 =1;
int vieu1 =1;
//......

int total =0 ;

void setup() {
  

  
  pinMode (deux,INPUT);
  pinMode (un,INPUT); 
  //......
  
  Serial.begin(9600);


}

void loop() {
  
  if (vieu2==1 && digitalRead(deux)==0){
    total+=2; }

  if (vieu1==1 && digitalRead(un)==0){
      total+=1; }

  //.......

  
  vieu2 = digitalRead(deux);
  vieu1 = digitalRead(un);
  //.......

  
  Serial.println(total);

}
