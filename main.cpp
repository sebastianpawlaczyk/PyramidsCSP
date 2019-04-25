#include <iostream>

#include "src/sdk/LifeController.hpp"

int main()
{

	pyramid::sdk::LifeController lifeController;
	lifeController.setUpEnvAndStart(3);

	return 0;
}