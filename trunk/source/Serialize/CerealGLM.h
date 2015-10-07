/******************************************************************************/
/*!
\file   CerealGLM.h
\author Jack Chang
\date   10/06/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief

*/
/******************************************************************************/
#pragma once

#include <cereal/cereal.hpp>
#include <glm/glm.hpp>

namespace cereal 
{
  template<class Archive>
  void serialize(Archive& ar, glm::vec2& v) {
    ar(cereal::make_nvp("x", v.x));
    ar(cereal::make_nvp("y", v.y));
  }

  template<class Archive>
  void serialize(Archive& ar, glm::vec3& v) {
    ar(cereal::make_nvp("x", v.x));
    ar(cereal::make_nvp("y", v.y));
    ar(cereal::make_nvp("z", v.z));
  }

  template<class Archive>
  void serialize(Archive& ar, glm::vec4& v) {
    ar(cereal::make_nvp("x", v.x));
    ar(cereal::make_nvp("y", v.y));
    ar(cereal::make_nvp("z", v.z));
    ar(cereal::make_nvp("w", v.w));
  }

  template<class Archive>
  void serialize(Archive& ar, glm::mat3& m) {
    ar(cereal::make_nvp("11", m.operator[0][0]));
    ar(cereal::make_nvp("12", m.operator[0][1]));
    ar(cereal::make_nvp("13", m.operator[0][2]));
    ar(cereal::make_nvp("21", m.operator[1][0]));
    ar(cereal::make_nvp("22", m.operator[1][1]));
    ar(cereal::make_nvp("23", m.operator[1][2]));
    ar(cereal::make_nvp("31", m.operator[2][0]));
    ar(cereal::make_nvp("32", m.operator[2][1]));
    ar(cereal::make_nvp("33", m.operator[2][2]));
    ar(cereal::make_nvp("41", m.operator[3][0]));
    ar(cereal::make_nvp("42", m.operator[3][1]));
    ar(cereal::make_nvp("43", m.operator[3][2]));
  }

  template<class Archive>
  void serialize(Archive& ar, glm::mat4& m) {
    ar(cereal::make_nvp("11", m.operator[0][0]));
    ar(cereal::make_nvp("12", m.operator[0][1]));
    ar(cereal::make_nvp("13", m.operator[0][2]));
    ar(cereal::make_nvp("14", m.operator[0][3]));
    ar(cereal::make_nvp("21", m.operator[1][0]));
    ar(cereal::make_nvp("22", m.operator[1][1]));
    ar(cereal::make_nvp("23", m.operator[1][2]));
    ar(cereal::make_nvp("24", m.operator[1][3]));
    ar(cereal::make_nvp("31", m.operator[2][0]));
    ar(cereal::make_nvp("32", m.operator[2][1]));
    ar(cereal::make_nvp("33", m.operator[2][2]));
    ar(cereal::make_nvp("34", m.operator[2][3]));
    ar(cereal::make_nvp("41", m.operator[3][0]));
    ar(cereal::make_nvp("42", m.operator[3][1]));
    ar(cereal::make_nvp("43", m.operator[3][2]));
    ar(cereal::make_nvp("44", m.operator[3][3]));
  }
}
