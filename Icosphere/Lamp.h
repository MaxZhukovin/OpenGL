#pragma once
#include "VertexInfo.h";
#include "TriangleInfo.h";
#include "Geometry.h";

class Lamp
{
public:
	Lamp(float Itensity,VertexInfo *Position);
	~Lamp();
	float GetLightCoefitient(TriangleInfo triangle,VertexInfo FigureCenter);
	float GetLightItensity();
	void SetLightItensity(float Itensity);
	VertexInfo GetPosition();
	//VertexInfo GetColoredCoefitient(TriangleInfo triangle, VertexInfo FigureCenter);
	void SetColor(float R, float G, float B);
	VertexInfo GetColor();
private:
	VertexInfo Color;
	float LightItensity;
	VertexInfo *Position;
};

