#include <Wire.h>
#include "constants.h"
#include "DeviceMapper.h"

DeviceMapper deviceMapper;

/**
 * Setup handler
 * Open the serial com, wait until ready, respond with success when ready
 * @return void
 */
void setup() {
  Serial.begin(BAUD_RATE);
  while (!Serial) ; 
  Serial.println(RESPONSE_SUCCESS);
}

/**
 * Main loop handler
 * @return void
 */
void loop() {
  // no-op
}

/**
 * Serial Event handler
 * @return void
 */
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

/**
 * Reads an input string from the serial input and copies data to buffer
 * @param buf buffer to hold input data
 * @return bool true if successful, false otherwise
 */
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

/**
 * Parses serfial buffer into input array
 * @param buf buffer of serial data
 * @param input array of parsed input
 * @return void
 */
void parseInput(char *buf, int *input) {
  int j = 0;
  for (int i = 0; i < strlen(buf); i += 2) {
    int d = hexByteAt(buf, i);
    input[j] = d;
    j++;
  }
}

/**
 * Parses 2 chars from buf at index and returns the hex value
 * @param buf char array of hex values
 * @param i buffer index of byte
 * @return int hex value of byte
 */
int hexByteAt(char *buf, int i) {
  int d;
  char str[] = { buf[i], buf[i + 1] };
  sscanf(str, "%x", &d);
  return d;
}
