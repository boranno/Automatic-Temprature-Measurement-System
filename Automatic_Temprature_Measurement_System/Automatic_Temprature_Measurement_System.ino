#include <LiquidCrystal.h>
int puss=8,pussout;
float c,d,t,a,b,f,hitemp=0,lowtemp=100;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16,2);
  pinMode(puss,OUTPUT);
}

void loop()
{
 pussout=digitalRead(puss);
    a=analogRead(A0);
    a=(5.0/1023.00)*a;
    b=5.00-a;
    c=a/(b/10000);
    d=log(c/10000);
    t=(1/((d/3977)+(1/(26 + 273.15))));
    t=t-273.15;
    f=(t*9/5.0)+32;
    if(hitemp<t)
    {
      hitemp=t;
    }
    if(lowtemp>t)
    {
      lowtemp=t;
    }
    if(pussout==1)
    {
      lcd.setCursor(0,0);
      lcd.print("HI TEMP");
      lcd.setCursor(9,0);
      lcd.print(hitemp);
      lcd.print("C");
      lcd.setCursor(0,1);
      f=(t*9/5.0)+32;
      lcd.print("LOW Temp ");
      lcd.setCursor(9,1);
      lcd.print(lowtemp);
      lcd.print("C");
      delay(5000);
      
    }
    else
    {
      lcd.setCursor(0,0);
      lcd.print("TEMPRATCHER IS");
      lcd.setCursor(0,1);
      lcd.print(t);
      lcd.print("C");
      lcd.setCursor(9,1);
      lcd.print(f);
      lcd.print("F");
    }
  delay(500);
}
