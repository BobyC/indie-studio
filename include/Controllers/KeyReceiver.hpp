/*
** KeyReceiver.hpp for KeyReceiver in /home/drozdz_b/Documents/TestIrrlitch5
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Sun May 29 00:16:41 2016 drozdz_b
// Last update Sat Jun  4 03:04:52 2016 Rigolat Sébastien
*/

#ifndef KEYRECEIVER_HPP_
#define KEYRECEIVER_HPP_

# include <vector>
# include "irrlicht.h"

using namespace irr;

class KeyReceiver : public IEventReceiver
{
private:
  std::vector<bool>			_keyIsDown;

public:
  KeyReceiver();
  ~KeyReceiver();

  virtual bool	OnEvent(const SEvent& event);
  virtual bool					KeyIsDown(EKEY_CODE keyCode) const;
};

#endif
