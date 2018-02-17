/*
 * IRDriverOne.cpp
 *
 *  Created on: Feb 20, 2017
 *      Author: Dylan Vos
 */

#include <IRDriverOne.h>

namespace IR {

IRDriverOne::IRDriverOne(IR::IRJoystick *_joystick, IR::IRRobotDrive *_myDrive) {
	joystick = _joystick;
	myDrive = _myDrive;
}

IRDriverOne::~IRDriverOne() {
	// TODO Auto-generated destructor stub
}

void IRDriverOne::Run(){
//	myDrive->ArcadeDrive(joystick, true); // drive with arcade style (use right stick), boolean true if using deadZone
	myDrive->TankDrive(joystick, true); // drive with controller tank style (use left stick for left and right stick for right), boolean true if using deadZone

	frc::Wait(0.005);
}

} /* namespace IR */
