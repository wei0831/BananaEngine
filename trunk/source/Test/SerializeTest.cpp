/******************************************************************************/
/*!
\file   main.cpp
\author Jack Chang
\date   10/06/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief

*/
/******************************************************************************/
#include "Precompiled.h"
// #include "Engine.h"
// #include "GameObject.h"
// #include "vld.h"
// #include "Player.h"
// 
// int main()
// {
//   GameObjectPtr g1 = std::make_shared<Player>("Burger");
//   GameObjectPtr g2;
// 
//   {
//     std::ofstream os("save.json", std::ios::out);
//     cereal::JSONOutputArchive w(os);
// 
//     w(g1);
//   }
// 
//   {
//     std::ifstream is("save.json", std::ios::in);
//     cereal::JSONInputArchive r(is);
// 
//     r(g2);
//   }
// 
//   {
//     g2->name = "CheeseBurger";
//     ComponentPtr t = g2->GetComponent("Transform");
//     if (t != nullptr)
//     {
//       std::static_pointer_cast<Transform>(t)->translation = glm::vec2(9.f, 1.f);
//     }
// 
//     std::ofstream os("save2.json", std::ios::out);;
//     cereal::JSONOutputArchive w(os);
// 
//     w(g2);
//   }
// 
//   getchar();
//   return 0;
// }
// 
