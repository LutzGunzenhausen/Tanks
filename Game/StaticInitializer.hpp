#ifndef STATICINITIALIZER_HPP_INCLUDED
#define STATICINITIALIZER_HPP_INCLUDED

#include "../Core/Logging/LoggingService.h"
#include "../Core/Media/GraphicsService.h"
#include "../Core/Physics/PhysicsService.h"
#include "../Core/Event/EventBus.h"
#include "../Core/Resource/MediaResourceStorage.h"
#include "../Core/StaticServiceLocator.h"

#include "../Core/Logging/DefaultLoggingService.hpp"
#include "../Core/Media/SDL/SDLGraphicsService.hpp"
#include "../Core/Physics/DefaultPhysicsService.hpp"
#include "../Core/Event/EventBus.h"
#include "Resource/SpaceInvadersResourceStorage.h"

namespace Game {

LoggingService *StaticServiceLocator::loggingService;
GraphicsService *StaticServiceLocator::graphicsService;
PhysicsService *StaticServiceLocator::physicsService;
EventBus *StaticServiceLocator::eventBus;
MediaResourceStorage *StaticServiceLocator::storage;


class StaticInitializer {
public:
    static void initialize() {
        StaticServiceLocator::setLoggingService(new DefaultLoggingService());
        StaticServiceLocator::setGraphicsService(new SDLGraphicsService());
        StaticServiceLocator::setPhysicsService(new DefaultPhysicsService());
        StaticServiceLocator::setEventBus(new EventBus());
        StaticServiceLocator::setMediaResourceStorage(new SpaceInvadersResourceStorage());
    }
};
}

#endif // STATICINITIALIZER_HPP_INCLUDED
