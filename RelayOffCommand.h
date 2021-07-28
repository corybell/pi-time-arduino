#pragma once
#include "RelaySettings.h"
#include "IRelayCommand.h"
#include "RelayService.h"

class RelayOffCommand : public IRelayCommand
{
  public:
    virtual bool Execute(RelaySettings relaySettings, RelayService relayService) override;
    RelayOffCommand();
    ~RelayOffCommand();
};

bool RelayOffCommand::Execute(RelaySettings relaySettings, RelayService relayService)
{
  int status = relayService.Status(relaySettings.address, relaySettings.statusCommand);
  if (status == -1)
  {
    return false;
  }

  if (status == 15)
  {
    relayService.Toggle(relaySettings.address, relaySettings.toggleCommand);
  } 
  
  return true;
}

RelayOffCommand::RelayOffCommand()
{
}

RelayOffCommand::~RelayOffCommand()
{
}
