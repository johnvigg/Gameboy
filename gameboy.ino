#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int Pin1 = 12;
int Pin2 = 13;

int lives = 3;
int score = 0;

int correctButton = 0;


bool startGame();
int dispGame(); // outputs correct button and outputs the game screen
int readButton(); // checks which button is pressed and outputs button value else 0
int timer = millis();
int waitTime = 2000;

void setup()
{
    lcd.init();
}

void loop()
{
    if(readButton()) // checks if any button is pressed
        startGame();

    lcd.backlight();
    
    lcd.setCursor(0, 0);
    lcd.print("yolo");
}

bool startGame(){
    while (lives != 0){
        correctButton = dispGame();
        timer = millis();
        if (!(correctButton == readButton())|| millis()-timer > waitTime)
            lives --;
        
    }
}

int readButton(){
    if (digitalRead(Pin1))
        return Pin1;
    if (digitalRead(Pin2))
        return Pin2;
    return 0;
}