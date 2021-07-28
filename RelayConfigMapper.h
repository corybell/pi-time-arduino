#pragma once
#include "constants.h"

struct RelayConfig {
  int address, statusCommand, toggleCommand;
};

class RelayConfigMapper
{
  private:
    RelayConfig RelayConfigs[RELAY_COUNT] = {
        { BOARD_1_ADDRESS, RELAY_1_STATUS, RELAY_1_TOGGLE },
        { BOARD_1_ADDRESS, RELAY_2_STATUS, RELAY_2_TOGGLE },
        { BOARD_1_ADDRESS, RELAY_3_STATUS, RELAY_3_TOGGLE },
        { BOARD_1_ADDRESS, RELAY_4_STATUS, RELAY_4_TOGGLE },
    };
  public:
    RelayConfig *Map(int i);
    RelayConfigMapper();
    ~RelayConfigMapper();
};

RelayConfig* RelayConfigMapper::Map(int i)
{
  if (i > RELAY_COUNT || i < 0) {
    return NULL;
  }
  
  RelayConfig r = this->RelayConfigs[i];
  
  RelayConfig *p = malloc(sizeof(RelayConfig));
  p->address = r.address;
  p->statusCommand = r.statusCommand;
  p->toggleCommand = r.toggleCommand;
  
  return p;
}

RelayConfigMapper::RelayConfigMapper()
{
}

RelayConfigMapper::~RelayConfigMapper()
{
}
