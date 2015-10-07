/******************************************************************************/
/*!
\file   GL_Input.cpp
\author Jack Chang
\date   10/09/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/
#include "Precompiled.h"
#include "GL_Input.h"
#include "GL_Graphics.h"

void GL_Input::init()
{
  isShutdown = false;

  initMouseInput();
  initKeyboardInput();

  // Temp
  if (GL_Grpaihcs::g_window)
  {
    glfwSetKeyCallback(GL_Grpaihcs::g_window, gl_key_callback);
    glfwSetMouseButtonCallback(GL_Grpaihcs::g_window, gl_cursorClick_callback);
    glfwSetCursorPosCallback(GL_Grpaihcs::g_window, gl_cursorPos_callback);
//     glfwSetScrollCallback(GL_Grpaihcs::g_window, (GLFWscrollfun)TwEventMouseWheelGLFW);
  }

  //

  printf("[Input System] Initialized...\n");
}

void GL_Input::shutdown()
{
  if (isShutdown)
    return;

  isShutdown = true;

  printf("[Input System] Closed...\n");
}

void GL_Input::update()
{
  clearMouseInput();
  clearKeyboardInput();
  glfwPollEvents();
}

bool GL_Input::GetMousePressed(int mouseBtn)
{
  return mouseInput[mouseBtn] == mouseState::Pressed;
}

bool GL_Input::GetMouseReleased(int mouseBtn)
{
  return mouseInput[mouseBtn] == mouseState::Pressed;
}

bool GL_Input::GetMouseClicked(int mouseBtn)
{
  return mouseInput[mouseBtn] == mouseState::Pressed;
}

bool GL_Input::GetKeyPressed(int keycode)
{
  return keyboardInput[keycode] == keyState::Pressed;
}

bool GL_Input::GetKeyReleased(int keycode)
{
  return keyboardInput[keycode] == keyState::Released;
}

bool GL_Input::GetKeyClicked(int keycode)
{
  return keyboardInput[keycode] == keyState::Clicked;
}

void GL_Input::clearMouseInput()
{
  while (!clickedMouseInput.empty())
  {
    int mouseBtn = clickedMouseInput.top();
    mouseInput[mouseBtn] = mouseState::Released;
    clickedMouseInput.pop();
    printf("[Mouse Input] %i is clicked at (%.2f, %.2f) \n", mouseBtn, mousePosition.x, mousePosition.y);

    if (mouseModifierInput[GLFW_MOD_SHIFT])
      printf("[Modifier Key] %s was used \n", "GLFW_MOD_SHIFT");
    if (mouseModifierInput[GLFW_MOD_CONTROL])
      printf("[Modifier Key] %s was used \n", "GLFW_MOD_CONTROL");
    if (mouseModifierInput[GLFW_MOD_ALT])
      printf("[Modifier Key] %s was used \n", "GLFW_MOD_ALT");
    if (mouseModifierInput[GLFW_MOD_SUPER])
      printf("[Modifier Key] %s was used \n", "GLFW_MOD_SUPER");
  }

  mouseModifierInput[GLFW_MOD_SHIFT] = false;
  mouseModifierInput[GLFW_MOD_CONTROL] = false;
  mouseModifierInput[GLFW_MOD_ALT] = false;
  mouseModifierInput[GLFW_MOD_SUPER] = false;
}

void GL_Input::clearKeyboardInput()
{
  while (!clickedKeyInput.empty())
  {
    int key = clickedKeyInput.top();
    keyboardInput[key] = keyState::Released;
    clickedKeyInput.pop();
    printf("[Keyboard Input] %i is clicked \n", key);

    if (keyModifierInput[GLFW_MOD_SHIFT])
      printf("[Modifier Key] %s was used \n", "GLFW_MOD_SHIFT");
    if (keyModifierInput[GLFW_MOD_CONTROL])
      printf("[Modifier Key] %s was used \n", "GLFW_MOD_CONTROL");
    if (keyModifierInput[GLFW_MOD_ALT])
      printf("[Modifier Key] %s was used \n", "GLFW_MOD_ALT");
    if (keyModifierInput[GLFW_MOD_SUPER])
      printf("[Modifier Key] %s was used \n", "GLFW_MOD_SUPER");
  }

  keyModifierInput[GLFW_MOD_SHIFT] = false;
  keyModifierInput[GLFW_MOD_CONTROL] = false;
  keyModifierInput[GLFW_MOD_ALT] = false;
  keyModifierInput[GLFW_MOD_SUPER] = false;
}

void GL_Input::initMouseInput()
{
  mouseModifierInput[GLFW_MOD_SHIFT] = false;
  mouseModifierInput[GLFW_MOD_CONTROL] = false;
  mouseModifierInput[GLFW_MOD_ALT] = false;
  mouseModifierInput[GLFW_MOD_SUPER] = false;
  mouseInput[GLFW_MOUSE_BUTTON_1] = mouseState::Released;
  mouseInput[GLFW_MOUSE_BUTTON_2] = mouseState::Released;
  mouseInput[GLFW_MOUSE_BUTTON_3] = mouseState::Released;
  mouseInput[GLFW_MOUSE_BUTTON_4] = mouseState::Released;
  mouseInput[GLFW_MOUSE_BUTTON_5] = mouseState::Released;
  mouseInput[GLFW_MOUSE_BUTTON_6] = mouseState::Released;
  mouseInput[GLFW_MOUSE_BUTTON_7] = mouseState::Released;
  mouseInput[GLFW_MOUSE_BUTTON_8] = mouseState::Released;
  mouseInput[GLFW_MOUSE_BUTTON_LAST] = mouseState::Released;
  mouseInput[GLFW_MOUSE_BUTTON_LEFT] = mouseState::Released;
  mouseInput[GLFW_MOUSE_BUTTON_RIGHT] = mouseState::Released;
  mouseInput[GLFW_MOUSE_BUTTON_MIDDLE] = mouseState::Released;
}

void GL_Input::initKeyboardInput()
{
  keyModifierInput[GLFW_MOD_SHIFT] = false;
  keyModifierInput[GLFW_MOD_CONTROL] = false;
  keyModifierInput[GLFW_MOD_ALT] = false;
  keyModifierInput[GLFW_MOD_SUPER] = false;
  keyboardInput[GLFW_KEY_UNKNOWN] = keyState::Released;
  keyboardInput[GLFW_KEY_SPACE] = keyState::Released;
  keyboardInput[GLFW_KEY_APOSTROPHE] = keyState::Released;
  keyboardInput[GLFW_KEY_COMMA] = keyState::Released;
  keyboardInput[GLFW_KEY_MINUS] = keyState::Released;
  keyboardInput[GLFW_KEY_PERIOD] = keyState::Released;
  keyboardInput[GLFW_KEY_SLASH] = keyState::Released;
  keyboardInput[GLFW_KEY_0] = keyState::Released;
  keyboardInput[GLFW_KEY_1] = keyState::Released;
  keyboardInput[GLFW_KEY_2] = keyState::Released;
  keyboardInput[GLFW_KEY_3] = keyState::Released;
  keyboardInput[GLFW_KEY_4] = keyState::Released;
  keyboardInput[GLFW_KEY_5] = keyState::Released;
  keyboardInput[GLFW_KEY_6] = keyState::Released;
  keyboardInput[GLFW_KEY_7] = keyState::Released;
  keyboardInput[GLFW_KEY_8] = keyState::Released;
  keyboardInput[GLFW_KEY_9] = keyState::Released;
  keyboardInput[GLFW_KEY_SEMICOLON] = keyState::Released;
  keyboardInput[GLFW_KEY_EQUAL] = keyState::Released;
  keyboardInput[GLFW_KEY_A] = keyState::Released;
  keyboardInput[GLFW_KEY_B] = keyState::Released;
  keyboardInput[GLFW_KEY_C] = keyState::Released;
  keyboardInput[GLFW_KEY_D] = keyState::Released;
  keyboardInput[GLFW_KEY_E] = keyState::Released;
  keyboardInput[GLFW_KEY_F] = keyState::Released;
  keyboardInput[GLFW_KEY_G] = keyState::Released;
  keyboardInput[GLFW_KEY_H] = keyState::Released;
  keyboardInput[GLFW_KEY_I] = keyState::Released;
  keyboardInput[GLFW_KEY_J] = keyState::Released;
  keyboardInput[GLFW_KEY_K] = keyState::Released;
  keyboardInput[GLFW_KEY_L] = keyState::Released;
  keyboardInput[GLFW_KEY_M] = keyState::Released;
  keyboardInput[GLFW_KEY_N] = keyState::Released;
  keyboardInput[GLFW_KEY_O] = keyState::Released;
  keyboardInput[GLFW_KEY_P] = keyState::Released;
  keyboardInput[GLFW_KEY_Q] = keyState::Released;
  keyboardInput[GLFW_KEY_R] = keyState::Released;
  keyboardInput[GLFW_KEY_S] = keyState::Released;
  keyboardInput[GLFW_KEY_T] = keyState::Released;
  keyboardInput[GLFW_KEY_U] = keyState::Released;
  keyboardInput[GLFW_KEY_V] = keyState::Released;
  keyboardInput[GLFW_KEY_W] = keyState::Released;
  keyboardInput[GLFW_KEY_X] = keyState::Released;
  keyboardInput[GLFW_KEY_Y] = keyState::Released;
  keyboardInput[GLFW_KEY_Z] = keyState::Released;
  keyboardInput[GLFW_KEY_LEFT_BRACKET] = keyState::Released;
  keyboardInput[GLFW_KEY_BACKSLASH] = keyState::Released;
  keyboardInput[GLFW_KEY_RIGHT_BRACKET] = keyState::Released;
  keyboardInput[GLFW_KEY_GRAVE_ACCENT] = keyState::Released;
  keyboardInput[GLFW_KEY_WORLD_1] = keyState::Released;
  keyboardInput[GLFW_KEY_WORLD_2] = keyState::Released;
  keyboardInput[GLFW_KEY_ESCAPE] = keyState::Released;
  keyboardInput[GLFW_KEY_ENTER] = keyState::Released;
  keyboardInput[GLFW_KEY_TAB] = keyState::Released;
  keyboardInput[GLFW_KEY_BACKSPACE] = keyState::Released;
  keyboardInput[GLFW_KEY_INSERT] = keyState::Released;
  keyboardInput[GLFW_KEY_DELETE] = keyState::Released;
  keyboardInput[GLFW_KEY_RIGHT] = keyState::Released;
  keyboardInput[GLFW_KEY_LEFT] = keyState::Released;
  keyboardInput[GLFW_KEY_DOWN] = keyState::Released;
  keyboardInput[GLFW_KEY_UP] = keyState::Released;
  keyboardInput[GLFW_KEY_PAGE_UP] = keyState::Released;
  keyboardInput[GLFW_KEY_PAGE_DOWN] = keyState::Released;
  keyboardInput[GLFW_KEY_HOME] = keyState::Released;
  keyboardInput[GLFW_KEY_END] = keyState::Released;
  keyboardInput[GLFW_KEY_CAPS_LOCK] = keyState::Released;
  keyboardInput[GLFW_KEY_SCROLL_LOCK] = keyState::Released;
  keyboardInput[GLFW_KEY_NUM_LOCK] = keyState::Released;
  keyboardInput[GLFW_KEY_PRINT_SCREEN] = keyState::Released;
  keyboardInput[GLFW_KEY_PAUSE] = keyState::Released;
  keyboardInput[GLFW_KEY_F1] = keyState::Released;
  keyboardInput[GLFW_KEY_F2] = keyState::Released;
  keyboardInput[GLFW_KEY_F3] = keyState::Released;
  keyboardInput[GLFW_KEY_F4] = keyState::Released;
  keyboardInput[GLFW_KEY_F5] = keyState::Released;
  keyboardInput[GLFW_KEY_F6] = keyState::Released;
  keyboardInput[GLFW_KEY_F7] = keyState::Released;
  keyboardInput[GLFW_KEY_F8] = keyState::Released;
  keyboardInput[GLFW_KEY_F9] = keyState::Released;
  keyboardInput[GLFW_KEY_F10] = keyState::Released;
  keyboardInput[GLFW_KEY_F11] = keyState::Released;
  keyboardInput[GLFW_KEY_F12] = keyState::Released;
  keyboardInput[GLFW_KEY_F13] = keyState::Released;
  keyboardInput[GLFW_KEY_F14] = keyState::Released;
  keyboardInput[GLFW_KEY_F15] = keyState::Released;
  keyboardInput[GLFW_KEY_F16] = keyState::Released;
  keyboardInput[GLFW_KEY_F17] = keyState::Released;
  keyboardInput[GLFW_KEY_F18] = keyState::Released;
  keyboardInput[GLFW_KEY_F19] = keyState::Released;
  keyboardInput[GLFW_KEY_F20] = keyState::Released;
  keyboardInput[GLFW_KEY_F21] = keyState::Released;
  keyboardInput[GLFW_KEY_F22] = keyState::Released;
  keyboardInput[GLFW_KEY_F23] = keyState::Released;
  keyboardInput[GLFW_KEY_F24] = keyState::Released;
  keyboardInput[GLFW_KEY_F25] = keyState::Released;
  keyboardInput[GLFW_KEY_KP_0] = keyState::Released;
  keyboardInput[GLFW_KEY_KP_1] = keyState::Released;
  keyboardInput[GLFW_KEY_KP_2] = keyState::Released;
  keyboardInput[GLFW_KEY_KP_3] = keyState::Released;
  keyboardInput[GLFW_KEY_KP_4] = keyState::Released;
  keyboardInput[GLFW_KEY_KP_5] = keyState::Released;
  keyboardInput[GLFW_KEY_KP_6] = keyState::Released;
  keyboardInput[GLFW_KEY_KP_7] = keyState::Released;
  keyboardInput[GLFW_KEY_KP_8] = keyState::Released;
  keyboardInput[GLFW_KEY_KP_9] = keyState::Released;
  keyboardInput[GLFW_KEY_KP_DECIMAL] = keyState::Released;
  keyboardInput[GLFW_KEY_KP_DIVIDE] = keyState::Released;
  keyboardInput[GLFW_KEY_KP_MULTIPLY] = keyState::Released;
  keyboardInput[GLFW_KEY_KP_SUBTRACT] = keyState::Released;
  keyboardInput[GLFW_KEY_KP_ADD] = keyState::Released;
  keyboardInput[GLFW_KEY_KP_ENTER] = keyState::Released;
  keyboardInput[GLFW_KEY_KP_EQUAL] = keyState::Released;
  keyboardInput[GLFW_KEY_LEFT_SHIFT] = keyState::Released;
  keyboardInput[GLFW_KEY_LEFT_CONTROL] = keyState::Released;
  keyboardInput[GLFW_KEY_LEFT_ALT] = keyState::Released;
  keyboardInput[GLFW_KEY_LEFT_SUPER] = keyState::Released;
  keyboardInput[GLFW_KEY_RIGHT_SHIFT] = keyState::Released;
  keyboardInput[GLFW_KEY_RIGHT_CONTROL] = keyState::Released;
  keyboardInput[GLFW_KEY_RIGHT_ALT] = keyState::Released;
  keyboardInput[GLFW_KEY_RIGHT_SUPER] = keyState::Released;
  keyboardInput[GLFW_KEY_MENU] = keyState::Released;
  keyboardInput[GLFW_KEY_LAST] = keyState::Released;
}

std::stack<int>  GL_Input::clickedKeyInput;
std::map<int, keyState>  GL_Input::keyboardInput;
std::map<int, bool> GL_Input::keyModifierInput;
std::map<int, bool> GL_Input::mouseModifierInput;
std::stack<int> GL_Input::clickedMouseInput;
std::map<int, mouseState> GL_Input::mouseInput;
glm::dvec2 GL_Input::mousePosition;

void GL_Input::gl_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  keyState& keystate = keyboardInput[key];

  if (action == GLFW_PRESS  && keystate != keyState::Pressed)
  {
    keystate = keyState::Pressed;
  }
  else if (action == GLFW_RELEASE && keystate == keyState::Pressed)
  {
    keystate = keyState::Clicked;
    clickedKeyInput.push(key);
  }

  keyModifierInput[mods] = true;

  TwEventKeyGLFW(key, action);
}

void GL_Input::gl_cursorPos_callback(GLFWwindow* window, double pos_x, double pos_y)
{
  mousePosition.x = pos_x;
  mousePosition.y = pos_y;

  TwEventMousePosGLFW((int)pos_x, (int)pos_y);
}

void GL_Input::gl_cursorClick_callback(GLFWwindow* window, int button, int action, int mods)
{
  mouseState& mousestate = mouseInput[button];

  if (action == GLFW_PRESS  && mousestate != mouseState::Pressed)
  {
    mousestate = mouseState::Pressed;
  }
  else if (action == GLFW_RELEASE && mousestate == mouseState::Pressed)
  {
    mousestate = mouseState::Clicked;
    clickedMouseInput.push(button);
  }

  mouseModifierInput[mods] = true;

  TwEventMouseButtonGLFW(button, action);
}
