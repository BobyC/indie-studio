//
// map.cpp for indie_studio in /home/monder_s/C++/indie
// 
// Made by Sacha Sacha Monderer
// Login   <monder_s@epitech.net>
// 
// Started on  Fri May 27 14:39:22 2016 Sacha Sacha Monderer
// Last update Wed Jun  1 16:24:46 2016 Sacha Sacha Monderer
//

#include "../include/Object.hh"

Object::Object(scene::ISceneNode *node)
{
  this->_node = node;
  this->_node->getPosition();
}

Object::~Object()
{
  ;
}

scene::ISceneNode& Object::getNode() const
{
  return (*this->_node);
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
  this->_pos.X += x;
  this->_pos.Y += y;
  this->_pos.Z += z;
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

#ifdef _MSC_VER
// We'll also define this to stop MSVC complaining about sprintf().
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "Irrlicht.lib")
#endif

/*#include <irrlicht.h>
#include "driverChoice.h"
*/
using namespace irr;

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

int main()
{
  video::E_DRIVER_TYPE driverType = driverChoiceConsole();
  std::vector<Object> myMap;
  
  if (driverType==video::EDT_COUNT)
    return 1;

  IrrlichtDevice* device = createDevice(driverType,
					 core::dimension2d<u32>(640, 480), 16, false, false, false);
  if (device == 0)
    return 1; // could not create selected driver.

  video::IVideoDriver* driver = device->getVideoDriver();
  scene::ISceneManager* smgr = device->getSceneManager();

  myMap = my_fill_map(myMap, *smgr);

  //placé 
  
   smgr->addCameraSceneNodeFPS();
  int lastFPS = -1;

  // In order to do framerate independent movement, we have to know
  // how long it was since the last frame
  u32 then = device->getTimer()->getTime();

  // This is the movemen speed in units per second.
  const f32 MOVEMENT_SPEED = 5.f;

  while(device->run())
    {
      // Work out a frame delta time.
      const u32 now = device->getTimer()->getTime();
      const f32 frameDeltaTime = (f32)(now - then) / 1000.f; // Time in seconds
      then = now;
      driver->beginScene(true, true, video::SColor(255,113,113,133));
      smgr->drawAll(); // draw the 3d scene
      // device->getGUIEnvironment()->drawAll(); // draw the gui environment (the logo)
      driver->endScene();
      int fps = driver->getFPS();
      if (lastFPS != fps)
        {
	  core::stringw tmp(L"Map Bomberman[");
	  tmp += driver->getName();
	  tmp += L"] fps: ";
	  tmp += fps;

	  device->setWindowCaption(tmp.c_str());
	  lastFPS = fps;
        }
    }
  device->drop();
    
  return 0;
}
