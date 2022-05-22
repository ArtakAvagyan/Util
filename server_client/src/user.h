#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

class User_t
{
    public:
        User_t() = default;
        User_t(const std::string&, const std::string&, size_t, size_t);
    public:
        void set_name(const std::string&);
        std::string get_name() const;
        void set_surname(const std::string&);
        std::string get_surname() const;
        bool set_age(const size_t);
        size_t get_age() const;
        void set_id(const size_t);
        size_t get_id() const;
        std::string to_string()const;
    private:
        std::string m_name;
        std::string m_surname;
        size_t m_age;
        size_t m_id;
};

std::ostream& operator<< (std::ostream&,const User_t&);
std::istream& operator>> (std::istream&,User_t&);

#endif //USER_H

