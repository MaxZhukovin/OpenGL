#pragma once


class VertexInfo
{
public:
	VertexInfo();
	VertexInfo(float xPos,float yPos,float zPos);
	~VertexInfo();
	float GetXPosition();
	float GetYPosition();
	float GetZPosition();

private:
	float xPos;
	float yPos;
	float zPos;

};

