#include <iostream>
#include <lua.hpp>
#include <string>
#include <vector>

bool executeScript(lua_State* L1)
{
    // Call the Lua function script1_logic
    lua_getglobal(L1, "script1_logic");

    if (!lua_isfunction(L1, -1)) {
        // Handle the case where the function is not defined
        std::cerr << "Error: script2_logic is not defined in script2.lua" << std::endl;
        lua_pop(L1, 1); // Pop the value from the stack
        return false;
    }

    if (lua_pcall(L1, 0, 1, 0) != 0) {
        // Handle error
        fprintf(stderr, "Error calling script1_logic: %s\n", lua_tostring(L1, -1));
        lua_pop(L1, 1); // Pop the error message from the stack
        return false;
    }

    // Check the return value
    if (!lua_toboolean(L1, -1)) {
        std::cout << "Terminating cycles due to script1_logic returning false." << std::endl;
        return false;
    }

    // Clear the Lua stacks
    lua_settop(L1, 0);
    return true;
}

void closeLuaStates(lua_State* L1)
{
    lua_close(L1);
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <script1.lua> <script2.lua>" << std::endl;
        return -1;
    }

    bool resume = true;

    std::vector<char*> luaScripts;
    for (int i = 1; i < argc; i++) {
        luaScripts.push_back(argv[i]);
    }

    std::vector<lua_State*> luaStates;
    for (int i = 1; i < argc; i++) {
        lua_State* l = luaL_newstate();
        luaL_openlibs(l);
        luaStates.push_back(l);
    }

    for (int i = 0; i < luaStates.size(); i++) {
        if (luaL_dofile(luaStates[i], luaScripts[i]) != 0) {
            fprintf(stderr, "Error in script 1: %s\n", lua_tostring(luaStates[i], -1));
            lua_pop(luaStates[i], 1);
            lua_close(luaStates[i]);
        }
    }
    while (resume) {
        for (int i = 0; i < luaStates.size(); i++) {
            resume = executeScript(luaStates[i]);
        }
    }

    for (int i = 0; i < luaStates.size(); i++) {
        closeLuaStates(luaStates[i]);
    }

    return 0;
}
