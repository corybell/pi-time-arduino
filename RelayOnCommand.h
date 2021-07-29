#pragma once
#include "RelaySettings.h"
#include "IRelayCommand.h"
#include "RelayService.h"

/**
 * Command to turn on relay
 */
class RelayOnCommand : public IRelayCommand
{
  public:
    virtual bool Execute(RelaySettings relaySettings, RelayService relayService) override;
    RelayOnCommand();
    ~RelayOnCommand();
};

/**
 * Executes the relay command
 * @param relaySettings the relay settings
 * @param relayService the relay service
 * @return true if the command was successful, flase otherwise
 */
bool RelayOnCommand::Execute(RelaySettings relaySettings, RelayService relayService)
{
  int status = relayService.Status(relaySettings.address, relaySettings.statusCommand);
  if (status == RELAY_STATUS_OFF)
  {
    return false;
  }
  
  if (status == RELAY_STATUS_OFF)
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
