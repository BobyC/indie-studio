 //
// main.cpp for main in /home/drozdz_b/Documents/TestIrrlitch
//
// Made by drozdz_b
// Login   <drozdz_b@epitech.net>
//
// Started on  Wed May  4 14:00:27 2016 drozdz_b
// Last update Sun Jun  5 01:03:27 2016 Sacha Sacha Monderer
//

#include <iostream>
#include "irrlicht.h"
#include "Character.hpp"
#include "KeyReceiver.hpp"
#include "PlayerController.hpp"
#include "Plan.hpp"
#include "Object.hh"
#include "Box.hh"
#include "Map.hh"
//#include "Bomb.hh"
#include "Core.hh"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int			main()
{
  SIrrlichtCreationParameters		params;

  E_DRIVER_TYPE				driverType = EDT_OPENGL;
  params.DriverType = driverType;
  params.WindowSize = dimension2d<u32>(640, 480);

  IrrlichtDevice	*device = createDevice(driverType,
			core::dimension2d<u32>(1024, 980), 16, false, false, false);

  if (!device)
    return 1;

  device->setWindowCaption(L"Indie Studio");

	Core app(device);

	app.run();

  return (0);
}
