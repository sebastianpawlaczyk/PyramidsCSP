// Created by seba on 10.04.19.

#include "PyramidAlgorithm.hpp"

#include <algorithm>
#include <sstream>
#include <iostream>

namespace pyramid
{
namespace algorithm
{

bool PyramidAlgorithm::found = false;

PyramidAlgorithm::PyramidAlgorithm()
{
	helper_ = std::make_shared<SquareHelper>();
}

std::string PyramidAlgorithm::toString(std::vector<int> square, std::vector<int> watchers, int sideOfSquare)
{
	std::stringstream stream;
	int index = 0;

	stream << std::endl;
	stream << "--------------------";
	stream << std::endl;
	int counter = 0;
	for (int row = 0; row < sideOfSquare; row++) {
		stream << "\t";
		for (counter; counter < sideOfSquare / 2; counter++) {
			stream << watchers[counter] << " ";
		}
		stream << std::endl;

		if(counter < watchers.size())
		{
			stream << watchers[counter] << " ";
			counter++;
		}

		stream << "\t";
		for (int column = 0; column < sideOfSquare; column++) {
			stream << square[index] << " ";
			index++;
		}

		stream << std::endl;
	}
	stream << "--------------------";
	stream << std::endl;
	return stream.str();
}

bool PyramidAlgorithm::isLatinSquareValid(int index, std::vector<int> square, std::vector<int> watchers, int sideOfSquare)
{
	int nextIndex = 0;
	int rowToCompare;
	int columnToCompere;

	int i = 0;
	for (i = 0; i < watchers.size() / 2; i++)
	{
		int pom = 0;
		for (int j = 0; j < square.size(); j++)
		{
			if (helper_->getColumn(j, sideOfSquare) == i)
			{
				if (watchers[i] - square[j] > 0)
				{
					pom++;
					continue;
				}
				pom++;
				break;
			}
		}
		if (pom < watchers[i])
		{
			return false;
		}
	}

	int row = 0;
	for (i; i < watchers.size(); i++)
	{
		int pom = 0;
		for (int j = 0; j < square.size(); j++)
		{
			if (helper_->getRow(j, sideOfSquare) == row)
			{
				if (watchers[i] - square[j] > 0)
				{
					pom++;
					continue;
				}
				pom++;
				break;
			}
		}
		if (pom < watchers[i])
		{
			return false;
		}
		row++;
	}

	for (const auto& i : square)
	{
		rowToCompare = helper_->getRow(nextIndex, sideOfSquare);
		columnToCompere = helper_->getColumn(nextIndex, sideOfSquare);

		if (helper_->getRow(index, sideOfSquare) == rowToCompare ||
			helper_->getColumn(index, sideOfSquare) == helper_->getColumn(nextIndex, sideOfSquare))
		{
			if (square[index] == square[helper_->getIndex(rowToCompare, columnToCompere, sideOfSquare)] && index != nextIndex)
			{
				return false;
			}
		}
		nextIndex++;
	}
	return true;

}

void PyramidAlgorithm::computeBacktracking(int index, std::vector<int> square, std::vector<int> watchers,
										   int sideOfSquare)
{
	if(found)return;
	if (index < 0 || isLatinSquareValid(index, square, watchers, sideOfSquare))
	{
		if (index == square.size() - 1)
		{
			std::cout << toString(square, watchers, sideOfSquare);
			found = true;
		}

		else
		{
			for (int i = 1; i <= sideOfSquare; i++)
			{
				square[index + 1] = i;
				computeBacktracking(index + 1, square, watchers, sideOfSquare);
			}
		}
	}
}

void PyramidAlgorithm::computeForwardChecking(int index, std::vector<int> square, int sideOfSquare, std::vector<int> watchers, std::vector<std::vector<int>> occupiedPlaces)
{
	//if(found){return;}
	if (index < 0 || isLatinSquareValid(index, square, watchers, sideOfSquare))
	{
		if (index == square.size() - 1)
		{
			std::cout << toString(square, watchers, sideOfSquare);
			//found = true;
		}

		else
		{
			for (int i = 1; i <= sideOfSquare; i++)
			{
				for (int j = 0; j < occupiedPlaces.size(); j++)
				{
					auto& vec = occupiedPlaces[j];
					if (helper_->getRow(index + 1, sideOfSquare) == helper_->getRow(j, sideOfSquare) ||
						helper_->getColumn(index + 1, sideOfSquare) == helper_->getColumn(j, sideOfSquare))
					{
						vec.push_back(square[index + 1]);
					}
				}

				auto vec = occupiedPlaces[index + 1];
				if (std::find(vec.begin(), vec.end(), i) == vec.end())
				{
					continue;
				}

				for (int j = 0; j < occupiedPlaces.size(); j++)
				{
					auto& vec = occupiedPlaces[j];
					if (helper_->getRow(index + 1, sideOfSquare) == helper_->getRow(j, sideOfSquare) ||
						helper_->getColumn(index + 1, sideOfSquare) == helper_->getColumn(j, sideOfSquare))
					{
						vec.erase(std::remove(vec.begin(), vec.end(), i), vec.end());
					}
				}

				square[index + 1] = i;
				computeForwardChecking(index + 1, square, sideOfSquare, watchers, occupiedPlaces);
			}
		}
	}
}

}  // namespace algorithm
}  // namespace pyramid
