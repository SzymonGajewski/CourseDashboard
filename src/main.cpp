#include <iostream>
#include "CourseDashboard.hpp"
#include "User.hpp"


int main()
{
    CourseDashboard cdb;
    std::cout << "Course Dashboard" << std::endl;

    std::vector<std::string> scoreKeys = 
    {"Lesson 1", "Lesson 2", "Lesson 3", "Other"};

    cdb.addScoreKeys(scoreKeys);

    //cdb.saveToFile("userDatabase.txt");
    cdb.loadFromFile("../userDatabase.json");

    std::vector<std::string> scoreKeys2 = 
    {"Lesson 1", "Lesson 3", "Extra"};

    cdb.addScoreKeys(scoreKeys2);

    cdb.updateUserScoreByNick("Laura","Lesson 1", 20);
    cdb.updateUserScoreByNick("Beth","Lesson 3", 500);
    cdb.updateUserScoreByNick("Laura","Lesson 1", 40);

    cdb.updateUserScoreByNick("test","Lesson 1", 20);
    cdb.updateUserScoreByNick("Beth","test", 500);

    return 0;
}
