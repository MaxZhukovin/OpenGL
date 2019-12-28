#pragma once

#include "Figure.h";
#include "Octahedron.h";
#include "Geometry.h";
#include <list>;

using namespace std;

class Sphere : public Figure
{
public:

	Sphere();
	~Sphere();	

	void SetSphere(Octahedron octahedron, int DetalizationLevel);
	void SetSphere(VertexInfo* O, float Radius, int DetalizationLevel);
	int GetDetalizationLevel();
	float GetRadius();

	void ChangeScale(float NewValue) override;
	virtual void AugmentScale(float Value) override;
	virtual void DecreaseScale(float Value) override;

private:
	int DetalizationLevel;
	float Radius;
};
