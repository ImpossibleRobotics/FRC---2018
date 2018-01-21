/*
 * IRDriverOne.h
 *
 *  Created on: Feb 20, 2017
 *      Author: Dylan Vos
 */

#ifndef IRDRIVERONE_H
#define IRDRIVERONE_H

#include <RobotBase.h>
#include <Timer.h>

#include <Multitasking/IRTask.h>
#include <HumanInterfaceDevices/IRJoystick.h>
#include <RobotDrive/IRCANRobotDrive.h>

namespace IR {

class IRDriverOne: public IRTask {
public:
	IRDriverOne(IR::IRJoystick *_joystick, IR::IRCANRobotDrive *_myDrive);
	virtual ~IRDriverOne();

	virtual void Run();

protected:
	IRJoystick *joystick;
	IRCANRobotDrive *myDrive;
};

} /* namespace IR */

#endif /* IRDRIVERONE_H */
