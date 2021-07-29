#pragma once
#include "IRelayCommand.h"
#include "RelayOffCommand.h"
#include "RelayOnCommand.h"

/**
 * This class is maps a command bit to a relay command
 */
class RelayCommandMapper
{
  public:
    IRelayCommand* Map(int commandBit);
    RelayCommandMapper();
    ~RelayCommandMapper();
};

/**
 * Maps a commandBit to an IRelayCommand
 * @param commandBit the commandBit to map
 * @return IRelayCommand
 */
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
