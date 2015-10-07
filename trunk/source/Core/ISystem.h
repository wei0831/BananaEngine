#pragma once

class ISystem
{
public:
  virtual void init() = 0;
  virtual void shutdown() = 0;

  virtual void update() = 0;

  virtual bool isShutDown() { return isShutdown; }

protected:
  bool isShutdown;
};