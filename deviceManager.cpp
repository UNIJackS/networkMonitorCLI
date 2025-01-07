#include "device.cpp"
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


class deviceManager{
private:
  map<int, device> devices;

  int deviceNumber = 0;

	void addDevice(device deviceToAdd){
		devices.insert({deviceToAdd.getID(), deviceToAdd});
	}

public:

	void printDevices(){
		cout << "| ID | Name          | IP Adress     | Mac Adress         | Status        |" << endl;
  	cout << "|----|---------------|---------------|--------------------|---------------|" << endl;


		for (auto person : devices) {

			cout << person.second.getInfo();
		}
	}

	void loadTestDevice(){
	  device test1 = device(1,"testDevice", "8.8.8.8","00:00:00:00:00:00");
  	addDevice(test1);
	}


	bool loadDevices(){
		ifstream MyReadFile("devices.txt");
		string myText;

		while (getline (MyReadFile, myText)) {
			vector<string> values = {""};
			int index = 0;

		  for(char letter : myText){
		  	if(letter == '|'){
		  		index += 1;
		  		values.push_back("");
		  	}else{
		  		values.at(index) += letter;
		  	}
		  }

  	  addDevice(device(stoi(values.at(0)),values.at(1), values.at(2),values.at(3)));
		}

		return true;
	}





};