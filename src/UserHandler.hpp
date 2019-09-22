#pragma once
#include "User.hpp"


class UserHandler
{
public:
    void showAll() const;
    void createUser(const User & user);
    void deleteUserByNick(std::string nick);
    User* retriveUserByNick(std::string nick);
    void updateUser(User* userIterator,
                    User::Group group,
                    std::string_view name = "",
                    std::string_view nick = "",
                    std::string_view github = "",
                    std::string_view firecode = "");
    void clearUserDatabase();
    Users& getUserDatabase();
    
    void addScoreKey(std::string key);
    void createUsersScoreTables();
    bool updateUserScoreByNick(std::string nick, std::string key, int points);
    bool showScoreTableByNick(std::string nick);

private:
    std::vector<User> users_;
    std::vector<std::string> scoreKeys_;

    bool isKeyExisting(std::string key);
};