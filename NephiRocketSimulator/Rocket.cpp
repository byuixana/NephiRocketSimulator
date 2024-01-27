#include <iostream>
#include "Rocket.h"
#include "Velocity.h"
#include <vector>
#include <thread>
using namespace std;
/*Falcon 9 Model:

Rocket Characteristics:

Mass: Approximately 549,054 kg (including fuel and payload).
Payload Capacity: Varies depending on the mission (e.g., up to 22,800 kg to low Earth orbit).
Engines: Merlin engines for the first stage.
Fuel: Uses rocket-grade kerosene (RP-1) and liquid oxygen (LOX).
Simulation Considerations:

Thrust: 
Acceleration: Constant
Velocity: Based on position*/

//This rocket simulator will be divided into four stages, or 'time steps': launching, dropPayload, landing, InAir.

//Class constructor here.
Rocket::Rocket(float payload)
	: _thrust(0.0f), _acceleration(0.0f), _velocity(0.0f), _mass(549054.0f), _gravity(9.8f), _timer(0), _payload(payload)
{
}


void Rocket::RocketLaunch()
{
	/*This function will call all of the functions utilized in the launch of the rocket.*/
	_thrust = CalculateThrust();
	_acceleration = CalculateAcceleration();
	cout << "Rocket Stats" << endl;
	cout << "Thrust: " << _thrust << " Acceleration: " << _acceleration << " Initial Velocity: 0" << endl;
	cout << "SS Celestial is now in air!" << endl;
}

float Rocket::CalculateThrust()
{
	//Thrust remains the same for rockets as they ascend in BASIC simulations.
	_thrust = _gravity * _mass;
	return _thrust;
}

float Rocket::CalculateAcceleration()
{
	//Each time step, the acceleration will be update.
	float acceleration = (_thrust - _gravity) / _mass;
	return acceleration;
}

void Rocket::RocketInAir(float userOrbit) {
	/*As soon as the rocket is in air, velocity begins to kick into action!Instantiate velocity class.*/

	//Initialize velocity.
	Velocity velocity;

	pair<float, float> rocketSpeed = { 2.0, 1.0 }; //2 kilometers per second (distance, time)

	//The average rocket falls at 2 kilometers per second.
	float kilometersPerSecond = rocketSpeed.first;

	//Initialize distance.
	float distance = 0.0;

	//Calculates velocity based on kilometers per second.
	float currentVelocity = velocity.CalculateVelocity(rocketSpeed.second, rocketSpeed.first);

		//Begins calculating velocity.
	for (distance = 0.0; distance <= userOrbit; distance += kilometersPerSecond)
	{
		this_thread::sleep_for(chrono::milliseconds(100));
		//Distance increases over time, the loop ends at the Orbit the user said.
		float time = distance / kilometersPerSecond;
		cout << " SS Celestial is " << distance << " kilometers in air, moving at " << currentVelocity << " kilometers per second." << endl;
	}

	
}

void Rocket::RocketFreeFall(float userOrbit)
{
	cout << "Payload has been dropped. Your rocket is now falling.";

	//Initializes a new velocity. 
	Velocity fallingVelocity;

	//Uses the gravitational acceleration and the time the rocket falls for. 
	pair<float, float> freefallSpeed = fallingVelocity.CalculateGandT(userOrbit);
	
	// Initializes distance at 0 for the loop. You ahve to initailize all variables in C++ before using it in a loop. 
	float distance = 0.0;

	//Calculates current velocity.
	float currentVelocity = fallingVelocity.CalculateVelocityFalling(freefallSpeed);

	/**/
	for (distance = userOrbit; distance > 0; distance -= (freefallSpeed.first / freefallSpeed.second))
	{
		this_thread::sleep_for(chrono::milliseconds(100));
		//Distance increases over time, the loop ends at the Orbit the user said.
		float time = distance / currentVelocity;
		cout << " SS Celestial is " << distance << " kilometers in air, moving at " << currentVelocity << " kilometers per second." << endl;
		
	}
	cout << "The SS Celestial has landed. Great job, space ranger!";
	
}

void GenerateRocketReport()
{
	cout << "This function will eventually have something in it.";
}

void Rocket::RocketLanding()
{
	cout << "3, 2, 1, landed!";
}

