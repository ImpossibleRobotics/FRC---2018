/*
 * IRDriverTwo.h
 *
 *  Created on: Feb 20, 2017
 *      Author: Dylan Vos
 */

#ifndef IRDRIVERTWO_H
#define IRDRIVERTWO_H

#include <RobotBase.h>
#include <Timer.h>

#include <Multitasking/IRTask.h>
#include <HumanInterfaceDevices/IRJoystick.h>

namespace IR {

class IRDriverTwo: public IRTask {
public:
	IRDriverTwo(IRJoystick *_joystick);
	virtual ~IRDriverTwo();

	virtual void Run();

protected:
	IRJoystick* joystick;
};

} /* namespace IR */

#endif /* IRDRIVERTWO_H */

