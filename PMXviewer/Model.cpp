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
	model->GetModelInfo(file);
	
	fclose(file);
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

void Model::GetDataIndex(FILE * file) {
	for (int i = 0; i < 6; i++) {
		fread(&dataIndexes[i], 1, 1, file);
	}
}

void Model::GetModelInfo(FILE * file) {
	GetLocalName(file);
	GetGlobalName(file);
	GetLocalComment(file);
	GetGlobalComment(file);
}

void Model::GetLocalName(FILE * file) {
	int size;
	fread(&size, 4, 1, file);
	printf("LocalName size : %d\n", size);
	fread(&localCharacterName, 2, size / 2, file);
}

void Model::GetGlobalName(FILE * file) {
	int size;
	fread(&size, 4, 1, file);
	printf("GlobalName size : %d\n", size);

	fread(&globalCharacterName, 2, size / 2, file);
}

void Model::GetLocalComment(FILE * file) {
	int size;
	fread(&size, 4, 1, file);
	printf("LocalComment size : %d\n", size);

	char buffer[2048];
	fread(buffer, 2, size / 2, file);
}

void Model::GetGlobalComment(FILE * file) {
	int size = 0;
	fread(&size, 4, 1, file);
	printf("GlobalComment size : %d\n", size);

	fread(&globalComment, 2, size / 2, file);
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
	cout << endl;
}


Model::~Model()
{
}
