#pragma once

/**
 * Interface for device handlers 
 */
class IDeviceHandler
{
  public:
    virtual void Handle(int indexBit, int commandBit);
    IDeviceHandler();
    ~IDeviceHandler();
};

/**
 * Handles the request for the given index and command bits
 * @param indexBit the index bit
 * @param commandBit the command bit
 * @return void
 */
void IDeviceHandler::Handle(int indexBit, int commandBit)
{
}

IDeviceHandler::IDeviceHandler()
{
}

IDeviceHandler::~IDeviceHandler()
{
}
