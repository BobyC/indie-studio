/*
** Plan.hpp for Plan in /home/drozdz_b/Documents/TestIrrlitch7
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Wed Jun 01 16:08:51 2016 drozdz_b
** Last update Wed Jun 01 16:49:56 2016 drozdz_b
*/

#ifndef PLAN_HPP_
#define PLAN_HPP_

#include "Object.hpp"

class Plan : public Object
{
private:
  ISceneNode			*parent;
  ISceneManager		*smgr;

public:
  void		addObject(const Object& obj);
  void		checkChild();
}

#endif
