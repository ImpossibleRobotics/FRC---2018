/*
 * 2017
 * */
#include <iostream>
#include <memory>
#include <string>

#include <HumanInterfaceDevices/IRJoystick.h>
#include <RobotDrive/IRCANRobotDrive.h>

#include <Joystick.h>
#include <SampleRobot.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Timer.h>

#include <IRDriverOne.h>
#include <IRDriverTwo.h>

class Robot: public frc::SampleRobot {
	//							  FL, RL, FR, RR
	IR::IRCANRobotDrive myDrive	 {1,  0,  2,  3, IR::Mecanum};
	IR::IRJoystick 		joystick {0},
						gamePad{1};

	frc::SendableChooser<std::string> chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";

	IR::IRDriverOne driverOneTask {&joystick, &myDrive};
	IR::IRDriverTwo driverTwoTask {&gamePad};

//	ADIS16448_IMU *imu;

public:
	Robot() {
//		imu = new ADIS16448_IMU;
	}
	void RobotInit() {
		chooser.AddDefault(autoNameDefault, autoNameDefault);
		chooser.AddObject(autoNameCustom, autoNameCustom);
		frc::SmartDashboard::PutData("Auto Modes", &chooser);

		myDrive.SetMotorsInverted(false, false, true, true);
	}

	/*
	 * This autonomous (along with the chooser code above) shows how to select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString line to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional comparisons to the
	 * if-else structure below with additional strings. If using the
	 * SendableChooser make sure to add them to the chooser code above as well.
	 */
	void Autonomous() {
		auto autoSelected = chooser.GetSelected();
		// std::string autoSelected = frc::SmartDashboard::GetString("Auto Selector", autoNameDefault);
		std::cout << "Auto selected: " << autoSelected << std::endl;

		myDrive.Drive(0.0, 0.5, 0.0);
		frc::Wait(2);
		myDrive.Drive(90.0, 0.5, 0.0);
		frc::Wait(2);
		myDrive.Drive(0.0, 0.0, 0.0);
	}

	/*
	 * Runs the motors with arcade steering.
	 */
	void OperatorControl() override {
		while (IsOperatorControl() && IsEnabled()) {
			if(!driverOneTask.isEnabled()) driverOneTask.Start();
			if(!driverTwoTask.isEnabled()) driverTwoTask.Start();

//			SmartDashboard::PutData("IMU", imu);

			SmartDashboard::PutBoolean("Driver One Task", driverOneTask.isEnabled());
			SmartDashboard::PutBoolean("Driver Two Task", driverTwoTask.isEnabled());

			SmartDashboard::PutNumber("Joy-Y", joystick.GetY());
			SmartDashboard::PutNumber("Joy-Y-DeadZoned", joystick.GetYDeadZoned());

			SmartDashboard::PutNumber("Joy-X", joystick.GetX());
			SmartDashboard::PutNumber("Joy-X-DeadZoned", joystick.GetXDeadZoned());

			SmartDashboard::PutNumber("Joy-Z", joystick.GetZ());
			SmartDashboard::PutNumber("Joy-Z-DeadZoned", joystick.GetZDeadZoned());

			SmartDashboard::PutNumber("Joy-Throttle", joystick.GetThrottle());
			SmartDashboard::PutNumber("Joy-Throttle-Leveled", joystick.GetLeveledThrottle());

			// wait for a motor update time
			frc::Wait(0.005);
		}
		driverOneTask.Pause();
		driverTwoTask.Pause();
	}

	/*
	 * Runs during test mode
	 */
	void Test() override {

	}

private:
};

START_ROBOT_CLASS(Robot)
