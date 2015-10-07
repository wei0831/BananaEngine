/******************************************************************************/
/*!
\file   DebugTool.h
\author Jack Chang
\date   10/06/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief

*/
/******************************************************************************/
#include "Precompiled.h"

void PrintError(const char *exp, const char *file, int line, const char *msg, ...)
{
  const int BufferSize = 2048;
  char formattedMsg[BufferSize];

  // Print out the file and line in visual studio format so the error can be
  // double clicked in the output window file(line) : error
  int offset = std::sprintf(formattedMsg, "%s(%d) : ", file, line);
  if (msg != NULL)
  {
    va_list args;
    va_start(args, msg);
    vsnprintf(formattedMsg + offset, BufferSize, msg, args);
    vfprintf(stderr, msg, args);
    va_end(args);
  }
  else
  {
    std::strcpy(formattedMsg + offset, "No Error Message");
    fprintf(stderr, formattedMsg);
  }

  fprintf(stderr, "\n");
}