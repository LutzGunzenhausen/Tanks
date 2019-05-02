#ifndef TUPEL_HPP_INCLUDED
#define TUPEL_HPP_INCLUDED

namespace Game {

template <typename T>
class Tupel {
private:
    T first;
    T second;
public:

    Tupel() : first(0), second(0) {
    }

    Tupel(T first_, T second_) : first(first_), second(second_) {
    }

    void add(Tupel *other) {
        if (other == NULL) {
            //StaticServiceLocator::getLoggingService()->log("Tupel.add - other is null!");
        }
        first += other->first;
        second += other->second;
    }

    void multiply(T factor) {
        first *= factor;
        second *= factor;
    }

    T getFirst() {
        return first;
    }

    T getSecond() {
        return second;
    }

    void printToLog() {
        const std::string &msg = "";
        //StaticServiceLocator::getLoggingService()->log("Deine Mutter");
    }

};

}


#endif // TUPEL_HPP_INCLUDED
