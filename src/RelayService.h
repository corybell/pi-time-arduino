#pragma once
#include "constants.h"
#include <Wire.h>

/**
 * This class handles all relay board communication via Wire.
 * Encapsulates all logic for sending and recieving data to/from relays.
 */
class RelayService
{
  private:
    void Send(int address, int *commands, int commandLength);
    bool Request(int address, int quantity, int *payload);
  public:
    void Toggle(int address, int command);
    int Status(int address, int command);
    RelayService();
    ~RelayService();
};

/**
 * Retrieves the status of the relay
 * @param address board address
 * @param command status command
 * @return int relay status
 */
int RelayService::Status(int address, int command)
{
  int sCommand[1] = { command };
  this->Send(address, sCommand , 1);
  int payload;
  if (!this->Request(address, 4, &payload)) {
    return RELAY_STATUS_ERROR;
  }
  return payload;
}

/**
 * Sends a toggle command to the relay
 * @param address board address
 * @param command toggle command
 * @return void
 */
void RelayService::Toggle(int address, int command)
{
  int tCommand[1] = { command };
  this->Send(address, { tCommand }, 1);
}

/**
 * Sends a command to the relay
 * @param address board address
 * @param commands relay commands
 * @param commandLength number of commands
 * @return void
 */
void RelayService::Send(int address, int *commands, int commandLength)
{
  Wire.beginTransmission(address);
  for (int i = 0; i < commandLength; i++)
  {
    Wire.write(commands[i]);
  }
  Wire.endTransmission();
}

/**
 * Requests data from the relay
 * @param address board address
 * @param quantity number of bytes to request
 * @param payload reference to output payload
 * @return bool
 */
bool RelayService::Request(int address, int quantity, int *payload)
{
  Wire.requestFrom(address, quantity); 
  
  if (!Wire.available()){
    return false;
  }

  *payload = Wire.read();
  return true;
}

RelayService::RelayService()
{
  Wire.begin();
}

RelayService::~RelayService()
{
}
