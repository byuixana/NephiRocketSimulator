// NephiRocketSimulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Rocket.h" //Includes the Rokcet class
#include "Velocity.h" //Includes the Velocity class
#include <vector>
using namespace std;


int main()
{
    float userMass;
    cout << "Select a weight for a payload: " << endl;
    cin >> userMass;

    // Add orbit options here.

    float userOrbit;
    cout << "Select an orbit: " << endl;
    cin >> userOrbit;

    //Creates rocket.
    Rocket nephiRocket(userMass);

    //Launches rocket.
    nephiRocket.RocketLaunch();

    //Calculates distance traveled in air.
    nephiRocket.RocketInAir(userOrbit);

    //Calculates rockets fall.
    nephiRocket.RocketFreeFall(userOrbit);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
