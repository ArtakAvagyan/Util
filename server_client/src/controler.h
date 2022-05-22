#ifndef CONTROLER_H
#define CONTROLER_H

#include "user.h"
#include "helper.h"

#include <iostream>
#include <fstream>
#include <unordered_map>

class Control_user
{
public:
    Control_user();
    ~Control_user();
    Control_user(const Control_user&) = delete;
    Control_user(Control_user&&) = delete;
    Control_user& operator=(const Control_user&) = delete;
    Control_user& operator=(Control_user&&) = delete;
public:
    std::string addUser(const User_t&);
    User_t getUset(const size_t);
    std::string loadFile();
private:
    std::fstream m_i_o_file;
    std::unordered_map<size_t,User_t> m_data;
};

#endif // CONROLER_H