/******************************************************************************/
/*!
\file   GL_ShaderManager.h
\author Jack Chang
\date   10/11/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/
#pragma once
#include "IManager.h"

#include "GL_Shader.h"
#include <GLFW/glfw3.h>
#include <GL/glew.h>

#define SHADER_DIR "source\\Shaders\\"


class GL_ShaderManager : public IManager
{
public:
  virtual void init();
  virtual void shutdown();

  void addShader(const char* name, const char * vert, const char * frag);
  GLuint getShader(const char* name);

private:
  std::map<std::string, GLuint> shaders;
  
  char * readShader(const char* filename);
  GLuint loadShader(const char * vert, const char * frag);
  GLuint compileShader(const char* source, const GLenum type);
};
