#include "user.h"

#include <iostream>
#include <string>

User_t::User_t(const std::string& name, const std::string& surname , size_t age , size_t id):
                        m_name{name},m_surname{surname},m_id{id}
{
    this->set_age(age);
}

void User_t::set_name(const std::string& name)
{
    m_name = name;
}

std::string User_t::get_name() const
{
    return m_name;
}

void User_t::set_surname(const std::string& surname)
{
    m_surname = surname;
}

std::string User_t::get_surname() const
{
    return m_surname;
}

bool User_t::set_age(const size_t age)
{
   if(age < 0 || age > 100)
   {    
       return false;
   }
   m_age = age;
   return true;
}

size_t User_t::get_age() const
{
   return m_age;
}

void User_t::set_id(const size_t id)
{
   m_id = id;
}

size_t User_t::get_id() const
{
   return m_id;
}

std::string User_t::to_string()const
{
    std::string str;
    str.reserve(m_name.size()+m_surname.size() + 8);
    str += m_name + " " + m_surname + "  ";
    str += std::to_string(m_age) + "  " + std::to_string(m_id) + "  ";
    return str;
}


std::ostream& operator<<(std::ostream& os,const User_t& us)
{
    os <<us.get_name() << "  " << us.get_surname() << "  "
        << us.get_age() << "  " << us.get_id() << std::endl;
    return os;
}
std::istream& operator>> (std::istream& fs,User_t& us)
{
    std::string tmp{};
    fs>> tmp;
    us.set_name(tmp);
    fs>> tmp ;
    us.set_surname(tmp);
    size_t num;
    fs>> num;
    us.set_age(num);
    fs>>num;
    us.set_id(num);
    return fs;
}
