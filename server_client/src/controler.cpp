#include "controler.h"

#include <fstream>

Control_user::Control_user()
    :m_i_o_file(COMMANDS::fileName,std::ios_base::in|std::ios_base::out)
{
    User_t tmp;
    while(!m_i_o_file.eof())
    {
        std::string str;
        m_i_o_file >> str;
        if(m_i_o_file.eof() || str == "") {break;}
        tmp.set_name(str);
        m_i_o_file >> str;
        if(m_i_o_file.eof() || str == "") {break;}
        tmp.set_surname(str);
        m_i_o_file >> str;
        if(m_i_o_file.eof() || str == "") {break;}
        std::cout<< str << std::endl;
        tmp.set_age(std::stoul(str));
        m_i_o_file >> str;
        if(m_i_o_file.eof() || str == "") {break;}
        tmp.set_id(std::stoul(str));
        m_data.emplace(tmp.get_id(),tmp);
    }
}

std::string Control_user::addUser(const User_t& us)
{
    if((m_data.find(us.get_id())) != m_data.end())
    {
        return "User already exists";
    }
    m_data.emplace(us.get_id(),us);
    return "OK";
}

User_t Control_user::getUset(const size_t id)
{
    return m_data[id];
}

std::string Control_user::loadFile()
{
    for (const auto & it : m_data)
    {
        m_i_o_file << it.second;
    }
    return "OK";
}


Control_user::~Control_user()
{
    this->loadFile();
}
