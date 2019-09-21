#include "calendar.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include "lesson.hpp"
#include "UserHandler.hpp"
#include <string>
void Calendar::addUserToLesson(UserHandler & us)
{
    std::string str1= "wekeend";
    std::string str2= "evening";
    for(auto& [group, Lesson] : MapLesson)
    {
        if(group==str1)
        {
            for(auto& lesson : Lesson)
            {
                lesson.addStudentsToLesson(us,1);
            }
        }
         if(group==str2)
        {
            for(auto& lesson : Lesson)
            {
                lesson.addStudentsToLesson(us,2);
            }
        }

    }
}
Calendar::Calendar()
{
    
    MapLesson.insert(std::pair<std::string,std::vector<Lesson>> ("evening",{}) );
    MapLesson.insert(std::pair<std::string,std::vector<Lesson>> ("weekend",{}) );
    add_lesson("weekend","Lekcja 2");
    add_lesson("weekend","Lekcja 3");
    add_lesson("evening","Lekcja 3");
    prinftlesson("weekend");
    prinftlesson("evening");
    
}
void Calendar::add_lesson(std::string group, std::string sub)
{   
   // auto search = example.find(2);
    auto it = MapLesson.find(group);
    if(it!=MapLesson.end()) it->second.push_back(Lesson(12,00,00,21,2,2019,sub));
    else std::cout<<"nie ma takiej grupy";

}
 void Calendar::prinftlesson(std::string group)
 {
     std::cout<<"DSADAS";
     auto it = MapLesson.find(group);
     if(it!=MapLesson.end()) 
     {
         for(auto el : it->second )
         {
             std::cout<<el.get_Subject();
             std::cout<<std::endl<<std::endl;
             el.list_of_students();         
            
         }
     }
 }