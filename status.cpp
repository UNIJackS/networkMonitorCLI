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

	string statusNames[3] = {"\033[0;32monline\033[0m","\033[0;31moffline\033[0m","\033[0;33mloading...\033[0m"};


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
