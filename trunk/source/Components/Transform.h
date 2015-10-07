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

class Transform : public IComponent
{
public:
  Transform() : IComponent("Transform"),
    translation(0.0f, 0.0f), rotation(0.0f, 0.0f), scale(1.f, 1.f)
  {}

  glm::vec2 translation;
  glm::vec2 rotation;
  glm::vec2 scale;

  SERIALIZE_BLOCK()
  {
    SERIALIZE_ADD(translation);
    SERIALIZE_ADD(rotation);
    SERIALIZE_ADD(scale);
  }
};
