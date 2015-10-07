--[[
/******************************************************************************/
/*!
 \file   premake5.lua
 \author Jack Chang
 \par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
]]

solution "BananaEngine"
  configurations { "Debug", "Release" }
  location "../"

project "BananaEngine"
  targetname "BananaEngine"
  location ".."
  language "C++"
  objdir "../obj"
  kind "ConsoleApp"
  pchheader "Precompiled.h"
  pchsource "../source/Precompiled/Precompiled.cpp"
    
  -- source files
  includedirs
  {
    "../include",
    "../source",
    "../source/**/",
    "../dependency/include"
  }

  files
  {
    "../include/**.h",
    "../include/**.hpp",
    "../source/**.h",
    "../source/**.cpp",
    "../source/**.glsl",
    "../source/**.frag",
    "../source/**.vert",
    "../assets/**"
  }

  libdirs
  {
    "../dependency/lib/AntTweakBar",
    "../dependency/lib/GL/Release/Win32",
    "../dependency/lib/GLFW"
  }

  configuration "Debug"
    flags { "Symbols", "NoMinimalRebuild" }
    defines { "_DEBUG", "_CRT_SECURE_NO_DEPRECATE" }
    buildoptions { "/MP", "/FS" }
    links
    { 
      "AntTweakBar64", "opengl32", "glew32", "glfw3dll"
    }
    targetdir "../bin/debug"
    postbuildcommands
    {
      "copy dependency\\lib\\GL\\Release\\Win32\\glew32.dll bin\\debug\\",
      "copy dependency\\lib\\AntTweakBar\\AntTweakBar.dll bin\\debug\\",
      "copy dependency\\lib\\AntTweakBar\\AntTweakBar64.dll bin\\debug\\",
      "copy dependency\\lib\\GLFW\\glfw3.dll bin\\debug\\"
    }

  configuration "Release"
    flags { "NoMinimalRebuild" }
    optimize "Full"
    defines { "NDEBUG", "_CRT_SECURE_NO_DEPRECATE" }
    buildoptions { "/MP", "/FS" }
    linkoptions { "/LTCG" }
    links
    {
      "AntTweakBar64", "opengl32", "glew32", "glfw3dll"
    }
    targetdir "../bin/release"
    postbuildcommands
    {
      "copy dependency\\lib\\GL\\Release\\Win32\\glew32.dll bin\\release\\",
      "copy dependency\\lib\\AntTweakBar\\AntTweakBar.dll bin\\release\\",
      "copy dependency\\lib\\AntTweakBar\\AntTweakBar64.dll bin\\release\\",
      "copy dependency\\lib\\GLFW\\glfw3.dll bin\\release\\"
    }
