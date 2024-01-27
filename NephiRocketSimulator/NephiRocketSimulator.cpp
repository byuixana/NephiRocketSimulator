// NephiRocketSimulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Rocket.h" //Includes the Rokcet class
#include "Velocity.h" //Includes the Velocity class
#include <vector>
using namespace std;


int main()
{
    // Add orbit options here.

    string userOrbitChoice;
    cout << "Select an orbit: " << endl;
    cin >> userOrbitChoice;

    float userOrbit;
    if (userOrbitChoice == "LEO")
    {
        userOrbit = 160;
    }
        
    else if (userOrbitChoice == "MEO")
    {
        userOrbit = 1200;
    }
    else if (userOrbitChoice == "GEO")
    {
        userOrbit = 35786;
    }

    //Creates rocket.
    Rocket* nephiRocket = new Rocket(549054.0);

    //Launches rocket.
    nephiRocket->RocketLaunch();

    //Calculates distance traveled in air.
    nephiRocket->RocketInAir(userOrbit);

    //Calculates rockets fall.
    nephiRocket->RocketFreeFall(userOrbit);

    //Delete rocket.
    delete nephiRocket;

    //Setting nephiRocket to null prevents the program from going back and trying to access an invalid memory address.
    nephiRocket = nullptr;
}
