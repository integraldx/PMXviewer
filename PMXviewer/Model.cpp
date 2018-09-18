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
	model->GetDataIndex(file);
	
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
	cout << "PMX version "				<< fileVersion << endl;
	cout << "Datas \t: "				<< (int)dataCount << endl;
	cout << "Encoding \t: "				<< (encoding == Encoding(UTF8) ? "UTF8" : "UTF16") << endl;
	cout << "Additional UV count \t: "	<< (int)additionalUVcount << endl;
	cout << endl;
	cout << "Vertex Index Size \t: "	<< (int)dataIndexes[0] << endl;
	cout << "Texture Index Size \t: "	<< (int)dataIndexes[1] << endl;
	cout << "Material Index Size \t: "	<< (int)dataIndexes[2] << endl;
	cout << "Bone Index Size \t: "		<< (int)dataIndexes[3] << endl;
	cout << "Morph Index Size \t: "		<< (int)dataIndexes[4] << endl;
	cout << "Rigid Index Size \t: "		<< (int)dataIndexes[5] << endl;
}

void Model::GetDataIndex(FILE * file) {
	for (int i = 0; i < 6; i++) {
		fread(&dataIndexes[i], 1, 1, file);
	}
}
Model::~Model()
{
}
