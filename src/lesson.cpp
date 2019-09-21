
#include <vector>
#include "time.hpp"
#include <iostream>
#include "User.hpp"
#include "lesson.hpp"


 Lesson::Lesson(int seconds,
        int minutes,
        int hours,
        int days,
        int months,
        int years,
        std::string sub)
    :Time_(seconds,minutes,hours),
    Data_(days,months,years),
    subject_(sub)  
{};
std::string Lesson::get_Subject()
{
    return subject_;
}
/*
User::User(const std::string &name,
           const std::string &nick,
           Group group,
           const std::string &gitHub,
           const std::string &firecode,
           const std::string &email,
           const std::string &password)
*/



void Lesson::add_students(int sz)                               
{
    for(int i=0;i<sz;i++)
    {
    //    users_.push_back(  User ("Rys", "nick", User::Group::weekend, "github", "firecode"));

    //    users_.push_back(  User ("Krzys", "nick", User::Group::evening, "github", "firecode"));
    }
    for(auto it = users_.begin();it != users_.end(); it++)
    {
        users_ptr_.push_back(&*it);
    }
    for(auto el: users_ptr_)
    {
        std::cout<<(el->getNick());
    }
}
void Lesson::list_of_students()
{
    for(auto el: users_ptr_)
    {
        std::cout<<(el->getNick());
    }
}