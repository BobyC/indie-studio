//
// Map.cpp for indie_studio in /home/monder_s/C++/cpp_indie_studio/srcs
// 
// Made by Sacha Sacha Monderer
// Login   <monder_s@epitech.net>
// 
// Started on  Fri Jun  3 16:46:32 2016 Sacha Sacha Monderer
// Last update Fri Jun  3 18:25:50 2016 Sacha Sacha Monderer
//

#include "Map.hh"
#include "Plan.hpp"
#include "Box.hh"
#include "Character.hpp"

Map::Map(scene::ISceneManager* smgr, video::IVideoDriver *driver)
{
  int           y;
  int           x;
  std::ifstream file("map.txt", std::ios::in);
  char          c;
  std::string	str;
  int		n;

  if (file)
    {
      x = 0;
      y = 0;
      n = 0;
      while (file.get(c))
        {
          if (c != '\n')
            {
              //Object    cube(smgr.addCubeSceneNode());
	      str[x] = c;
	      x++;
	      //cube.setType(c - 48);
              //this->_map.push_back(cube);
            }
        }
      str[x] = '\0';
      x = 0;
      this->_map.push_back(new Plan(smgr, driver));
      while (str[x] != '\0')
	{
	  if (str[x] == '0')
	    {
	      //vide
	    }
	  else if (str[x] == '1' && str[x] == '2')
	    {
	      //mur 1 & mur destruc 2
	      this->_map.push_back(new Box(smgr, driver));
	    }
	  else if (str[x] == '3')
	    {
	      //joueur
	      this->_map.push_back(new Character(smgr, driver));
	    }
	  x++;
	}
      x = 0;
      std::list<Object*>::iterator it = this->_map.begin();
      while (y != 25)
        {
          while (x != 25)
            {
	      if (str[n] != '0')
		{
		  (*it)->setPosition(x, y, 30);
		  (*it)->setType(str[n] - 48);
		  if (str[n] == '2')
		    {
		      (*it)->setDestruct(true);
		    }
		  it++;
		}
              x++;
	      n++;
            }
          x = 0;
          y++;
        }
    }
}

Map::~Map()
{
  ;
}

std::list<Object*>	Map::getMap() const
{
  return (this->_map);
}
