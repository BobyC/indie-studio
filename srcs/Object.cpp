//
// map.cpp for indie_studio in /home/monder_s/C++/indie
//
// Made by Sacha Sacha Monderer
// Login   <monder_s@epitech.net>
//
// Started on  Fri May 27 14:39:22 2016 Sacha Sacha Monderer
// Last update Thu Jun  2 16:05:41 2016 Sacha Sacha Monderer
//

#include "Object.hh"

Object::Object(scene::ISceneNode *node)
{
  this->_node = node;
  this->_node->getPosition();
  this->_isdead = false;
}

/*Object::Object(scene::ISceneNode *node, video::IVideoDriver *driver)
{
  this->_node = node;
  this->_node->getPosition();
  _node->setMaterialTexture(0, driver->getTexture("../irrlicht-1.8.3/media/wall.bmp"));
  _node->setMaterialFlag(video::EMF_LIGHTING, false);
  this->_isdead = false;
  }*/

Object::~Object()
{
//    this->_node->remove();
}

scene::ISceneNode* Object::getNode() const
{
  return (this->_node);
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
  this->_pos = this->_node->getPosition();
  this->_pos.X = x;
  this->_pos.Y = y;
  this->_pos.Z = z;
  this->_node->setPosition(this->_pos);
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

std::vector<Object>&	my_fill_map(std::vector<Object>& myMap, scene::ISceneManager& smgr)
{
  int		y;
  int		x;
  std::ifstream file("map.txt", std::ios::in);
  char		c;

  if (file)
    {
      while (file.get(c))
	{
	  if (c != '\n')
	    {
	      Object	cube(smgr.addCubeSceneNode());

	      cube.setType(c - 48);
	      myMap.push_back(cube);
	    }
	}
      x = 0;
      y = 0;
      std::vector<Object>::iterator it = myMap.begin();
      while (y != 25)
	{
	  while (x != 25)
	    {
	      it->setPosition(x, y, 30);
	      it++;
	      x++;
	    }
	  x = 0;
	  y++;
	}
    }
  return (myMap);
}
