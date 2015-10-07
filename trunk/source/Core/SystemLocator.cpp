/******************************************************************************/
/*!
\file   SystemLocator.cpp
\author Jack Chang
\date   10/09/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief

*/
/******************************************************************************/
#include "Precompiled.h"
#include "SystemLocator.h"

IGraphics* SystemLocator::graphics_;
NullGraphics SystemLocator::null_graphics_;

IInput* SystemLocator::input_;
NullInput SystemLocator::null_input_;

IAudio* SystemLocator::audio_;
NullAudio SystemLocator::null_audio_;

IPhysics* SystemLocator::physics_;
NullPhysics SystemLocator::null_physics_;
