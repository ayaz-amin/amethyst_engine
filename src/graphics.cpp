#include "graphics.hpp"

int PrintText(lua_State* L)
{
    std::string text = lua_tostring(L, 1);
    int posX = (int)lua_tonumber(L, 2);
    int posY = (int)lua_tonumber(L, 3);
    int fontSize = (int)lua_tonumber(L, 4);
    DrawText(text.c_str(), posX, posY, fontSize, GRAY);
    return 0;
}