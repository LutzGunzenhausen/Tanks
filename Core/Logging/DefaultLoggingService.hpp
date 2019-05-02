#ifndef DEFAULTLOGGINGSERVICE_HPP_INCLUDED
#define DEFAULTLOGGINGSERVICE_HPP_INCLUDED

#include <string>
#include <iostream>

namespace Game {

class DefaultLoggingService : public LoggingService {
public:
    void log(const std::string &message) {
        std::cout << message << std::endl;
    }
};
}
#endif // DEFAULTLOGGINGSERVICE_HPP_INCLUDED
