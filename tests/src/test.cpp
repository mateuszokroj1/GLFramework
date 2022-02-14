#include <gtest/gtest.h>
#include "GLFramework.h"

TEST(GLFramework_Core, Name_ShouldBeValid)
{
	GLFramework framework;

	std::string actual(framework.Name),
		expected("GLFramework");

	ASSERT_EQ(expected, actual);
}