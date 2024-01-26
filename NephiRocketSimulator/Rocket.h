#pragma once
#include <vector>
class Rocket
{
public:
	Rocket(float payload);
	void RocketLaunch();
	float CalculateThrust();
	float CalculateAcceleration();
	void RocketInAir(float userOrbit);
	void RocketLanding();
	void RocketFreeFall(float userOrbit);
	float UpdateMass();
	

private:
	float _acceleration;	//Meters per second squared
	float _velocity;		// Meters per second
	float _thrust;			//In Newtons
	float _mass = 100000.0f;			//In kilograms
	int _timer;				//In seconds
	float _gravity = 9.8f;	//In m/s^2
	float _payload;
};

