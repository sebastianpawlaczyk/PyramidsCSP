// Created by seba on 10.04.19.

#include "SquareHelper.hpp"

namespace pyramid
{
namespace algorithm
{

int SquareHelper::getRow(int index, int sideOfSquare)
{
	return index / (sideOfSquare); // how many number is in the row
}

int SquareHelper::getColumn(int index, int sideOfSquare)
{
	return index % (sideOfSquare); // how many number is in the row
}

int SquareHelper::getIndex(int row, int column, int sideOfSquare)
{
	return (row) * (sideOfSquare) + column;
}

}  // namespace algorithm
}  // namespace pyramid
