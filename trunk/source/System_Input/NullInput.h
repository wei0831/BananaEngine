/******************************************************************************/
/*!
\file   NullInput.cpp
\author Jack Chang
\date   10/09/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/
#pragma once
#include "IInput.h"

class NullInput : public IInput
{
public:

  virtual ~NullInput(){}
  virtual void init(){}
  virtual void shutdown(){}
  virtual void update(){}

  virtual bool GetKeyPressed(int keycode) { return false; }
  virtual bool GetKeyReleased(int keycode){ return false; }
  virtual bool GetKeyClicked(int keycode) { return false; }
  virtual bool GetMousePressed(int mouseBtn) { return false; }
  virtual bool GetMouseReleased(int mouseBtn) { return false; }
  virtual bool GetMouseClicked(int mouseBtn){ return false; }
};
