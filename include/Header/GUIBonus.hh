//
// GUIBonus.hh for  in /home/foncel_a/rendu/TEK2/CPP/CPP2/cpp_indie_studio/include/Header
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Mon May  2 18:38:27 2016 Anaïs Foncel
// Last update Thu May  5 16:22:00 2016 Anaïs Foncel
//

#ifndef GUIBONUS_HH__
# define GUIBONUS_HH__

class		GUIBonus
{
private:
  video::ITexture	*_img;
  video::IVideoDriver	*_driver;
  float			_posX;
  float			_posY;

public:
  GUIBonus(video::IVideoDriver *driver);
  ~GUIBonus();

  void			setImage(std::string const &name_image_file);
  video::ITexture	*getImage() const;
  void			displayImage(float const &posX, float const &posY);
};

#endif /* !GUIBONUS_HH__ */
