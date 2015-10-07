/******************************************************************************/
/*!
\file   NullGraphics.cpp
\author Jack Chang
\date   10/09/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/
#pragma once
#include "IGraphics.h"

class NullGraphics : public IGraphics
{
public:
  void init(){}
  void shutdown(){}
  void update(){}
  void draw(){}
};
