//
// Map.hh for indie_studio in /home/monder_s/C++/cpp_indie_studio/include
// 
// Made by Sacha Sacha Monderer
// Login   <monder_s@epitech.net>
// 
// Started on  Fri Jun  3 16:42:32 2016 Sacha Sacha Monderer
// Last update Fri Jun  3 18:03:41 2016 Sacha Sacha Monderer
//

#ifndef MAP_HH_
# define MAP_HH_

#include "Object.hh"

class	Map
{
  std::list<Object*>	_map;

public:
  Map(scene::ISceneManager*, video::IVideoDriver*);
  ~Map();

  std::list<Object*> getMap() const;
};

#endif /* MAP_HH_ */
