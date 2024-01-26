#pragma once
#include <utility>
using namespace std;
class Velocity
{
public:
	Velocity();
	float CalculateVelocity(float time, float distance); //Must include parameters to find function.
	pair<float, float> CalculateGandT(float userOrbit);
	float CalculateVelocityFalling(pair<float, float> gtPair);
private:
	float _time;
	float _distance;
};



