#pragma once
#include "User.hpp"
#include <vector>
#include "UserHandler.hpp"
#include "calendar.hpp"

class CourseDashboard
{
public:
    
    void loadFromFile(const std::string& pathTofile);
    void saveToFile(const std::string& pathTofile);

    bool login(const std::string& email, const std::string& password);
    void createUser(int );
    void showUser();
    void addUserToLesson();
private:
    UserHandler userHandler_;
    Calendar calendar_;
};
