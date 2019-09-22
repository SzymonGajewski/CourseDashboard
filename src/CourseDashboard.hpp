#pragma once
#include "User.hpp"
#include <vector>
#include "UserHandler.hpp"

class CourseDashboard
{

public:
    void loadFromFile(const std::string& pathTofile);
    void saveToFile(const std::string& pathTofile);

    bool login(const std::string& email, const std::string& password);

    void addScoreKeys(const std::vector<std::string> &scoreKeys);
    void updateUserScoreByNick(std::string nick, std::string key, int points);
    void showScoreTableByNick(std::string nick);
    void showRanking() const;


private:
    UserHandler userHandler_;
};
