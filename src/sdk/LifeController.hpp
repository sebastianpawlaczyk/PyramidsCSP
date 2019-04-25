// Created by seba on 10.04.19.

#ifndef SRC_SDK_LIFECONTROLLER_HPP
#define SRC_SDK_LIFECONTROLLER_HPP

#include <vector>

namespace pyramid
{
namespace sdk
{

class LifeController
{
public:
	LifeController();

	void setUpEnvAndStart(int sideOfSquare);

public:
	std::vector<int> generateWatchers(int sideOfSquare);
};

}  // namespace sdk
}  // namespace pyramid

#endif //SRC_SDK_LIFECONTROLLER_HPP
