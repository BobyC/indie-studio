//
// HUD.hh for  in /home/foncel_a/rendu/TEK2/CPP/CPP2/cpp_indie_studio/include
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Mon May  2 18:28:07 2016 Anaïs Foncel
// Last update Mon May  2 18:52:12 2016 Anaïs Foncel
//

#ifndef HUD_HH__
# define HUD_HH__

# include "CharacterInfo.hh"

class		HUD
{
private:
  CharacterInfo[4]	_characters;

public:
  HUD();
  ~HUD();
};

#endif /* !HUD_HH__ */
