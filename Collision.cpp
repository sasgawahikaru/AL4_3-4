#include "Collision.h"
using namespace DirectX;

bool Collision::CheckSphere2Plane(const Sphere& sphere,
	const Plane& plane, DirectX::XMVECTOR* inter)
{
	XMVECTOR distV = XMVector3Dot(sphere.center, plane.normal);
	float dist = distV.m128_f32[0] - plane.distance;
	if (fabsf(dist) > sphere.radius) return false;
	if (inter) {
		*inter = -dist * plane.normal + sphere.center;
	}
	return true;
}
