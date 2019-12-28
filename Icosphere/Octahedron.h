

#pragma once

#include <list>
#include "Figure.h"

using namespace std;

class Octahedron : public Figure
{
public:
	Octahedron();
	~Octahedron();

	float GetVertexDistance();
	void SetOctahedron(float R, VertexInfo *O);

	void ChangeScale(float NewValue) override;
	virtual void AugmentScale(float Value) override;
	virtual void DecreaseScale(float Value) override;

private:

	float VertexDistance;
};

