//
// Box.hh for indie_studio in /home/monder_s/C++/cpp_indie_studio/include
//
// Made by Sacha Sacha Monderer
// Login   <monder_s@epitech.net>
//
// Started on  Thu Jun  2 15:52:38 2016 Sacha Sacha Monderer
// Last update Thu Jun  2 16:05:01 2016 Sacha Sacha Monderer
//

#ifndef BOX_HH_
# define BOX_HH_

#include "Object.hh"

class Box : public Object
{
public:
  Box(scene::ISceneNode*);
  Box(scene::ISceneNode*, video::IVideoDriver*);
  ~Box();
};

#endif /* BOX_HH_ */
