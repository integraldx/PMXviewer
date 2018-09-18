
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
	
	bool VerifyHeader(FILE *);
	void GetFileInfo(FILE *);

public:
	Model();
	~Model();
	int GetVertexNum();

	static Model* GetModelByName(std::string);
	void PrintModelInfo();
};

