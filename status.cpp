#pragma once
#include <string>

using namespace std;


class status{
private:
	enum statusEnum{
		ONLINE,
		OFFLINE,
		LOADING
	};

	string statusNames[3] = {"online","offline","loading..."};


	enum statusEnum currentStatus = LOADING;


public:
	status(){
		currentStatus = LOADING;
	}

	string getStatus(){
		switch(currentStatus){
			case ONLINE:
				return statusNames[0];
				break;

			case OFFLINE:
				return statusNames[1];
				break;

			case LOADING:
				return statusNames[2];
				break;
			default:
				return "unavailable";
		}
	}

};
