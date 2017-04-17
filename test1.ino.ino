#include <SevSeg.h>

SevSeg sevseg;


  void setup()
  {
    Serial.begin(9600);
    Serial.println("25");
    Serial.println("04050033 04050475");//　第一題
    byte numDigits = 4;
    byte digitPins[] = {5,4,3,2};
    byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};

    sevseg.begin(COMMON_CATHODE, numDigits, digitPins,segmentPins);
  }
  
  void loop()
  {   
       int n;
       if(Serial.available())
      {
         n = Serial.parseInt();
           
        if(n>=0 && n<=9999){
          sevseg.setNumber(n,-1);
          Serial.println(n);
        }else
           Serial.println("range error");
      }    
      for(int n=0;n<8000;n++)
      {     
          sevseg.refreshDisplay(); 
          sevseg.refreshDisplay();
      }
  }  
