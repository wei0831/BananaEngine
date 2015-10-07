/******************************************************************************/
/*!
\file   GL_Shader.h
\author Jack Chang
\date   10/11/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/
#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#define MAX_CHAR_PERLINE 255
#define MAX_LINE_PERFILE 255
#define MAX_SHADER_PROG_SIZE 2048
class GL_Shader
{
public:
  GL_Shader(GLenum type_) : shaderType(type_){};
  ~GL_Shader()  { glDeleteShader(shader); } //RAII

  GLuint readShaderFile(const char* filename);
  GLuint getShader() { return shader; }

  bool parseFileToStr(const char* file_name, char* shader_str, int max_len);

private:
  GLenum shaderType;
  GLuint shader;
};

