#pragma once
#include <exception>

class ShapeException : public std::exception
{
	virtual const char* what() const
	{
		return "This is a shape exception!";
	}
};