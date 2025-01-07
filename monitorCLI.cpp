#include <iostream>
#include <string>
#include "device.cpp"
#include "deviceManager.cpp"

using namespace std;

deviceManager deviceMG;

int main() {
  cout << "Hello World!" << std::endl;

  //deviceMG.loadTestDevice();

  deviceMG.loadDevices();

  deviceMG.printDevices();



  return 0;
}