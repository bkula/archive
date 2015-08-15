#include "Block.h"

USING_NS_CC;

Block::Block()
: color(Color4F(Color4F(RandomHelper::random_int(0,1),0.3,0,1)))
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
    if ( !cocos2d::Node::init() )
    {
        return false;
    }

    this->scheduleUpdate();

    //Point b[] = {Point(0,0),Point(0,size),Point(size,size),Point(size,0)};
    //drawPolygon(b, 4, Color4F(1,RandomHelper::random_int(0,1),1,1), 0, Color4F(0,0,1,1));

    /*
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {

        }
    }
    */

    return 1;
}

void Block::update(float delta)
{
    // children' tags
    // 0 - circle
    // 1, 2, 3, 4 - squares

    if (getChildByTag(0) == nullptr) {
        auto c = DrawNode::create();
        c->drawDot(Point(Block::size/2, Block::size/2), Block::size/2, color);
        addChild(c, 0, 0);
    }
}
