//
// HUD.cpp for  in /home/foncel_a/rendu/TEK2/CPP/CPP2/cpp_indie_studio/include/Header
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Mon May  2 18:32:39 2016 Anaïs Foncel
// Last update Thu May  5 18:26:36 2016 Anaïs Foncel
//

#include "HUD.hh"

HUD::HUD(video::VideoDriver const *driver, IrrlichtDevice const *device, std::vector<int> const &size)
{
  _driver = driver;
  _device = device;
  _characters = NULL;
  _bonus(_driver);
  _size_winX = size.x;
  _size_winY = size.y;
  _size_HUD_Y = _size_winY / 4;
  _size_mHUD_X = _size_winX / 4;
}

HUD::~HUD()
{

}

/*
** DISPLAY SCORE
*/
void		HUD::displayScore(CharacterInfo const character) const
{
  gui::IGUIFont	*font;
  int		score;
  int		posX;
  int		posY;

  score = character.getScore();

  posX = (character.getId() - 1) * _size_mHUD_X;
  posY = ((_size_HUD_Y / 4) / 3) * 2;

  font = _device->getGUIEnvironment()->getBuiltInFont();
  if (font)
  font->draw(score, core::rect<s32>(posX, posY, 300, 50), video::SColor(255, 255, 255, 255));
}


/*
** DISPLAY NAME
*/
void		HUD::displayName(CharacterInfo const character) const
{
  gui::IGUIFont	*font;
  int		posX;
  int		posY;
  std::string	name;

  name = character.getName();

  posX = (character.getId() - 1) * _size_mHUD_X;
  posY = 0;

  font = _device->getGUIEnvironment()->getBuiltInFont();
  if (font)
  font->draw(name, core::rect<s32>(posX, posY, 300, 50), video::SColor(255, 255, 255, 255));
}


/*
** DISPLAY TYPE OF BONUS
*/
void		HUD::displayBonusBomb(CharacterInfo const character) const
{
  gui::IGUIFont	*font;
  int		posX_Image;
  int		posY_Image;
  int		posX;
  int		posY;
  int		num;

  posX_Image = (character.getId() - 1) * _size_mHUD_X;
  posY_Image = ((_size_HUD_Y / 4) / 3);


  posX = (character.getId() - 1) * _size_mHUD_X;
  posY = ((_size_HUD_Y / 4) / 3) + SIZE_IMAGE;

  num = character.getCountBomb();

  // _bonus.setImage(std::string NAME OF FILE);
  // _bonus.displayImage(posX_Image, posY_Image, SIZE_IMAGE);
  // _bonus._img.clear();

  font = _device->getGUIEnvironment()->getBuiltInFont();
  if (font)
  font->draw(num, core::rect<s32>(posX, posY, 300, 50), video::SColor(255, 255, 255, 255));
}

void		HUD::displayBonusDeflagration(CharacterInfo const character) const
{
  gui::IGUIFont	*font;
  int		posX_Image;
  int		posY_Image;
  int		posX;
  int		posY;
  int		num;

  posX_Image = ((character.getId() - 1) * _size_mHUD_X) + (_size_mHUD_X / 3);
  posY_Image = ((_size_HUD_Y / 4) / 3);

  posX = ((character.getId() - 1) * _size_mHUD_X) + (_size_mHUD_X / 3);
  posY = ((_size_HUD_Y / 4) / 3) + SIZE_IMAGE;

  num = character.getDeflagration();

  // _bonus.setImage(std::string NAME OF FILE);
  // _bonus.displayImage(posX_Image, posY_Image, SIZE_IMAGE);
  // _bonus._img.clear();

  font = _device->getGUIEnvironment()->getBuiltInFont();
  if (font)
  font->draw(num, core::rect<s32>(posX, posY, 300, 50), video::SColor(255, 255, 255, 255));
}

void		HUD::displayBonusThird(CharacterInfo const character) const
{
  int		posX_Image;
  int		posY_Image;

  posX_Image = ((character.getId() - 1) * _size_mHUD_X) + (2 * (_size_mHUD_X / 3));
  posY_Image = ((_size_HUD_Y / 4) / 3);
  // _bonus.setImage(std::string NAME OF FILE);
  // _bonus.displayImage(posX_Image, posY_Image, SIZE_IMAGE);
  // _bonus._img.clear();
}


/*
** DISPLAY BONUS
*/
void		HUD::displayBonus(CharacterInfo const character) const
{
  displayBonusBomb(character);
  displayBonusDeflagration(character);
  if (character.getThirdBonus() == true)
    displayBonusThird(character);
}


/*
** GENERAL DISPLAY
*/
void		HUD::display() const
{
  for (unsigned int i = 0, i < _character.size(), ++i)
    {
      displayName(_character[i]);
      displayBonus(_character[i]);
      displayScore(_character[i]);
    }
}
