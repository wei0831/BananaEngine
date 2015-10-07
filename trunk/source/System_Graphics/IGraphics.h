/******************************************************************************/
/*!
\file   IGraphics.cpp
\author Jack Chang
\date   10/09/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/
#pragma once
#include "ISystem.h"

class IGraphics : public ISystem
{
public:

  virtual ~IGraphics(){}

  virtual void init() = 0;
  virtual void shutdown() = 0;
  virtual void update() = 0;

  // New 
  virtual void draw() = 0;
};
