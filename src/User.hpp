#pragma once
#include <string>
#include <map>
#include "nlohmann/json.hpp"

class User
{
public:
    enum class Group
    {
        weekend,
        evening
    };

    User(const std::string & name,
         const std::string & nick,
         Group group,
         const std::string & gitHub,
         const std::string & firecode,
         const std::string &email = "",
         const std::string &password = "");

    User(nlohmann::json userJson);
   
    std::string toString() const;
    nlohmann::json toJson() const;

    void setName(std::string_view name);
    void setNick(std::string_view nick);
    void setGroup(Group group);
    void setGitHub(std::string_view gitHub);
    void setFirecode(std::string_view firecode);
    std::string getNick() const;
    std::string getEmail() const;
    std::string getPassword() const;

    friend bool operator==(const User &lhs, const User& rhs);

    void updateUserScore(std::string key, int poits);
    void createScoreTable(std::vector<std::string> scoreKeys);

    std::string scoreTableToString() const;

    int getTotalPoints() const;

private:
    std::string name_;
    std::string nick_;
    Group group_;
    std::string gitHub_;
    std::string firecode_;
    std::string email_;
    std::string password_;

    std::map<std::string, int> scoreTable_;
    int totalPoints_;

    void updateTotalPoints();
};

using Users = std::vector<User>;
