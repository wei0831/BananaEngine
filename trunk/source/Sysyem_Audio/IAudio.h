/******************************************************************************/
/*!
\file   IAudio.cpp
\author Jack Chang
\date   10/09/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/
#pragma once
#include "ISystem.h"

class IAudio : public ISystem
{
public:
  virtual ~IAudio(){}
  virtual void init() = 0;
  virtual void shutdown() = 0;
  virtual void update() = 0;
};
