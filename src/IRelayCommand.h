#pragma once
#include "RelaySettings.h"
#include "RelayService.h"

/**
 * Interface for relay commands
 */
class IRelayCommand
{
  public:
    virtual bool Execute(RelaySettings relaySettings, RelayService relayService);
    IRelayCommand();
    ~IRelayCommand();
};

/**
 * Executes the relay command
 * @param relaySettings the relay settings
 * @param relayService the relay service
 * @return true if the command was successful, flase otherwise
 */
bool IRelayCommand::Execute(RelaySettings relaySettings, RelayService relayService)
{
}

IRelayCommand::IRelayCommand()
{
}

IRelayCommand::~IRelayCommand()
{
}
