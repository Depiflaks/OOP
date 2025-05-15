//
// Created by smmm on 15.05.2025.
//

#include "TVSet.h"
int main() {
	TVSet tv;
	tv.Info();
	tv.SelectChannel(5);
	tv.Info();
	tv.TurnOn();
	tv.SelectChannel(5);
	tv.Info();
}