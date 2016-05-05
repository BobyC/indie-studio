//
// HUD.hh for  in /home/foncel_a/rendu/TEK2/CPP/CPP2/cpp_indie_studio/include
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Mon May  2 18:28:07 2016 Anaïs Foncel
// Last update Wed May  4 17:49:50 2016 Anaïs Foncel
//

#ifndef HUD_HH__
# define HUD_HH__

# include "CharacterInfo.hh"

# define NB_CHARACTERS	(4)

class		HUD
{
private:
  CharacterInfo[NB_CHARACTERS]	_characters;

public:
  HUD();
  ~HUD();

  void			displayBonusBomb(int i) const;
  void			displayBonusDeflagration(int i) const;
  void			displayBonusThird(int i) const;
  void			displayBonus(int i) const;
  void			display() const;
};

#endif /* !HUD_HH__ */
