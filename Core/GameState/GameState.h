#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

namespace Game {
class GameState {
public:
    virtual ~GameState() {}

    virtual GameState* update(InputMask *inputMask) = 0;
    virtual void paint() = 0;
};
}
#endif // GAMESTATE_H_INCLUDED
