#pragma once
#include "RelaySettings.h"
#include "IRelayCommand.h"
#include "RelayService.h"

class RelayOnCommand : public IRelayCommand
{
  public:
    virtual bool Execute(RelaySettings relaySettings, RelayService relayService) override;
    RelayOnCommand();
    ~RelayOnCommand();
};

bool RelayOnCommand::Execute(RelaySettings relaySettings, RelayService relayService)
{
  int status = relayService.Status(relaySettings.address, relaySettings.statusCommand);
  if (status == -1)
  {
    return false;
  }
  
  if (status == 0)
  {
    relayService.Toggle(relaySettings.address, relaySettings.toggleCommand);
  } 
  
  return true;
}

RelayOnCommand::RelayOnCommand()
{
}

RelayOnCommand::~RelayOnCommand()
{
}
