#define button1 12 // switch input Active Low
#define button2 11
#define button3 10
#define ledR 4
#define ledY 3
#define ledG 2
long timeledR = 0;
long timeledG = 0;
long timeledY = 0;
int count = 10;
void setup()
{
  Serial.begin(9600);

  pinMode(ledR,OUTPUT);
  pinMode(ledY,OUTPUT);
  pinMode(ledG,OUTPUT);
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(button3,INPUT_PULLUP);
}

void loop()
{
  // ledR
  if (digitalRead(button1) == HIGH && millis() - timeledR >= 250)
  {
    timeledR = millis();
    if (digitalRead(ledR) == LOW)
    {
      digitalWrite(ledR, HIGH);
    }
    else if (digitalRead(ledR) == HIGH)
    {
      digitalWrite(ledR, LOW);
    }
  }
  if (digitalRead(button1) == LOW)
  {
    if (millis() - timeledR >= 3000)
    {
      digitalWrite(ledR, LOW);
    }
  }
  // ledG
  if (digitalRead(button3) == LOW && millis() - timeledG >= 250 && digitalRead(ledR) != HIGH)
  {
    timeledG = millis();
    if (digitalRead(ledG) == LOW)
    {
      digitalWrite(ledG, HIGH);
    }
    else if (digitalRead(ledG) == HIGH)
    {
      digitalWrite(ledG, LOW);
    }
  }
  if (digitalRead(button3) == HIGH)
  {
    if (millis() - timeledG >= 3000)
    {
      digitalWrite(ledG, LOW);
    }
  }
  // ledY
  if (digitalRead(button2) == LOW && millis() - timeledY >= 250 && digitalRead(ledR) != HIGH && digitalRead(ledG) != HIGH)
  {
      count = 0;
  }
  else if (count <= 4)
  {
      if (millis() - timeledY >= 500)
      {
        if (digitalRead(ledY) == LOW)
        {
          Serial.println("LED tid");
          digitalWrite(ledY, HIGH);
        }
        else if (digitalRead(ledY) == HIGH)
        {
          Serial.println("LED dob");
          digitalWrite(ledY, LOW);
        }
        timeledY = millis();
        count++;
      }
  }
  if (count >= 4)
    {
      Serial.println("LEDY turnOFF");
      digitalWrite(ledY, LOW);
    }
}