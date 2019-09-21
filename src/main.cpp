#include <iostream>
#include "CourseDashboard.hpp"
#include "User.hpp"


int main()
{
    CourseDashboard cdb;
    cdb.createUser(6);
    cdb.showUser();
    std::cout << "Course Dashboard" << std::endl;

    cdb.saveToFile("userDatabase.txt");
    cdb.loadFromFile("userDatabase.txt");

    return 0;
}
