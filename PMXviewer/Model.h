
#pragma once
#include <string>
#include <fstream>
#include <iostream>

#include <glm/glm.hpp>
#include <cstddef>
#include <Bits.h>


class Model
{
private:
	enum Encoding{UTF16, UTF8};
	float fileVersion;
	uint8_t dataCount = 0;
	uint8_t additionalUVcount = 0;
	uint8_t encoding;
	uint8_t dataIndexes[6];
	
	bool VerifyHeader(FILE *);
	void GetFileInfo(FILE *);
	void GetDataIndex(FILE *);

public:
	Model();
	~Model();
	int GetVertexNum();

	static Model* GetModelByName(std::string);
	void PrintModelInfo();
};

