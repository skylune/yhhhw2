#include <Arduino.h>
//定义使用的串口
const int LEDPIN1 = 25;
const int LEDPIN2 = 26;

//记录LED当前状态，-1为灭，1为亮
int flag1=-1;
int flag2=-1;

void processcommand(char command);


void setup() {
    // 设定引脚为输出模式
    pinMode(LEDPIN1,OUTPUT);
    pinMode(LEDPIN2,OUTPUT);

    //初始化为熄灭
    digitalWrite(LEDPIN1,LOW);
    digitalWrite(LEDPIN2,LOW);
    //初始化串口通信
    Serial.begin(9600);

}

void loop() {
    //检查串口
    if(Serial.available()>0){
        char command = Serial.read();

        //等待数据传输完成并清空
        delay(50);
        while(Serial.available()>0){
            Serial.read();
        }

        //开始处理
        processcommand(command);
    }
}

void processcommand(char command){
    switch(command){
        case '1':
            //25号
            if(flag1==-1){
                flag1=-1*flag1;
                digitalWrite(LEDPIN1,HIGH);
                Serial.println("LED1亮");
                break;
            }else{
                flag1=-1*flag1;
                digitalWrite(LEDPIN1,LOW);
                Serial.println("LED1灭");
                break;
            }

            case '2':
            //26号
            if(flag2==-1){
                flag2=-1*flag2;
                digitalWrite(LEDPIN2,HIGH);
                Serial.println("LED2亮");
                break;
            }else{
                flag2=-1*flag2;
                digitalWrite(LEDPIN2,LOW);
                Serial.println("LED2灭");
                break;
            }    
            default:
            //未知指令
            Serial.print("未知指令：");
            Serial.println(command);
            break;
    }
}
