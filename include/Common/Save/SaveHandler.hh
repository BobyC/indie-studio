//
// SaveHandler.hh for IndieStudio in /home/pujol_n/rendu/cpp_indie_studio/include
//
// Made by Nicolas Pujol
// Login   <pujol_n@epitech.net>
//
// Started on  Thu May 26 22:00:34 2016 Nicolas Pujol
// Last update Thu May 26 23:12:11 2016 Nicolas Pujol
//

#pragma once

# include "Save.hh"
# include "json.hpp"
# include <map>
# include <chrono>
# include <ctime>
# include <sstream>
# include <iomanip>
# include <iostream>
# include <fstream>
# include <streambuf>

class					SaveHandler {

public:

  SaveHandler();
  ~SaveHandler();

  static  std::string			getCurrentTime();
  void					          save(Save&);
  Save					          *operator[](const std::string &);
  void					          preload();

private:
  void writeSavefile();
  nlohmann::json saveToJson(Save*);

  std::map<std::string, Save*>		_saves;
};
