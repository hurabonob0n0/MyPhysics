#pragma once
#include "Defines.h"

BEGIN(Ragon)
	class RAGON_DLL Vector3
	{
	public:
		Vector3() : x(0.f),y(0.f),z(0.f){}
		Vector3(const real x, const real y, const real z) : x(x), y(y), z(z) {}

	public:
		Vector3 operator + (const Vector3& v);
		void operator += (const Vector3& v);
		Vector3 operator - (const Vector3& v);
		void operator -= (const Vector3& v);
		Vector3 operator* (const real value);
		void operator *= (const real value);

		// --------- vector dot -----------
		real operator * (const Vector3& v);
		real DotProduct (const Vector3& v);

		// --------- vector cross -----------
		Vector3 operator % (const Vector3& v);
		void    operator %= (const Vector3& v);
		Vector3 CrossProduct  (const Vector3& v);

	public:
		void Invert();
		real Length() const;
		real SquareLength() const;
		void Normalize();
		Vector3 ComponentProduct(const Vector3& v) const;
		void	ComponentProductUpdate(const Vector3& v);
		// |/_ 정규직교기저 만들기
		void makeOrthonormalBasis(_Inout_ Vector3* a, Vector3* b, Vector3* c);

	public:
		void clear();


	public:
		real x;
		real y;
		real z;
	private:
		real pad;

	};
END

