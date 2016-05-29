/*
** ICharacterController.hpp for ICharacterController in /home/drozdz_b/Documents/TestIrrlitch5
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Sun May 29 00:13:58 2016 drozdz_b
** Last update Sun May 29 02:41:29 2016 drozdz_b
*/

#ifndef ICHARACTERCONTROLLER_HPP_
#define ICHARACTERCONTROLLER_HPP_

#include <irr/irrlicht.h>

class ICharacterController
{
public:
  virtual ~ICharacterController(){}
  virtual void doAction() = 0;
};

#endif
