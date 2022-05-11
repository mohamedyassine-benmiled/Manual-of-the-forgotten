char BYTE;
int buttonR = 2;
int buttonL = 3;
int buttonJ = 7;
int LED1 = 12;
int LED2 = 13;
int right =0;
int left =0;
int jump =0;
void setup() {
  // put your setup code here, to run once:
  pinMode(buttonR, INPUT_PULLUP); // BUTTON R CONNECTED INPUT
  pinMode(buttonL, INPUT_PULLUP); // BUTTON L CONNECTED INPUT
  pinMode(buttonJ, INPUT_PULLUP); // BUTTON J CONNECTED INPUT
  pinMode(LED1,OUTPUT);// LED ONE CONNECTED TO PIN ? 
  pinMode(LED2,OUTPUT); //  LED TWO CONNECTED TO PIN ? 
  Serial.begin(9600);
  digitalWrite(LED1,LOW); // INITIATE LED ONE TO OFF 
  digitalWrite(LED2,LOW); // INITIATE LED TWO TO OFF 

}

void loop() {
  // put your main code here, to run repeatedly:
//traitement des deux boutons

  right = digitalRead(buttonR);
  left = digitalRead(buttonL);
  jump = digitalRead(buttonJ);
if(right==1){
  Serial.write(1);
  Serial.println("Moving Right cause thats gay"); 

    }
else if(left==1){
  Serial.write(2);
  Serial.println("Moving Left cause thats straight"); 
 
  }
else {
  Serial.write(0);
  Serial.println("No move means you're in between");  

  }
  // traitement des deux diodes led
if(Serial.available()>0)
{
  BYTE=Serial.read();// on va lire l'information venant du SDL (une collision par exemple)
  if(BYTE=='1') //(Si la collision du coté droite on reçoi 1 alors on allume la première diode qui est sur la pin 13)
  {
    digitalWrite(LED1,HIGH);// allumer une première diode 
    digitalWrite(LED2,LOW);// la deuxième est éteinte
    Serial.println("collision right\n");// afficher un message sur le moniteur serie
  }
  else if(BYTE=='0')// (Si la collision coté gauche on reçoi 2 on allume la deuxième diode branchée sur la pin 12)
  {
    digitalWrite(LED2,HIGH);// allumer la deuxième diode
    digitalWrite(LED1,LOW);//la première diode est eteinte
    Serial.println("collision left\n");// afficher un message sur le moniteur serie
  }
else {// c'est à dire pas de collision on reçoi 0
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    Serial.println("no collision \n");
  }
}

}
