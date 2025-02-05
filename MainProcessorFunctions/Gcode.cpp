#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

//Example lines of data from a CSV file
/*
Timestamp,Pot1,Pot2,Pot3,Pot4,Pot5,Accel1_X,Accel1_Y,Accel1_Z,Gyro1_X,Gyro1_Y,Gyro1_Z,Mag1_X,Mag1_Y,Mag1_Z,Accel2_X,Accel2_Y,Accel2_Z,Gyro2_X,Gyro2_Y,Gyro2_Z,Mag2_X,Mag2_Y,Mag2_Z
1612345678,45.0,45.0,54.08,81.73,66.27,0.12,9.81,-0.34,0.02,-0.01,0.05,32.5,-15.8,42.3,0.15,9.79,-0.32,0.03,-0.02,0.04,31.8,-16.1,41.9
1612345680,12.18,55.48,41.75,83.7,56.91,0.11,9.8,-0.33,0.01,-0.01,0.05,32.4,-15.7,42.2,0.14,9.78,-0.31,0.02,-0.02,0.04,31.7,-16.0,41.8
1612345682,5.96,25.39,49.15,69.5,16.3,0.13,9.82,-0.35,0.02,-0.01,0.06,32.6,-15.9,42.4,0.16,9.8,-0.33,0.03,-0.02,0.05,31.9,-16.2,42.0
*/

//function declerations
int parse(string line);
int potGcode(float potValues[5]);
int accelGcode(float accelValues[18]);

int main(){
    string line;
    cout << "enter the line of values:\n";
    cin >> line;
    cout << "----------------------------------------------" << endl;
    //calling parse function
    parse(line);
}

int parse(string line){
    stringstream ss(line);

    float potValues[5];
    float accelValues[18];

    // Skip the timestamp (first value)
    long timestamp;
    ss >> timestamp;
    ss.ignore();  // Skip the comma

    for (int i = 0; i < 5; i++){
        ss >> potValues[i];
        ss.ignore();
    }

    for (int i = 0; i < 18; i++){
        ss >> accelValues[i];
        ss.ignore();
    }

    potGcode(potValues);
    accelGcode(accelValues);
    return 0;
     
}

//NEED TO REMEMBER TO CONVERT BACK TO DEGREES AT THE END

int potGcode(float potValues[5]){
    //arm length in inches
    const int armLength = 10;
    const double pi = 3.1415928;
    //Need to find the length from the potentiometer to each finger for relative coordinates

    //Theta 1: first potentiometer value, elbow vertical movement
    float thetaOneDeg = potValues[0];
    float thetaOneRad = (thetaOneDeg * pi) / 180;
    float thetaOneX = cos(thetaOneRad) * armLength;
    float thetaOneY = sin(thetaOneRad) * armLength;
    //cout << "x1: " << thetaOneX << ", " << "y1: " << thetaOneY << endl; 
    cout << "Theta one Gcode: " << "G01 " << "X" << thetaOneX << " Y" << thetaOneY << endl;
    
    //Theta 2: second potentiometer value, elbow horizontal movement
    float thetaTwoDeg = potValues[1];
    float thetaTwoRad = (thetaTwoDeg * pi) / 180;
    float thetaTwoX = cos(thetaTwoRad) * armLength;
    float thetaTwoY = sin(thetaTwoRad) * armLength;
    //cout << "x2: " << thetaTwoX << ", " << "y2: " << thetaTwoY << endl;
    cout << "Theta two Gcode: " "G01 " << "X" << thetaTwoX << " Y" << thetaTwoY << endl;

    //Theta 5: third potentiometer value, "index" finger opening and closing

    //Theta 6: fourth potentiometer value, "middle" finger opening and closing

    //Theta 7: fifth potentiometer value, thumb opening and closing

    return 0;
}



int accelGcode(float accelValues[18]){
    //arm length in inches
    const int armLength = 10;
    const double pi = 3.1415928;

    //Theta 3: First accelerometer value, wrist flexion 
    /*
    |Gyro2_Z| - |Gyro1_Z|
    */

    return 0;
}
