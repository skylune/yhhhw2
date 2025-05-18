#include <Arduino.h>
#include <Adafruit_SSD1306.h>  // Adafruit 库
#include <Adafruit_GFX.h>

//定义屏幕参数
#define SCREEN_WIDTH  128 // OLED 宽度（单位：像素）
#define SCREEN_HEIGHT 64  // OLED 高度（单位：像素）
#define OLED_RESET    -1  // 无复位引脚时设为 -1
#define SCREEN_ADDRESS 0x3C // I2C 地址（可通过 I2C 扫描工具获取）

//创建OLED对象
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
    pinMode(25,OUTPUT);
    digitalWrite(25,HIGH);
    //初始化串口通信
    Serial.begin(9600);

    //初始化oled
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;); // 初始化失败则循环等待
      }

    // 清除屏幕并设置参数
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE); // 设置字体颜色为白色
    display.setTextSize(2); // 设置字体大小（1~5）
    display.setCursor(10, 20); // 设置字符起始位置（x, y）
    display.println("Hello, OLED!"); // 显示字符
    display.display(); // 刷新屏幕
}



void loop() {
    
}
