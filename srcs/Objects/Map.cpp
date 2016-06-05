//
// Map.cpp for indie_studio in /home/monder_s/C++/cpp_indie_studio/srcs
//
// Made by Sacha Sacha Monderer
// Login   <monder_s@epitech.net>
//
// Started on  Fri Jun  3 16:46:32 2016 Sacha Sacha Monderer
// Last update Sun Jun  5 10:03:13 2016 drozdz_b
//

#include "Map.hh"
#include "Plan.hpp"
#include "Box.hh"
#include "Character.hpp"
#include "PlayerController.hpp"
#include "KeyReceiver.hpp"

Map::Map(scene::ISceneManager* smgr, video::IVideoDriver *driver, IrrlichtDevice *device,
KeyReceiver* receiver)
{
  _receiver = receiver;
  _smgr = smgr;
  _device = device;
  _driver = driver;
}

Map::~Map()
{
  while (!_map.empty())
    _map.erase(_map.begin());
}

Object*		Map::createCharacter(int& nbChar)
{
  Character*			character = new Character(_smgr, _driver);

  if (nbChar == 0)
    _controllers.push_back(new PlayerController(character, _receiver, _device));
  if (nbChar == 1)
  {
    ICharacterController	*player = new PlayerController(character, _receiver, _device, nbChar);
    _controllers.push_back(player);
  }
  nbChar++;
  return ((Object*)character);
}

Object*		Map::createObject(char c, int& nbChar, int& i)
{
  Object	*obj;

  if (c == '0')
  {
    obj = new Object(NULL);
  }
  else if (c == '1')
  {
      obj = new Box(_smgr, _driver);
  }
  else if (c == '2')
  {
    obj = new Box(_smgr, _driver);
    obj->setDestruct(true);
  }
  else if (c == '3')
  {
    obj = createCharacter(nbChar);
    this->_vect.push_back(i);
  }
  else
    return (NULL);
  ++i;
  return (obj);
}

void	Map::load(const std::string& path)
{
  std::ifstream file(path.c_str(), std::ios::in);
  char	c;
  Object	*obj;
  int			nbChar;
  int			i;
  int			j = 0;
  i = 0;
  nbChar = 0;
  if (file)
  {
    _plan = new Plan(_smgr, _driver);
    while (file.get(c))
    {
      if (c != '\n')
      {
        obj = createObject(c, nbChar, i);
        if (obj != NULL)
        {
          this->_map.push_back(obj);
        }
        ++j;
      }
    }
  }
  _smgr->addCameraSceneNode(0, core::vector3df(5, 9, -2), core::vector3df(5,0, 5), true);
}

void	Map::setCollisionList(Object* character, std::list<Object*>::iterator sup)
{
  std::list<Object*>::iterator	it;
  int		c = 0;

  it = _map.begin();
  while (it != _map.end())
  {
      if (it != sup)
        {
          if ((*it)->getNode() && (*it)->getBlockable())
          {
            character->setCollision((*it)->getNode(), _smgr->getGeometryCreator()->createCubeMesh(core::vector3df(1, 1, 1)), _smgr);
            c++;
          }
        }
    ++it;
  }
}

void	Map::placeObjects()
{
  std::list<Object*>::iterator	it;
  int		x;
  int		z;
  int		i;

  it = _map.begin();
  x = 0;
  z = 0;
  i = 0;
  while (i < 100 && it != _map.end() && z < 10)
  {
    while (i < 100 && it != _map.end() && x < 10)
    {
      if (!(*it)->isAnimated())
        (*it)->setPosition(x, 0.5, z);
      else
      {
        (*it)->setPosAnim(x, 1, z);
        setCollisionList((*it), it);
      }
      ++x;
      ++it;
      ++i;
    }
    x = 0;
    ++z;
  }
}

std::list<Object*>	Map::getMap() const
{
  return (this->_map);
}

void	Map::doAction()
{
  std::list<ICharacterController*>::iterator	it;

  it = _controllers.begin();
  while (it != _controllers.end())
  {
    (*it)->doAction();
    ++it;
  }
}
