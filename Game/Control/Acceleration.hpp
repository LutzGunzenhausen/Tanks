#ifndef ACCELERATION_HPP_INCLUDED
#define ACCELERATION_HPP_INCLUDED

namespace Game {

enum Direction {
    STANDING, FORWARD, BACKWARDS
};

class Acceleration {
private:
    const double acceleration;
    const double maxSpeed;
    double speed;
    Direction direction;

public:
    Acceleration(double acceleration_, double maxSpeed_)
     : acceleration(acceleration_), maxSpeed(maxSpeed_), speed(0.0), direction(STANDING) {
    }

    double getSpeed() {
        return speed;
    }

    void setDirection(Direction direction_) {
        direction = direction_;
    }

    void update() {
        if (direction == FORWARD) {
            speed += acceleration;
            if (speed > maxSpeed) {
                speed = maxSpeed;
            }
        } else if (direction == BACKWARDS) {
            speed -= acceleration;
            if (speed < -maxSpeed) {
                speed = -maxSpeed;
            }
        } else if (speed > 0) {
            speed -= 10;
            if (speed < 0) {
                speed = 0;
            }
        } else if (speed < 0) {
            speed += 10;
            if (speed > 0) {
                speed = 0;
            }
        }
    }
};

}

#endif // ACCELERATION_HPP_INCLUDED
