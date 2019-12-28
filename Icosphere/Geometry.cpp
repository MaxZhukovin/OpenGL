#include "Geometry.h"


VertexInfo *Geometry::GetNormalizedCenter(VertexInfo A, VertexInfo B, float Distance,float o[3])
{
	float ix = (A.GetXPosition() + B.GetXPosition()) / 2;
	float iy = (A.GetYPosition() + B.GetYPosition()) / 2;
	float iz = (A.GetZPosition() + B.GetZPosition()) / 2;

	VertexInfo I(ix,iy,iz);
	VertexInfo O(o[0], o[1], o[2]);

	float ox = ix - o[0];
	float oy = iy - o[1];
	float oz = iz - o[2];

	float distance = Geometry::GetDistance(O, I);
	//float distance = sqrt(ox * ox+ oy * oy + oz *oz);

	float x = (ox * Distance / distance) + o[0];
	float y = (oy * Distance / distance) + o[1];
	float z = (oz * Distance / distance) + o[2];

	VertexInfo *C = new VertexInfo(x, y, z);
	return C;
}

float Geometry::GetCos(VertexInfo a, VertexInfo b)
{
	float ab = a.GetXPosition() * b.GetXPosition() + a.GetYPosition() * b.GetYPosition() + a.GetZPosition() * b.GetZPosition();
	float adistance = sqrt(pow(a.GetXPosition(),2) + pow(a.GetYPosition(),2) + pow(a.GetZPosition(),2));
	float bdistance = sqrt(pow(b.GetXPosition(), 2) + pow(b.GetYPosition(), 2) + pow(b.GetZPosition(), 2));
	float k = ab / (adistance*bdistance);

	return k;
}
float Geometry::GetDistance(VertexInfo a, VertexInfo b) 
{
	float abX = b.GetXPosition() - a.GetYPosition();
	float abY = b.GetYPosition() - a.GetYPosition();
	float abZ = b.GetZPosition() - a.GetZPosition();

	return sqrt(abX * abX + abY * abY + abZ * abZ);
}