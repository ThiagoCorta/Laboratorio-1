void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

  pinMode(11,OUTPUT); // speaker
  pinMode(13,OUTPUT); // led
}


char matriz[4][4]={
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

char cod[4] = {'4','8','2','9'};
char incod[4] = {'0','0','0','0'};
char previousButton = 'x';
int timeCounter = 0;
int counter = 0;

void loop() {
  char currentButton = readButton();
  if(currentButton != 'x' && currentButton!=previousButton){
    //timeCounter = 0;
    incod[counter] = currentButton;
    previousButton = currentButton;
    counter++;
    if(counter==4){
      if(validateCode()){
        tone(11, 1000);
        digitalWrite(13, HIGH);
        delay(3000);
        tone(11, 0);
        digitalWrite(13, LOW);
        noTone(11);
      }
      else{
        tone(11, 500);
        delay(250);
        tone(11, 0);
        delay(250);
        tone(11, 500);
        delay(250);
        tone(11, 0);
        noTone(11);
      }
      counter=0;
      printCode();
      resetCode();
    }
    printCode();
  }
}

char readButton(){
 int valor;
  char ret = 'x';
  for(int i=9;i>=6;i--){
      digitalWrite(i, LOW);
      for(int j=5;j>=2;j--){
        valor = !digitalRead(j);
          if(valor){
            ret = matriz[9-i][5-j];
          }
      }
      digitalWrite(i, HIGH);
  } 
  return ret;
}

bool validateCode(){
  if(cod[0]==incod[0] && cod[1]==incod[1] && cod[2]==incod[2] && cod[3]==incod[3]) return true;
  return false;
}

void resetCode(){
  incod[0] = '0';
  incod[1] = '0';
  incod[2] = '0';
  incod[3] = '0';
}

void printCode(){
  Serial.print(incod[0]);
  Serial.print(incod[1]);
  Serial.print(incod[2]);
  Serial.println(incod[3]);
}
