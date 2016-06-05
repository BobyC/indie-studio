//
// Bomb.hh for Indie_studio in /home/pujol_n/rendu/cpp_indie_studio/include
//
// Made by Nicolas Pujol
// Login   <pujol_n@epitech.net>
//
// Started on  Fri Jun  3 16:12:24 2016 Nicolas Pujol
// Last update Sun Jun  5 11:05:18 2016 Nicolas Pujol
//

#ifndef BOMB_HH_
# define BOMB_HH_

#include <list>

//#include "Character.hpp"
#include "Object.hh"

class				Bomb : public Object
{

public:

  Bomb(scene::ISceneNode *);
  Bomb(scene::ISceneManager *, video::IVideoDriver *, IrrlichtDevice *);
  ~Bomb();

  void	addCollision(Object *);
  void	addCollision(std::list<Object*>);
  void	explode(std::list<Object*> &);
  f32	getDistance(Object *) const;
  bool	common(Object *) const;

private:

  //scene::IAnimatedMeshSceneNode *_node;
  scene::ISceneCollisionManager	*_col;
  core::vector3d<f32>		_size;
  scene::IMesh			*_mesh;
  scene::ISceneManager		*_smgr;
  IrrlichtDevice		*_device;
  ITimer			*_timer;
  u32				_time;
};

#endif /* !BOMB_HH_ */
