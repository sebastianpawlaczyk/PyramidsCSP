// Created by seba on 10.04.19.

#ifndef SRC_ALGORITHM_PYRAMIDALGORITHM_HPP
#define SRC_ALGORITHM_PYRAMIDALGORITHM_HPP

#include <string>
#include <vector>
#include <memory>

#include "SquareHelper.hpp"

namespace pyramid
{
namespace algorithm
{

class PyramidAlgorithm
{
public:
	PyramidAlgorithm();

	void computeBacktracking(int index, std::vector<int> square, std::vector<int> watchers, int sideOfSquare);
	void computeForwardChecking(int index, std::vector<int> square, int sideOfSquare, std::vector<int> watchers, std::vector<std::vector<int>> occupiedPlaces);

	static bool found;

private:
	bool isLatinSquareValid(int index, std::vector<int> square, std::vector<int> watchers, int sideOfWholeSquare);
	std::string toString(std::vector<int> square, std::vector<int> watchers, int sideOfWholeSquare);

	std::shared_ptr<SquareHelper> helper_;
};

}  // namespace algorithm
}  // namespace pyramid

#endif //SRC_ALGORITHM_PYRAMIDALGORITHM_HPP
