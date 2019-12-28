#pragma once
#include "TriangleInfo.h";
#include "VertexInfo.h";
#include <math.h>;

static class Geometry
{
public:

	static VertexInfo *GetNormalizedCenter(VertexInfo A, VertexInfo B, float Distance, float o[3]);
	static float GetCos(VertexInfo a, VertexInfo b);
	static float GetDistance(VertexInfo a, VertexInfo b);
};

