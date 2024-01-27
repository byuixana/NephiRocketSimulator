#include <iostream>
#include "Velocity.h"
#include <vector>
#include <utility>
using namespace std;
Velocity::Velocity() :_time(0.0), _distance(0.0) {
	
}

float Velocity::CalculateVelocity(float time, float distance)
{
	//Calculates velocity based on distance traveled and current time.
	float _velocity = distance / time;

	return _velocity;
}

pair<float, float> Velocity::CalculateGandT(float userOrbit)
{
	/*This function calculates the gravitational acceleration and the time the rocket will fall for.*/

	//1609.34 is meters, 9.8 is the gravitational constant.
	float t = 2.0 * (userOrbit * 1609.34) / 9.8;

	//Calculates the gravitational acceleration.
	float gAcceleration = sqrt((.5 * 9.8) * (t * t));

	//Puts the values in a pair.
	pair<float, float> gtPair = { gAcceleration, t };

	//Returns pair.
	return gtPair;
}


float Velocity::CalculateVelocityFalling(pair<float, float> gtPair)
{
	//Uses the formula v = ga (gravitational acceleration) / t (time) is in seconds.
	float _fallingVelocity = gtPair.first * gtPair.second;
	
	return _fallingVelocity;
}

/*	/*This function calculates velocity using distance and time. 
float* floatDistancePtr = &_distance; //Create a distance pointer.
float* floatTimePtr = &_time; //Do the same for time.


float* floatDistancePtr = velocityPair.first; //Asign the pointer to the first pair value.
float* floatTimePtr = velocityPair.second; //Assign the pointer the second pair value.*/

//The user will give a distance for the rocket to travel. This will be the final_distance.
//The rocket moves at two kilometers per second.
//The vector is filled with lists with distance and time inside.
//These loops will create a list to add to the vector based on the user's input.