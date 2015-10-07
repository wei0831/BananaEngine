/******************************************************************************/
/*!
\file   GL_Input.h
\author Jack Chang
\date   10/09/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/
#include "IInput.h"
#include <map>
#include <stack>
#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>
#include <AntTweakBar/AntTweakBar.h>

enum class keyState { Released, Pressed, Clicked };
enum class mouseState { Released, Pressed, Clicked };

class GL_Input : public IInput
{
public:
  GL_Input(){}
  ~GL_Input() { shutdown(); }
  void init();
  void shutdown();
  void update();

  bool GetKeyPressed(int keycode);
  bool GetKeyReleased(int keycode);
  bool GetKeyClicked(int keycode);
  bool GetMousePressed(int mouseBtn);
  bool GetMouseReleased(int mouseBtn);
  bool GetMouseClicked(int mouseBtn);

  static void gl_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
  static void gl_cursorPos_callback(GLFWwindow* window, double pos_x, double pos_y);
  static void gl_cursorClick_callback(GLFWwindow* window, int button, int action, int mods);

private:
  static std::stack<int> clickedKeyInput;
  static std::map<int, keyState> keyboardInput;

  static std::map<int, bool> keyModifierInput;
  static std::map<int, bool> mouseModifierInput;

  static std::stack<int> clickedMouseInput;
  static std::map<int, mouseState> mouseInput;
  static glm::dvec2 mousePosition;

  void initKeyboardInput();
  void clearKeyboardInput();

  void initMouseInput();
  void clearMouseInput();
};
