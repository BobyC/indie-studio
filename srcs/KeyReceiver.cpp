/*
** KeyReceiver.cpp for KeyReceiver in /home/drozdz_b/Documents/TestIrrlitch5
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Sun May 29 01:02:54 2016 drozdz_b
// Last update Fri Jun  3 19:28:58 2016 Nicolas Pujol
*/

#include "../include/KeyReceiver.hpp"

KeyReceiver::KeyReceiver()
{
  u32		i;

  i = 0;
  while (i < KEY_KEY_CODES_COUNT)
  {
    this->_keyIsDown.push_back(false);
    ++i;
  }
}

KeyReceiver::~KeyReceiver()
{
}

bool 			KeyReceiver::OnEvent(const SEvent& event)
{
  if (event.EventType == irr::EET_KEY_INPUT_EVENT)
    this->_keyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
  return (false);
}

bool			KeyReceiver::KeyIsDown(EKEY_CODE keyCode) const
{
    return (this->_keyIsDown[keyCode]);
}
