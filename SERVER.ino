// Javid Uddin, 656128438 and muddi7
// Project
// (2/2) ARDUINO SERVER

#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <string.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int buttonPin1 = 10;
const int buttonPin2 = 7;
int spots[5] = {0, 0, 0, 0, 0};
int currentIndex = -1;
String topLine;
String bottomLine;

// start screen
const String scrollMessage = "Press any button to continue";
int startScreenVisible = 1;
unsigned long scrollStart = 0;
const unsigned long scrollInterval = 500;  
int scrollPosition = 0;

int buttonState = 0;
int prevButtonTime = 0;
int prevButtonState = 0;

SoftwareSerial btSerial(1, 0); // RX, TX (Connect RX of Bluetooth to pin 10, TX to pin 9)

int getSpotsCount() {
  return sizeof(spots) / sizeof(spots[0]);
}

void handleBtn(int buttonReading) {
  if(currentIndex == -1) {
    currentIndex = 0;
  }
  else if(currentIndex + buttonReading >= 0 && currentIndex + buttonReading < getSpotsCount()) {
    currentIndex += buttonReading;
  }
  else if(currentIndex + buttonReading < 0){
    currentIndex = getSpotsCount() - 1;
  }
  else if(currentIndex + buttonReading >= getSpotsCount()) {
    currentIndex = 0;
  }
  displayStatus();
}

void displayStatus() {
  topLine = "Parking Spot #" + String(currentIndex + 1);
  if(spots[currentIndex] == 0) {
    bottomLine = "Available";
  } else {
    bottomLine = "Unavailable";
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(topLine);
  lcd.setCursor(0, 1);
  lcd.print(bottomLine);
}

void showStartScreen() {
  if (millis() - scrollStart >= scrollInterval) {
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("SpotterSense");
    scrollStart = millis();  // reset scroll timer
    
    // display part of the scroll message on the bottom line
    lcd.setCursor(0, 1);
    lcd.print(scrollMessage.substring(scrollPosition, scrollPosition + 16));
    
    // update scroll position & reset if we reach the end
    scrollPosition++;
    if (scrollPosition > scrollMessage.length() - 16) {
      scrollPosition = 0;  // reset to start of msg
    }
  }
}

void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  lcd.begin(16, 2);
  btSerial.begin(9600);      // bluetooth module
}

void loop() {

  if(startScreenVisible) {
    showStartScreen();
  }

  int buttonReading1 = digitalRead(buttonPin1);
  int buttonReading2 = digitalRead(buttonPin2);
  int buttonReading = buttonReading2 - buttonReading1;

  if (millis() - prevButtonTime >= 200){
    if (buttonReading != prevButtonState){
      prevButtonTime = millis();
      startScreenVisible = 0;
      handleBtn(buttonReading);
    }
  }
  prevButtonState = buttonReading;

  if (btSerial.available() > 0) { // input from serial monitor
    String input = btSerial.readStringUntil('\n');  // read input as a single line
    input.trim();  // remove any leading/trailing whitespace
    int spotNumber = input[0] - '0' - 1;
    int spotStatus = input[2] - '0';
    spots[spotNumber] = spotStatus;
    if(!startScreenVisible) {
      displayStatus();
    }
  }
}
