
#include <vector>
#include "time.hpp"
#include <iostream>
#include "User.hpp"
#include "UserHandler.hpp"
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

void Lesson::addStudentsToLesson(UserHandler & us, int str)                               
{   
    auto ptr= us.returnPtr();
    for(auto it =ptr->begin();it!=ptr->end();it++)
    {
        if(it->getNumberGroup()==str)  { users_ptr_.push_back(&*it); std::cout<<"Oliwier"; } 
    }
    
}
void Lesson::list_of_students()
{   
    std::cout<<"zada";
    for(auto el: users_ptr_)
    {
        std::cout<<"petla";
        std::cout<<(el->getNick());
    }
}