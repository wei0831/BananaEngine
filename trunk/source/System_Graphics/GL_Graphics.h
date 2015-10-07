/******************************************************************************/
/*!
\file   GL_Grpaihcs.cpp
\author Jack Chang
\date   10/09/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/
#pragma once
#include "IGraphics.h"

#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <GL_ShaderManager.h>

#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <AntTweakBar/AntTweakBar.h>

class GL_Grpaihcs : public IGraphics
{
public:
  GL_Grpaihcs(){}
  void init();
  void shutdown();
  void update();

  static bool g_close;

private:
  friend class GL_Input;

  GL_ShaderManager glsm;

  GLuint vp_vbo;
  GLuint vn_vbo;
  GLuint vao;
  glm::vec3 clearColor;
  GLuint sp;

  TwBar *bar;

  static int g_window_w;
  static int g_window_h;
  static GLFWwindow* g_window;
  static std::string g_window_title;

  const GLubyte* renderer;
  const GLubyte* version;

  bool gl_start();

  void initGeometry();
  void initShaderManager();
  void initRenderSetting();
  void draw();

  static void gl_error_callback(int error, const char* description);
  static void gl_window_size_callback(GLFWwindow* window, int width, int height);

  static double previous_seconds;
  static int frame_count;
  static void gl_fps_counter(GLFWwindow* window);
};
