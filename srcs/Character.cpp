/*
** Character.cpp for Character in /home/drozdz_b/Documents/TestIrrlitch3
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Thu May 26 15:17:50 2016 drozdz_b
** Last update Sun May 29 03:02:40 2016 drozdz_b
*/

#include "Character.hpp"

/*
** Construtors & Destructor
*/

Character::Character(scene::ISceneNode* node)
{
  this->_node = node;
  this->_node->getPosition();
}

Character::~Character()
{
}

/*
** Getters & Setters
*/
const core::vector3df&	Character::getPosition() const
{
  return (this->_pos);
}

void	Character::setPosition(f32 x, f32 y)
{
  this->_pos = this->_node->getPosition();
  this->_pos.X += x;
  this->_pos.Y += y;
  this->_node->setPosition(this->_pos);
}

void	Character::setPosition(f32 x, f32 y, f32 z)
{
  this->_pos = this->_node->getPosition();
  this->_pos.X += x;
  this->_pos.Y += y;
  this->_pos.Z += z;
  this->_node->setPosition(this->_pos);
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
  this->_pos = this->_node->getPosition();
  this->_pos.X += x;
  this->_pos.Y += y;
  this->_node->setPosition(this->_pos);
}

void	Character::move(f32 x, f32 y, f32 z)
{
  this->_pos = this->_node->getPosition();
  this->_pos.X += x;
  this->_pos.Y += y;
  this->_pos.Z += z;
  this->_node->setPosition(this->_pos);
}
