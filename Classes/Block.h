#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "cocos2d.h"

class Block : public cocos2d::Node
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

    void update(float delta);

    enum BlockType
    {
        BLOCK_STONE,
        BLOCK_GROUND,
        BLOCK_AIR,
        BLOCK_SIZE
    };

    //static cocos2d::Color4F typeColor[BLOCK_SIZE];

    void changeType(BlockType _type);

private:

    BlockType type;
    cocos2d::Color4F color;

};

#endif // __BLOCK_H__
