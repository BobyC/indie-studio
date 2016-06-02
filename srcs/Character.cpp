/*
** Character.cpp for Character in /home/drozdz_b/Documents/TestIrrlitch3
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Thu May 26 15:17:50 2016 drozdz_b
** Last update Thu Jun 02 17:06:36 2016 drozdz_b
*/

#include "Character.hpp"

/*
** Construtors & Destructor
*/

Character::Character(scene::ISceneNode* node)
: Object(node)
{
}

Character::Character(scene::ISceneNode* node, video::IVideoDriver * driver)
: Object(node, driver)
{

}

Character::Character(scene::ISceneManager* smgr, video::IVideoDriver * driver)
: Object(NULL)
{
  scene::IAnimatedMesh *bomber = smgr->getMesh("tris.md2");
  //bomber->setFrameLoop(0, 10);
  _node = smgr->addAnimatedMeshSceneNode(bomber);
  _size = core::vector3df(1, 1, 1);
  if (_node)
  {
      _node->setMaterialTexture(0, driver->getTexture("Bomber.PCX"));
      _node->setMaterialFlag(video::EMF_LIGHTING, false);
      _node->setScale(core::vector3df(0.4, 0.4, 0.4));
      _node->setPosition(core::vector3df(0, 10, 0));
      _node->setFrameLoop(1000, 1200);
  }
}

/*Character::Character(scene::ISceneNode* node, video::IVideoDriver * driver)
: Object(node, driver)
{

}*/

Character::~Character()
{
}

CharacterInfo&	Character::getInfo()
{
  return (this->_info);
}

/*
** Actions of Character
*/
void	Character::move(f32 x, f32 y)
{
  if (x > 0)
    _node->setRotation(core::vector3df(0, -30, 0));
  if (x < 0)
    _node->setRotation(core::vector3df(0, 150, 0));

  this->_pos = this->_node->getPosition();
  this->_pos.X += x;
  this->_pos.Y += y;
  this->_node->setPosition(this->_pos);
}

void	Character::move(f32 x, f32 y, f32 z)
{
  if (x > 0)
    _node->setRotation(core::vector3df(0, -30, 0));
  if (x < 0)
    _node->setRotation(core::vector3df(0, 30, 0));
  if (z > 0)
    _node->setRotation(core::vector3df(0, -60, 0));
  if (z < 0)
    _node->setRotation(core::vector3df(0, 60, 0));

  this->_pos = this->_node->getPosition();
  this->_pos.X += x;
  this->_pos.Y += y;
  this->_pos.Z += z;
  this->_node->setPosition(this->_pos);
}
