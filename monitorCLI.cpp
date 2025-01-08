#include <iostream>
#include <string>
#include "device.cpp"
#include "deviceManager.cpp"

using namespace std;

deviceManager deviceMG;

int main() {
  cout << "Hello World!" << std::endl;

  //deviceMG.loadTestDevice();

  if(!deviceMG.loadDevices()){
  	cout<< "Devices not loaded correctly terminating ..." << endl;
  	return 1;
  }

  deviceMG.printDevices();

  return 0;
}