/**
 ofxMouseController.h https://github.com/TatsuyaOGth/ofxMouseController
 
 Copyright (c) 2014 TatsuyaOGth http://ogsn.org
 
 This software is released under the MIT License.
 http://opensource.org/licenses/mit-license.php
 */
#pragma once

#include "ofPoint.h"
#include "ofAppRunner.h"

enum ofxMouseControllerButton
{
    OFX_MOUSE_CONTROLLER_BUTTON_LEFT    = 0,
    OFX_MOUSE_CONTROLLER_BUTTON_RIGHT   = 1,
};

class ofxMouseController
{
    
public:

    // move position
    static        void setPos(const float x, const float y);
    static inline void setPos(const ofPoint pos) { setPos(pos.x, pos.y); }
    
    static float getMousePosX() { return ofGetWindowPositionX() + ofGetMouseX(); }
    static float getMousePosY() { return ofGetWindowPositionY() + ofGetMouseY(); }
    static ofPoint getMousePos(){ return ofPoint(getMousePosX(), getMousePosY()); }
    
    // button
    static void click(const ofxMouseControllerButton button);
    
    static inline void click()      { click(OFX_MOUSE_CONTROLLER_BUTTON_LEFT); }
    static inline void clickLeft()  { click(OFX_MOUSE_CONTROLLER_BUTTON_LEFT); }
    static inline void clickRight() { click(OFX_MOUSE_CONTROLLER_BUTTON_RIGHT); }
    
    // button down and up #
    static void buttonDown (const ofxMouseControllerButton button);
    static void buttonUp   (const ofxMouseControllerButton button);
    
    static inline void buttonDown()        { buttonDown(OFX_MOUSE_CONTROLLER_BUTTON_LEFT); }
    static inline void buttonUp()          { buttonUp(OFX_MOUSE_CONTROLLER_BUTTON_LEFT); }
    static inline void leftButtonDown()    { buttonDown(OFX_MOUSE_CONTROLLER_BUTTON_LEFT); }
    static inline void rightButtonDown()   { buttonDown(OFX_MOUSE_CONTROLLER_BUTTON_RIGHT);}
    static inline void leftButtonUp()      { buttonUp(OFX_MOUSE_CONTROLLER_BUTTON_LEFT); }
    static inline void rightButtonUp()     { buttonUp(OFX_MOUSE_CONTROLLER_BUTTON_RIGHT);}

};
