#include "VertexInfo.h"


VertexInfo::VertexInfo() 
{

}

VertexInfo::VertexInfo(float xPos, float yPos, float zPos)
{
	this->xPos = xPos;
	this->yPos = yPos;
	this->zPos = zPos;
}


VertexInfo::~VertexInfo()
{
}

float VertexInfo::GetXPosition() 
{
	return this->xPos;
}
float VertexInfo::GetYPosition()
{
	return this->yPos;
}
float VertexInfo::GetZPosition()
{
	return this->zPos;
}
