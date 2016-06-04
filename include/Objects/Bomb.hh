//
// Bomb.hh for Indie_studio in /home/pujol_n/rendu/cpp_indie_studio/include
//
// Made by Nicolas Pujol
// Login   <pujol_n@epitech.net>
//
// Started on  Fri Jun  3 16:12:24 2016 Nicolas Pujol
// Last update Fri Jun  3 19:44:54 2016 Nicolas Pujol
//

#ifndef BOMB_HH_
# define BOMB_HH_

# include "Object.hh"

class				Bomb : public Object
{

public:

  Bomb(scene::ISceneNode *);
  Bomb(scene::ISceneNode *, video::IVideoDriver *);
  Bomb(scene::ISceneManager *, video::IVideoDriver *);
  ~Bomb();

private:

  scene::IAnimatedMeshSceneNode *_node;
  scene::ISceneCollisionManager	*_col;
  core::vector3d<f32>		_size;

};

#endif /* !BOMB_HH_ */
