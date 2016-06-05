//
// MenuManager.cpp for Manager in /home/rigola_s/test_repo/test_irrlicht/test_indie/srcs/Manager
// 
// Made by Rigolat Sébastien
// Login   <rigola_s@epitech.net>
// 
// Started on  Fri May  6 15:07:53 2016 Rigolat Sébastien
// Last update Fri May  6 15:07:53 2016 Rigolat Sébastien
//

#include "MenuManager.hpp"

Manager::MenuManager *Manager::MenuManager::_instance = NULL;

AGUIMenu *Manager::MenuManager::getCurrent() const
{
	return (_current);
}

IrrlichtDevice *Manager::MenuManager::getDevice() const
{
	return (_device);
}

void											Manager::MenuManager::killInstance()
{
	delete (_instance);
}

void											Manager::MenuManager::render() const
{
	_current->draw();
}

void											Manager::MenuManager::switchMenu(MenuType type)
{
	_previous = _current;
	_current = _menuMap[type];

	_device->setEventReceiver(_current);

	_current->setVisible(true);
	_previous->setVisible(false);
};

void												Manager::MenuManager::initMenus()
{
	/*
	 menu type :

			MAIN_MENU,
			PLAY_MENU,
			OPTION_MENU,
			PLAY_SUB_MENU,
			LEADER_BOARD_MENU,
			PAUSE_MENU
	*/
	SAppContext context(_device, gui::EGUIET_ELEMENT,
						MAIN_MENU,
						_device->getGUIEnvironment()->getRootGUIElement(),
						core::rect<s32>(0, 0, 1920, 1080));

	_current = _menuMap[MAIN_MENU] = new MainMenu(context);


	context.id = OPTION_MENU;
	_menuMap[OPTION_MENU] = new MainMenu(context);

	context.id = LEADER_BOARD_MENU;
	_menuMap[LEADER_BOARD_MENU] = new MainMenu(context);

	context.id = PLAY_MENU;
	_menuMap[PLAY_MENU] = new PlayMenu(context);

	context.id = PLAY_SUB_MENU;
	_menuMap[PLAY_SUB_MENU] = new PlaySubMenu(context);

	for (std::map<MenuType, AGUIMenu*>::iterator it = _menuMap.begin();
		 it != _menuMap.end(); ++it)
		it->second->setVisible(false);

	_current->setVisible(true);
	_device->setEventReceiver(_current);
	_previous = NULL;
}
