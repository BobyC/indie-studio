//
// MainMenu.cpp for Menus in /home/rigola_s/test_repo/test_irrlicht/test_indie/srcs/Menus
//
// Made by Rigolat Sébastien
// Login   <rigola_s@epitech.net>
//
// Started on  Mon May  2 17:42:08 2016 Rigolat Sébastien
// Last update Thu May  5 16:46:43 2016 Rigolat Sébastien
//

#include "MenuManager.hpp"

MainMenu::MainMenu(const SAppContext &context)
	: AGUIMenu(context)
{
	AGUIMenu::initGUIelements();
	initGUIelements();
	initKeyMap();
}

MainMenu::~MainMenu()
{

}

/*
bool MainMenu::OnEvent(const SEvent &event)
{
	if (event.EventType == EET_GUI_EVENT)
		{
			onGUIEvent(event);
			return true;
		}
	else if (event.EventType == EET_KEY_INPUT_EVENT)
		return (keyInputTreatment(event));
	return false;
}
*/

void MainMenu::initGUIelements()
{
	s32 X = 1920/ 2 - 100;
	s32 Y = 1080 / 2 - 32;
	_selectableButtons.push_back(Environment->addButton(core::rect<s32>(X, Y - 100, X + 100, (Y - 100) + 32),
						   this,
						   PLAY,
						   L"Play"));
	//  ->setImage(_driver->getTexture("Media/irrlichtlogo2.png"));
	_selectableButtons.push_back(Environment->addButton(core::rect<s32>(X, Y - 60, X + 100, (Y - 60) + 32),
						   this,
						   OPTION,
						   L"Option"));
	//			  ->setImage(_driver->getTexture("Media/irrlichtlogo2.png"));
	_selectableButtons.push_back(Environment->addButton(core::rect<s32>(X, 320, X + 100, 320 + 32),
						   this,
						   LEADER_BOARD,
						   L"Leaderboard"));
	//			  ->setImage(_driver->getTexture("Media/irrlichtlogo2.png"));
	_selectableButtons.push_back(Environment->addButton(core::rect<s32>(X, 360, X + 100, 360 + 32),
						   this,
						   EXIT,
						   L"Exit"));
	//			  ->setImage(_driver->getTexture("Media/irrlichtlogo2.png"));
	_currentButton = getElementFromId(PLAY);
	moveSelector();
}

void				MainMenu::initKeyMap()
{
	_mMap[KEY_UP] = &MainMenu::upKeyPressed;
	_mMap[KEY_DOWN] = &MainMenu::downKeyPressed;
	_mMap[KEY_RETURN] = &MainMenu::enterKeyPressed;

	_mMap[KEY_ESCAPE] = static_cast<mPtr>(&MainMenu::onExit);
	_mMap[EXIT] = static_cast<mPtr>(&MainMenu::onExit);
	_mMap[PLAY] = static_cast<mPtr>(&MainMenu::onPlay);
}

void			MainMenu::onLeaderBoard()
{

}

void			MainMenu::onOption()
{
	Manager::MenuManager::getInstance()->switchMenu(OPTION_MENU);
}

void			MainMenu::onPlay()
{
	Manager::MenuManager::getInstance()->switchMenu(PLAY_MENU);
}

void			MainMenu::onExit()
{
	_context.device->closeDevice();
}
