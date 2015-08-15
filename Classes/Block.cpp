#include "Block.h"

USING_NS_CC;

Block::Block()
: color(Color4F(Color4F(RandomHelper::random_int(0,1),0.3,0,1)))
, type(BLOCK_GROUND)
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

    return 1;
}

void Block::update(float delta)
{
    // children' tags
    // 0 - circle
    // 1, 2, 3, 4 - squares

    if (getChildByTag(0) == nullptr) {
        auto d = DrawNode::create();
        d->drawDot(Point(Block::size/2, Block::size/2), Block::size/2, color);
        addChild(d, 0, 0);
    }

    auto x = getPosition().x;
    auto y = getPosition().y;
    auto s = Block::size;

    // top left
    if ((! neighbor[0][1] || neighbor[0][1]->type != BLOCK_AIR) ||
        (! neighbor[1][0] || neighbor[1][0]->type != BLOCK_AIR))
    {
        if (! getChildByTag(1)) {
            auto d = DrawNode::create();
            Point b[] = {Point(0,s),Point(s/2,s),Point(s/2,s/2),Point(0,s/2)};
            d->drawPolygon(b, 4, color, 0, color);
            addChild(d, 0, 1);
        }
    } else {
        if (getChildByTag(1)) removeChildByTag(1);
    }

    // top right
    if ((! neighbor[0][1] || neighbor[0][1]->type != BLOCK_AIR) ||
        (! neighbor[1][2] || neighbor[1][2]->type != BLOCK_AIR))
    {
        if (! getChildByTag(2)) {
            auto d = DrawNode::create();
            Point b[] = {Point(s/2,s),Point(s,s),Point(s,s/2),Point(s/2,s/2)};
            d->drawPolygon(b, 4, color, 0, color);
            addChild(d, 0, 1);
        }
    } else {
        if (getChildByTag(2)) removeChildByTag(2);
    }

    // down left
    if ((! neighbor[1][0] || neighbor[1][0]->type != BLOCK_AIR) ||
        (! neighbor[1][1] || neighbor[1][1]->type != BLOCK_AIR))
    {
        if (! getChildByTag(3)) {
            auto d = DrawNode::create();
            Point b[] = {Point(0,s/2),Point(s/2,s/2),Point(s/2,0),Point(0,0)};
            d->drawPolygon(b, 4, color, 0, color);
            addChild(d, 0, 1);
        }
    } else {
        if (getChildByTag(3)) removeChildByTag(3);
    }

    // down right
    if ((! neighbor[1][1] || neighbor[1][1]->type != BLOCK_AIR) ||
        (! neighbor[1][2] || neighbor[1][2]->type != BLOCK_AIR))
    {
        if (! getChildByTag(4)) {
            auto d = DrawNode::create();
            Point b[] = {Point(s/2,s/2),Point(s,s/2),Point(s,0),Point(s/2,0)};
            d->drawPolygon(b, 4, color, 0, color);
            addChild(d, 0, 1);
        }
    } else {
        if (getChildByTag(4)) removeChildByTag(4);
    }
}
