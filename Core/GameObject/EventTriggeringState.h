#ifndef EVENTTRIGGERINGSTATE_H_INCLUDED
#define EVENTTRIGGERINGSTATE_H_INCLUDED

namespace Game {

class EventTriggeringState : public GameObjectState {
private:
    Event *event = NULL;

public:
    EventTriggeringState(GraphicsObject *graphicsObject_, Event *event_)
     : EventTriggeringState(graphicsObject_, 0, event_) {
    }

    EventTriggeringState(GraphicsObject *graphicsObject_, int delay_, Event *event_)
     : GameObjectState(graphicsObject_, delay_), event(event_) {
    }
    ~EventTriggeringState() {
        delete event;
    }
protected:
    void animationFinished() {
        StaticServiceLocator::getEventBus()->publishEvent(event);
    }
};

}

#endif // EVENTTRIGGERINGSTATE_H_INCLUDED
