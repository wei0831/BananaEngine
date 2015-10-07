/******************************************************************************/
/*!
\file   GL_Shader.cpp
\author Jack Chang
\date   10/11/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/
#include "Precompiled.h"

#include "GL_Shader.h"

GLuint GL_Shader::readShaderFile(const char* filename)
{
  shader = glCreateShader(shaderType);

  char str[MAX_CHAR_PERLINE * MAX_LINE_PERFILE];
  parseFileToStr(filename, str, MAX_CHAR_PERLINE * MAX_LINE_PERFILE);

  const GLchar* p = (const GLchar*)str;
  glShaderSource(shader, 1, &p, NULL);
  glCompileShader(shader);

  int params = -1;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &params);
  ErrorIf(GL_TRUE != params, "ERROR: GL Shader: %s did not compile\n", filename);

  return shader;
}

bool GL_Shader::parseFileToStr(const char* file_name, char* shader_str, int max_len)
{
  shader_str[0] = '\0'; // reset string
  FILE* fp = fopen(file_name, "r");
  ErrorIf(!fp, "ERROR: opening file for reading: %s\n", file_name);

  int current_len = 0;
  char line[MAX_SHADER_PROG_SIZE];
  strcpy(line, ""); // remember to clean up before using for first time!
  while (!feof(fp)) 
  {
    if (NULL != fgets(line, MAX_SHADER_PROG_SIZE, fp))
    {
      current_len += strlen(line); // +1 for \n at end
      ErrorIf(current_len >= max_len, "ERROR: shader length is longer than string buffer length %i\n", max_len);
      strcat(shader_str, line);
    }
  }
  fclose(fp);
  return true;
}
