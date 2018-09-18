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
	Model* model = new Model();
	if (!model->VerifyHeader(file)) {
		std::cout << "Wrong PMX file" << std::endl;
		return NULL;
	}
	model->GetFileInfo(file);
	
	return model;
}

bool Model::VerifyHeader(FILE* file) {
	char headerPMX[4];
	fread(headerPMX, 4, 1, file);
	fread(&fileVersion, 1, 4, file);
	if (!std::strcmp(headerPMX, "PMX ")) {
		return false;
	}
	return true;
}

void Model::GetFileInfo(FILE* file) {
	fread(&dataCount, 1, 1, file);
	fread(&encoding, 1, 1, file);
	fread(&additionalUVcount, 1, 1, file);
}

void Model::PrintModelInfo() {
	using namespace std;
	cout << "PMX version " << fileVersion << endl;
	cout << "Datas : " << (int)dataCount << endl;
	cout << "Encoding : " << (encoding == Encoding(UTF8) ? "UTF8" : "UTF16") << endl;
	cout << "Additional UV count : " << (int)additionalUVcount << endl;
}
Model::~Model()
{
}
