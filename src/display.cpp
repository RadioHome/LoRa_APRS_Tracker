
#include <Wire.h>
#include "display.h"
#include "settings.h"
#include "pins.h"

#ifdef SH1106
	#include <U8g2lib.h>
	U8G2_SH1106_128X64_NONAME_F_HW_I2C display(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

#else
	#include <Adafruit_GFX.h>
	#include <Adafruit_SSD1306.h>
	Adafruit_SSD1306 display(128, 64, &Wire, OLED_RST);
	
#endif


void setup_display()
{
	pinMode(OLED_RST, OUTPUT);
	digitalWrite(OLED_RST, LOW);
	delay(20);
	digitalWrite(OLED_RST, HIGH);

	Wire.begin(OLED_SDA, OLED_SCL);
	#ifdef SH1106
		display.begin();
		display.clearBuffer();
		display.setFont(u8g2_font_8x13_tf);
		display.setCursor(0,0);
		display.print("LORA SENDER ");
		display.sendBuffer();
	#else
		if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c, false, false))
		{
			Serial.println("SSD1306 allocation failed");
			while (1);
		}
		display.clearDisplay();
		display.setTextColor(WHITE);
		display.setTextSize(1);
		display.setCursor(0,0);
		display.print("LORA SENDER ");
		display.ssd1306_command(SSD1306_SETCONTRAST);
		display.ssd1306_command(1);
		display.display();
	#endif	
	}
	

void show_display(String header, int wait)
{
	#ifdef SH1106
		display.clearBuffer();
		display.setFont(u8g2_font_8x13_tf);
		display.setCursor(0,0);
		display.println(header);
		display.sendBuffer();
		delay(wait);
	#else	
		display.clearDisplay();
		display.setTextColor(WHITE);
		display.setTextSize(2);
		display.setCursor(0,0);
		display.println(header);
		display.ssd1306_command(SSD1306_SETCONTRAST);
		display.ssd1306_command(1);
		display.display();
		delay(wait);
	#endif
}

void show_display(String header, String line1, int wait)
{
	#ifdef SH1106
		display.clearBuffer();
		display.setFont(u8g2_font_8x13_tf);
		display.setCursor(0,0);
		display.println(header);
		display.setFont(u8g2_font_6x10_tf);
		display.setCursor(0,16);
		display.println(line1);
		display.sendBuffer();
		delay(wait);

	#else
		display.clearDisplay();
		display.setTextColor(WHITE);
		display.setTextSize(2);
		display.setCursor(0,0);
		display.println(header);
		display.setTextSize(1);
		display.setCursor(0,16);
		display.println(line1);
		display.ssd1306_command(SSD1306_SETCONTRAST);
		display.ssd1306_command(1);
		display.display();
		delay(wait);
	#endif	
}

void show_display(String header, String line1, String line2, int wait)
{
	#ifdef SH1106
		display.clearBuffer();
		display.setFont(u8g2_font_8x13_tf);
		display.setCursor(0,0);
		display.println(header);
		display.setFont(u8g2_font_6x10_tf);
		display.setCursor(0,16);
		display.println(line1);
		display.setCursor(0,26);
		display.println(line2);
		display.sendBuffer();
		delay(wait);
	
	#else
		display.clearDisplay();
		display.setTextColor(WHITE);
		display.setTextSize(2);
		display.setCursor(0,0);
		display.println(header);
		display.setTextSize(1);
		display.setCursor(0,16);
		display.println(line1);
		display.setCursor(0,26);
		display.println(line2);
		display.ssd1306_command(SSD1306_SETCONTRAST);
		display.ssd1306_command(1);
		display.display();
		delay(wait);
	#endif	
}

void show_display(String header, String line1, String line2, String line3, int wait)
{
	#ifdef SH1106
		display.clearBuffer();
		display.setFont(u8g2_font_8x13_tf);
		display.setCursor(0,0);
		display.println(header);
		display.setFont(u8g2_font_6x10_tf);
		display.setCursor(0,16);
		display.println(line1);
		display.setCursor(0,26);
		display.println(line2);
		display.setCursor(0,36);
		display.println(line3);
		display.sendBuffer();
		delay(wait);
	#else
		display.clearDisplay();
		display.setTextColor(WHITE);
		display.setTextSize(2);
		display.setCursor(0,0);
		display.println(header);
		display.setTextSize(1);
		display.setCursor(0,16);
		display.println(line1);
		display.setCursor(0,26);
		display.println(line2);
		display.setCursor(0,36);
		display.println(line3);
		display.ssd1306_command(SSD1306_SETCONTRAST);
		display.ssd1306_command(1);
		display.display();
		delay(wait);
	#endif
}

void show_display(String header, String line1, String line2, String line3, String line4, int wait)
{
	#ifdef SH1106
		display.clearBuffer();
		display.setFont(u8g2_font_8x13_tf);
		display.setCursor(0,0);
		display.println(header);
		display.setFont(u8g2_font_6x10_tf);
		display.setCursor(0,16);
		display.println(line1);
		display.setCursor(0,26);
		display.println(line2);
		display.setCursor(0,36);
		display.println(line3);
		display.setCursor(0,46);
		display.println(line4);
		display.sendBuffer();
		delay(wait);

	#else
		display.clearDisplay();
		display.setTextColor(WHITE);
		display.setTextSize(2);
		display.setCursor(0,0);
		display.println(header);
		display.setTextSize(1);
		display.setCursor(0,16);
		display.println(line1);
		display.setCursor(0,26);
		display.println(line2);
		display.setCursor(0,36);
		display.println(line3);
		display.setCursor(0,46);
		display.println(line4);
		display.ssd1306_command(SSD1306_SETCONTRAST);
		display.ssd1306_command(1);
		display.display();
		delay(wait);
	#endif
}

void show_display(String header, String line1, String line2, String line3, String line4, String line5, int wait)
{
	#ifdef SH1106
		display.clearBuffer();
		display.setFont(u8g2_font_8x13_tf);
		display.setCursor(0,0);
		display.println(header);
		display.setFont(u8g2_font_6x10_tf);
		display.setCursor(0,16);
		display.println(line1);
		display.setCursor(0,26);
		display.println(line2);
		display.setCursor(0,36);
		display.println(line3);
		display.setCursor(0,46);
		display.println(line4);
		display.setCursor(0,56);
		display.println(line5);
		display.sendBuffer();
		delay(wait);

	#else
		display.clearDisplay();
		display.setTextColor(WHITE);
		display.setTextSize(2);
		display.setCursor(0,0);
		display.println(header);
		display.setTextSize(1);
		display.setCursor(0,16);
		display.println(line1);
		display.setCursor(0,26);
		display.println(line2);
		display.setCursor(0,36);
		display.println(line3);
		display.setCursor(0,46);
		display.println(line4);
		display.setCursor(0,56);
		display.println(line5);
		display.ssd1306_command(SSD1306_SETCONTRAST);
		display.ssd1306_command(1);
		display.display();
		delay(wait);
	#endif
}
