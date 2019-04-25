// Created by seba on 10.04.19.

#ifndef SRC_ALGORITHM_SQUAREHELPER_HPP
#define SRC_ALGORITHM_SQUAREHELPER_HPP

namespace pyramid
{
namespace algorithm
{

class SquareHelper
{
public:
	int getRow(int index, int sideOfSquare);
	int getColumn(int index, int sideOfSquare);
	int getIndex(int row, int column, int sideOfSquare);
};

}  // namespace algorithm
}  // namespace pyramid

#endif //SRC_ALGORITHM_SQUAREHELPER_HPP
