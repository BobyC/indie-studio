//
// map.cpp for indie_studio in /home/monder_s/C++/indie
//
// Made by Sacha Sacha Monderer
// Login   <monder_s@epitech.net>
//
// Started on  Fri May 27 14:39:22 2016 Sacha Sacha Monderer
// Last update Sun Jun  5 01:23:12 2016 Sacha Sacha Monderer
//

#include "Object.hh"

Object::Object(scene::ISceneNode *node)
{
  this->_node = node;
  this->_nodeAnim = NULL;
  this->_isdead = false;
  this->_animated = false;
  this->_blockable = false;
}

Object::Object(scene::ISceneNode *node, video::IVideoDriver *driver)
{
  this->_node = node;
  this->_nodeAnim = NULL;
  this->_node->getPosition();
  this->_animated = false;
  _node->setPosition(core::vector3df(0,0,20));
  _node->setMaterialTexture(0, driver->getTexture("../irrlicht-1.8.3/media/wall.bmp"));
  _node->setMaterialFlag(video::EMF_LIGHTING, false);
  this->_isdead = false;
}

Object::~Object()
{
//    this->_node->remove();
}

bool		Object::isAnimated() const
{
  return (false);
}

scene::ISceneNode* Object::getNode() const
{
  if (_node)
    return (this->_node);
  else
    return (NULL);
}

int	 Object::getMyType() const
{
  return (this->_type);
}

const core::vector3df&	Object::getPosition() const
{
  return (this->_pos);
}

bool	Object::getBlockable() const
{
  return (this->_blockable);
}

bool	Object::getDestruct() const
{
  return (this->_destructible);
}

bool	Object::getIsdead() const
{
  return (this->_isdead);
}

void	 Object::setTexture(video::IVideoDriver& driver, const std::string &text)
{
  this->_node->setMaterialTexture(0, driver.getTexture(text.c_str()));
  this->_node->setMaterialFlag(video::EMF_LIGHTING, false);
}

void	 Object::setType(int type)
{
  this->_type = type;
}

void	Object::setPosition(f32 x, f32 y, f32 z)
{
  if (_node)
  {
    this->_pos = this->_node->getPosition();
    this->_pos.X += x;
    this->_pos.Y += y;
    this->_pos.Z += z;
    this->_node->setPosition(this->_pos);
  }
}

void	Object::setBlockable(bool b)
{
  this->_blockable = b;
}

void	Object::setDestruct(bool d)
{
  this->_destructible = d;
}

void	Object::setIsdead(bool d)
{
  this->_isdead = d;
}

scene::IAnimatedMeshSceneNode* Object::getNodeAnim() const
{
  return (this->_nodeAnim);
}

void    Object::setPosAnim(f32 x, f32 y, f32 z)
{
  if (_nodeAnim)
  {
    this->_pos = this->_nodeAnim->getPosition();
    this->_pos.X = x;
    this->_pos.Y = y;
    this->_pos.Z = z;
    this->_nodeAnim->setPosition(this->_pos);
  }
}

void    Object::setNodeAnim(scene::IAnimatedMeshSceneNode* n)
{
  this->_nodeAnim = n;
}

void		Object::setCollision(scene::ISceneNode *mapNode, scene::IMesh *mesh, scene::ISceneManager *smgr)
{
  scene::ITriangleSelector *selector =
    smgr->createOctreeTriangleSelector(mesh, mapNode, 128);
  if (selector)
  {
    std::cout << "ok" << std::endl;
    mapNode->setTriangleSelector(selector);
    scene::ISceneNodeAnimator	*anim =
      smgr->createCollisionResponseAnimator(selector, mapNode,
        core::vector3df(0.5,0.5,0.5),core::vector3df(0,0,0),
        core::vector3df(0,0,0));
    selector->drop();
    _node->addAnimator(anim);
    anim->drop();
  }
}

void		Object::setCollision(scene::ISceneNode *mapNode, scene::IMesh *mesh, scene::ISceneManager *smgr, core::vector3df	vect)
{
  scene::ITriangleSelector *selector =
    smgr->createOctreeTriangleSelector(mesh, mapNode, 128);
  if (selector)
  {
    mapNode->setTriangleSelector(selector);
    scene::ISceneNodeAnimator	*anim =
      smgr->createCollisionResponseAnimator(selector, mapNode,
        vect,core::vector3df(0,0,0),
        core::vector3df(0,0,0));
    selector->drop();
    _node->addAnimator(anim);
    anim->drop();
  }
}

void		Object::setCharacterList(std::list<Object*> list)
{
  _charList = list;
}
