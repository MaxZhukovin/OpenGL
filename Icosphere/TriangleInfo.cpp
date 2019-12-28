#include "TriangleInfo.h"


TriangleInfo::TriangleInfo() 
{

}

TriangleInfo::TriangleInfo(VertexInfo *vertex1, VertexInfo *vertex2, VertexInfo *vertex3) 
{
	this->vertex1 = new VertexInfo(vertex1->GetXPosition(),vertex1->GetYPosition(),vertex1->GetZPosition());
	this->vertex2 = new VertexInfo(vertex2->GetXPosition(), vertex2->GetYPosition(), vertex2->GetZPosition());
	this->vertex3 = new VertexInfo(vertex3->GetXPosition(), vertex3->GetYPosition(), vertex3->GetZPosition());
}


TriangleInfo::~TriangleInfo()
{

}

VertexInfo TriangleInfo::GetVertex1() 
{
	return *vertex1;
}
VertexInfo TriangleInfo::GetVertex2()
{
	return *vertex2;
}
VertexInfo TriangleInfo::GetVertex3()
{
	return *vertex3;
}