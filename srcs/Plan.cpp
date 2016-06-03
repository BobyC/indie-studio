/*
** Plan.cpp for Plan in /home/drozdz_b/Documents/TestIrrlitch7
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Wed Jun 01 16:08:39 2016 drozdz_b
** Last update Fri Jun 03 17:24:50 2016 drozdz_b
*/

#include "Plan.hpp"

Plan::Plan(scene::ISceneNode *node, scene::ISceneManager *smgr)
: Object(node)
{
  this->_smgr = smgr;
}

Plan::Plan(scene::ISceneManager* smgr, video::IVideoDriver * driver)
: Object(NULL)
{
  scene::IMesh			*plane =
    smgr->getGeometryCreator()->createPlaneMesh(tileSize, tileCount);
  _node = smgr->addMeshSceneNode(plane);

  if(_node)
  {
    _node->setMaterialTexture(0, driver->getTexture("WoodChips01_D.tga"));
  }
}

Plan::~Plan()
{
}
