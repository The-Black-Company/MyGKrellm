#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>
#include <algorithm>
#include <string_view>
#include <vector>
#include <cassert>
#include <string>
#include <map>
#include <ncurses.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <ctime>


#include "window.hpp"
#include "IMonitorModule.hpp"
#include "ModuleCPU.hpp"
#include "ModuleName.hpp"
#include "ModuleRAM.hpp"
#include "ModuleTime.hpp"
#include "ModuleNet.hpp"
#include "ModuleSys.hpp"
#include "ModuleCore.hpp"


std::string split (std::string str, char begin, char end);
std::string cat (const char *std);
std::string cat (const char *std, const char *search, int size_search);
std::string cat (const char *std, int l);
std::string split (std::string str, char begin, char end, int nb);
