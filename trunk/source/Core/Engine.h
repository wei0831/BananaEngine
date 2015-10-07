#pragma once

#include "ISystem.h"

class Engine : ISystem
{
public:
  void run();
  virtual void init();
  virtual void shutdown();
  virtual void update();

private:
  
};