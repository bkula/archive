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

    int s = std::min(screen.width, screen.height) / Block::size;
    Block* blocks[s][s];

    // first create blocks
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            blocks[i][j] = Block::create();
        }
    }

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {

            // type
            int r = RandomHelper::random_int(0,99);
            Block::BlockType t;
            if (r < 50) t = Block::BLOCK_GROUND;
            else if (r > 88) t = Block::BLOCK_STONE;
            else t = Block::BLOCK_AIR;
            blocks[i][j]->changeType(t);

            // position
            blocks[i][j]->setPosition(Point(
                screen.width/2 - static_cast<float>(Block::size*s+1)/2.0 + Block::size*j,
                screen.height/2 + static_cast<float>(Block::size*s+1)/2.0 - Block::size*i
            ));

            // neighbors
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if ((i+x < 0 || i+x >= s) || (j+y < 0 || j+y >= s)) blocks[i][j]->neighbor[x+1][y+1] = nullptr;
                    else blocks[i][j]->neighbor[x+1][y+1] = blocks[i+x][j+y];
                }
            }

            this->addChild(blocks[i][j], 0);
        }
    }

    return true;
}
