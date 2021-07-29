#pragma once
#include "constants.h"
#include "RelaySettings.h"
#include "IRelayCommand.h"
#include "RelayService.h"

/**
 * Command to turn off relay
 */
class RelayOffCommand : public IRelayCommand
{
  public:
    virtual bool Execute(RelaySettings relaySettings, RelayService relayService) override;
    RelayOffCommand();
    ~RelayOffCommand();
};

/**
 * Executes the relay command
 * @param relaySettings the relay settings
 * @param relayService the relay service
 * @return true if the command was successful, flase otherwise
 */
bool RelayOffCommand::Execute(RelaySettings relaySettings, RelayService relayService)
{
  int status = relayService.Status(relaySettings.address, relaySettings.statusCommand);
  if (status == RELAY_STATUS_ERROR)
  {
    return false;
  }

  if (status == RELAY_STATUS_ON)
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
