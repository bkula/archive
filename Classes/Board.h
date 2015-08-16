#ifndef __BOARD_H__
#define __BOARD_H__

#include "cocos2d.h"

#include "Block.h"

class Board : public cocos2d::Node
{
public:

    Board();

    virtual bool init();
    CREATE_FUNC(Board);

    static constexpr float scrollSpeed = 0.1;

    void update(float delta);

private:

    // mouse
    bool _isMouseDown;
    float _moveFromX;
    float _moveFromY;
    float _scaleChange;
};

#endif // __BOARD_H__
