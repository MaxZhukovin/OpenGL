#include "Octahedron.h"



Octahedron::Octahedron()
{
}


Octahedron::~Octahedron()
{
}

float Octahedron::GetVertexDistance()
{
	return VertexDistance;

}

void  Octahedron::SetOctahedron(float Distance,VertexInfo *O) 
{
	float R = Distance;
	float o[3] = {O->GetXPosition(),O->GetYPosition(),O->GetZPosition()};

	VertexInfo *v1 = new VertexInfo( R + o[0], 0 + o[1], 0 + o[2]);
	VertexInfo *v2 = new VertexInfo( 0 + o[0], R + o[1], 0 + o[2]);
	VertexInfo *v3 = new VertexInfo(-R + o[0], 0 + o[1], 0 + o[2]);
	VertexInfo *v4 = new VertexInfo( 0 + o[0],-R + o[1], 0 + o[2]);
	VertexInfo *v5 = new VertexInfo( 0 + o[0], 0 + o[1], R + o[2]);
	VertexInfo *v6 = new VertexInfo( 0 + o[0], 0 + o[1],-R + o[2]);

	//top pyramid of octahedron
	TriangleInfo *t1 = new TriangleInfo(v1, v2, v5);
	TriangleInfo *t2 = new TriangleInfo(v3, v2, v5);
	TriangleInfo *t3 = new TriangleInfo(v3, v4, v5);
	TriangleInfo *t4 = new TriangleInfo(v1, v4, v5);

	//bottom pyramid of octahedron
	TriangleInfo *t5 = new TriangleInfo(v2, v6, v3);
	TriangleInfo *t6 = new TriangleInfo(v2, v1, v6);
	TriangleInfo *t7 = new TriangleInfo(v4, v3, v6);
	TriangleInfo *t8 = new TriangleInfo(v1, v4, v6);

	this->VertexDistance = Distance;
	this->Center = *O;

	this->Triangles.push_back(*t1);
	this->Triangles.push_back(*t2);
	this->Triangles.push_back(*t3);
	this->Triangles.push_back(*t4);
	this->Triangles.push_back(*t5);
	this->Triangles.push_back(*t6);
	this->Triangles.push_back(*t7);
	this->Triangles.push_back(*t8);

}

void Octahedron::ChangeScale(float NewValue) 
{
	this->SetOctahedron(NewValue, &this->Center);
}
void Octahedron::AugmentScale(float Value) 
{
	this->SetOctahedron(this->VertexDistance + Value,&this->Center);
}
void Octahedron::DecreaseScale(float Value)
{
	if (this->VertexDistance > 0.01)
		this->SetOctahedron( this->VertexDistance - Value, &this->Center);
}