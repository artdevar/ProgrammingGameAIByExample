 extern "C"
{
  #include <lua.h>
  #include <lualib.h>
  #include <lauxlib.h>
}

#include <iostream>

int main()
{
  //create a lua state
  lua_State* pL = lua_open();

  //open the libraries
  luaL_openlibs(pL);
  
  if (int error = luaL_dofile(pL, "your_first_lua_script.lua") != 0)
  {
    std::cout << "\n[C++]: ERROR(" << error << "): Problem with lua script file!\n\n" << std::endl;

    return 0;
  }

  //tidy up
  lua_close(pL);

  return 0;
}