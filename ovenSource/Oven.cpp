#include "Oven.h"

Oven::Oven() : CurrentT(72), SetT(350), RoomT(72),
OvenStatus(false), MaxT(550), MinT(200) 
{
	//Blank..
}

int Oven::GetCurrentTemperature() const
{
	return CurrentT;
}

int Oven::GetSetTemperature() const
{
	return SetT;
}

void Oven::SetSetTemperature(int setT)
{
	if (setT >= MinT && setT <= MaxT) {
		SetT = setT;
	}
}

void Oven::TurnOn(int setT = 350)
{
	OvenStatus = true;
	SetSetTemperature(setT);
}

void Oven::TurnOff()
{
	OvenStatus = false;
}

bool Oven::isOn()
{
	if (OvenStatus) {
		return true;
	}
	return false;
}

int Oven::GetMinimumTemperature() const
{
	return MinT;
}

int Oven::GetMaximumTemperature() const
{
	return MaxT;
}

int Oven::GetRoomTemperature() const
{
	return RoomT;
}



void Oven::SimulatePassingOfTime(int timeValue)
{
	if (OvenStatus) {
		if (CurrentT < SetT) {
			for (int x = 0; x < timeValue; x++) {
				if (CurrentT < SetT) {
					CurrentT += 25;
					if (CurrentT > SetT) {
						CurrentT = SetT;
						break;
					}
				}

			}

		}
		else if (CurrentT > SetT) {
			for (int x = 0; x < timeValue; x++) {
				if (CurrentT > SetT) {
					CurrentT -= 15;
					if (CurrentT < SetT) {
						CurrentT = SetT;
						break;
					}
				}
			}
		}
	}

	else 
		for (int x = 0; x < timeValue; x++) {
			if (CurrentT != 72) {
				CurrentT -= 15;
				if (CurrentT < 72) {
					CurrentT = 72;
					break;
				}
			}
		}
}

