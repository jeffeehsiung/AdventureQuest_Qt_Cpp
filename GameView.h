#ifndef GAMEVIEW_H
#define GAMEVIEW_H

class GameView {
public:
    virtual ~GameView() {}
    virtual void updateView() = 0; // Pure virtual function for updating the view
};

#endif // GAMEVIEW_H
