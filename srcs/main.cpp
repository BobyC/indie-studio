//
// main.cpp for srcs in /home/rigola_s/rendu/C++/cpp_indie_studio/srcs
//
// Made by Rigolat Sébastien
// Login   <rigola_s@epitech.net>
//
// Started on  Mon Apr 25 19:16:43 2016 Rigolat Sébastien
// Last update Wed Jun  1 16:44:23 2016 Sacha Sacha Monderer
//

#ifdef _MSC_VER  
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "Irrlicht.lib")
#endif

#include "../Object.hh"

using namespace irr;

int	main()
{
  video::E_DRIVER_TYPE driverType = driverChoiceConsole();
  std::vector<Object> myMap;
  
  if (driverType==video::EDT_COUNT)
    return 1;
  
  IrrlichtDevice* device = createDevice(driverType,
					core::dimension2d<u32>(640, 480), 16, \
					false, false, false);
  if (device == 0)
    return 1;
  
  video::IVideoDriver* driver = device->getVideoDriver();
  scene::ISceneManager* smgr = device->getSceneManager();
  
  myMap = my_fill_map(myMap, *smgr);
  
  smgr->addCameraSceneNodeFPS();
  int lastFPS = -1;
  u32 then = device->getTimer()->getTime();
  
  const f32 MOVEMENT_SPEED = 5.f;
  
  while(device->run())
    {
      const u32 now = device->getTimer()->getTime();
      const f32 frameDeltaTime = (f32)(now - then) / 1000.f;
      then = now;
      driver->beginScene(true, true, video::SColor(255,113,113,133));
      smgr->drawAll();
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
