//
// Bomb.cpp for Indie_studio in /home/pujol_n/rendu/cpp_indie_studio/srcs
//
// Made by Nicolas Pujol
// Login   <pujol_n@epitech.net>
//
// Started on  Fri Jun  3 16:00:42 2016 Nicolas Pujol
// Last update Sat Jun  4 22:26:08 2016 drozdz_b
//

#include "Bomb.hh"

Bomb::Bomb(scene::ISceneNode *node) : Object(node) {}

Bomb::Bomb(scene::ISceneManager *smgr, video::IVideoDriver *driver) :
  Object(NULL)
{
  _mesh = smgr->getMesh("Dynamite/dinamite.obj");
  _node = smgr->addMeshSceneNode(_mesh);
  _size = core::vector3df(1, 1, 1);
  _smgr = smgr;
  if (_node)
    {
      _node->setMaterialTexture(0, driver->getTexture("Dynamite/D.png"));
      _node->setMaterialFlag(video::EMF_LIGHTING, false);
      _node->setScale(core::vector3df(2, 2, 2));
      _node->setPosition(core::vector3df(-10, 5, -10));
    }
}

void	Bomb::addCollision(Object *character)
{
  character->setCollision(_node, _smgr->getGeometryCreator()->createCubeMesh(), _smgr, core::vector3df(1,1,1));
}

void	Bomb::addCollision(std::list<Object*> cList)
{
  std::list<Object *>::iterator	it;

  it = cList.begin();
  while (it != cList.end())
  {
    addCollision(*it);
    ++it;
  }
}

Bomb::~Bomb() {}
