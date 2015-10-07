/******************************************************************************/
/*!
\file   NullAudio.cpp
\author Jack Chang
\date   10/09/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/
#pragma once
#include "IAudio.h"

class NullAudio : public IAudio
{
public:

  virtual ~NullAudio(){}
  virtual void init(){}
  virtual void shutdown(){}
  virtual void update(){}
};
