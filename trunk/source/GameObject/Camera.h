/******************************************************************************/
/*!
\file   Camera.h
\author Jack Chang
\date   10/10/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief

*/
/******************************************************************************/
#pragma once

#include "GameObject.h"
#include "Transform.h"
#include "BoxCollider.h"

class Camera : public GameObject
{
public:
  Camera() : GameObject("Camera") { Init(); }
  Camera(const char * name_) : GameObject(name_){ Init(); }

  virtual void Init()
  {
    AddComponent(std::make_shared<Transform>());
  };

  SERIALIZE_BLOCK()
  {
    SERIALIZE_ADD_BASE(GameObject);
  }
};
