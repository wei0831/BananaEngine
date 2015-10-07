/******************************************************************************/
/*!
\file   IProcess.cpp
\author Jack Chang
\date   10/09/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/
#include "Precompiled.h"
#include "IProcess.h"

void IProcess::emit()
{
  std::cout << "[Emit Messages...]" << std::endl;
  sig(this);
}

void IProcess::connect(GameObject* go)
{
  sig.connect<GameObject, &GameObject::UpdateSubscriber>(go);
  std::cout << go->name << " [Connected]" << std::endl;
}

void IProcess::disconnect(GameObject* go)
{
  sig.disconnect<GameObject, &GameObject::UpdateSubscriber>(go);
  std::cout << go->name << " [Disconnected]" << std::endl;
}

const char* IProcess::GetName()
{
  return name.c_str();
}