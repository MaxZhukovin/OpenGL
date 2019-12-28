#include "Sphere.h"
#include <thread>
#include <chrono>

Sphere::Sphere()
{
}


Sphere::~Sphere()
{
}

float Sphere::GetRadius() 
{
	return Radius;

}

int Sphere::GetDetalizationLevel() {
	return DetalizationLevel;
}

void Sphere::SetSphere(Octahedron octahedron, int DetalizationLevel)
{
	float o[3] = { octahedron.GetCenter().GetXPosition(),octahedron.GetCenter().GetYPosition(),octahedron.GetCenter().GetZPosition() };
	std::list<TriangleInfo> iSphere;
	std::list<TriangleInfo> Sphere = octahedron.GetTriangles();
	float R = octahedron.GetVertexDistance();

	for (int i = 0; i < DetalizationLevel; i++) {

		iSphere = Sphere;
		Sphere.clear();
		for (TriangleInfo t : iSphere)
		{

			VertexInfo *v1new = Geometry::GetNormalizedCenter(t.GetVertex1(), t.GetVertex2(), R, o);//новая нормализованая точка
			VertexInfo *v2new = Geometry::GetNormalizedCenter(t.GetVertex2(), t.GetVertex3(), R, o);//новая нормализованая точка
			VertexInfo *v3new = Geometry::GetNormalizedCenter(t.GetVertex1(), t.GetVertex3(), R, o);//новая нормализованая точка

			VertexInfo *v1 = &t.GetVertex1();
			VertexInfo *v2 = &t.GetVertex2();
			VertexInfo *v3 = &t.GetVertex3();

			TriangleInfo *t1 = new TriangleInfo(v1, v1new, v3new);
			TriangleInfo *t2 = new TriangleInfo(v1new, v2, v2new);
			TriangleInfo *t3 = new TriangleInfo(v2new, v3, v3new);
			TriangleInfo *t4 = new TriangleInfo(v1new, v2new, v3new);

			Sphere.push_back(*t1);
			Sphere.push_back(*t2);
			Sphere.push_back(*t3);
			Sphere.push_back(*t4);
		}

	}
	this->Center =octahedron.GetCenter();
	this->DetalizationLevel = DetalizationLevel;
	this->Radius = octahedron.GetVertexDistance();
	this->Triangles = Sphere;
}

void Sphere::SetSphere(VertexInfo* O, float Radius, int DetalizationLevel)
{
	Octahedron octahedron = *(new Octahedron());
	octahedron.SetOctahedron(Radius, O);
	float o[3] = { octahedron.GetCenter().GetXPosition(),octahedron.GetCenter().GetYPosition(),octahedron.GetCenter().GetZPosition() };
	std::list<TriangleInfo> iSphere;
	std::list<TriangleInfo> Sphere = octahedron.GetTriangles();
	float R = octahedron.GetVertexDistance();

	for (int i = 0; i < DetalizationLevel; i++) {

		iSphere = Sphere;
		Sphere.clear();
		for (TriangleInfo t : iSphere)
		{

			VertexInfo* v1new = Geometry::GetNormalizedCenter(t.GetVertex1(), t.GetVertex2(), R, o);//новая нормализованая точка
			VertexInfo* v2new = Geometry::GetNormalizedCenter(t.GetVertex2(), t.GetVertex3(), R, o);//новая нормализованая точка
			VertexInfo* v3new = Geometry::GetNormalizedCenter(t.GetVertex1(), t.GetVertex3(), R, o);//новая нормализованая точка

			VertexInfo* v1 = &t.GetVertex1();
			VertexInfo* v2 = &t.GetVertex2();
			VertexInfo* v3 = &t.GetVertex3();

			TriangleInfo* t1 = new TriangleInfo(v1, v1new, v3new);
			TriangleInfo* t2 = new TriangleInfo(v1new, v2, v2new);
			TriangleInfo* t3 = new TriangleInfo(v2new, v3, v3new);
			TriangleInfo* t4 = new TriangleInfo(v1new, v2new, v3new);

			Sphere.push_back(*t1);
			Sphere.push_back(*t2);
			Sphere.push_back(*t3);
			Sphere.push_back(*t4);
		}

	}
	this->Center = octahedron.GetCenter();
	this->DetalizationLevel = DetalizationLevel;
	this->Radius = octahedron.GetVertexDistance();
	this->Triangles = Sphere;
}

void Sphere::ChangeScale(float NewValue) {
	this->SetSphere(&this->Center,NewValue,this->DetalizationLevel);
}
void Sphere::AugmentScale(float Value) {
	this->SetSphere(&this->Center, this->Radius + Value, this->DetalizationLevel);
}
void Sphere::DecreaseScale(float Value) 
{
	if(this->Radius > 0.01)
		this->SetSphere(&this->Center, this->Radius - Value, this->DetalizationLevel);
}