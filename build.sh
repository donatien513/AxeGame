#!/bin/bash
g++ main.cpp -o axe_game -I./raylib/include -L./raylib/lib -lraylib -Wl,-R./raylib/lib
