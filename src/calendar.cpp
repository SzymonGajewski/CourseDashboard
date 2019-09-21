#include "calendar.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include "lesson.hpp"
#include "UserHandler.hpp"
void Calendar::addUserToLesson(UserHandler & us)
{
    
}

Calendar::Calendar()
{
    
    MapLesson.insert(std::pair<std::string,std::vector<Lesson>> ("wieczorowa",{}) );
    MapLesson.insert(std::pair<std::string,std::vector<Lesson>> ("weekendowa",{}) );
    
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
     auto it = MapLesson.find(group);
     if(it!=MapLesson.end()) 
     {
         for(auto el : it->second )
         {
             std::cout<<el.get_Subject();
         }
     }
 }