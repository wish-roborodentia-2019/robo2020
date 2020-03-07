const int E1 = 3; ///<Motor1 Speed
const int E2 = 11;///<Motor2 Speed
const int E3 = 5; ///<Motor3 Speed
const int E4 = 6; ///<Motor4 Speed

const int M1 = 4; ///<Motor1 Direction
const int M2 = 12;///<Motor2 Direction
const int M3 = 8; ///<Motor3 Direction
const int M4 = 7; ///<Motor4 Direction



void setup() {
  Serial.begin(9600);

  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A0, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
}

void M1_advance(char Speed) ///<Motor1 Advance
{
 digitalWrite(M1,LOW);
 analogWrite(E1,Speed);
}
void M2_advance(char Speed) ///<Motor2 Advance
{
 digitalWrite(M2,LOW);
 analogWrite(E2,Speed);
}
void M3_advance(char Speed) ///<Motor3 Advance
{
 digitalWrite(M3,LOW);
 analogWrite(E3,Speed);
}
void M4_advance(char Speed) ///<Motor4 Advance
{
 digitalWrite(M4,LOW);
 analogWrite(E4,Speed);
}

void M1_back(char Speed) ///<Motor1 Back off
{
 digitalWrite(M1,HIGH);
 analogWrite(E1,Speed);
}
void M2_back(char Speed) ///<Motor2 Back off
{
 digitalWrite(M2,HIGH);
 analogWrite(E2,Speed);
}
void M3_back(char Speed) ///<Motor3 Back off
{
 digitalWrite(M3,HIGH);
 analogWrite(E3,Speed);
}
void M4_back(char Speed) ///<Motor4 Back off
{
 digitalWrite(M4,HIGH);
 analogWrite(E4,Speed);
}

void backward(){
   M1_back(40);
   M2_back(40);
   M3_back(40);
   M4_back(40); 
}

void forward(){
   M1_advance(40);
   M2_advance(40);
   M3_advance(40);
   M4_advance(40); 
}
void left(){
  M1_back(50);
  M2_advance(50);
  M3_back(50);
  M4_advance(50); 
  
}
void right(){
  M1_back(50);
  M2_advance(50);
  M3_back (50);
  M4_advance(50); 
}

void stopDriving(){
    M1_advance(0);
    M2_advance(0);
    M3_advance(0);
    M4_advance(0);
}

void turnLeft90(){
  unsigned long starttime = millis();
  unsigned long endtime = starttime;
  while ((endtime - starttime) <= 1530) // do this loop for up to 1000mS
  {
    Serial.println("Inside right turn90");
    // code here
    //M1_back(100);
    //M2_advance(100);
    //M3_back(100);
    //M4_advance(100);
    left();
    endtime = millis();
  }

  for (int i = 0; i < 50; i++) {
    Serial.println("Moving forward in right turn90");
  }
}

void turnRight90(){
  unsigned long starttime = millis();
  unsigned long endtime = starttime;
  while ((endtime - starttime) <= 1510) // do this loop for up to 1000mS
  {
    Serial.println("Inside right turn90");
    // code here
    //M1_advance(100);
    //M2_back(100);
    //M3_advance(100);
    //M4_back(100);
    right();
    endtime = millis();
  }

  for (int i = 0; i < 50; i++) {
    Serial.println("Moving forward in right turn90");
  }
}

void loop(){
  //first two lines of cans
  for (int i = 0; i < 600; i++){
  forward();
  Serial.println("forward");
  }
  turnLeft90();
  for (int i = 0; i < 600; i++){
  forward();
  }
  turnRight90();
  for (int i = 0; i < 300; i++){
  forward();
  }
  turnRight90();
  for (int i = 0; i < 600; i++){
  forward();
  }
  turnRight90();
  forward();
  //other two lines of cans
 
}
