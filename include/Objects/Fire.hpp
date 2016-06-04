/*
** Fire.hpp for Fire in /home/drozdz_b/Documents/testIrrIntegration
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Fri Jun 03 17:45:48 2016 drozdz_b
** Last update Fri Jun 03 17:51:03 2016 drozdz_b
*/

#ifndef FIRE_HPP_
#define FIRE_HPP_

#include "Object.hh"

class Fire : public Object
{
public:
  Fire(scene::ISceneNode *node, scene::ISceneManager *smgr);
  Fire(scene::ISceneManager* smgr, video::IVideoDriver * driver);
  ~Fire();
};

#endif
