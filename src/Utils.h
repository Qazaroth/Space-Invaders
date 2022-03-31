#pragma once

#include <iostream>

inline int static getRandomNumber(int min, int max)
{
	return min + (std::rand() % (max - min + 1));
}