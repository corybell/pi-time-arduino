#pragma once
#include "IDeviceHandler.h"
#include "RelayHandler.h"

/**
 * This class maps a device bit to a device handler
 */
class DeviceMapper
{
  public:
    IDeviceHandler* Map(int deviceBit);
    DeviceMapper();
    ~DeviceMapper();
};

/**
 * Maps a deviceBit to an IDeviceHandler
 * @param deviceBit the deviceBit to map
 * @return an IDeviceHandler to handle the request
 */
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
