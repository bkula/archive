#include "Board.h"

Board::Board()
{
    //ctor
}

bool Board::init()
{
    USING_NS_CC;

    if (! Node::init()) return false;

    Size screen = Director::getInstance()->getVisibleSize();

    // blocks
    auto s = Block::size;
    for (int x = 0; x < screen.width; x += s) {
        for (int y = 0; y < screen.height; y += s) {
            auto block = Block::create();
            block->setPosition(Vec2(x, y));
            this->addChild(block, 0);
        }
    }

    return true;
}
