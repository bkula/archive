#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "cocos2d.h"

class Block : public cocos2d::DrawNode
{
public:

    Block();
    virtual ~Block();

    virtual bool init();
    CREATE_FUNC(Block);

    static const int size = 30;

    Block* neighbor[3][3];
    /* old
    6 5 4
    7 X 3
    0 1 2
    */

protected:
private:

};

#endif // __BLOCK_H__
