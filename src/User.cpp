#include "User.hpp"
#include <iostream>
#include <iomanip>

User::User(const std::string & name,
           const std::string & nick,
           Group group,
           const std::string & gitHub,
           const std::string & firecode)
    : name_(name)
    , nick_(nick)
    , group_(group)
    , gitHub_(gitHub)
    , firecode_(firecode)
{}

User::User(nlohmann::json userJson)
    : name_(userJson["name"].get<std::string>())
    , nick_(userJson["nick"].get<std::string>())
    , group_(userJson["group"].get<Group>())
    , gitHub_(userJson["gitHub"].get<std::string>())
    , firecode_(userJson["firecod"].get<std::string>())
{}

std::string User::toString() const
{
    std::stringstream ss;
    ss << std::left;   
    ss << std::setw(1) << "1." << name_ << "|";
    ss << std::setw(1) << "2." << nick_ << "|";
    ss << std::setw(1) << "3." << (group_ == Group::weekend ? "weekend" : "evening") << "|";
    ss << std::setw(1) << "4." << gitHub_ << "|";
    ss << std::setw(1) << "5." << firecode_ << "|";
    ss << std::endl;
    return ss.str();
}

nlohmann::json User::toJson() const
{
    nlohmann::json uJson = {
        { "name", name_},
        { "nick", nick_},
        { "group", group_},
        { "gitHub", gitHub_},
        { "firecod", firecode_}
    };
    return uJson;
}

void User::setName(std::string_view name)           { name_ = name; }
void User::setNick(std::string_view nick)           { nick_ = nick; }
void User::setGroup(Group group)                    { group_ = group; }
void User::setGitHub(std::string_view gitHub)       { gitHub_ = gitHub; }
void User::setFirecode(std::string_view firecode)   { firecode_ = firecode; }

std::string User::getNick() const                   { return nick_; }
