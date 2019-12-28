#pragma once
#include <list>;
#include"TriangleInfo.h";
#include"VertexInfo.h";
#include <string>;

using namespace std;
class Figure
{
public:

	Figure();
	~Figure();

	list<TriangleInfo> GetTriangles();
	string GetName();
	int GetTrianglesCount();
	int GetVertexCount();
	VertexInfo GetCenter();

	virtual void ChangeScale(float NewValue) = 0;
	virtual void AugmentScale(float Value) = 0;
	virtual void DecreaseScale(float Value) = 0;

protected:

	VertexInfo Center;
	std::string Name;
	list<TriangleInfo> Triangles;
};

