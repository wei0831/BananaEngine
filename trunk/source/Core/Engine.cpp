#include "Precompiled.h"
#include "Engine.h"
#include "GL_Graphics.h"
#include "GL_Input.h"

#include <thread>
bool cmd_close;
std::string s;
void Engine::run()
{
  // Init
  init();

  std::thread t([&]() {
    while (!cmd_close) 
    {
      std::cout << "Input: ";
      std::cin >> s;
      std::cout << "Command: " << s << std::endl;
      if (s == "q") {
        cmd_close = true;
        std::cout << "Exit command system..." << std::endl;
        std::cout.flush();
      }
    }
  });

  // Loop
  update();

  t.join();

  // End
  shutdown();
}

void Engine::init()
{
  SystemLocator::init();

  SystemLocator::provide(new GL_Grpaihcs());
  SystemLocator::getGraphics()->init();

  SystemLocator::provide(new GL_Input());
  SystemLocator::getInput()->init();
}

void Engine::shutdown()
{
  SystemLocator::clear();
}

// Main Game Loop
void Engine::update()
{
  while (!GL_Grpaihcs::g_close)
  {
    SystemLocator::getAudio()->update();

    SystemLocator::getInput()->update();

    SystemLocator::getPhysics()->update();

    SystemLocator::getGraphics()->update();
  }
}
