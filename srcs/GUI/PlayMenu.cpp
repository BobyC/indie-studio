//
// PlayMenu.cpp for Menus in /home/rigola_s/test_repo/test_irrlicht/test_indie/srcs/Menus
// 
// Made by Rigolat Sébastien
// Login   <rigola_s@epitech.net>
// 
// Started on  Mon May  2 17:39:16 2016 Rigolat Sébastien
// Last update Mon May  2 17:39:16 2016 Rigolat Sébastien
//

#include "MenuManager.hpp"

PlayMenu::PlayMenu(SAppContext const &context)
	: AGUIMenu(context)
{
	AGUIMenu::initGUIelements();
	initGUIelements();
	initKeyMap();
}

PlayMenu::~PlayMenu() {}

void PlayMenu::initGUIelements()
{
	s32 X = 1920/ 2 - 100;
	s32 Y = 1080 / 2 - 32;
	_selectableButtons.push_back(Environment->addButton(core::rect<s32>(X, 360, X + 100, 360 + 32),
						   this,
						   LOAD_SAVE,
						   L"Continue"));
	//	->setImage(_driver->getTexture("Media/irrlichtlogo2.png"));
	_selectableButtons.push_back(Environment->addButton(core::rect<s32>(X, Y - 100, X + 100, (Y - 100) + 32),
						   this,
						   NEW_GAME,
						   L"New Game"));
//	->setImage(_driver->getTexture("Media/irrlichtlogo2.png"));
	_selectableButtons.push_back(Environment->addButton(core::rect<s32>(X, Y - 60, X + 100, (Y - 60) + 32),
						   this,
						   BACK,
						   L"Return"));
//	 ->setImage(_driver->getTexture("Media/irrlichtlogo2.png"));
	_currentButton = getElementFromId(NEW_GAME);
	moveSelector();
}

void				PlayMenu::initKeyMap()
{

	_mMap[KEY_UP] = &PlayMenu::upKeyPressed;
	_mMap[KEY_DOWN] = &PlayMenu::downKeyPressed;
	_mMap[KEY_RETURN] = &PlayMenu::enterKeyPressed;

	_mMap[KEY_ESCAPE] = static_cast<mPtr>(&PlayMenu::onReturn);
	_mMap[BACK] = static_cast<mPtr>(&PlayMenu::onReturn);
	_mMap[NEW_GAME] = static_cast<mPtr>(&PlayMenu::onNewGame);
	_mMap[LOAD_SAVE] = static_cast<mPtr>(&PlayMenu::onContinue);
}

void				PlayMenu::onNewGame()
{
	Manager::MenuManager::getInstance()->switchMenu(PLAY_SUB_MENU);
}

void				PlayMenu::onContinue()
{
		Manager::MenuManager::getInstance()->switchMenu(PLAY_SUB_MENU);
}

void				PlayMenu::onReturn()
{
	Manager::MenuManager::getInstance()->switchMenu(MAIN_MENU);
}
