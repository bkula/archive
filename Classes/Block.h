#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "cocos2d.h"

#include "Common.h"

USING_NS_CC;

class Block : public cocos2d::Node
{
public:

    Block();
    virtual ~Block();

    virtual bool init();
    CREATE_FUNC(Block);

    static const int size = 45;

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

    static Color4F colorAir() { return Color4F(0.5, 0.95, 1, 1); }
    static Color4F colorGround() { return Color4F(0.65, 0.45, 0.30, 1); }
    static Color4F colorStone() { return Color4F(0.3, 0.4, 0.4, 1); }

    void changeType(BlockType _type);
    BlockType getType() const { return _type; }

private:

    BlockType _type;
    cocos2d::Color4F _color;

};

#endif // __BLOCK_H__
