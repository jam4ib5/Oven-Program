#pragma once

#ifndef OVEN_H
#define OVEN_H

class Oven {
public:

	Oven() ;

	int GetCurrentTemperature() const;

	int GetSetTemperature() const;

	void SetSetTemperature(int setT ) ;
	
	void TurnOn(int setT);
	
	void TurnOff();
	
	bool isOn();
	
	int GetMinimumTemperature() const;
	
	int GetMaximumTemperature() const;
	
	int GetRoomTemperature() const;
	
	void SimulatePassingOfTime(int timeValue);

private: 

	int CurrentT;
	int SetT;
	int RoomT;
	bool OvenStatus;
	int MaxT;
	int MinT;
};
#endif // !OVEN_H