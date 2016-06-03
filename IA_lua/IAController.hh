//
// IAController.hh for  in /home/mollon_m/rendu/test-lua
//
// Made by Maxime Mollonguet
// Login   <mollon_m@epitech.net>
//
// Started on  Fri Jun 03 18:59:36 2016 Maxime Mollonguet
// Last update Fri Jun  3 22:05:41 2016 Maxime Mollonguet
//

#ifndef IACONTROLLER_HH_
# define IACONTROLLER_HH_

# include <iostream>
# include "ICharacterController.hpp"
# include "LuaScript.hh"

class		IAController : public	ICharacterController
{
private:
  Character*					_character;
  IrrlichtDevice*                               _device;
  u32                                           _now;
  u32                                           _last;
  f32                                           _frameDeltaTime;
  f32                                           _speed;

public:
  IAController();
  ~IAController();
  IAController(Character* character, KeyReceiver* receiver,
	       IrrlichtDevice* device);

public:
  IAController		&operator=(const IAController &) const;
  void			result();
  virtual void		doAction();

};

#endif /* !IACONTROLLER_HH_ */
