/*
** PlayerController.cpp for PlayerController in /home/drozdz_b/Documents/TestIrrlitch3
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Wed May 25 14:49:38 2016 drozdz_b
// Last update Sun May 29 02:49:35 2016 drozdz_b
*/

#include "PlayerController.hpp"

/*
** Construtors & Destructor
*/
PlayerController::PlayerController()
{
  this->_action_player = NONE;
  this->_character = NULL;
  this->_map[MOVE_XN] = KEY_KEY_CODES_COUNT;
  this->_map[MOVE_XP] = KEY_KEY_CODES_COUNT;
  this->_map[MOVE_YN] = KEY_KEY_CODES_COUNT;
  this->_map[MOVE_YP] = KEY_KEY_CODES_COUNT;
  this->_map[MOVE_ZN] = KEY_KEY_CODES_COUNT;
  this->_map[MOVE_ZP] = KEY_KEY_CODES_COUNT;
}

PlayerController::PlayerController(Character* character,
  KeyReceiver* receiver, IrrlichtDevice* device)
{
  this->_action_player = NONE;
  this->_character = character;
  this->_receiver = receiver;
  this->_device = device;
  this->_last = this->_device->getTimer()->getTime();
}

PlayerController::~PlayerController()
{

}

/*
** Getters & Setters
*/
void	PlayerController::setAxisControleX(EKEY_CODE xneg, EKEY_CODE xpos)
{
  this->_map[MOVE_XN] = xneg;
  this->_map[MOVE_XP] = xpos;
}

void	PlayerController::setAxisControleY(EKEY_CODE yneg, EKEY_CODE ypos)
{
  this->_map[MOVE_YN] = yneg;
  this->_map[MOVE_YP] = ypos;
}

void	PlayerController::setAxisControleZ(EKEY_CODE zneg, EKEY_CODE zpos)
{
  this->_map[MOVE_ZN] = zneg;
  this->_map[MOVE_ZP] = zpos;
}

/*
** Actions
*/
void		PlayerController::doAction()
{
  _now = _device->getTimer()->getTime();
  _frameDeltaTime = (f32)(_now - _last) / 1000.f;
  _last = _now;

  if (_receiver->KeyIsDown(_map[MOVE_XN]))
    _character->move(-(5.f * _frameDeltaTime), 0);
  else if (_receiver->KeyIsDown(_map[MOVE_XP]))
    _character->move((5.f * _frameDeltaTime), 0);
  if (_receiver->KeyIsDown(_map[MOVE_YN]))
    _character->move(0, -(5.f * _frameDeltaTime));
  else if (_receiver->KeyIsDown(_map[MOVE_YP]))
    _character->move(0, (5.f * _frameDeltaTime));
  if (_receiver->KeyIsDown(_map[MOVE_ZN]))
    _character->move(0, 0, -(5.f * _frameDeltaTime));
  else if (_receiver->KeyIsDown(_map[MOVE_ZP]))
    _character->move(0, 0, (5.f * _frameDeltaTime));
}
