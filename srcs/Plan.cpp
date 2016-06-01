/*
** Plan.cpp for Plan in /home/drozdz_b/Documents/TestIrrlitch7
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Wed Jun 01 16:08:39 2016 drozdz_b
** Last update Wed Jun 01 16:48:58 2016 drozdz_b
*/

#include "Plan.hpp"

Plan::Plan(ISceneNode *node, ISceneNode *Parent, ISceneManager *smgr) : Object(node)
{

}

void	  Plan::addObject(Object* obj)
{
  this->_node->addChild(obj.getNode());
}

void		Plan::checkChild()
{
  core::list<ISceneNode*>	list = this->_node->getChildren();
  core::list<ISceneNode*>::iterator it = list.begin();

  while (it != list.end())
  {
    if((*it)->getIsDead())
    {
      this->_node->removeChild(*it);
      delete (*it);
    }
    ++it;
  }
}
