 #include <PS4Controller.h>

int VTS = 80; // Vitesse
int VTS2 = 30; // vitesse 2
int t=50; // seuil control analog
int tp = 10; // temp

void setup() {
  Serial.begin(115200);
  PS4.begin("e8:6b:ea:d2:c4:66");
  Serial.println("Ready.");
  for (int i = 12; i<16; i++)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(33, OUTPUT);
  pinMode(2, OUTPUT);
  digitalWrite(12, VTS);
  digitalWrite(2, VTS);
  
}

void loop() {
  // Below has all accessible outputs from the controller
  if (PS4.isConnected()) {
    while (PS4.Right()) {
      Serial.println("Right Button");
      droite();
      
    }
    while (PS4.Down()) {
      Serial.println("Down Button");
      reculer();
      
    }
    while (PS4.Up()) {
      Serial.println("Up Button");
      avancer();
      
    }
    while (PS4.Left()) {
      Serial.println("Left Button");
      gauche();
      
    }

    if (PS4.Square()){
      Serial.println("Square Button");
      VTS = 0;
      arret();
    }
    if (PS4.Cross()) {
      Serial.println("Cross Button");
      VTS = 125;
      
    }
    if (PS4.Circle()) {
      Serial.println("Circle Button");
      VTS = 80  ;
     
    }
    if (PS4.Triangle()) {
      Serial.println("Triangle Button");
      VTS = 255  ;
    }

    if (PS4.UpRight()) {
      Serial.println("Up Right");
      CornerRigth();
      
    }
    if (PS4.DownRight()) {
      Serial.println("Down Right");
      BackCornerRigth();
      
    }
    if (PS4.UpLeft()) {
      Serial.println("Up Left");
      CornerLeft();
    }
    if (PS4.DownLeft()) {
      Serial.println("Down Left");
      BackCornerLeft();
        
    }

    if (PS4.L1()) {
      Serial.println("L1 Button");
      VTS = 255;
      reculer();
    }
    if (PS4.R1()) {
      Serial.println("R1 Button");
      VTS = 255;
      avancer();
      
    }

    if (PS4.Share()) {
      Serial.println("Share Button");
    }
    if (PS4.Options()) {
      Serial.println("Options Button");
    }
    if (PS4.L3()) {
      Serial.println("L3 Button");
    }
    if (PS4.R3()) {
      Serial.println("R3 Button");
    }

    if (PS4.PSButton()) {
      Serial.println("PS Button");
    }
    if (PS4.Touchpad()) {
      Serial.println("Touch Pad Button");
    }

    if (PS4.L2()) {
      Serial.printf("L2 button at %d\n", PS4.L2Value());
      VTS = 125;
      reculer();
      
    }
    if (PS4.R2()) {
      Serial.printf("R2 button at %d\n", PS4.R2Value());
      VTS = 125;
      avancer();
      
    }

    if       (PS4.LStickX()<t && PS4.LStickX()> -t && PS4.LStickY()>t ) {
      Serial.printf("Left Stick x at %d\n", PS4.LStickX());
      Serial.printf("Left Stick y at %d\n", PS4.LStickY());
      avancer();
      
      
    }
    if (PS4.LStickX()<t && PS4.LStickX()> -t && PS4.LStickY()< -t) {
      Serial.printf("Left Stick x at %d\n", PS4.LStickX());
      Serial.printf("Left Stick y at %d\n", PS4.LStickY());
      reculer();
      
    }
    if (PS4.LStickX()>t && PS4.LStickY()> -t && PS4.LStickY()< t) {
      Serial.printf("Left Stick x at %d\n", PS4.LStickX());
      Serial.printf("Left Stick y at %d\n", PS4.LStickY());
      droite();
      
    }
    if (PS4.LStickX()<-t && PS4.LStickY()> -t && PS4.LStickY()< t) {
      Serial.printf("Left Stick x at %d\n", PS4.LStickX());
      Serial.printf("Left Stick y at %d\n", PS4.LStickY());
      gauche();
      
    }
    if (PS4.LStickX()>t && PS4.LStickY()> t) {
      Serial.printf("Left Stick x at %d\n", PS4.LStickX());
      Serial.printf("Left Stick y at %d\n", PS4.LStickY());
      CornerRigth();
     
    }
    if (PS4.LStickX()<-t && PS4.LStickY()<- t) {
      Serial.printf("Left Stick x at %d\n", PS4.LStickX());
      Serial.printf("Left Stick y at %d\n", PS4.LStickY());
      BackCornerLeft();
   
    }
    if (PS4.LStickX()<-t && PS4.LStickY()> t) {
      Serial.printf("Left Stick x at %d\n", PS4.LStickX());
      Serial.printf("Left Stick y at %d\n", PS4.LStickY());
      CornerLeft();
      
    }
    if (PS4.LStickX()>t && PS4.LStickY()<- t) {
      Serial.printf("Left Stick x at %d\n", PS4.LStickX());
      Serial.printf("Left Stick y at %d\n", PS4.LStickY());
      BackCornerRigth();
      
    }
    Serial.printf("Battery Level : %d\n", PS4.Battery());
    if (PS4.Charging()) {
      Serial.println("The controller is charging");
     
      };

    Serial.println();
    // This delay is to make the output more human readable
    // Remove it when you're not trying to see the   
   
  }
} 



