//
// main.cpp for indie_studio in /home/monder_s/C++/cpp_indie_studio
// 
// Made by Sacha Sacha Monderer
// Login   <monder_s@epitech.net>
// 
// Started on  Fri Jun  3 17:33:08 2016 Sacha Sacha Monderer
// Last update Fri Jun  3 17:51:28 2016 Sacha Sacha Monderer
//

using namespace irr;

#include "../include/Map.hh"

#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif 

int main()
{
  video::E_DRIVER_TYPE driverType=driverChoiceConsole();
  if (driverType==video::EDT_COUNT)
    return 1;
  IrrlichtDevice *device =
    createDevice(driverType, core::dimension2d<u32>(640, 480), 16,	\
		 false);
  
  if (device == 0)
    return 1;
  video::IVideoDriver* driver = device->getVideoDriver();
  scene::ISceneManager* smgr = device->getSceneManager();
  
  Map	map(smgr, device);
  
  while(device->run())
    if (device->isWindowActive())
      {
	driver->beginScene(true, true, 0);
	smgr->drawAll();
	
	driver->endScene();
	
	int fps = driver->getFPS();
	
	if (lastFPS != fps)
	  {
	    core::stringw str = L"Collision detection example - Irr\
licht Engine [";
	    str += driver->getName();
	    str += "] FPS:";
	    str += fps;
	    
	    device->setWindowCaption(str.c_str());
	    lastFPS = fps;
	  }
      }
  
  device->drop();
  
  return 0;
}
