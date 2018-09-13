
#pragma once
#include <string>
#include <fstream>
#include <iostream>

#include <glm/glm.hpp>
#include <Bits.h>
class Model
{
private:
	enum TextEncoding{UTF16, UTF8};
	static bool VerifyHeader(FILE *);
	byte dataCount;
	TextEncoding encoding;
	int additionalUVcount;

public:
	Model();
	~Model();
	int GetVertexNum();

	static Model* GetModelByName(std::string);
	
};

