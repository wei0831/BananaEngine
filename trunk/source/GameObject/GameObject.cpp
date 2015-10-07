/******************************************************************************/
/*!
\file   GameObject.cpp
\author Jack Chang
\date   10/09/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/
#include "Precompiled.h"
#include "GameObject.h"
#include "IProcess.h"

GameObject::~GameObject()
{
  UnSubscribeAll();
}

void GameObject::Init()
{
}

void GameObject::AddComponent(std::shared_ptr<IComponent> cp)
{
  auto result = components.insert(
    std::pair<std::string, std::shared_ptr<IComponent>>(cp->GetTypeName(), cp));
  ErrorIf(!result.second, "Try to Insert Duplicated Component");
}

void GameObject::RemoveComponent(std::string s)
{
  components.erase(s);
}

std::shared_ptr<IComponent> GameObject::GetComponent(std::string s)
{
  std::map<std::string, std::shared_ptr<IComponent>>::iterator it;
  it = components.find(s);

  if (it == components.end())
    return nullptr;
  else
    return it->second;
}

void GameObject::SubscribeTo(IProcess* ip)
{
  ip->connect(this);
  processors.emplace(ip->GetName(), ip);
}

bool GameObject::UpdateSubscriber(IProcess* ip)
{
  ip->update(this);
  return true;
}

void GameObject::UnsubscribeTo(IProcess* ip)
{
  ip->disconnect(this);
  processors.erase(ip->GetName());
}

NOTE("We expected all processors will be alive the entire program.")
void GameObject::UnSubscribeAll()
{
  for (std::map<const char*, IProcess *>::iterator it = processors.begin(); it != processors.end(); ++it)
  {
    it->second->disconnect(this);
  }
}
