#pragma once
#include "IRelayCommand.h"
#include "RelayOffCommand.h"
#include "RelayOnCommand.h"

class RelayCommandMapper
{
  public:
    IRelayCommand* Map(int commandBit);
    RelayCommandMapper();
    ~RelayCommandMapper();
};

IRelayCommand* RelayCommandMapper::Map(int commandBit)
{
  switch (commandBit){
    case 0:
      return new RelayOffCommand();
    case 1:
      return new RelayOnCommand();
  }
  
  return NULL;
}

RelayCommandMapper::RelayCommandMapper()
{
}

RelayCommandMapper::~RelayCommandMapper()
{
}
