/******************************************************************************/
/*!
\file   IInput.cpp
\author Jack Chang
\date   10/09/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/
#pragma once
#include "ISystem.h"

class IInput : public ISystem
{
public:

  virtual ~IInput(){}
  virtual void init() = 0;
  virtual void shutdown() = 0;
  virtual void update() = 0;

  virtual bool GetKeyPressed(int keycode) = 0;
  virtual bool GetKeyReleased(int keycode) = 0;
  virtual bool GetKeyClicked(int keycode) = 0;
  virtual bool GetMousePressed(int mouseBtn) = 0;
  virtual bool GetMouseReleased(int mouseBtn) = 0;
  virtual bool GetMouseClicked(int mouseBtn) = 0;
};
