//
// Box.cpp for indie_studio in /home/monder_s/C++/cpp_indie_studio/srcs
//
// Made by Sacha Sacha Monderer
// Login   <monder_s@epitech.net>
//
// Started on  Thu Jun  2 15:56:21 2016 Sacha Sacha Monderer
// Last update Thu Jun  2 16:05:03 2016 Sacha Sacha Monderer
//

#include "Box.hh"

Box::Box(scene::ISceneNode *node) : Object(node)
{
  this->_node = node;
  if (this->_node)
  {
    this->_node->getPosition();
    this->_isdead = false;
  }
}

Box::Box(scene::ISceneNode *node, video::IVideoDriver *driver) : Object(node, driver)
{
  this->_node = node;
  if (this->_node)
  {
    this->_node->getPosition();
    this->_node->setMaterialTexture(0, driver->getTexture("../irrlicht-1.8.3/media/wall.bmp"));
    this->_node->setMaterialFlag(video::EMF_LIGHTING, false);
    this->_isdead = false;
  }
}

Box::Box(scene::ISceneManager *smgr, video::IVideoDriver *driver) : Object(NULL)
{
  scene::IMesh *cube = smgr->getGeometryCreator()->createCubeMesh();
  this->_node = smgr->addMeshSceneNode(cube);
  this->_node->getPosition();
  if (this->_node)
  {
    this->_node->setMaterialTexture(0, driver->getTexture("../irrlicht-1.8.3/media/wall.bmp"));
    this->_node->setMaterialFlag(video::EMF_LIGHTING, false);
    _node->setScale(core::vector3df(1, 1, 1));
    _node->setPosition(core::vector3df(0, 5, 0));
    this->_isdead = false;
  }
}

Box::~Box()
{
}
