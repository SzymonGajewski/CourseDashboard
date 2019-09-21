#pragma once
#include "time.hpp"
#include <string>
#include <vector>
#include <memory>
#include "User.hpp"


class Lesson
{
public:
    Lesson() = default;
    Lesson(int,int,int,int,int,int,std::string);
    void add_students(int);
    void list_of_students();
    std::string get_Subject();
private:
    std::string subject_;
    std::vector<User>users_;
    std::vector<User *> users_ptr_;
    times Time_;
    date Data_;
};