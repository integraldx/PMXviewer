#include "Model.h"



Model::Model()
{
}

Model* Model::GetModelByName(std::string fileName) 
{
	std::cout << "Loading " << fileName << "..." << std::endl;
	FILE* file = fopen(fileName.c_str(), "r");
	if (file == NULL) {
		std::cout << "Failed to open file" << std::endl;
		return NULL;
	}
	if (!VerifyHeader(file)) {
		std::cout << "Wrong PMX file" << std::endl;
		return NULL;
	}
	return new Model();
}

bool Model::VerifyHeader(FILE* file) {
	char headerPMX[4];
	float headerVersion;
	fread(headerPMX, 4, 1, file);
	fread(&headerVersion, 1, 4, file);
	if (!std::strcmp(headerPMX, "PMX ")) {
		return false;
	}
	std::cout << "PMX version " << headerVersion << std::endl;
	return true;
}
Model::~Model()
{
}
