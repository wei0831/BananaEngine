/******************************************************************************/
/*!
\file   BoxCollider.h
\author Jack Chang
\date   10/09/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/
#pragma once

#include "IComponent.h"
#include "Transform.h"

class BoxCollider : public IComponent
{
public:
  BoxCollider() : IComponent("BoxCollider"), ghost(false)
  {}

  Transform local_transform;
  bool ghost;

  SERIALIZE_BLOCK()
  {
    SERIALIZE_ADD(local_transform);
    SERIALIZE_ADD(ghost);
  }
};
