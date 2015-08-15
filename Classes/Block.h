#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "cocos2d.h"

class Block : public cocos2d::DrawNode
{
public:

    Block();
    virtual ~Block();

    virtual bool init();
    CREATE_FUNC(Block);

    static const int size = 30;

protected:
private:
};

#endif // __BLOCK_H__
