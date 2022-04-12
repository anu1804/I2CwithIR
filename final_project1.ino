#include <IRremote.h>
int RECV_PIN = A0;
IRrecv irrecv(RECV_PIN);
decode_results results;

int value;
void setup()
{
Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}
void loop()
{
 if (irrecv.decode(&results))
 {
   value=results.value;
   Serial.write(value);
   irrecv.resume();
 }
}