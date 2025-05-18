#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define WIDTH   128   // OLED display width, in pixels
#define HEIGHT  64    // OLED display height, in pixels
// 软件 SPI 总线
// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_SCK  22
#define OLED_SDA  21
#define OLED_RES  15


// 构造对象
Adafruit_SSD1306  OLED(WIDTH, HEIGHT, OLED_SDA, OLED_SCK, OLED_RES);

void setup() {
  // OLED初始化
  OLED.begin();
  // OLED清除显示
  OLED.clearDisplay();
  // 设置光标位置
  OLED.setCursor(1, 1);
  // 设置文本颜色
  OLED.setTextColor(SSD1306_WHITE);
  // 设置字体大小
  OLED.setTextSize(2);
  // 显示字符
  OLED.println("HelloWorld");

  // 显示内容
  OLED.display();
}

void loop() {
  // put your main code here, to run repeatedly:
}
