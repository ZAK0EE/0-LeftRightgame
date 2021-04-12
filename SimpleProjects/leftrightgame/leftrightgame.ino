/*No:0
 *Date:13/04/2021
 *Purpose:For fun
 *Difficulity: Easy
 */
#define LEFTBUTTON 3
#define RIGHTBUTTON 0
int  LEDS[5] = {13, 12, 11, 10, 9};
int CURRENTLED = 0;

// the setup function runs once when you press reset or power the board
void setup() 
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LEFTBUTTON, INPUT_PULLUP);
  pinMode(RIGHTBUTTON, INPUT_PULLUP);
  
  for (int LED = 0; LED < 5;LED++)
    pinMode(LEDS[LED], OUTPUT);

  Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop() 
{
  if (CURRENTLED == 5)
  {
    Serial.println("WINNER");
    Winner();

  }
  if (digitalRead(LEFTBUTTON) == LOW)
  {
    Serial.println("LEFT PRESSED");
    PressLeft();
    while(digitalRead(LEFTBUTTON) == LOW);
  }

  else if (digitalRead(RIGHTBUTTON) == LOW)
  {
    Serial.println("RIGHT PRESSED");
    PressRight();
    while(digitalRead(RIGHTBUTTON) == LOW);
  }
    
}

void PressLeft(void)
{
  if(CURRENTLED == 0) return;
  digitalWrite(LEDS[--CURRENTLED], LOW);;
  
}

void PressRight(void)
{
  if(CURRENTLED == 5) return;
  digitalWrite(LEDS[CURRENTLED++], HIGH);  
}

void Reset(void)
{
  for (int i = 0; i < 5; i++)
    digitalWrite(LEDS[i], LOW);
  CURRENTLED = 0;
}
//A series of LED patterns to show winning mode.
void Winner(void)
{
  Reset();
  //Even loop
  for (int  i = 0; i < 5; i+=2)
    digitalWrite(LEDS[i], HIGH);
  delay(1000);
  Reset();
  //Odd Loop
  for (int  i = 1; i < 5; i+=2)
    digitalWrite(LEDS[i], HIGH);
  delay(1000);
  Reset();
  //UP loop
  for (int  i = 0; i < 5; i++)
  {
    digitalWrite(LEDS[i], HIGH);
    delay(200);
  }    
  Reset();
  //DOWN LOOP
  for (int  i = 4; i >= 0; i--)
  {
    digitalWrite(LEDS[i], HIGH);
    delay(200);
  }  
  Reset();

}
