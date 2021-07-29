#pragma once

/**
 * Relay Settings model
 * Holds a board address, status command, and toggle command
 */
class RelaySettings
{
  public:
    int address, statusCommand, toggleCommand;
    RelaySettings(int address, int statusCommand, int toggleCommand);
    ~RelaySettings();
};

/**
 * Constructor
 * @param address board address
 * @param statusCommand status command
 * @param toggleCommand toggle command
 */
RelaySettings::RelaySettings(int address, int statusCommand, int toggleCommand)
{
  this->address = address;
  this->statusCommand = statusCommand;
  this->toggleCommand = toggleCommand;
}

RelaySettings::~RelaySettings()
{
}
