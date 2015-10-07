/******************************************************************************/
/*!
\file   IProcess.h
\author Jack Chang
\date   10/09/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
Example of Process
*/
/******************************************************************************/
#pragma once
#include <singalslot/nano_signal_slot.hpp>
#include "GameObject.h"

class IProcess
{
public:
  IProcess() : name("ProcessUnknown"){}
  IProcess(std::string s) : name(s){}

  virtual bool update(GameObject* go) = 0;

  // No need to modify
  virtual void emit();
  virtual void connect(GameObject* go);
  virtual void disconnect(GameObject* go);
  virtual const char* GetName();

private:
  Nano::Signal<bool(IProcess*)> sig;
  std::string name;
};
