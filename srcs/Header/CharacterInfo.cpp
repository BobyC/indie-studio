//
// CharacterInfo.cpp for  in /home/foncel_a/rendu/TEK2/CPP/CPP2/cpp_indie_studio/include/Header
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Mon May  2 18:32:50 2016 Anaïs Foncel
// Last update Mon May  2 19:34:06 2016 Anaïs Foncel
//

#include "CharacterInfo.hh"

CharacterInfo::CharacterInfo()
{

}

CharacterInfo::~CharacterInfo()
{

}

std::string	CharacterInfo::getName() const
{
  return (_name);
}

Score		CharacterInfo::getScore() const
{
  return (_score);
}
