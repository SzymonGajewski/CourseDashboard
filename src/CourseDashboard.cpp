#include "CourseDashboard.hpp"
#include "FileHandler.hpp"
#include "Utility.hpp"
#include "AuthenticationProvider.hpp"
#include <iostream>


void CourseDashboard::loadFromFile(const std::string& pathTofile)
{
    FileHandler fileHandler(pathTofile);
    auto userFromFile = fileHandler.read();
    userHandler_.getUserDatabase()  = convertToArray(userFromFile);
    userHandler_.createUsersScoreTables();
}

void CourseDashboard::saveToFile(const std::string& pathTofile)
{
    FileHandler fileHandler(pathTofile);
    auto userVectorInJsonFormat = convertToJson(userHandler_.getUserDatabase());
    fileHandler.write(userVectorInJsonFormat.dump());
}

bool CourseDashboard::login(const std::string& email, const std::string& password)
{
    auto byEmail = [&email](auto user) {
        return !user.getEmail().compare(email);
    };
    auto users = userHandler_.getUserDatabase();
    auto user = std::find_if(users.begin(), users.end(), byEmail);

    AuthenticationProvider authenticationProvider;

    return authenticationProvider(*user, email, password);
}

void CourseDashboard::addScoreKeys(const std::vector<std::string> &scoreKeys)
{
    for(auto &k : scoreKeys)
    {
        userHandler_.addScoreKey(k);
    }
}

void CourseDashboard::updateUserScoreByNick(std::string nick, std::string key, int points)
{
    if (!userHandler_.updateUserScoreByNick(nick, key, points))
    {
        std::cerr << "Update user: " << nick << " score failed.\n key:"
                  << key <<  " points:" << points << "\n" ;
    }
}
