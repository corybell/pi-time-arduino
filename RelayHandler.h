#pragma once
#include "IDeviceHandler.h"
#include "RelayService.h"
#include "RelaySettingsMapper.h"
#include "RelayCommandMapper.h"

RelaySettingsMapper relaySettingsMapper;
RelayCommandMapper relayCommandMapper;
RelayService relayService;

class RelayHandler : public IDeviceHandler
{
  public:
    void Handle(int i, int c) override;
    RelayHandler();
    ~RelayHandler();
};

void RelayHandler::Handle(int i, int c)
{ 
  auto relaySettings(relaySettingsMapper.Map(i));
  if (relaySettings == NULL) 
  {
    Serial.println(RESPONSE_BAD_REQUEST);
    return;
  }

  auto command(relayCommandMapper.Map(c));
  if (command == NULL) 
  {
    Serial.println(RESPONSE_BAD_REQUEST);
    return;
  }
  
  if (!command->Execute(*relaySettings, relayService))
  {
    Serial.println(RESPONSE_ERROR);
  } 
  else
  {
    Serial.println(RESPONSE_SUCCESS);   
  }

  relaySettings = NULL;
  command = NULL;
}

RelayHandler::RelayHandler()
{
}

RelayHandler::~RelayHandler()
{
}
