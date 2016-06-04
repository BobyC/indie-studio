//
// Bomb.hh for Indie_studio in /home/pujol_n/rendu/cpp_indie_studio/include
//
// Made by Nicolas Pujol
// Login   <pujol_n@epitech.net>
//
// Started on  Fri Jun  3 16:12:24 2016 Nicolas Pujol
// Last update Sat Jun  4 21:57:22 2016 drozdz_b
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
  Bomb(scene::ISceneNode *, video::IVideoDriver *);
  Bomb(scene::ISceneManager *, video::IVideoDriver *);
  ~Bomb();

  void	addCollision(Object *);
  void	addCollision(std::list<Object*>);

private:

  //scene::IAnimatedMeshSceneNode *_node;
  scene::ISceneCollisionManager	*_col;
  core::vector3d<f32>		_size;
  scene::IMesh					*_mesh;
  scene::ISceneManager		*_smgr;
};

#endif /* !BOMB_HH_ */
