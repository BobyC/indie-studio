/*
** Character.hpp for Character in /home/drozdz_b/Documents/TestIrrlitch3
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Thu May 26 15:18:39 2016 drozdz_b
// Last update Sat Jun  4 17:21:48 2016 Sacha Sacha Monderer
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <irrlicht.h>
#include <map>

#include "CharacterInfo.hh"
#include "Object.hh"

using namespace irr;

class Character : public Object
{

private:
  //scene::IAnimatedMeshSceneNode*	_nodeAnim;
  //core::vector3df			_pos;
  CharacterInfo				_info;
  core::vector3d<f32>			_size;
  bool	_moving;
  bool	_movingPreced;
  scene::ISceneCollisionManager	*_col;

public:
  Character(scene::ISceneNode* node);
  Character(scene::ISceneManager* smgr, video::IVideoDriver * driver);
  ~Character();

  CharacterInfo&					getInfo();

  virtual void	move(f32 x, f32 y);
  virtual void	move(f32 x, f32 y, f32 z);
  virtual void	 stati();
  virtual void		updateAnim();
  virtual void		setCollision(scene::ISceneNode *,scene::IMesh*, scene::ISceneManager*);
};

#endif
