/******************************************************************************/
/*!
\file   Debug.h
\author Jack Chang
\date   10/06/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief

*/
/******************************************************************************/
#pragma once
#include <stdio.h>
#include <stdarg.h> 

// Define the debug break using the MS specific or general using assembly interrupt 3
#ifdef _MSC_VER
#define DEBUG_BREAK __debugbreak()
#else
#define DEBUG_BREAK do { __asm int 3 } while(0)
#endif

// Output a note during compilation. Can double click on NOTE to jump to in-file.
#define NOTE( MESSAGE ) \
  __pragma( message (__FILE__ "(" STRINGIZE(__LINE__) ") : NOTE [ " MESSAGE " ]") )

// Output a warning during compilation. Can double click on WARN to jump to in-file.
#define WARN( MESSAGE ) \
  __pragma( message (__FILE__ "(" STRINGIZE(__LINE__) ") : WARNING [ " MESSAGE " ]") )

// Output a todo during compilation. Can double click on TODO to jump to in-file.
#define TODO( MESSAGE ) \
  __pragma( message (__FILE__ "(" STRINGIZE(__LINE__) ") : TODO [ " MESSAGE " ]") )

void PrintError(const char *exp, const char *file, int line, const char *msg, ...);

#ifdef _DEBUG

// Displays an error message if the expression returns false and breaks
#define ErrorIf( EXP, ... )                                \
  do {                                                     \
    if(EXP) {                                              \
      PrintError( #EXP, __FILE__, __LINE__, __VA_ARGS__ ); \
      DEBUG_BREAK;                                         \
    }                                                      \
  } while(false)

// Displays an error with provided expression and breaks
#define Error( ... )                                     \
  do {                                                   \
    PrintError( NULL, __FILE__, __LINE__, __VA_ARGS__ ); \
    DEBUG_BREAK;                                         \
  } while(false)

// Logs an error to debug output if expression is false
#define ErrorIfLog( EXP, ... )                             \
  do {                                                     \
    if(EXP) {                                              \
      PrintError( #EXP, __FILE__, __LINE__, __VA_ARGS__ ); \
    }                                                      \
  } while(false)

// Logs an error to debug output
#define ErrorLog( ... )                                  \
  do {                                                   \
    PrintError( NULL, __FILE__, __LINE__, __VA_ARGS__ ); \
  } while(false)

#else
#define ErrorIf( ... )    __VA_ARGS__
#define Error( ... )      __VA_ARGS__
#define ErrorIfLog( ... ) __VA_ARGS__
#define ErrorLog( ... )   __VA_ARGS__
#endif

inline void CreateDebugConsole(void)
{
#ifdef WIN32
  AllocConsole();
#endif

  freopen("CON", "w", stdout);
  freopen("CON", "w", stderr);
}
