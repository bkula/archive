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

protected:
private:
};

#endif // __BOARD_H__
