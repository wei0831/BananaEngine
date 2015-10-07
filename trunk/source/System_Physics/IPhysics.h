/******************************************************************************/
/*!
\file   IPhysics.cpp
\author Jack Chang
\date   10/09/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/
#pragma once
#include "ISystem.h"

class IPhysics : public ISystem
{
public:
  virtual ~IPhysics(){}
  virtual void init() = 0;
  virtual void shutdown() = 0;
  virtual void update() = 0;
};
