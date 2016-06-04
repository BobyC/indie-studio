//
// Bomb.cpp for Indie_studio in /home/pujol_n/rendu/cpp_indie_studio/srcs
//
// Made by Nicolas Pujol
// Login   <pujol_n@epitech.net>
//
// Started on  Fri Jun  3 16:00:42 2016 Nicolas Pujol
// Last update Sat Jun  4 03:14:33 2016 Rigolat Sébastien
//

#include "Bomb.hh"

Bomb::Bomb(scene::ISceneNode *node) : Object(node) {}

Bomb::Bomb(scene::ISceneManager *smgr, video::IVideoDriver *driver) :
  Object(NULL)
{
  scene::IAnimatedMesh	*bomb = smgr->getMesh("");
  _node = smgr->addAnimatedMeshSceneNode(bomb);
  _size = core::vector3df(1, 1, 1);
  _col = smgr->getSceneCollisionManager();
  if (_node)
    {
      _node->setMaterialTexture(0, driver->getTexture(""));
      _node->setMaterialFlag(video::EMF_LIGHTING, false);
      _node->setScale(core::vector3df(0.2, 0.2, 0.2));
      _node->setPosition(core::vector3df(-10, 5, -10));
      _node->setFrameLoop(400, 600);
      _node->setAnimationSpeed(30);
    }
}

Bomb::~Bomb() {}
