// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>
#include <M5StickC.h>

// Data wire is plugged into port 32 on the M5stick
#define ONE_WIRE_BUS 32

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

//VariablesMax y Min
float maxTemp =-100;
float minTemp=100;

void setup(void)
{
   M5.begin();
   sensors.begin();
   Serial.begin(9600);
   
}
void loop(void)
{ 
  M5.update();  // Lectura de estado pulsadores
    if (M5.BtnA.wasPressed()) {  // Boton A
       M5.Axp.SetLDO2(true); 
       M5.Axp.ScreenBreath(9); // Brillo de pantalla
    
    }
       else
  {
      M5.Axp.SetLDO2(false); 
      M5.Axp.ScreenBreath(0);
      sensors.requestTemperatures(); // Send the command to get temperatures
    float tempC = sensors.getTempCByIndex(0);
    M5.Lcd.setRotation(3);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(30, 5);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setTextSize(3);
    M5.Lcd.println(tempC);
    M5.Lcd.setCursor(120, 5);
    M5.Lcd.setTextColor(YELLOW);
    M5.Lcd.println("C");
    if (tempC>maxTemp){maxTemp = tempC;}
    if (tempC<minTemp){minTemp = tempC;}
      // Max display
    M5.Lcd.setTextColor(RED);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(10, 35);
    M5.Lcd.println("Max");
    M5.Lcd.setCursor(10, 55);
    M5.Lcd.println(maxTemp);
   
    // Min display
    M5.Lcd.setTextColor(BLUE);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(90, 35);
    M5.Lcd.println("Min");
    M5.Lcd.setCursor(90, 55);
    M5.Lcd.println(minTemp);

 //   M5.Axp.LightSleep(SLEEP_SEC(5));
     }
    }
 /*
 M5.update();

    if(M5.BtnA.wasPressed())
    { 
    sensors.requestTemperatures(); // Send the command to get temperatures
   float tempC = sensors.getTempCByIndex(0);

  // Check if reading was successful
  if(tempC != DEVICE_DISCONNECTED_C) 
  {
    // Temperatura Actual
   // M5.Lcd.writecommand(ST7735_DISPOFF);
   // M5.Axp.ScreenBreath(0); // Brillo de pantalla
    M5.Axp.SetLDO2(false);
    M5.Lcd.setRotation(3);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(30, 5);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setTextSize(3);
    M5.Lcd.println(tempC);
    M5.Lcd.setCursor(120, 5);
    M5.Lcd.setTextColor(YELLOW);
    M5.Lcd.println("C");
    
    // Maxima y Minima
    if (tempC>maxTemp){maxTemp = tempC;}
    if (tempC<minTemp){minTemp = tempC;}
   
    // Max display
    M5.Lcd.setTextColor(RED);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(10, 35);
    M5.Lcd.println("Max");
    M5.Lcd.setCursor(10, 55);
    M5.Lcd.println(maxTemp);
   
    // Min display
    M5.Lcd.setTextColor(BLUE);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(90, 35);
    M5.Lcd.println("Min");
    M5.Lcd.setCursor(90, 55);
    M5.Lcd.println(minTemp);

    Serial.println(tempC);
    M5.Axp.LightSleep(SLEEP_SEC(5));
  } 
  else
  {
    
    M5.Lcd.setRotation(3);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(30, 5);
    M5.Lcd.setTextColor(YELLOW);
    M5.Lcd.setTextSize(3);
    M5.Lcd.println("Sonda");
  }
   }   
 
  M5.update();  // Lectura de estado pulsadores
    if (M5.BtnA.wasPressed()) {  // Boton A
      //M5.Lcd.writecommand(ST7735_DISPON);
      //M5.Axp.ScreenBreath(9); // Brillo de pantalla
      M5.Axp.SetLDO2(true); 
      tiempo1 = millis();
    } 
  */
