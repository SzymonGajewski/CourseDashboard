#include "Fstream.hpp"

#include <fstream>
#include <functional>
#include <ios>
#include <memory>

using fstreamPtr = std::unique_ptr<std::fstream, std::function<void(std::fstream*)>>;

namespace
{
    fstreamPtr setUpFile()
    {
        fstreamPtr file(new std::fstream(),
            [](std::fstream* f)
            {
                if(f->is_open())
                {
                    f->close();
                }
            });

        file->exceptions(std::ios_base::badbit);
        return file;
    }
}

Fstream::Fstream(const std::string& filePath)
:IFstream(filePath)
{
}

Fstream::~Fstream()
{
}


void Fstream::tryToWrite(const std::string& content)
{
    auto file = setUpFile();

    try
    {
        file->open(filePath_, 
            std::fstream::out);
        file->write(content.c_str(), content.size());
    }

    catch(std::ios_base::failure& e)
    {
        throw e;
    }
}

std::string Fstream::tryToRead()
{
    std::string strBuff {};
    auto file = setUpFile();

    try
    {
        file->open(filePath_, std::fstream::in);
        while(!file->eof()) {
            strBuff.push_back(file->get());
        }
        strBuff.pop_back();
    }

    catch(std::ios_base::failure& e)
    {
        throw e;
    }

    return strBuff;
}