void avancer()
{
    
    analogWrite(13,0 );
    analogWrite(14, VTS);
    analogWrite(15, 0);
    analogWrite(33, VTS);
    delay(tp);
    arret();
}
void reculer()
{
     
    analogWrite(13, VTS);
    analogWrite(14, 0);
    analogWrite(15, VTS);
    analogWrite(33, 0);
    delay(tp);
    arret();
}

void gauche()
{
  
    analogWrite(13, VTS);
    analogWrite(14, 0);
    analogWrite(15, 0);
    analogWrite(33, VTS);
    delay(tp);
    arret();
}
void droite()
{
    
    analogWrite(13, 0);
    analogWrite(14, VTS);
    analogWrite(15, VTS);
    analogWrite(33, 0);
    delay(tp);
    arret();
}

void arret()
{
    
    analogWrite(13, 0);
    analogWrite(14, 0);
    analogWrite(15, 0);
    analogWrite(33, 0);
    delay(tp);
}


/*void autreCommande()
{
      if (PS4.RStickX()) {
      Serial.printf("Right Stick x at %d\n", PS4.RStickX());
    }
    if (PS4.RStickY()) {
      Serial.printf("Right Stick y at %d\n", PS4.RStickY());
    }

    if (PS4.Charging()) {
      Serial.println("The controller is charging");
    }
    if (PS4.Audio()) {
      Serial.println("The controller has headphones attached");
    }
    if (PS4.Mic()) {
      Serial.println("The controller has a mic attached");
    }
}*/

void CornerRigth()
{
 
    analogWrite(13, 0);
    analogWrite(14, VTS);
    analogWrite(15, 0);
    analogWrite(33, VTS2);
    delay(tp);
    arret();
}

void CornerLeft()
{
    analogWrite(13, 0);
    analogWrite(14, VTS2);
    analogWrite(15, 0);
    analogWrite(33, VTS);
    delay(tp);
    arret();
}

void BackCornerLeft()
{
    analogWrite(13, VTS2);
    analogWrite(14, 0);
    analogWrite(15, VTS);
    analogWrite(33, 0);
    delay(tp);
    arret();
}

void BackCornerRigth()
{
    analogWrite(13, VTS);
    analogWrite(14, 0);
    analogWrite(15, VTS2);
    analogWrite(33, 0);
    delay(tp);
    arret();
}
/*void regulSpeed()
{
  if (VTS < 0)
  {
    VTS = 0;
  }
    if (VTS > 255)
  {
    VTS = 255;
  }
  if(VTS2 < 0)
  {
    VTS2 = 0;
  }
  if(VTS2 > 255)
  {
    VTS2 = 255;
  }
}*/

/*Video Youtube: https://www.youtube.com/watch?v=EEViXFoSzww
 * Dowload Sixaxis pair tool o view or change de IP Adress of PS4 Controller
