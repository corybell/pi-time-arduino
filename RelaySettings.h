#pragma once

class RelaySettings
{
  public:
    int address, statusCommand, toggleCommand;
    RelaySettings(int a, int s, int t);
    ~RelaySettings();
};


RelaySettings::RelaySettings(int a, int s, int t)
{
  this->address = a;
  this->statusCommand = s;
  this->toggleCommand = t;
}

RelaySettings::~RelaySettings()
{
}
