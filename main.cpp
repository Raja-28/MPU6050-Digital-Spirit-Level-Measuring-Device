#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <MPU6050.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define BUZZER_PIN 7
#define LED_PIN 13


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
MPU6050 mpu;

void setup() {
  
  Serial.begin(115200);

  
  Wire.begin();
  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed");
    while (1);
  }

  
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (1);
  }

  
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  display.clearDisplay();
  display.display();
}

void loop() {
  
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  
  float angleX = atan2(ay, az) * 180 / PI;
  float angleY = atan2(ax, az) * 180 / PI;

  
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("X: ");
  display.print(angleX, 1);
  display.println(" deg");

  display.setCursor(0, 30);
  display.print("Y: ");
  display.print(angleY, 1);
  display.println(" deg");
  display.display();

  
  if (abs(angleX) < 2 && abs(angleY) < 2) {
    
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000); 
  } else {
    
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
  }

  delay(100);
}
