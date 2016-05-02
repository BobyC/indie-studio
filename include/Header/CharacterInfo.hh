//
// CharacterInfo.hh for  in /home/foncel_a/rendu/TEK2/CPP/CPP2/cpp_indie_studio/include
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Mon May  2 18:27:00 2016 Anaïs Foncel
// Last update Mon May  2 19:31:33 2016 Anaïs Foncel
//

#ifndef CHARACTERINFO_HH__
# define CHARACTERINFO_HH__

# include "Score.hh"

class		CharacterInfo
{
private:
  std::string	_name;
  Score		_score;
  // Bonus

public:
  CharacterInfo();
  ~CharacterInfo();

  std::string	getName() const;
  Score		getScore() const;
};

#endif /* !CHARACTERINFO_HH__ */
