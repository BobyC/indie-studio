//
// Bomb.cpp for Indie_studio in /home/pujol_n/rendu/cpp_indie_studio/srcs
//
// Made by Nicolas Pujol
// Login   <pujol_n@epitech.net>
//
// Started on  Fri Jun  3 16:00:42 2016 Nicolas Pujol
// Last update Sun Jun  5 11:05:58 2016 Nicolas Pujol
//

#include "Bomb.hh"

Bomb::Bomb(scene::ISceneNode *node) : Object(node) {}

Bomb::Bomb(scene::ISceneManager *smgr, video::IVideoDriver *driver, IrrlichtDevice *device) :
  Object(NULL)
{
  _mesh = smgr->getMesh("imgs/Dynamite/dinamite.obj");
  _node = smgr->addMeshSceneNode(_mesh);
  _size = core::vector3df(1, 1, 1);
  _smgr = smgr;
  _device = device;
  _time = _device->getTimer()->getTime();
  if (_node)
    {
      _node->setMaterialTexture(0, driver->getTexture("imgs/Dynamite/D.png"));
      _node->setMaterialFlag(video::EMF_LIGHTING, false);
      _node->setScale(core::vector3df(0.5, 0.5, 0.5));
//      _node->setPosition(core::vector3df(-10, 5, -10));
    }
}

void	Bomb::addCollision(Object *character)
{
  character->setCollision(_node,
    _smgr->getGeometryCreator()->createCubeMesh(core::vector3df(1, 1, 1)),
  _smgr, core::vector3df(0.2,0.2,0.2));
}

void	Bomb::addCollision(std::list<Object*> cList)
{
  std::list<Object *>::iterator	it;

  it = cList.begin();
  while (it != cList.end())
  {
    addCollision(*it);
    ++it;
  }
}

f32	Bomb::getDistance(Object *it) const
{
  core::vector3df vectBomb;
  core::vector3df vectBloc;

  vectBomb = this->getNode()->getPosition();
  vectBloc = it->getNode()->getPosition();
  std::cout << "Bomb x = " << vectBomb.X << std::endl;
  std::cout << "Bloc Z = " << vectBloc.Z << std::endl;
  return (core::squareroot((vectBloc.X - vectBomb.X) * (vectBloc.X - vectBomb.X)) +
			   ((vectBloc.Z - vectBomb.Z) * (vectBloc.Z - vectBomb.Z)));
}

bool			Bomb::common(Object *it) const
{
  core::vector3df vectBomb;
  core::vector3df vectBloc;

  vectBomb = this->getNode()->getPosition();
  vectBloc = it->getNode()->getPosition();
  if (((vectBomb.X <= vectBloc.X + 0.5) || (vectBomb.Z >= vectBloc.Z - 0.5)) ||
      ((vectBomb.Z <= vectBloc.Z + 0.5) || (vectBomb.Z >= vectBloc.Z - 0.5)))
    return (true);
  else
    return (false);
}

void	Bomb::explode(std::list<Object*> &cList)
{
  std::list<Object *>::iterator it;


  it = cList.begin();
  while (it != cList.end())
    {
      std::cout << "Distance : " << getDistance(*it) << std::endl;
      if (_device->getTimer()->getTime() - _time > 1500)
      	{
	  if ((*it)->getDestruct() && getDistance(*it) < 50 && common(*it))
	    {
	      std::cout << "DEDANT" << std::endl;
	      (*it)->setIsdead(true);
	    }
	}
      ++it;
    }
}

Bomb::~Bomb() {}
