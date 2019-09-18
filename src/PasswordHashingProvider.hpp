#pragma once
#include <string>

class PasswordHashingProvider {
public:
    PasswordHashingProvider();
    PasswordHashingProvider(unsigned pwdSaltLength, unsigned pwdHashLength);
    PasswordHashingProvider(const PasswordHashingProvider&) = default;
    PasswordHashingProvider(PasswordHashingProvider&&) noexcept = delete;
    PasswordHashingProvider& operator= (const PasswordHashingProvider&) = default;
    PasswordHashingProvider& operator= (PasswordHashingProvider&&) noexcept = delete;
    ~PasswordHashingProvider();
        
    void printSaltAndHashLength() const;
    std::string generateSalt() const;
    std::string generateHash(const std::string& passwordSalt, const std::string& passwordPhrase) const;

private:
    void checkAndCorrectInitialValues(const unsigned& saltLength, const unsigned& hashLength);
    std::string convertToString(const uint8_t* input, const unsigned& length) const;

    unsigned passwordSaltLength;
    unsigned passwordHashLength;  
    static const unsigned minSaltLength = 8;
    static const unsigned maxSaltLength = 32;
    static const unsigned minHashLength = 8;
    static const unsigned maxHashLength = 64;
    static const int iterations = 1;
    static const int memoryCost = (1<<16);
    static const int threads = 1;
};