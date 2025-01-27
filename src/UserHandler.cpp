#include "UserHandler.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>


void UserHandler::showAll() const
{
    for (auto &user : users_)
    {
        std::cout << user.toString();
    }
}

void UserHandler::createUser(const User &user)
{
    users_.emplace_back(user);
}

void UserHandler::deleteUserByNick(std::string nick)
{
    auto it = std::find_if(std::begin(users_), std::end(users_), [nick](const auto &user) {
        return user.getNick() == nick;
    });

    if (it != std::end(users_))
    {
        users_.erase(it);
    }
}

User* UserHandler::retriveUserByNick(std::string nick)
{
    auto it = std::find_if(users_.begin(), users_.end(), [nick](const auto &user) {
        return user.getNick() == nick;
    });
    if (it == users_.end())
        return nullptr;
    return &(*it);
}

void UserHandler::updateUser(User *userIterator,
                             User::Group group,
                             std::string_view name,
                             std::string_view nick,
                             std::string_view github,
                             std::string_view firecode)
{
    userIterator->setGroup(group);
    if (not name.empty())
        userIterator->setName(name);
    if (not nick.empty())
        userIterator->setNick(name);
    if (not github.empty())
        userIterator->setGitHub(name);
    if (not firecode.empty())
        userIterator->setFirecode(name);
}

void UserHandler::clearUserDatabase()
{
    users_.clear();
}

Users& UserHandler::getUserDatabase()
{
    return users_;
}
