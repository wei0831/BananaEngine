/******************************************************************************/
/*!
\file   Transform.h
\author Jack Chang
\date   10/09/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/
#pragma once

#include "IComponent.h"

class Sprite : public IComponent
{
public:
  Sprite() : IComponent("Sprite"){}




  SERIALIZE_BLOCK()
  {
//     SERIALIZE_ADD(translation);
//     SERIALIZE_ADD(rotation);
//     SERIALIZE_ADD(scale);
  }

private:

};
