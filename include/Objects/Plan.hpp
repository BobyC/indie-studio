/*
** Plan.hpp for Plan in /home/drozdz_b/Documents/TestIrrlitch7
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Wed Jun 01 16:08:51 2016 drozdz_b
// Last update Fri Jun  3 18:10:51 2016 Sacha Sacha Monderer
*/

#ifndef PLAN_HPP_
#define PLAN_HPP_

#include <list>

#include "Object.hh"

class Plan : public Object
{
protected:
  scene::ISceneManager		*_smgr;

public:
  Plan(scene::ISceneNode *, scene::ISceneManager *);
  Plan(scene::ISceneManager* smgr, video::IVideoDriver * driver);
  ~Plan();
};

#endif
