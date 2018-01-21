/*
 * IRDriverTwo.cpp
 *
 *  Created on: Feb 20, 2017
 *      Author: Dylan Vos
 */

#include <IRDriverTwo.h>

namespace IR {

IRDriverTwo::IRDriverTwo(IRJoystick *_joystick) {
	joystick = _joystick;
}

IRDriverTwo::~IRDriverTwo() {
	// TODO Auto-generated destructor stub
}

void IRDriverTwo::Run(){
	frc::Wait(0.005);
}

} /* namespace IR */
