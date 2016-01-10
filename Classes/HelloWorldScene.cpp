#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    Director* director = Director::getInstance();
    TextureCache* textureCache = director->getTextureCache();
    Size visibleSize = director->getVisibleSize();
    Vec2 origin = director->getVisibleOrigin();

    TMXTiledMap *_tileMap = TMXTiledMap::create("cowboy_background.tmx");
    _tileMap->setMapSize(visibleSize);
    int scale = 4;


    _tileMap->setPosition(Vec2::ZERO);

    _tileMap->setScale(scale);
    addChild(_tileMap, 0);

    TMXObjectGroup *objects = _tileMap->getObjectGroup("Objects");

    auto spawnPoint = objects->getObject("SpawnPoint");

//    int x = spawnPoint["x"].asInt();
//    int y = spawnPoint["y"].asInt();

//    Animation* animation = Animation::create();
    Animation* animation;
    Texture2D* textTure = textureCache->addImage("Player_1_Walking_sheet.png");
    float tw = textTure->getContentSize().width;
    float th = textTure->getContentSize().height;

    int cols = 4;
    int rows = 4;
    float w = tw/cols;
    float h = th/rows;
//    CCArray  *animFrames=CCArray::create();
    Vector<SpriteFrame*> frames;
    for (int i = 12; i < 16; ++i)
    {

        SpriteFrame* frame = SpriteFrame::createWithTexture(textTure, Rect(w*(i%cols),h*(i/rows),w,h));
//        if(i==0){
//            firstFrame = frame;
//         }

//         animation->addSpriteFrame(frame);
            frames.pushBack(frame);
    //        animFrames->addObject(frame);
    }
    ssize_t index = 0;

    SpriteFrame* firstFrame = frames.at( index );
    
    Sprite *sp = Sprite::createWithSpriteFrame(firstFrame);
    sp->setAnchorPoint(Vec2::ZERO);
//    float offsetx = (_tileMap->getContentSize().width-visibleSize.width)/2;
//    float offsety =(_tileMap->getContentSize().height-visibleSize.height)/2;
//    sp->setPosition(Vec2(origin.x-offsetx+x*w,origin.y-offsety+y*h));
    sp->setPosition(Vec2(origin.x,origin.y));
    sp->setScale(scale);
    addChild(sp,1);

    animation = Animation::createWithSpriteFrames(frames,0.2f);

//    animation = Animation::create(animFrames,0.2f);
//    animation->setDelayPerUnit(0.2f);
    Animate* animate = Animate::create(animation);
    RepeatForever* repeat = RepeatForever::create(animate);
    sp->runAction(repeat);

    Texture2D* healthBarTexture = textureCache->addImage("Player_1_Health_Bar.png");
    Sprite *player1HealthBar = Sprite::createWithTexture(healthBarTexture);
    player1HealthBar->setAnchorPoint(Vec2::ZERO);
    player1HealthBar->setPosition(Vec2(origin.x,visibleSize.height-healthBarTexture->getContentSize().height-origin.y));

    player1HealthBar->setScale(scale);
    addChild(player1HealthBar,3);

    Sprite *weapon = Sprite::createWithTexture(textureCache->addImage("Weapon_Blank_GUI.png"));
    weapon->setAnchorPoint(Vec2::ONE);
    weapon->setPosition(Vec2(visibleSize.width,origin.y+visibleSize.height));
    weapon->setScale(scale);
    addChild(weapon,3);
    
    Texture2D* healthTexture = textureCache->addImage("Health_bar.png");
    Sprite *health = Sprite::createWithTexture(healthTexture);
    health->setAnchorPoint(Vec2::ZERO);
    health->setPosition(Vec2(origin.x-5+(healthBarTexture->getContentSize().width-healthTexture->getContentSize().width)*scale,3.75f+visibleSize.height-healthBarTexture->getContentSize().height-origin.y));
    health->setScale(scale);
    addChild(health,3);
    
    
    // frameCache->addSpriteFramesWithFile("boy.plist","boy.png");
    // auto frame_sp = Sprite::createWithSpriteFrameName("boy1.png");
    // this->addChild(frame_sp,2);
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
//    auto closeItem = MenuItemImage::create(
//                                           "CloseNormal.png",
//                                           "CloseSelected.png",
//                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
//  closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
//                                origin.y + closeItem->getContentSize().height/2));

//    // create menu, it's an autorelease object
//    auto menu = Menu::create(closeItem, NULL);
//    menu->setPosition(Vec2::ZERO);
//    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
//    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
//    
//    // position the label on the center of the screen
//    label->setPosition(Vec2(origin.x + visibleSize.width/2,
//                            origin.y + visibleSize.height - label->getContentSize().height));
//
//    // add the label as a child to this layer
//    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    // auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    // sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    // this->addChild(sprite, 0);
   
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
