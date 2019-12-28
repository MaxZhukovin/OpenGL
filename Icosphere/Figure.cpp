#include "Figure.h"

Figure::Figure() {

}
Figure::~Figure() {

}


std::string Figure::GetName()
{
	return Name;
}

int Figure::GetTrianglesCount()
{
	int count = 0;
	for (TriangleInfo t : Triangles)
	{
		count++;
	}
	return count;
}

int Figure::GetVertexCount()
{
	int count = 0;
	for (TriangleInfo t : Triangles)
	{
		count += 3;
	}
	return count;
}

std::list<TriangleInfo> Figure::GetTriangles()
{
	return Triangles;
}

VertexInfo Figure::GetCenter() {
	return Center;
}