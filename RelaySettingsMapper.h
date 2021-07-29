#pragma once
#include "RelaySettings.h"

/**
 * This class maps a relay index to a settings model
 */
class RelaySettingsMapper
{
  public:
    RelaySettings* Map(int i);
    RelaySettingsMapper();
    ~RelaySettingsMapper();
};

/**
 * Maps a relay index to RelaySettings
 * @param i relay index
 * @return RelaySettings
 */
RelaySettings* RelaySettingsMapper::Map(int i)
{
  switch (i){
    case 0:
      return new RelaySettings(BOARD_1_ADDRESS, RELAY_1_STATUS, RELAY_1_TOGGLE);
    case 1:
      return new RelaySettings(BOARD_1_ADDRESS, RELAY_2_STATUS, RELAY_2_TOGGLE);
    case 2:
      return new RelaySettings(BOARD_1_ADDRESS, RELAY_3_STATUS, RELAY_3_TOGGLE);
    case 3:
      return new RelaySettings(BOARD_1_ADDRESS, RELAY_4_STATUS, RELAY_4_TOGGLE);
  } 
  return NULL; 
}

RelaySettingsMapper::RelaySettingsMapper()
{
}

RelaySettingsMapper::~RelaySettingsMapper()
{
}
