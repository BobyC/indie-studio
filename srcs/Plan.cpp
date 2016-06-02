/*
** Plan.cpp for Plan in /home/drozdz_b/Documents/TestIrrlitch7
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Wed Jun 01 16:08:39 2016 drozdz_b
** Last update Thu Jun 02 15:15:43 2016 drozdz_b
*/

#include "Plan.hpp"

Plan::Plan(scene::ISceneNode *node, scene::ISceneManager *smgr)
: Object(node)
{
  this->_smgr = smgr;
}

void	  Plan::addObject(Object* obj)
{
  this->_node->addChild(obj->getNode());
  this->_objects.push_back(obj);
}

void		Plan::checkChild()
{
  std::list<Object*>::iterator it = this->_objects.begin();
  std::list<Object*>::iterator it2;

  while (it != this->_objects.end())
  {
    if((*it)->getIsdead())
    {
      this->_node->removeChild((*it)->getNode());
      it2 = this->_objects.erase(it);
//    delete (*it);
      it = it2;
    }
    else
      ++it;
  }
}
