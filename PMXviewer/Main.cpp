#include <iostream>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Model.h"

using namespace std;
int main() {
	string filename;
	cout << "input PMX file name to open : ";
	cin >> filename;
	Model* model;
	if ((model = Model::GetModelByName(filename)) == NULL) {
		std::cout << "Failed to open file" << std::endl;
		std::getchar();
		std::getchar();
		return 1;
	}

	std::cout << "PMX Successfully opened." << std::endl;
	model->PrintModelInfo();
	std::getchar();
	std::getchar();
	return 0;
}