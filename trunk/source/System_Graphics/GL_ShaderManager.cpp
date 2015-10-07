/******************************************************************************/
/*!
\file   GL_ShaderManager.cpp
\author Jack Chang
\date   10/16/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/
#include "Precompiled.h"
#include "GL_ShaderManager.h"


void GL_ShaderManager::init()
{

}

void GL_ShaderManager::shutdown()
{

}

void GL_ShaderManager::addShader(const char* name, const char * vert, const char * frag)
{
  if (shaders.find(name) != shaders.end())
  {
    Error("[Shader Manager] Duplicated Shader: \"%s\" \n", name);
  }
  else
  {
    shaders.emplace(
      std::make_pair<std::string, GLint>(
      std::string(name),
      loadShader(vert, frag)));
  }
}

GLuint GL_ShaderManager::getShader(const char* name)
{
  auto result = shaders.find(std::string(name));
  if (result != shaders.end())
    return result->second;
  else
    Error("[Shader Manager] No Shader: %s Found\n", name);

  return 0;
}

char * GL_ShaderManager::readShader(const char* filename)
{
  FILE * file;
  char * buffer;
  size_t size;

  file = fopen(filename, "rb");
  if (!file)
  {
    fprintf(stderr, "[Shader Manager] Unable to open file \"%s\".\n", filename);
    return 0;
  }
  fseek(file, 0, SEEK_END);
  size = ftell(file);
  fseek(file, 0, SEEK_SET);
  buffer = (char *)malloc((size + 1) * sizeof(char *));
  fread(buffer, sizeof(char), size, file);
  buffer[size] = 0;
  fclose(file);
  return buffer;
}

GLuint GL_ShaderManager::loadShader(const char * vert, const char * frag)
{
  GLuint handle = glCreateProgram();
  GLint link_status;

  if (vert && strlen(vert))
  {
    char *vert_source = readShader(vert);
    GLuint vert_shader = compileShader(vert_source, GL_VERTEX_SHADER);
    glAttachShader(handle, vert_shader);
    glDeleteShader(vert_shader);
    free(vert_source);
  }
  if (frag && strlen(frag))
  {
    char *frag_source = readShader(frag);
    GLuint frag_shader = compileShader(frag_source, GL_FRAGMENT_SHADER);
    glAttachShader(handle, frag_shader);
    glDeleteShader(frag_shader);
    free(frag_source);
  }

  glLinkProgram(handle);

  glGetProgramiv(handle, GL_LINK_STATUS, &link_status);
  if (link_status == GL_FALSE)
  {
    GLchar messages[256];
    glGetProgramInfoLog(handle, sizeof(messages), 0, &messages[0]);
    fprintf(stderr, "%s\n", messages);
    exit(1);
  }
  fprintf(stdout, "[Shader Manager] Vertex Shader \"%s\" Loaded.\n", vert);
  fprintf(stdout, "[Shader Manager] Fragment Shader \"%s\" Loaded.\n", frag);
  return handle;
}

GLuint GL_ShaderManager::compileShader(const char* source, const GLenum type)
{
  GLint compile_status;
  GLuint handle = glCreateShader(type);
  glShaderSource(handle, 1, &source, 0);
  glCompileShader(handle);

  glGetShaderiv(handle, GL_COMPILE_STATUS, &compile_status);
  if (compile_status == GL_FALSE)
  {
    GLchar messages[256];
    glGetShaderInfoLog(handle, sizeof(messages), 0, &messages[0]);
    fprintf(stderr, "%s\n", messages);
    exit(EXIT_FAILURE);
  }
  return handle;
}
