//
// Box.cpp for indie_studio in /home/monder_s/C++/cpp_indie_studio/srcs
//
// Made by Sacha Sacha Monderer
// Login   <monder_s@epitech.net>
//
// Started on  Thu Jun  2 15:56:21 2016 Sacha Sacha Monderer
// Last update Sat Jun  4 18:44:39 2016 Sacha Sacha Monderer
//

#include "Box.hh"

Box::Box(scene::ISceneNode *node) : Object(node)
{
  this->_node = node;
  if (this->_node)
  {
    this->_node->getPosition();
    this->_isdead = false;
    this->_destructible = false;
  }
}

Box::Box(scene::ISceneManager *smgr, video::IVideoDriver *driver) : Object(NULL)
{
  core::vector3df   size(1, 0.5f, 1);
  scene::IMesh *cube = smgr->getGeometryCreator()->createCubeMesh(size);
  this->_node = smgr->addMeshSceneNode(cube);
  this->_node->getPosition();
  if (this->_node)
  {
    this->_node->setMaterialTexture(0, driver->getTexture("../../irrlicht-1.8.3/media/wall.bmp"));
    this->_node->setMaterialFlag(video::EMF_LIGHTING, false);
    this->_isdead = false;
  }
}

Box::~Box()
{
}
