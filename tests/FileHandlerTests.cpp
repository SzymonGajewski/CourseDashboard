#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include "FileHandler.hpp"


using namespace testing;

namespace
{
std::string testFilePath = "iotest.txt";
std::string dummyStr = "dummy";

std::string actual(const std::string& filePath)
{
	std::fstream fileStream(filePath);
	std::string strBuff(
		(std::istreambuf_iterator<char>(fileStream)), 
		std::istreambuf_iterator<char>());
	fileStream.close();
	return strBuff;
}

} // namespace

TEST(FileHandlerTests, shouldWriteToFile)
{
	FileHandler sut(testFilePath);
	sut.write(dummyStr);
	EXPECT_EQ(actual(testFilePath), dummyStr);
}

TEST(FileHandlerTests, shouldReadFromFile)
{
	FileHandler sut(testFilePath);
	sut.write(dummyStr);
	EXPECT_EQ(sut.read(), dummyStr);
}
