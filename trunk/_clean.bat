@echo off

GOTO EndComment
/******************************************************************************/
/*!
 \file   _clean.bat
 \author Jack Chang
 \date   09/08/2014
 \par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
    Clear all unneeded files
 */
/******************************************************************************/
:EndComment

rm *.sdf
rm *.opensdf
rm *.sln
rm *.suo
rm *.ipch
rm *.vcxproj*
rm *.CSV
rmdir /S /Q ipch
rmdir /S /Q obj
rmdir /S /Q bin
