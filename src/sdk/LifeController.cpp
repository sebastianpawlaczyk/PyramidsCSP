// Created by seba on 10.04.19.

#include "LifeController.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "../algorithm/PyramidAlgorithm.hpp"

namespace pyramid
{
namespace sdk
{

LifeController::LifeController()
{
	srand(time(NULL));
}

void LifeController::setUpEnvAndStart(int sideOfSquare)
{
	if (sideOfSquare <= 1)
	{
		std::cout << "OAM_ASSERT" << std::endl;
		return;
	}

	int size = (sideOfSquare) * (sideOfSquare);
	std::vector<int> square(size,0);
	auto watchers = generateWatchers(sideOfSquare);
	algorithm::PyramidAlgorithm algorithm;
	clock_t begin = clock();
	algorithm.computeBacktracking(-1, square, watchers, sideOfSquare);
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << elapsed_secs << std::endl;
}

std::vector<int> LifeController::generateWatchers(int sideOfSquare)
{
	std::vector<int> randomWatchers;
	int range = sideOfSquare;
	if (sideOfSquare % 2 != 0) sideOfSquare--;

	for (int i = 0; i < sideOfSquare; i++)
	{
		int number = std::rand() % range + 1;
		randomWatchers.push_back(number);
	}

	return randomWatchers;
}

}  // namespace sdk
}  // namespace pyramid
