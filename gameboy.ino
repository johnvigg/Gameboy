#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int btn1 = 12;
int btn2 = 13;
int btn3 = 14;
int btn4 = 15;
int btn5 = 16;
int btn6 = 17;

int lives = 3;
int score = 0;
int topScore = 0;
int flag = 1; //Flag=1 starts game, flag =2

int correctButton = 0;
int timer = millis();
int waitTime = 2000;

bool startGame();
int dispGame(); // outputs correct button and outputs the game screen
int readButton(); // checks which button is pressed and outputs button value else 0
void dispGameEnd();
void dispMainScreen();
void saveTopScore(int score);

void setup()
{
    pinMode(btn1, INPUT_PULLUP);
    pinMode(btn2, INPUT_PULLUP);
    Serial.begin(9600);
    lcd.init();
    Serial.println("started");
}

void loop()
{
    dispMainScreen();
    delay(10);
    if(readButton()){ // checks if any button is pressed
        lives = 3;
        startGame();
        
    }
}

bool startGame()
    {
    lcd.clear();
    Serial.println("into screen");
    while (lives > 0)
        {
        flag=1;
        correctButton = dispGame();
        int buttonPressed ;
        timer = millis();
        while(millis()-timer < waitTime && flag==1)
        {
            Serial.println("Entered while loop");
            buttonPressed = readButton();
              if((correctButton == buttonPressed)&&(buttonPressed =! 0))
              {
                 lives ++;
                  score ++;
                  Serial.println("breaked");
                flag=0;
              }else if((correctButton != buttonPressed)&&(buttonPressed =! 0))
                break;
              
            
        }
            lives --;
        }
            
    topScore = score;
    
    // saveTopScore(topScore);
    lcd.clear();
    timer = millis();
    while(millis()-timer < waitTime){
        dispGameEnd();
        delay(10);
    }
    score = 0;
    lcd.clear();
}

int readButton(){
    if (!digitalRead(btn1)){
      delay(75);
      while(!digitalRead(btn1)){delay(1);}
      Serial.println("button pressed");
      return btn1;
    }
        
    if (!digitalRead(btn2)){
        delay(75);
      while(!digitalRead(btn1)){delay(1);}
      Serial.println("button pressed");
        return btn2;

    }
//    if (digitalRead(btn3))
//        return btn3;
//    if (digitalRead(btn4))
//        return btn4;
//    if (digitalRead(btn5))
//        return btn5;
//    if (digitalRead(btn6))
//        return btn6;
    return 0;
}

void dispMainScreen(){
    lcd.backlight();
    
    lcd.setCursor(0, 0);
    lcd.print("Press any button");
    lcd.setCursor(1, 3);
    lcd.print("   to start");
}

void dispGameEnd(){
    
    lcd.backlight();
    
    lcd.setCursor(4, 0);
    lcd.print("GAME OVER");
    lcd.setCursor(0, 1);
    lcd.print("top:");
    lcd.setCursor(5, 1);
    lcd.print(score);
    lcd.setCursor(8, 1);
    lcd.print("now:");
    lcd.setCursor(13, 1);
    lcd.print(score);


}

int dispGame(){
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("score:");
    lcd.setCursor(7, 0);
    lcd.print(score);
    lcd.setCursor(10, 0);
    lcd.print(lives);

   int randNo = random(2);
   switch (randNo)
   {
   case 1:
       lcd.setCursor(1, 1);
       lcd.print("1");
       return btn1;
       break;
   case 2:
       lcd.setCursor(1, 3);
       lcd.print("2");
       return btn2;
       break;
//    case 3:
//        lcd.setCursor(1, 4);
//        lcd.print("3");
//        return btn3;
//        break;
//    case 4:
//        lcd.setCursor(1, 6);
//        lcd.print("4");
//        return btn4;
//        break;
//    case 5:
//        lcd.setCursor(1, 8);
//        lcd.print("5");
//        return btn5;
//        break;
//    case 6:
//        lcd.setCursor(1, 10);
//        lcd.print("6");
//        return btn6;
//        break;
//    
   default:
       break;
   }
}