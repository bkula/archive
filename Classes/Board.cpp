#include "Board.h"

Board::Board()
: _scaleChange(1)
, _isMouseDown(false)
, _moveFromX(0)
, _moveFromY(0)
{
    //ctor
}

bool Board::init()
{
    USING_NS_CC;

    if (! Node::init()) return false;

    Size screen = Director::getInstance()->getVisibleSize();

    this->scheduleUpdate();

    //
    // mouse
    //

    auto mouseListener = EventListenerMouse::create();

    mouseListener->onMouseDown = [&](Event *event)
    {
        EventMouse* e = static_cast<EventMouse*>(event);

        if (e->getMouseButton() == 0) {
            _isMouseDown = true;
            _moveFromX = e->getCursorX();
            _moveFromY = e->getCursorY();
        }
    };

    mouseListener->onMouseMove = [&](Event *event)
    {
        EventMouse* e = static_cast<EventMouse*>(event);

        if (_isMouseDown) {
            this->runAction(MoveBy::create(0, Vec2(e->getCursorX() - _moveFromX, e->getCursorY() - _moveFromY)));
            _moveFromX = e->getCursorX();
            _moveFromY = e->getCursorY();
        }
    };

    mouseListener->onMouseUp = [&](Event *event)
    {
        EventMouse* e = static_cast<EventMouse*>(event);

        if (e->getMouseButton() == 0) {
            if (_isMouseDown) {
                this->runAction(MoveBy::create(0, Vec2(e->getCursorX() - _moveFromX, e->getCursorY() - _moveFromY)));
                _isMouseDown = false;
            }
        }
    };

    mouseListener->onMouseScroll = [&](Event* event)
    {
        EventMouse* e = static_cast<EventMouse*>(event);

        if (e->getScrollY() > 0) {
            _scaleChange *= 1.0 - scrollSpeed;
        }

        if (e->getScrollY() < 0) {
            _scaleChange *= 1.0 + scrollSpeed;
        }
    };

    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);

    //
    // blocks
    //

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
                - static_cast<float>(Block::size*s+1)/2.0 + Block::size*j,
                static_cast<float>(Block::size*s+1)/2.0 - Block::size*(i+1)
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

void Board::update(float delta)
{
    if (_scaleChange != 1.0) {
        this->runAction(ScaleBy::create(0, _scaleChange));
        _scaleChange = 1.0;
    }
}
