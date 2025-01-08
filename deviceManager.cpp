#include "device.cpp"
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "Less than 4 values read for a device";
  }
} tooFewValues;




class deviceManager{
private:
	bool devicesLoaded = false;
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


	//Returns true if devices loaded sucessfully
	bool loadDevices(){
		ifstream MyReadFile("devices.txt");
		string myText;


		try {
		  while (getline (MyReadFile, myText)) {
		  	//Stores the charicters between the "|".
				vector<string> values = {""};
				//Keeps track of how many "|" have been seen.
				int index = 0;

			  for(char letter : myText){
			  	//Checks if the current letter is a "|".
			  	if(letter == '|'){
			  		//If it is then stop writting this value and move to the next one.
			  		index += 1;
			  		values.push_back("");
			  	}else{
			  		//If it is not then concatinate the letter onto the current value.
			  		values.at(index) += letter;
			  	}
			  }
			  if(values.size() > 3){
	  	  	addDevice(device(stoi(values.at(0)),values.at(1), values.at(2),values.at(3)));
			  }else{
			  	throw(tooFewValues);
			  }
			}
		}
		catch (exception& e){
		   cout << "Device Manager - Exception Message : "<<e.what() << '\n';
		   return false;
		 }
		
	 	devicesLoaded = true;
		return true;
	}



};