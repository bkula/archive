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
    int s = std::min(screen.width, screen.height) / Block::size - 1;
    Block* blocks[s][s];
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            blocks[i][j] = Block::create();
            blocks[i][j]->setPosition(Point(
                screen.width/2 - static_cast<float>(Block::size*s)/2.0 + Block::size*i,
                screen.height/2 - static_cast<float>(Block::size*s)/2.0 + Block::size*j
            ));
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    auto n = blocks[i][j]->neighbor[x+1][y+1];
                    if ((x < 0 || x >= s) || (y < 0 || y >= s)) n = nullptr;
                    else n = blocks[i+x][j+y];
                }
            }
            this->addChild(blocks[i][j], 0);
        }
    }

    return true;
}
