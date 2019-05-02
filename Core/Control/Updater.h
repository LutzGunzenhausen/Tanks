#ifndef UPDATER_H_INCLUDED
#define UPDATER_H_INCLUDED

namespace Game {

class Updater {
public:
    virtual ~Updater() {
    }
    virtual void update(InputMask *inputMask) = 0;
};

}

#endif // UPDATER_H_INCLUDED
