#pragma once
#include "VertexInfo.h"
class TriangleInfo
{
public:

	TriangleInfo();
	TriangleInfo(VertexInfo *vertex1, VertexInfo *vertex2, VertexInfo *vertex3);
	~TriangleInfo();

	VertexInfo GetVertex1();
	VertexInfo GetVertex2();
	VertexInfo GetVertex3();

private:
	VertexInfo *vertex1;
	VertexInfo *vertex2;
	VertexInfo *vertex3;
};

