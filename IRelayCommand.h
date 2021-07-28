#pragma once
#include "RelaySettings.h"
#include "RelayService.h"

class IRelayCommand
{
  public:
    virtual bool Execute(RelaySettings relaySettings, RelayService relayService);
    IRelayCommand();
    ~IRelayCommand();
};

bool IRelayCommand::Execute(RelaySettings relaySettings, RelayService relayService)
{
}

IRelayCommand::IRelayCommand()
{
}

IRelayCommand::~IRelayCommand()
{
}
