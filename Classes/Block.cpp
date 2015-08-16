#include "Block.h"

USING_NS_CC;

Block::Block()
{
    changeType(BLOCK_GROUND);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            neighbor[i][j] = nullptr;
            neighborTypeUsedForTexture[i][j] = BLOCK_SIZE;
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
    if ( !cocos2d::Sprite::init() )
    {
        return false;
    }

    this->scheduleUpdate();

    return 1;
}

Block::BlockType Block::getNeighborType(int i, int j)
{
    ASSERT(i < 0 || i > 2, "Invalid neighbor index");
    ASSERT(j < 0 || j > 2, "Invalid neighbor index");
    if (neighbor[i][j]) return neighbor[i][j]->getType();
    else return BLOCK_STONE;
}

void Block::setNeighbor(int i, int j, Block* n)
{
    ASSERT(i < 0 || i > 2, "Invalid neighbor index");
    ASSERT(j < 0 || j > 2, "Invalid neighbor index");
    neighbor[i][j] = n;
}

void Block::update(float delta)
{
    if (isVisible()) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (neighborTypeUsedForTexture[i][j] != getNeighborType(i, j)) {
                    updateTexture();
                }
            }
        }
    }
}

void Block::changeType(BlockType newType)
{
    _type = newType;

    switch (_type) {
    case BLOCK_STONE: _color = colorStone(); break;
    case BLOCK_GROUND: _color = colorGround(); break;
    case BLOCK_AIR: _color = colorAir(); break;
    default: break;
    }

    /* old
    for (int i = 0; i <= 4; i++) {
        if (getChildByTag(i)) removeChildByTag(i);
    }
    */
}

void Block::updateTexture()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
                neighborTypeUsedForTexture[i][j] = getNeighborType(i, j);
        }
    }

    // begin
    auto texture = RenderTexture::create(size, size);
    texture->setPosition(Point(0,0));
    texture->begin();

    // air
    Point b[] = {Point(0,0),Point(0,size),Point(size,size),Point(size,0)};
    auto a = DrawNode::create();
    a->drawPolygon(b, 4, colorAir(), 0, colorAir());
    a->visit();

    // circle
    auto c = DrawNode::create();
    c->drawDot(Point(Block::size/2, Block::size/2), Block::size/2, _color);
    c->visit();

    auto x = getPosition().x;
    auto y = getPosition().y;
    auto s = Block::size;

    // top left
    if ((getNeighborType(0,1) != BLOCK_AIR) ||
        (getNeighborType(1,0) != BLOCK_AIR))
    {
        auto d = DrawNode::create();
        Point b[] = {Point(0,s),Point(s/2,s),Point(s/2,s/2),Point(0,s/2)};
        d->drawPolygon(b, 4, _color, 0, _color);
        d->visit();
    }

    // top right
    if ((getNeighborType(0,1) != BLOCK_AIR) ||
        (getNeighborType(1,2) != BLOCK_AIR))
    {
        auto d = DrawNode::create();
        Point b[] = {Point(s/2,s),Point(s,s),Point(s,s/2),Point(s/2,s/2)};
        d->drawPolygon(b, 4, _color, 0, _color);
        d->visit();
    }

    // down left
    if ((getNeighborType(1,0) != BLOCK_AIR) ||
        (getNeighborType(2,1) != BLOCK_AIR))
    {
        auto d = DrawNode::create();
        Point b[] = {Point(0,s/2),Point(s/2,s/2),Point(s/2,0),Point(0,0)};
        d->drawPolygon(b, 4, _color, 0, _color);
        d->visit();
    }

    // down right
    if ((getNeighborType(2,1) != BLOCK_AIR) ||
        (getNeighborType(1,2) != BLOCK_AIR))
    {
        auto d = DrawNode::create();
        Point b[] = {Point(s/2,s/2),Point(s,s/2),Point(s,0),Point(s/2,0)};
        d->drawPolygon(b, 4, _color, 0, _color);
        d->visit();
    }

    // end
    texture->end();
    Director::getInstance()->getRenderer()->render();
    setAnchorPoint(Point(0,0));
    setTexture(texture->getSprite()->getTexture());
    setTextureRect(Rect(0,0,size,size));
}

// TRASH

/*
    // top left
    if ((! neighbor[0][1] || neighbor[0][1]->getType() != BLOCK_AIR) ||
        (! neighbor[1][0] || neighbor[1][0]->getType() != BLOCK_AIR))
    {
        if (! getChildByTag(1)) {
            auto d = DrawNode::create();
            Point b[] = {Point(0,s),Point(s/2,s),Point(s/2,s/2),Point(0,s/2)};
            d->drawPolygon(b, 4, _color, 0, _color);
            addChild(d, 0, 1);
        }
    } else {
        if (getChildByTag(1)) removeChildByTag(1);
    }

    // top right
    if ((! neighbor[0][1] || neighbor[0][1]->getType() != BLOCK_AIR) ||
        (! neighbor[1][2] || neighbor[1][2]->getType() != BLOCK_AIR))
    {
        if (! getChildByTag(2)) {
            auto d = DrawNode::create();
            Point b[] = {Point(s/2,s),Point(s,s),Point(s,s/2),Point(s/2,s/2)};
            d->drawPolygon(b, 4, _color, 0, _color);
            addChild(d, 0, 1);
        }
    } else {
        if (getChildByTag(2)) removeChildByTag(2);
    }

    // down left
    if ((! neighbor[1][0] || neighbor[1][0]->getType() != BLOCK_AIR) ||
        (! neighbor[2][1] || neighbor[2][1]->getType() != BLOCK_AIR))
    {
        if (! getChildByTag(3)) {
            auto d = DrawNode::create();
            Point b[] = {Point(0,s/2),Point(s/2,s/2),Point(s/2,0),Point(0,0)};
            d->drawPolygon(b, 4, _color, 0, _color);
            addChild(d, 0, 1);
        }
    } else {
        if (getChildByTag(3)) removeChildByTag(3);
    }

    // down right
    if ((! neighbor[2][1] || neighbor[2][1]->getType() != BLOCK_AIR) ||
        (! neighbor[1][2] || neighbor[1][2]->getType() != BLOCK_AIR))
    {
        if (! getChildByTag(4)) {
            auto d = DrawNode::create();
            Point b[] = {Point(s/2,s/2),Point(s,s/2),Point(s,0),Point(s/2,0)};
            d->drawPolygon(b, 4, _color, 0, _color);
            addChild(d, 0, 1);
        }
    } else {
        if (getChildByTag(4)) removeChildByTag(4);
    }
*/
