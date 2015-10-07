/******************************************************************************/
/*!
\file   main.cpp
\author Jack Chang
\date   10/06/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief

*/
/******************************************************************************/
#include "Precompiled.h"
#include "Engine.h"
#include "vld.h"

int main()
{
  SetConsoleTitle(TEXT("Banana Engine - Console Window"));

  Engine e;
  e.run();

  getchar();
  return 0;
}


