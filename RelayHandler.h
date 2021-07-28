#pragma once
#include "IDeviceHandler.h"
#include "RelayService.h"
#include "RelayConfigMapper.h"
#include "RelayCommandMapper.h"

RelayConfigMapper relayConfigMapper;
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
  RelayConfig* relayConfig = relayConfigMapper.Map(i);
  if (relayConfig == NULL) 
  {
    Serial.println(RESPONSE_BAD_REQUEST);
    return;
  }

  auto command(relayCommandMapper.Map(c));

  if (!command->Execute(*relayConfig, relayService))
  {
    Serial.println(RESPONSE_ERROR);
  } 
  else
  {
    Serial.println(RESPONSE_SUCCESS);   
  }

  relayConfig = NULL;
  command = NULL;
}

RelayHandler::RelayHandler()
{
}

RelayHandler::~RelayHandler()
{
}
