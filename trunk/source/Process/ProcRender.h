/******************************************************************************/
/*!
\file   ProcRender.h
\author Jack Chang
\date   10/16/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/
#include "IProcess.h"

class ProcRender : public IProcess
{
public:
  ProcRender() : IProcess("ProcRender"){}
  virtual bool update(GameObject* go);
};