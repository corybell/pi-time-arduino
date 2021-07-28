#include <Wire.h>
#include "constants.h"
#include "DeviceMapper.h"

DeviceMapper deviceMapper;

void setup() {
  Serial.begin(BAUD_RATE);
  while (!Serial) ; 
  Serial.println(RESPONSE_SUCCESS);
}

void loop() {
  // no-op
}

void serialEvent() {
  char buf[BUF_SIZE + 1];
  
  if (!getInput(buf)) {
    return;
  }
  
  int input[3];
  parseInput(buf, input);
  
  auto handler(deviceMapper.Map(input[0]));

  handler->Handle(input[1], input[2]);
  handler = NULL;
}

bool getInput(char *buf)
{
  if (Serial.available() > 0) {
    String inputString = Serial.readString();
    inputString.trim(); 
    inputString.toCharArray(buf, BUF_SIZE + 1);
    return true;
  }
  return false;
}

void parseInput(char *buf, int *input) {
  int j = 0;
  for (int i = 0; i < strlen(buf); i += 2) {
    int d = hexByteAt(buf, i);
    input[j] = d;
    j++;
  }
}

int hexByteAt(char *buf, int i) {
  int d;
  char str[] = { buf[i], buf[i + 1] };
  sscanf(str, "%x", &d);
  return d;
}
