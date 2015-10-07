/******************************************************************************/
/*!
\file   Macros.h
\author Jack Chang
\date   10/06/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief

*/
/******************************************************************************/
#pragma once

// Internal usage
#define STRINGIZE_2( _ ) #_
#define STRINGIZE( _ ) STRINGIZE_2( _ )
#define PPCAT_NX(A, B) A ## B

// Don't forget to use END_DISABLE
#define DISABLE_WARNING( WARN_ID ) \
  __pragma( warning( push ) ) \
  __pragma( warning( disable : WARN_ID ) )

// Disables a warning without the push call
#define PERM_DSIABLE_WARNING( WARN_ID ) \
  __pragma( warning( disable : WARN_ID ) )

#define END_DISABLE( ) \
  __pragma( warning( pop ) )
