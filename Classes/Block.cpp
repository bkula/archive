#include "Block.h"

USING_NS_CC;

Block::Block()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            neighbor[i][j] = nullptr;
        }
    }
    neighbor[1][1] = this;
}

Block::~Block()
{
    //dtor
}

bool Block::init()
{
    if ( !cocos2d::DrawNode::init() )
    {
        return false;
    }

    //SpriteFrame *frame = SpriteFrame::frameWithTexture(texture, rect, offset);
    //this->setDisplayFrame(frame);
    Point b[] = {Point(0,0),Point(0,size),Point(size,size),Point(size,0)};
    drawPolygon(b, 4, Color4F(1,RandomHelper::random_int(0,1),1,1), 0, Color4F(0,0,1,1));

    return 1;
}
