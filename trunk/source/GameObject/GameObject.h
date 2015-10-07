/******************************************************************************/
/*!
\file   GameObject.h
\author Jack Chang
\date   10/09/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/
#pragma once
#include "IComponent.h"
#include <singalslot/nano_signal_slot.hpp>

// Forward Declaration 
class IProcess;

class GameObject : public Nano::Observer
{
public:
  GameObject() : name("GameObject"){ Init(); }
  GameObject(const char * name_) : name(name_){ Init(); }

  ~GameObject();
  virtual void Init();

  // Do Not Need Touch
  virtual void AddComponent(std::shared_ptr<IComponent> cp);
  virtual void RemoveComponent(std::string s);
  virtual std::shared_ptr<IComponent> GetComponent(std::string s);

  // Slot
  virtual void SubscribeTo(IProcess*);
  virtual bool UpdateSubscriber(IProcess*);
  virtual void UnsubscribeTo(IProcess*);

  std::string name;

  SERIALIZE_BLOCK()
  {
    SERIALIZE_ADD(name);
    SERIALIZE_ADD(components);
  }

private:
  std::map<std::string, std::shared_ptr<IComponent>> components;
  std::map<const char*, IProcess *> processors;
  virtual void UnSubscribeAll();
};

typedef std::shared_ptr<IComponent> ComponentPtr;
typedef std::shared_ptr<GameObject> GameObjectPtr;
