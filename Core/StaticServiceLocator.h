#ifndef STATICSERVICELOCATOR_H_INCLUDED
#define STATICSERVICELOCATOR_H_INCLUDED

#include "Logging/LoggingService.h"
#include "Media/GraphicsService.h"
#include "Physics/PhysicsService.h"
#include "Event/EventBus.h"
#include "Resource/MediaResourceStorage.h"

namespace Game {

class StaticServiceLocator {
private:
    static LoggingService *loggingService;
    static GraphicsService *graphicsService;
    static PhysicsService *physicsService;
    static EventBus *eventBus;
    static MediaResourceStorage *storage;
public:
    static void setLoggingService(LoggingService *loggingService_) {
        loggingService = loggingService_;
    }

    static LoggingService *getLoggingService() {
        return loggingService;
    }

    static void setGraphicsService(GraphicsService *graphicsService_) {
        graphicsService = graphicsService_;
    }

    static GraphicsService *getGraphicsService() {
        return graphicsService;
    }

    static void setPhysicsService(PhysicsService *physicsService_) {
        physicsService = physicsService_;
    }

    static PhysicsService *getPhysicsService() {
        return physicsService;
    }

    static void setEventBus(EventBus *eventBus_) {
        eventBus = eventBus_;
    }

    static EventBus *getEventBus() {
        return eventBus;
    }

    static void setMediaResourceStorage(MediaResourceStorage *storage_) {
        storage = storage_;
    }

    static MediaResourceStorage *getMediaResourceStorage() {
        return storage;
    }
};

}
#endif // STATICSERVICELOCATOR_H_INCLUDED
