#pragma once

class IDeviceHandler
{
  public:
    virtual void Handle(int i, int c);
    IDeviceHandler();
    ~IDeviceHandler();
};

void IDeviceHandler::Handle(int i, int c)
{
}

IDeviceHandler::IDeviceHandler()
{
}

IDeviceHandler::~IDeviceHandler()
{
}
