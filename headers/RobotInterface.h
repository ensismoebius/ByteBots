#ifndef ROBOTINTERFACE_H
#define ROBOTINTERFACE_H
class RobotInterface
{
public:
    virtual void initialize() = 0;
    virtual void performAction() = 0;
    virtual void displayInfo() const = 0;
    virtual ~RobotInterface() = default;
};

// Function to create an instance of the robot (factory function)
extern "C" RobotInterface* createRobot();
#endif // ROBOTINTERFACE_H
