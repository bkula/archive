#include "cocos2d.h"

#include "iostream"
#include "string"

#define DELETE(ptr) {if(ptr)delete(ptr);ptr=nullptr;}

#define DEB(x) std::cout<<(x)<<std::endl;

#define ASSERT(b,m) if(b)DEB(m);
