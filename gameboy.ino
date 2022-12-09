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

int correctButton = 0;
int timer = millis();
int waitTime = 2000;

bool startGame();
int dispGame(); // outputs correct button and outputs the game screen
int readButton(); // checks which button is pressed and outputs button value else 0
void dispGameEnd();
void dispMainScreen();

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
                break;
            }
        }
        lives --;
    }
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
    lcd.print("yolo");
}