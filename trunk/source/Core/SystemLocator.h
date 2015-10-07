/******************************************************************************/
/*!
\file   SystemLocator.h
\author Jack Chang
\date   10/09/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief

*/
/******************************************************************************/
#pragma once

#include "IGraphics.h"
#include "NullGraphics.h"
#include "IAudio.h"
#include "NullAudio.h"
#include "IPhysics.h"
#include "NullPhysics.h"
#include "IInput.h"
#include "NullInput.h"

class SystemLocator
{
public:

  static void init()
  {
    graphics_ = &null_graphics_;
    audio_ = &null_audio_;
    physics_ = &null_physics_;
    input_ = &null_input_;
  }

  static void clear()
  {

    graphics_->shutdown();
    audio_->shutdown();
    physics_->shutdown();
    input_->shutdown();

    if (graphics_ != &null_graphics_)
      delete graphics_;
    if (audio_ != &null_audio_)
      delete audio_;
    if (physics_ != &null_physics_)
      delete physics_;
    if (input_ != &null_input_)
      delete input_;
  }

  static IGraphics* getGraphics() { return graphics_; }
  static IAudio* getAudio() { return audio_; }
  static IPhysics* getPhysics() { return physics_; }
  static IInput* getInput() { return input_; }

  static void provide(IGraphics* service)
  {
    if (service == nullptr)
      graphics_ = &null_graphics_;
    else if (service != graphics_)
    {
      if (graphics_ != &null_graphics_)
        delete graphics_;
      graphics_ = service;
    }
  }
  static void provide(IAudio* service)
  {
    if (service == nullptr)
      audio_ = &null_audio_;
    else if (service != audio_)
    {
      if (audio_ != &null_audio_)
        delete audio_;
      audio_ = service;
    }
  }
  static void provide(IPhysics* service)
  {
    if (service == nullptr)
      physics_ = &null_physics_;
    else if (service != physics_)
    {
      if (physics_ != &null_physics_)
        delete physics_;
      physics_ = service;
    }
  }
  static void provide(IInput* service)
  {
    if (service == nullptr)
      input_ = &null_input_;
    else if (service != input_)
    {
      if (input_ != &null_input_)
        delete input_;
      input_ = service;
    }
  }

private:
  static IGraphics* graphics_;
  static NullGraphics null_graphics_;

  static IAudio* audio_;
  static NullAudio null_audio_;

  static IPhysics* physics_;
  static NullPhysics null_physics_;

  static IInput* input_;
  static NullInput null_input_;
};

