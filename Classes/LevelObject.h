#ifndef LEVELOBJECT_H
#define LEVELOBJECT_H
#include "cocos2d.h"

class LevelObject : public Node
{
private:
  // It helps to typedef super & self so if you change the name
  // of the class or super class, you don't have to replace all
  // the references
  typedef Node super;
  typedef LevelObject self;

protected:
  b2Body* body;
  Sprite* sprite;

public:
  LevelObject();
  virtual ~LevelObject();
};

#endif // LEVELOBJECT_H
