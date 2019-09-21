#pragma once
#include "User.hpp"
#include "UserHandler.hpp"

class UserHandler
{
public:
    void addUserToLesson(UserHandler & );
    void showAll() const;
    void createUser(const User & user);
    void deleteUserByNick(std::string nick);
    std::vector<User >* returnPtr();
    User* retriveUserByNick(std::string nick);
    void updateUser(User* userIterator,
                    User::Group group,
                    std::string_view name = "",
                    std::string_view nick = "",
                    std::string_view github = "",
                    std::string_view firecode = "");
    void clearUserDatabase();
    Users& getUserDatabase();  

private:
    std::vector<User> users_;
};