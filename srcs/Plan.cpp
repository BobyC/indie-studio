/*
** Plan.cpp for Plan in /home/drozdz_b/Documents/TestIrrlitch7
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Wed Jun 01 16:08:39 2016 drozdz_b
// Last update Fri Jun  3 19:30:49 2016 Nicolas Pujol
*/

#include "../include/Plan.hpp"

Plan::Plan(scene::ISceneNode *node, scene::ISceneManager *smgr)
: Object(node)
{
  this->_smgr = smgr;
}

Plan::Plan(scene::ISceneManager* smgr, video::IVideoDriver * driver)
: Object(NULL)
{
  core::dimension2d<f32> tileSize(1, 1);
  core::dimension2d<u32>   tileCount(50, 50);
  scene::IMesh			*plane =
    smgr->getGeometryCreator()->createPlaneMesh(tileSize, tileCount);
  _node = smgr->addMeshSceneNode(plane);

  if(_node)
  {
    _node->setMaterialFlag(video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, driver->getTexture("WoodChips01_D.tga"));
  }
}

Plan::~Plan()
{
}
