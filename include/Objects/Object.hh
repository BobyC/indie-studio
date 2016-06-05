//
// Objet.hh for indie_studio in /home/monder_s/C++/indie
//
// Made by Sacha Sacha Monderer
// Login   <monder_s@epitech.net>
//
// Started on  Fri May 27 14:33:04 2016 Sacha Sacha Monderer
// Last update Sun Jun  5 01:22:16 2016 Sacha Sacha Monderer
//

#ifndef OBJECT_HH_
# define OBJECT_HH_

#include <irrlicht.h>
//#include "driverChoice.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

#include <list>

using namespace irr;

class Object
{
protected:
  int			_type;
  scene::ISceneNode	*_node;
  scene::IAnimatedMeshSceneNode *_nodeAnim;
  core::vector3df	_pos;
  bool			_blockable;
  bool			_destructible;
  bool			_isdead;
  bool			_animated;
  std::list<Object*> _charList;

public:
  Object(scene::ISceneNode*);
  Object(scene::ISceneNode*, video::IVideoDriver *driver);
  ~Object();

  virtual void			setPosition(f32, f32, f32);
  virtual void			setPosAnim(f32, f32, f32);
  void			setType(int);
  void			setBlockable(bool);
  void			setDestruct(bool);
  void			setIsdead(bool);
  void			setNodeAnim(scene::IAnimatedMeshSceneNode*);
  void			setTexture(video::IVideoDriver&, const std::string&);
  const core::vector3df&	getPosition() const;
  int			getMyType() const;
  scene::ISceneNode*	getNode() const;
  scene::IAnimatedMeshSceneNode* getNodeAnim() const;
  bool			getBlockable() const;
  bool			getDestruct() const;
  bool			getIsdead() const;
  virtual void			setCollision(scene::ISceneNode *mapNode, scene::IMesh *mesh, scene::ISceneManager *smgr);
  virtual void  setCollision(scene::ISceneNode *mapNode, scene::IMesh *mesh, scene::ISceneManager *smgr, core::vector3df	vect);
  virtual bool	isAnimated() const;
  virtual void	setCharacterList(std::list<Object*> list);
};

#endif /* OBJECT_HH_ */
