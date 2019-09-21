#pragma once
#include <string>
#include "nlohmann/json.hpp"

class User
{
public:
    enum class Group
    {
        weekend=1,
        evening=2
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
    int getNumberGroup();
    void setName(std::string_view name);
    void setNick(std::string_view nick);
    void setGroup(Group group);
    void setGitHub(std::string_view gitHub);
    void setFirecode(std::string_view firecode);
    std::string getNick() const;
    std::string getEmail() const;
    std::string getPassword() const;

    friend bool operator==(const User &lhs, const User& rhs);
    Group group_;
private:
    std::string name_;
    std::string nick_;
    
    std::string gitHub_;
    std::string firecode_;
    std::string email_;
    std::string password_;

};

using Users = std::vector<User>;
