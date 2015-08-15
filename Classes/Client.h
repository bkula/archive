#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "cocos2d.h"

class Client : public cocos2d::Scene
{
public:

    Client();

    virtual bool init();

    CREATE_FUNC(Client);

    void menuCloseCallback(cocos2d::Ref* pSender);

protected:
private:
};

#endif // __CLIENT_H__
