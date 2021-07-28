#pragma once
#include "constants.h"
#include "IRelayCommand.h"
#include "RelayService.h"

class RelayOffCommand : public IRelayCommand
{
  public:
    virtual bool Execute(RelayConfig relayConfig, RelayService relayService) override;
    RelayOffCommand();
    ~RelayOffCommand();
};

bool RelayOffCommand::Execute(RelayConfig relayConfig, RelayService relayService)
{
  int status = relayService.Status(relayConfig.address, relayConfig.statusCommand);
  if (status == -1)
  {
    return false;
  }

  if (status == 15)
  {
    relayService.Toggle(relayConfig.address, relayConfig.toggleCommand);
  } 
  
  return true;
}

RelayOffCommand::RelayOffCommand()
{
}

RelayOffCommand::~RelayOffCommand()
{
}
