#pragma once
#include <string>
#include "status.cpp"

using namespace std;

class device {
private:

	int id;
	string ip;
	string mac;
	string name;
	status currentStatus;

	// Checks the ip is made up of 0-255.0-255.0-255.0-255.
	// If the ip is invalid it will be set to "".
	string validateIP(string inputIP){
		string numbersStr[4];

		// Validates that there are only 3 full stops in the ip.
		int fullStopTotal = 0;
		for(int i =0; i < inputIP.size(); i +=1){
			if(inputIP[i] == '.'){
				//If there is a full stop then ...
				fullStopTotal +=1;

				//If there are more than 3 full stops
				if(fullStopTotal >= 4){
					return "";
				}
			}else{
				numbersStr[fullStopTotal] += inputIP[i];
			}
		}

		// Validates that all the charicters between the full stops are numbers
		// and that all the numbers are less than 255.
		int numbersInt[4];
		for(int i =0; i < 4; i +=1){
			// attempts to convert all the strings to ints.
			try{
				numbersInt[i] = stoi(numbersStr[i]);
			}catch (...){
        		return "";
   			}

   			// checks less than 255.
   			if(numbersInt[i] > 255){
   				return "";
   			}
		}

		return inputIP;

	}

	string getWhiteSpace(string value, int whiteSpace){
		string output = "| " + value;
		for(int i = whiteSpace-value.size(); i > 0; i -=1){
			output += " ";
		}
		return output;
	}

public:
	int getID(){return id;}
	string getName(){return name;}
	string getIP(){return ip;}
	string getMac(){return mac;}

	device(int id,string name, string ip, string mac){
		this->id = id;
		this->name = name;
		this->ip = validateIP(ip);
		this->mac = mac;
	}

	string getInfo(){
		string output;
		output += getWhiteSpace(to_string(id),3);
		output += getWhiteSpace(name,14);
		output += getWhiteSpace(ip,14);
		output += getWhiteSpace(mac,19);
		output += getWhiteSpace(currentStatus.getStatus(),14);

		output += "|\n";


		return output;
	}


};