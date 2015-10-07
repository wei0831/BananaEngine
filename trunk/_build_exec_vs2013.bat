@echo off

GOTO EndComment
/******************************************************************************/
/*!
 \file   _build_exec_vs2013.bat
 \author Jack Chang
 \date   10/15/2014
 \par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
    Generate and Excute Visual Studio 2013 Project
 */
/******************************************************************************/
:EndComment

cd tools
.\premake5 vs2013
cd ..
start "" "BananaEngine.sln"