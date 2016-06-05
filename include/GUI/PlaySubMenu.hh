//
// PlaySubMenu.hh for Menus in /home/rigola_s/test_repo/test_irrlicht/test_indie/include/Menus
// 
// Made by Rigolat Sébastien
// Login   <rigola_s@epitech.net>
// 
// Started on  Mon May  2 17:46:35 2016 Rigolat Sébastien
// Last update Mon May  2 17:46:35 2016 Rigolat Sébastien
//

#ifndef PLAYSUBMENU_HH_
# define PLAYSUBMENU_HH_

#include "AGUIMenu.hh"
#include <vector>

extern bool onPause;

class PlaySubMenu : public AGUIMenu
{
	public:
		explicit PlaySubMenu(SAppContext const &context);
		~PlaySubMenu();

	private:
		size_t							_nbPlayer;
		gui::IGUIStaticText	*_nbTxt;
		std::vector<gui::IGUIEditBox *> _names;

		void							onStart();
		void							onReturn();
		void							incPlayerNb();
		void							decPlayerNb();
		virtual void				initGUIelements();
		virtual void				initKeyMap();
};

#endif // !PLAYSUBMENU_HH_
