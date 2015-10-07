#pragma once

class IManager
{
public:
  virtual void init() = 0;
  virtual void shutdown() = 0;

  virtual bool isIntitalized() { return isInitalized; }
  virtual bool isShutDown() { return isShutdown; }
protected:
  bool isShutdown;
  bool isInitalized;
};