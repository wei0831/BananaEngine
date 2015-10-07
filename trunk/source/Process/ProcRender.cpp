/******************************************************************************/
/*!
\file   ProcRender.cpp
\author Jack Chang
\date   10/16/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/
#include "Precompiled.h"
#include "ProcRender.h"

bool ProcRender::update(GameObject* go)
{
  std::cout << "Render Object: " << go->name << std::endl;
  go->name += "_RenderOnce";
  return true;
}