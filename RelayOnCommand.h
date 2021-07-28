#pragma once
#include "constants.h"
#include "IRelayCommand.h"
#include "RelayService.h"

class RelayOnCommand : public IRelayCommand
{
  public:
    virtual bool Execute(RelayConfig relayConfig, RelayService relayService) override;
    RelayOnCommand();
    ~RelayOnCommand();
};

bool RelayOnCommand::Execute(RelayConfig relayConfig, RelayService relayService)
{
  int status = relayService.Status(relayConfig.address, relayConfig.statusCommand);
  if (status == -1)
  {
    return false;
  }
  
  if (status == 0)
  {
    relayService.Toggle(relayConfig.address, relayConfig.toggleCommand);
  } 
  
  return true;
}

RelayOnCommand::RelayOnCommand()
{
}

RelayOnCommand::~RelayOnCommand()
{
}
