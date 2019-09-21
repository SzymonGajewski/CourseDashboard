#pragma once
#include "time.hpp"
#include <string>
#include <vector>
#include <memory>
#include "UserHandler.hpp"

class Lesson
{
public:
    Lesson() = default;
    Lesson(int,int,int,int,int,int,std::string);
    void addStudentsToLesson(UserHandler &, int);
    void list_of_students();
    std::string get_Subject();
private:
    std::string subject_;
    std::vector<User>users_;
    std::vector<User *> users_ptr_;
    times Time_;
    date Data_;
};