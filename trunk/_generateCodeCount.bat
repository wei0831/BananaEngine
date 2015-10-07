@echo off

GOTO EndComment
/******************************************************************************/
/*!
 \file   _generateCodeCount.bat
 \author Jack Chang
 \date   10/14/2014
 \par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
    Generate Code Count.
    Required CLOC to be installed: http://cloc.sourceforge.net/
 */
/******************************************************************************/
:EndComment

cloc-1.62 --by-file source/*.cpp source/*/*.cpp --quiet --out=CodeCount.CSV --csv
start "" "CodeCount.CSV"