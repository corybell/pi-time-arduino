#pragma once
#include "IDeviceHandler.h"
#include "RelayHandler.h"

class DeviceMapper
{
  public:
    IDeviceHandler* Map(int deviceBit);
    DeviceMapper();
    ~DeviceMapper();
};

IDeviceHandler* DeviceMapper::Map(int deviceBit)
{
  switch (deviceBit){
    case 0:
      return new RelayHandler();
  } 
  return NULL;
}

DeviceMapper::DeviceMapper()
{
}

DeviceMapper::~DeviceMapper()
{
}
