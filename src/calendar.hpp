#pragma once
#include<vector>
#include "lesson.hpp"
#include <string>
#include<map>
#include "UserHandler.hpp"
class Calendar
{
private:
    std::map<std::string,std::vector<Lesson> > MapLesson ;
  //  std::vector<Lesson> wieczorowa_;
  //  std::vector<Lesson> weekendowa_;
  //  std::vector<std::string> groups_ = {"wieczorowa","weekendowa" };

public:
    Calendar();
    void add_lesson(std::string,std::string);
    void addUserToLesson(UserHandler &);
    void prinftlesson(std::string);
    void printf_lesson_for_student();
    
};