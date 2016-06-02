//
// test2.hpp for  in /home/mollon_m/rendu/test-lua
//
// Made by mollon_m
// Login   <mollon_m@epitech.net>
//
// Started on  Fri May  6 16:27:39 2016 mollon_m
// Last update Fri May  6 20:13:40 2016 mollon_m
//

class Lua_State
{
  lua_State *L;
public:
  Lua_State() : L(lua_open()) { }

  ~Lua_State() {
    lua_close(L);
  }

  // implicitly act as a lua_State pointer
  inline operator lua_State*() {
    return L;
  }
};
