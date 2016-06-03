//
// main.cpp for srcs in /home/rigola_s/test_repo/test_irrlicht/test_indie/srcs
//
// Made by Rigolat Sébastien
// Login   <rigola_s@epitech.net>
//
// Started on  Mon May  2 17:07:25 2016 Rigolat Sébastien
// Last update Thu May  5 02:40:43 2016 Rigolat Sébastien
//

#include "irrlicht.h"
#include "MenuManager.hpp"
#include "driverChoice.h"

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

int		main()
{
	irr::IrrlichtDevice		*device;
	video::E_DRIVER_TYPE	driverType = driverChoiceConsole();
	if (driverType == video::EDT_COUNT)
		return (-1);

	device = createDevice(driverType, irr::core::dimension2d<irr::u32>(1920, 1080));
	Manager::MenuManager::createManager(device);
	irr::video::IVideoDriver	*driver = NULL;
	if (!device)
		{
			std::cerr << "Error occured" << std::endl;
			return (-1);
		}

	device->setWindowCaption(L"Indie Studio");
	device->setResizable(true);
	driver = device->getVideoDriver();
	while(device->run() && driver)
		if (device->isWindowActive())
			{
				driver->beginScene(true, true, video::SColor(0,200,200,200));
				device->getGUIEnvironment()->drawAll();
//				Manager::MenuManager::getInstance()->render();
				driver->endScene();
			}

	device->drop();
	return (0);
}
