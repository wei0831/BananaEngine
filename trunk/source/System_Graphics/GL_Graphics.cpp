/******************************************************************************/
/*!
\file   GL_Grpaihcs.cpp
\author Jack Chang
\date   10/09/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/
#include "Precompiled.h"

#include "GL_Graphics.h"
#include "GL_Shader.h"

/////////////////////
#include "SystemLocator.h"
/////////////////////

#define ONE_DEG_IN_RAD (2.0F * PI) / 360.0F // 0.017444444

bool GL_Grpaihcs::g_close = false;
glm::mat4 model_mat;
int model_mat_location, view_mat_location, proj_mat_location;


void GL_Grpaihcs::init()
{
  isShutdown = false;
  g_window_w = 800;
  g_window_h = 600;
  g_window_title = std::string("Initial Window V0");

  gl_start();
  initGeometry();
  initShaderManager();
  initRenderSetting();

  /************************************************************************/
  /* Temp                                                                 */
  /************************************************************************/
  TwWindowSize(g_window_w, g_window_h);
  TwInit(TW_OPENGL, NULL);

  bar = TwNewBar("Test");
  TwDefine(" GLOBAL help='Testing...' "); // Message added to the help bar.
  TwAddVarRW(bar, "bgColor", TW_TYPE_COLOR3F, glm::value_ptr(clearColor), " label='BG Color' ");

  //////////////////////////////////////////////////////////////////////////////
  float aspect = (float)g_window_w / (float)g_window_h;

  glm::mat4 view = glm::lookAt(glm::vec3(0.f, 0.f, 1.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 1.f, 0.f));
  model_mat = glm::mat4(1.0f);

  glm::mat4 projection = glm::ortho(-aspect, aspect, -1.0f, 1.0f, 0.0f, 10.0f);

  glUseProgram(sp);
  model_mat_location = glGetUniformLocation(sp, "model");
  glUniformMatrix4fv(model_mat_location, 1, GL_FALSE, glm::value_ptr(model_mat));
  view_mat_location = glGetUniformLocation(sp, "view");
  glUniformMatrix4fv(view_mat_location, 1, GL_FALSE, glm::value_ptr(view));
  proj_mat_location = glGetUniformLocation(sp, "projection");
  glUniformMatrix4fv(proj_mat_location, 1, GL_FALSE, glm::value_ptr(projection));

  /************************************************************************/
  /* End Temp                                                             */
  /************************************************************************/


  printf("[Graphics System] Initialized...\n");
}

void GL_Grpaihcs::initGeometry()
{
  GLfloat points[] = {
    0.0f, 0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f
  };
  glGenBuffers(1, &vp_vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vp_vbo);
  glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), points, GL_STATIC_DRAW);

  float normals[] = {
    0.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 1.0f,
  };
  glGenBuffers(1, &vn_vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vn_vbo);
  glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), normals, GL_STATIC_DRAW);

  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  glBindBuffer(GL_ARRAY_BUFFER, vp_vbo);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
  glBindBuffer(GL_ARRAY_BUFFER, vn_vbo);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
}

void GL_Grpaihcs::initShaderManager()
{
  glsm.addShader("Simple", "source\\Shaders\\Simple.vert", "source\\Shaders\\Simple.frag");
  sp = glsm.getShader("Simple");
}

void GL_Grpaihcs::initRenderSetting()
{
  glfwSwapInterval(60);
  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);
  glCullFace(GL_BACK);
  glFrontFace(GL_CW);
  glEnable(GL_CULL_FACE);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);
  clearColor = { 0.0f, 0.5f, 0.5f };
  glViewport(0, 0, g_window_w, g_window_h);
}

void GL_Grpaihcs::shutdown()
{
  if (isShutdown)
    return;

  isShutdown = true;

  printf("[Graphics System] Shutting down...\n");

  TwTerminate();
  glfwTerminate();

  printf("[Graphics System] Closed...\n");
}

void GL_Grpaihcs::draw()
{
  glClearColor(clearColor.x, clearColor.y, clearColor.z, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  /************************************************************************/
  /* Temp                                                                 */
  /************************************************************************/
  glViewport(0, 0, g_window_w, g_window_h);

  glUseProgram(sp);

  double current_seconds = glfwGetTime();
  float *pSource = glm::value_ptr(model_mat);
  pSource[12] = sinf((float)current_seconds);

  glUniformMatrix4fv(model_mat_location, 1, GL_FALSE, glm::value_ptr(model_mat));
  glBindVertexArray(vao);
  glDrawArrays(GL_TRIANGLES, 0, 3);

  TwDraw();
  /************************************************************************/
  /* End Temp                                                             */
  /************************************************************************/

  glfwSwapBuffers(g_window);
}

void GL_Grpaihcs::update()
{
  if (!glfwWindowShouldClose(g_window))
  {
    gl_fps_counter(g_window);

    if (GLFW_PRESS == glfwGetKey(g_window, GLFW_KEY_ESCAPE)) {
      glfwSetWindowShouldClose(g_window, 1);
    }

    draw();
  }
  else
  {
    g_close = true;
    shutdown();
  }
}

bool GL_Grpaihcs::gl_start()
{
  printf("GLFW version: %s\n", glfwGetVersionString());
  glfwSetErrorCallback(gl_error_callback);

  if (!glfwInit())
  {
    ErrorLog("ERROR: could not start GLFW3\n");
    return false;
  }

  g_window =
    glfwCreateWindow(g_window_w, g_window_h, g_window_title.c_str(), NULL, NULL);
  if (!g_window)
  {
    ErrorLog("ERROR: could not open window with GLFW3\n");
    shutdown();
    return false;
  }

  glfwSetWindowSizeCallback(g_window, gl_window_size_callback);
  glfwMakeContextCurrent(g_window);
  glfwWindowHint(GLFW_SAMPLES, 4);
  glewExperimental = GL_TRUE;
  glewInit();

  renderer = glGetString(GL_RENDERER); // get renderer string
  version = glGetString(GL_VERSION); // version as a string
  printf("Renderer: %s\n", renderer);
  printf("OpenGL version supported %s\n", version);

  return true;
}

/******************************************************************************/
// Static Variables
/******************************************************************************/
int GL_Grpaihcs::g_window_w;
int GL_Grpaihcs::g_window_h;
GLFWwindow* GL_Grpaihcs::g_window;
std::string GL_Grpaihcs::g_window_title;
double GL_Grpaihcs::previous_seconds;
int GL_Grpaihcs::frame_count;

void GL_Grpaihcs::gl_error_callback(int error, const char* description)
{
  ErrorLog(description);
}

void GL_Grpaihcs::gl_window_size_callback(GLFWwindow* window, int width, int height)
{
  g_window_w = width;
  g_window_h = height;
  printf("Window:%s Width:%i Height:%i\n", g_window_title.c_str(), width, height);
}

void GL_Grpaihcs::gl_fps_counter(GLFWwindow* window) {
  double current_seconds;
  double elapsed_seconds;

  current_seconds = glfwGetTime();
  elapsed_seconds = current_seconds - previous_seconds;
  if (elapsed_seconds > 0.1)
  {
    previous_seconds = current_seconds;
    char tmp[128];
    double fps = (double)frame_count / elapsed_seconds;
    sprintf(tmp, "BananaEngine - FPS: %.2f", fps);
    glfwSetWindowTitle(window, tmp);
    frame_count = 0;
  }
  frame_count++;
}
