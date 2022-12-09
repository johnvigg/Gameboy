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
    lcd.init();
}

void loop()
{
    dispMainScreen();
    if(readButton()) // checks if any button is pressed
        startGame();
}

bool startGame(){
    while (lives != 0){
        correctButton = dispGame();
        timer = millis();
        while(millis()-timer < waitTime){
            if (correctButton == readButton() ){
                lives ++;
                score ++;
                break;
            }
        }
        lives --;
    }
    topScore = score;
    saveTopScore(topScore);
    timer = millis();
    while(millis()-timer < waitTime){
        dispGameEnd();
    }
}

int readButton(){
    if (digitalRead(btn1))
        return btn1;
    if (digitalRead(btn2))
        return btn2;
    if (digitalRead(btn3))
        return btn3;
    if (digitalRead(btn4))
        return btn4;
    if (digitalRead(btn5))
        return btn5;
    if (digitalRead(btn6))
        return btn6;
    return 0;
}

void dispMainScreen(){
    lcd.backlight();
    
    lcd.setCursor(0, 0);
    lcd.print("Press any button to start");
    lcd.setCursor(1, 3);
    lcd.print(" to start");
}

void dispGameEnd(){
    lcd.backlight();
    
    lcd.setCursor(0, 4);
    lcd.print("GAME OVER");
    lcd.setCursor(1, 0);
    lcd.print("top-");
    lcd.setCursor(1, 5);
    lcd.print(score);
    lcd.setCursor(1, 8);
    lcd.print("now-");
    lcd.setCursor(1, 13);
    lcd.print(score);


}

int dispGame(){
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("score-");
    lcd.setCursor(0, 7);
    lcd.print(score);

    int randNo = random(6);
    switch (randNo)
    {
    case 1:
        lcd.setCursor(1, 0);
        lcd.print("1");
        return bt1;
        break;
    case 2:
        lcd.setCursor(1, 2);
        lcd.print("2");
        return bt2;
        break;
    case 3:
        lcd.setCursor(1, 4);
        lcd.print("3");
        return bt3;
        break;
    case 4:
        lcd.setCursor(1, 6);
        lcd.print("4");
        return bt4;
        break;
    case 5:
        lcd.setCursor(1, 8);
        lcd.print("5");
        return bt5;
        break;
    case 6:
        lcd.setCursor(1, 10);
        lcd.print("6");
        return bt6;
        break;
    
    default:
        break;
    }
}