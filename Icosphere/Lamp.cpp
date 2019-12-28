#include "Lamp.h"



Lamp::Lamp(float Itensity,VertexInfo *Position)
{
	this->LightItensity = Itensity;
	this->Position = new VertexInfo(Position->GetXPosition(),Position->GetYPosition(),Position->GetZPosition());
}


Lamp::~Lamp()
{
}

float Lamp::GetLightCoefitient(TriangleInfo triangle,VertexInfo FigureCenter) 
{
	VertexInfo A1 = triangle.GetVertex1();
	VertexInfo *B1 = new VertexInfo((A1.GetXPosition() - FigureCenter.GetXPosition()) + A1.GetXPosition(), (A1.GetYPosition() - FigureCenter.GetYPosition()) + A1.GetYPosition(), (A1.GetZPosition() - FigureCenter.GetZPosition()) + A1.GetZPosition());
	VertexInfo *vector1 = new VertexInfo( B1->GetXPosition() - A1.GetXPosition(),B1->GetYPosition() - A1.GetYPosition(),B1->GetZPosition() - A1.GetZPosition());

	VertexInfo A2 = triangle.GetVertex2();
	VertexInfo *B2 = new VertexInfo((A2.GetXPosition() - FigureCenter.GetXPosition()) + A2.GetXPosition(), (A2.GetYPosition() - FigureCenter.GetYPosition()) + A2.GetYPosition(), (A2.GetZPosition() - FigureCenter.GetZPosition()) + A2.GetZPosition());
	VertexInfo *vector2 = new VertexInfo(B2->GetXPosition() - A2.GetXPosition(), B2->GetYPosition() - A2.GetYPosition(), B2->GetZPosition() - A2.GetZPosition());


	VertexInfo A3 = triangle.GetVertex3();
	VertexInfo *B3 = new VertexInfo((A3.GetXPosition() - FigureCenter.GetXPosition()) + A3.GetXPosition(), (A3.GetYPosition() - FigureCenter.GetYPosition()) + A3.GetYPosition(), (A3.GetZPosition() - FigureCenter.GetZPosition()) + A3.GetZPosition());
	VertexInfo *vector3 = new VertexInfo(B3->GetXPosition() - A3.GetXPosition(), B3->GetYPosition() - A3.GetYPosition(), B3->GetZPosition() - A3.GetZPosition());
	
	VertexInfo *LightVector1 = new VertexInfo(Position->GetXPosition() - A1.GetXPosition(),Position->GetYPosition() - A1.GetYPosition(),Position->GetZPosition() - A1.GetZPosition());
	VertexInfo *LightVector2 = new VertexInfo(Position->GetXPosition() - A2.GetXPosition(), Position->GetYPosition() - A2.GetYPosition(), Position->GetZPosition() - A2.GetZPosition());
	VertexInfo *LightVector3 = new VertexInfo(Position->GetXPosition() - A3.GetXPosition(), Position->GetYPosition() - A3.GetYPosition(), Position->GetZPosition() - A3.GetZPosition());

	float cos1 = Geometry::GetCos(*vector1,*LightVector1);
	float cos2 = Geometry::GetCos(*vector2, *LightVector2);
	float cos3 = Geometry::GetCos(*vector3, *LightVector3);

	float k = ((cos1 + cos2 + cos3) / 3) * LightItensity;

	//if (Focus != 0 && k >= 0) {
	//	float diff = k / (Focus * 2);
	//	k = k * diff;
	//}

	//if (Focus != 0 && k >= 0)
	//{
	//	float d = k / Focus;
	//	if (k > Focus) 
	//	{		
	//		float diff = k - Focus;
	//		k += diff;
	//	}
	//	else 
	//	{
	//		float diff = Focus - k;
	//		k -= diff;
	//	}
	//}

	return k;
}

float Lamp::GetLightItensity() 
{
	return LightItensity;
}

void Lamp::SetColor(float R,float G,float B) 
{
	
	VertexInfo *c = new VertexInfo(R, G, B);
	Color = *c;

}

void Lamp::SetLightItensity(float Itensity) {
	
	this->LightItensity = Itensity;
}

VertexInfo Lamp:: GetPosition() {
	return *Position;
}

VertexInfo Lamp::GetColor() {
	return Color;
}
//VertexInfo Lamp::GetColoredCoefitient(TriangleInfo triangle, VertexInfo FigureCenter) 
//{
//	float k = GetLightCoefitient(triangle, FigureCenter);
//	float R = k * Color.GetXPosition();
//	float G = k * Color.GetYPosition();
//	float B = k * Color.GetZPosition();
//
//	VertexInfo *coloredCoef = new VertexInfo(R, G, B);
//	return *coloredCoef;
//}
