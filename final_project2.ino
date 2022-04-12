int t,i=0;
int v;
int sensorState = 0;
int sp=2;
int bulb=12;
int buzzerpin=7;
String password="1234";
bool state;
void setup()
{
pinMode(buzzerpin,OUTPUT);
pinMode(sp, INPUT);
pinMode(bulb, OUTPUT);
digitalWrite(bulb, HIGH);
Serial.begin(9600);
}
void loop()
{
  t=3;
  digitalWrite(bulb, HIGH);
  while(t>0)
{
  i=0;
 String ch;
while(i<password.length())
{
 v = Serial.read();
Serial.println(v);
if(v==-1)
  continue;
switch (v) {
case 207:
  ch=String(ch+'0');
  break;
case 247:
 ch=String(ch+'1');
break;
case 119:
 ch=String(ch+'2');
break;
case 183:
 ch=String(ch+'3');
break;
case 215:
 ch=String(ch+'4');
  break;
case 87:
  ch=String(ch+'5');
  break;
case 151:
 ch=String(ch+'6');
break;
case 231:
 ch=String(ch+'7');
break;
case 103:
 ch=String(ch+'8');
break;
case 167:
 ch=String(ch+'9');
  break;
}
  i++;
 delay(500);
}///1st inner while
Serial.println(ch);
delay(500);
while(ch==password)
{
 //delay(1000);
sensorState = digitalRead(sp);
if (sensorState == HIGH)
{ 
 noTone(buzzerpin); 
digitalWrite(bulb, LOW);
Serial.println("Welcome");
state=true;
  x:
v = Serial.read();
Serial.println(v);
if(v==-1)
  goto x;
if(v==255){
  digitalWrite(bulb, HIGH);
  t=-1;
  ch="";
  continue;
 }
}//if
else if(state!=true){
  tone(buzzerpin,500);
  digitalWrite(bulb, HIGH);
  Serial.println("Come close to sensor");
}//else
// delay(500);
}//2nd inner while
  if(t!=-1)
  tone(buzzerpin,500);
 t--;
}//outer while
} 
