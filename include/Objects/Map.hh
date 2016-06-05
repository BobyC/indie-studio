//
// Map.hh for indie_studio in /home/monder_s/C++/cpp_indie_studio/include
//
// Made by Sacha Sacha Monderer
// Login   <monder_s@epitech.net>
//
// Started on  Fri Jun  3 16:42:32 2016 Sacha Sacha Monderer
// Last update Sat Jun  4 18:29:03 2016 Sacha Sacha Monderer
//

#ifndef MAP_HH_
# define MAP_HH_

#include "Object.hh"
#include "PlayerController.hpp"

class	Map
{
  std::list<Object*>	_map;
  std::list<ICharacterController*>	_controllers;
  KeyReceiver												*_receiver;

public:
    Map(scene::ISceneManager*, video::IVideoDriver*, IrrlichtDevice*, KeyReceiver*);
  ~Map();

  std::list<Object*> getMap() const;
    void	doAction();
};

#endif /* MAP_HH_ */
