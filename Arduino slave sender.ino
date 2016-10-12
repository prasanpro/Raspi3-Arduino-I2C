#include <Wire.h>

void setup()
{
  Wire.begin(0x04);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
}

void loop()
{
  delay(100);
}

char data[] = "hello";
int index = 0;

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent()
{
 Wire.write(data[index]);
    ++index;
    if (index >= 5) {
         index = 0;
    }
}
