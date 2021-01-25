#include <iostream>
#include "lua54/include/lua.hpp"
#include "raylib35/include/raylib.h"

#include "graphics.hpp"


void OnStart(lua_State* L)
{
    lua_getglobal(L, "OnStart");
    lua_pcall(L, 0, 0, 1);
}

void OnUpdate(lua_State* L, float delta_time)
{
    lua_getglobal(L, "OnUpdate");
    lua_pushnumber(L, delta_time);
    lua_pcall(L, 1, 0, 1);
}


int main()
{
    lua_State* L = luaL_newstate();

    lua_register(L, "PrintText", PrintText);

    const int screen_width = 800;
    const int screen_height = 600;
    const std::string title = "Game";

    InitWindow(screen_width, screen_height, title.c_str());
    SetTargetFPS(60);

    luaL_dofile(L, "game_src/_main.lua");

    OnStart(L);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        OnUpdate(L, GetFrameTime());
        EndDrawing();
    }
    
    CloseWindow();
    lua_close(L);

    return 0;
}