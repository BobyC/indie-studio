/*
** PlayerController.hpp for PlayerController in /home/drozdz_b/Documents/TestIrrlitch3
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Wed May 25 14:48:26 2016 drozdz_b
// Last update Sat Jun  4 03:05:59 2016 Rigolat Sébastien
*/

#ifndef PLAYERCONTROLLER_HPP_
#define PLAYERCONTROLLER_HPP_

# include <vector>
# include <map>
# include "irrlicht.h"
# include "Character.hpp"
# include "ICharacterController.hpp"
# include "KeyReceiver.hpp"

using namespace irr;

enum e_action_player
{
    MOVE_XN,
    MOVE_XP,
    MOVE_YP,
    MOVE_YN,
    MOVE_ZP,
    MOVE_ZN,
    NONE
};

class PlayerController : public ICharacterController
{
private:
  e_action_player									_action_player;
//  std::vector<>		_vect;
  Character*											_character;
  KeyReceiver*									_receiver;
  IrrlichtDevice*									_device;
	std::map<e_action_player, EKEY_CODE>	_map;
  u32															_now;
  u32															_last;
  f32															_frameDeltaTime;
  f32															_speed;

public:
  PlayerController();
  PlayerController(Character*, KeyReceiver*, IrrlichtDevice*);
  ~PlayerController();

  void	setAxisControleX(EKEY_CODE, EKEY_CODE);
  void	setAxisControleY(EKEY_CODE, EKEY_CODE);
  void	setAxisControleZ(EKEY_CODE, EKEY_CODE);

  virtual void	doAction();
};

#endif
