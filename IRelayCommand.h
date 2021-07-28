#pragma once
#include "constants.h"
#include "RelayService.h"

class IRelayCommand
{
  public:
    virtual bool Execute(RelayConfig relayConfig, RelayService relayService);
    IRelayCommand();
    ~IRelayCommand();
};

bool IRelayCommand::Execute(RelayConfig relayConfig, RelayService relayService)
{
}

IRelayCommand::IRelayCommand()
{
}

IRelayCommand::~IRelayCommand()
{
}
