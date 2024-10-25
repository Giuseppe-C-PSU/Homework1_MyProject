#include "q1.h"
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <chrono>
#include <thread>

using namespace std;
// this code still doesn't work, fuel calculation off for readjustment
double totWeight(double empty, double frontS, double backS, double bag, double fuelG, double fuel){
    double totWeight = empty + frontS + backS + bag + (fuelG * fuel);
    return totWeight;
}
double totMom(double frontS, double momFrontS, double backS, double momBackS, double fuel, double momFuelL, double fuelG, double bag, double bagMom, double momWeightE){
    double momTot = frontS * momFrontS + momWeightE + backS * momBackS + fuel*fuelG*momFuelL + bag * bagMom;
    return momTot;
}

double CG(double momTot, double weightTot){
    double COG = momTot/weightTot;
    return COG;
}

bool question1() {
    cout << "Please insert the following parameters" << endl;

    cout << "Airplane empty weight (pounds)" << endl;
    double weightE;
    cin >> weightE;

    cout << "Airplane empty-weight moment (pounds-inches)" << endl;
    double momWeightEL;
    cin >> momWeightEL;

    cout << "The number of front seat occupants" << endl;
    int numSeatsFront;
    cin >> numSeatsFront;


    vector<int> seatsFrontWeights;
    if (numSeatsFront > 0){
        cout << "Weight of each front seat occupant (pounds)" << endl;

        for (int i = 0; i < numSeatsFront; i++) {
            cout << "Weight of person " << to_string(i + 1) << ": ";
            int value;
            cin >> value;
            seatsFrontWeights.push_back(value);
        }
    }else{
        cout << "There are no front seats" << endl;
    }

    cout << "Front seat moment arm (inches)" << endl;
    int momFrontSeatsL;
    cin >> momFrontSeatsL;

    cout << "The number of rear seat occupants" << endl;
    int numBackSeats;
    cin >> numBackSeats;

    vector <int> seatsBackWeights;
    if (numBackSeats > 0){
        cout << "Weight of each back seater" << endl;

        for (int i = 0; i < numBackSeats; i++){
            cout << "Weight of person " << to_string(i+1) << ": ";
            int value;
            cin >> value;
            seatsBackWeights.push_back(value);
        }
    }

    cout << "Rear seat moment arm (inches)" << endl;
    int momRearSeatsL;
    cin >> momRearSeatsL;

    cout << "The number of gallons of usable fuel (gallons)" << endl;
    int fuel;
    cin >> fuel;

    cout << "Usable fuel weights per gallon (pounds)" << endl;
    int fulGal;
    cin >> fulGal;

    cout << "Fuel tank moment arm (inches)" << endl;
    int momFuelL;
    cin >> momFuelL;

    cout << "Baggage weight (pounds)" << endl;
    int bagWeight;
    cin >> bagWeight;

    cout << "Baggage moment arm (inches)" << endl;
    int momBagL;
    cin >> momBagL;



    // Now we check and do maths and stuff:
    int frontseats;
    int backseats;
    frontseats = accumulate(seatsFrontWeights.begin(),seatsFrontWeights.end(), 0.0);
    backseats = accumulate(seatsBackWeights.begin(),seatsBackWeights.end(), 0.0);

    // Total weight for the entire plane using accumulate because vectors are weird:
    double weightTot = totWeight(weightE,frontseats,backseats,bagWeight,fulGal,fuel);
    
    // Total mom arm for the entire plane:
    double momTot = totMom(frontseats, momFrontSeatsL, backseats, momRearSeatsL, fuel, momFuelL, fulGal, bagWeight, momBagL, momWeightEL);


    double COG = CG(momTot,weightTot);

    cout << "Weight for plane is: " << to_string(weightTot) << " Pounds" << endl;
    cout << "COG for this plane is: " << to_string(COG) << " inches from datum" << endl;

    bool allowed;

    this_thread::sleep_for(chrono::seconds(2));

    if (weightTot < 2950 && (COG < 84.7 && COG > 82.1)){
        cout << "The plane is allowed" << endl;
        allowed = true;
    }else{ 
        cout << "This plane is not allowed" << endl;
        allowed = false;
    }

    return allowed;
}

//     if (allowed){
//         return allowed;
//     } else {
//         while (!allowed) {
//             if (weightTot > 2950) {
//                 cout << "Too much weight, removing fuel" << endl;
//                 double weightDiff = weightTot - 2950;
//                 weightTot -= weightDiff;
//                 cout << "Weight Diff: " << to_string(weightDiff) << "Weight Tot: " << to_string(weightTot) << endl; 
//                 fuel -= weightDiff;
//                 cout << "Fuel: " << to_string(fuel) << endl;
//                 COG = totMom(frontseats, momFrontSeatsL, backseats, momRearSeatsL, fuel, momFuelL, fulGal, bagWeight, momBagL, momWeightEL);
//                 cout << "CG is now at " << to_string(COG) << " from datum" << endl;
//                 this_thread::sleep_for(chrono::seconds(2));
//             }

//             if (COG > 84.7) {
//                 cout << "CG too forward, adjusting fuel" << endl;
//                 fuel = (84.7 * weightTot - (frontseats * momFrontSeatsL + backseats * momRearSeatsL + bagWeight * momBagL + momWeightEL)) / (momFuelL * fulGal);
//                 cout << "Fuel is now " << to_string(fuel) << endl;
//                 this_thread::sleep_for(chrono::seconds(2));
//                 COG = totMom(frontseats, momFrontSeatsL, backseats, momRearSeatsL, fuel, momFuelL, fulGal, bagWeight, momBagL, momWeightEL); // Update COG
//             } else if (COG < 82.1) {
//                 cout << "CG too rearward, adjusting fuel" << endl;
//                 fuel = (82.1 * weightTot - (frontseats * momFrontSeatsL + backseats * momRearSeatsL + bagWeight * momBagL + momWeightEL)) / (momFuelL * fulGal);
//                 cout << "Fuel is now " << to_string(fuel) << endl;
//                 this_thread::sleep_for(chrono::seconds(2));
//                 COG = totMom(frontseats, momFrontSeatsL, backseats, momRearSeatsL, fuel, momFuelL, fulGal, bagWeight, momBagL, momWeightEL); // Update COG
//             }

//             if (weightTot < 2950 && (COG < 84.7 && COG > 82.1)) {
//                 cout << "The plane is allowed" << endl;
//                 this_thread::sleep_for(chrono::seconds(2));
//                 allowed = true;
//             } else {
//                 cout << "This plane is not allowed" << endl;
//                 this_thread::sleep_for(chrono::seconds(2));
//             }
//         }
//         return allowed;
//     }
// }