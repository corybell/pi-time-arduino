#pragma once
#include "IDeviceHandler.h"
#include "RelayService.h"
#include "RelaySettingsMapper.h"
#include "RelayCommandMapper.h"

RelaySettingsMapper relaySettingsMapper;
RelayCommandMapper relayCommandMapper;
RelayService relayService;

/**
 * Relay implementation of IDeviceHandler
 */
class RelayHandler : public IDeviceHandler
{
  public:
    void Handle(int indexBit, int commandBit) override;
    RelayHandler();
    ~RelayHandler();
};

/**
 * Handles the request for the given index and command bits
 * @param indexBit the index bit
 * @param commandBit the command bit
 * @return void
 */
void RelayHandler::Handle(int indexBit, int commandBit)
{
  // map settings
  auto relaySettings(relaySettingsMapper.Map(indexBit));
  if (relaySettings == NULL) 
  {
    Serial.println(RESPONSE_BAD_REQUEST);
    return;
  }

  // map command
  auto command(relayCommandMapper.Map(commandBit));
  if (command == NULL) 
  {
    Serial.println(RESPONSE_BAD_REQUEST);
    return;
  }
  
  // execute
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
