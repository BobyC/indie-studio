//
// Objet.hh for indie_studio in /home/monder_s/C++/indie
//
// Made by Sacha Sacha Monderer
// Login   <monder_s@epitech.net>
//
// Started on  Fri May 27 14:33:04 2016 Sacha Sacha Monderer
// Last update Sat Jun  4 22:20:00 2016 drozdz_b
//

#ifndef OBJECT_HH_
# define OBJECT_HH_

#include <irr/irrlicht.h>
//#include "driverChoice.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace irr;

class Object
{
protected:
  int			_type;
  scene::ISceneNode	*_node;
  core::vector3df	_pos;
  bool			_blockable;
  bool			_destructible;
  bool			_isdead;

public:
  Object(scene::ISceneNode*);
  Object(scene::ISceneNode*, video::IVideoDriver *driver);
  ~Object();

  void			setPosition(f32, f32, f32);
  void			setType(int);
  void			setBlockable(bool);
  void			setDestruct(bool);
  void			setIsdead(bool);
  void			setTexture(video::IVideoDriver&, const std::string&);
  const core::vector3df&	getPosition() const;
  int			getMyType() const;
  scene::ISceneNode*	getNode() const;
  bool			getBlockable() const;
  bool			getDestruct() const;
  bool			getIsdead() const;
  virtual void			setCollision(scene::ISceneNode *mapNode, scene::IMesh *mesh, scene::ISceneManager *smgr);
virtual void  setCollision(scene::ISceneNode *mapNode, scene::IMesh *mesh, scene::ISceneManager *smgr, core::vector3df	vect);
  
  std::vector<Object>&	my_fill_map(std::vector<Object>&, scene::ISceneManager&);

};
  
#endif /* OBJECT_HH_ */
