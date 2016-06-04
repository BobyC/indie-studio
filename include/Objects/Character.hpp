/*
** Character.hpp for Character in /home/drozdz_b/Documents/TestIrrlitch3
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Thu May 26 15:18:39 2016 drozdz_b
// Last update Sun Jun  5 00:49:43 2016 Sacha Sacha Monderer
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <irrlicht.h>
#include <map>
#include <list>

#include "CharacterInfo.hh"
#include "Object.hh"
#include "Bomb.hh"

using namespace irr;

class Character : public Object
{

private:
  scene::IAnimatedMeshSceneNode*	_node;
  //core::vector3df			_pos;
  CharacterInfo				_info;
  core::vector3d<f32>			_size;
  bool	_moving;
  bool	_movingPreced;
  scene::ISceneCollisionManager	*_col;
  std::list<Bomb*>							_bombList;
  scene::ISceneManager									*_smgr;
  video::IVideoDriver										*_driver;

public:
  Character(scene::ISceneNode* node);
  Character(scene::ISceneNode* node, video::IVideoDriver *driver);
  Character(scene::ISceneManager* smgr, video::IVideoDriver * driver);
  ~Character();

  CharacterInfo&					getInfo();

  virtual void	move(f32 x, f32 y);
  virtual void	move(f32 x, f32 y, f32 z);
  virtual void	 stati();
  virtual void		updateAnim();
  virtual void		setCollision(scene::ISceneNode *,scene::IMesh*, scene::ISceneManager*);
  virtual void	setCollision(scene::ISceneNode *mapNode, scene::IMesh *mesh, scene::ISceneManager *smgr, core::vector3df	vect);
  virtual	void		putBomb();
  virtual void		update();

};

#endif
