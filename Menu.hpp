/*********************************************************************
** Program name: Menu.hpp
** Author: Sarah Flower
** Date: October 16, 2018
** Description: This is the header file for the Menu class (Menu.cpp).
** It contains data members and functions for the Menu class.
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cstddef>
#include <algorithm>
#include <climits>

class Menu
{
private:
    std::string input;
    std::vector<std::string> menuVector;

public:
    Menu();
    void displayMenu();
    void addOption(std::string);
    int getChoice();
    void run();
};

#endif
