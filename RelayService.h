#pragma once
#include <Wire.h>

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

int RelayService::Status(int address, int command)
{
  int sCommand[1] = { command };
  this->Send(address, sCommand , 1);
  int payload;
  if (!this->Request(address, 4, &payload)) {
    return -1;
  }
  return payload;
}

void RelayService::Toggle(int address, int command)
{
  int tCommand[1] = { command };
  this->Send(address, { tCommand }, 1);
}

void RelayService::Send(int address, int *commands, int commandLength)
{
  Wire.beginTransmission(address);
  for (int i = 0; i < commandLength; i++)
  {
    Wire.write(commands[i]);
  }
  Wire.endTransmission();
}

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
