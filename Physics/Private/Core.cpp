#include "../Public/Core.h"

//---------------- operator overloading---------------------
Vector3 Vector3::operator+(const Vector3& v)
{
	return Vector3(x + v.x, y + v.y, z + v.z);
}

void Vector3::operator+=(const Vector3& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
}

Vector3 Vector3::operator-(const Vector3& v)
{
	return Vector3(x - v.x, y - v.y, z - v.z);
}

void Vector3::operator-=(const Vector3& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
}

Vector3 Vector3::operator*(const real value)
{
	return Vector3(x*value, y * value, z * value);
}

void Vector3::operator*=(const real value)
{
	x *= value;
	y *= value;
	z *= value;
}

// ---------- vector dot --------------
real Vector3::operator*(const Vector3& v)
{
	return x * v.x + y * v.y + z * v.z;
}

real Vector3::DotProduct(const Vector3& v)
{
	return x * v.x + y * v.y + z * v.z;
}

// ------------- vector cross ------------

Vector3 Vector3::operator%(const Vector3& v)
{
	return Vector3(y * v.z - z * v.y,
					z * v.x - x * v.z,
					x * v.y - y * v.x);
}

void Vector3::operator%=(const Vector3& v)
{
	x = y * v.z - z * v.y;
	y = z * v.x - x * v.z;
	z = x * v.y - y * v.x;
}

Vector3 Vector3::CrossProduct(const Vector3& v)
{
	return Vector3(y * v.z - z * v.y,
					z * v.x - x * v.z,
					x * v.y - y * v.x);
}


#ifdef RIGHT_HANDED
void Vector3::makeOrthonormalBasis(Vector3* a, Vector3* b, Vector3* c)
{
	a->Normalize();
	(*c) = (*a) % (*b);
	if (c->SquareLength() == 0.f) return;
	c->Normalize();
	(*b) = (*c) % (*a);
}
#else
void Vector3::makeOrthonormalBasis(Vector3* a, Vector3* b, Vector3* c)
{
	a->Normalize();
	(*c) = (*b) % (*a);
	if (c->SquareLength() == 0.f) return;
	c->Normalize();
	(*b) = (*a) % (*c);
}
#endif

//---------------- *= -1; ---------------------

void Vector3::Invert()
{
	x = -x;
	y = -y;
	z = -z;
}

//---------------- length ---------------------
real Vector3::Length() const
{
	return real_sqrt(x * x + y * y + z * z, 0.5f);
}
//---------------- length * length ---------------------
real Vector3::SquareLength() const
{
	return x * x + y * y + z * z;
}

void Vector3::Normalize()
{
	real length = Length();
	if (length > 0)
		(*this) *= 1.f / length;
}

Vector3 Vector3::ComponentProduct(const Vector3& v) const
{
	return Vector3(x*v.x,y*v.y,z*v.z);
}

void Vector3::ComponentProductUpdate(const Vector3& v)
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
}

void Vector3::clear()
{
	x = y = z = 0;
}
