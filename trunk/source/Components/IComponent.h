/******************************************************************************/
/*!
\file   IComponent.h
\author Jack Chang
\date   10/06/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/
#pragma once

#include <string>
#include <cereal/archives/json.hpp>
#include <cereal/types/polymorphic.hpp>

#define SERIALIZE_BLOCK()   \
  template <class Archive>   \
  void serialize(Archive & ar)
#define SERIALIZE_ADD(ITEM)  \
  ar(CEREAL_NVP(ITEM))
#define SERIALIZE_ADD_CUSTOMNAME(NAME, ITEM)  \
  ar(cereal::make_nvp(NAME, ITEM))
#define SERIALIZE_ADD_BASE(BASETYPE)  \
  ar(cereal::base_class<BASETYPE>(this));

class IComponent
{
public:
  IComponent() : type("IComponent"){}
  virtual std::string GetTypeName() { return type; }

  SERIALIZE_BLOCK()
  {
    SERIALIZE_ADD(type);
  }

protected:
  IComponent(const char * name_) : type(name_){}

private:
  std::string type;
};
