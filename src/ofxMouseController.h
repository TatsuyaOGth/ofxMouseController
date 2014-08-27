/**
 ofxMouseController.h https://github.com/TatsuyaOGth/ofxMouseController
 
 Copyright (c) 2014 TatsuyaOGth http://ogsn.org
 
 This software is released under the MIT License.
 http://opensource.org/licenses/mit-license.php
 */
#pragma once

#include "ofMain.h"

enum ofxMouseControllerButton
{
    OFX_MOUSE_CONTROLLER_BUTTON_LEFT    = 0,
    OFX_MOUSE_CONTROLLER_BUTTON_RIGHT   = 1,
};

class ofxMouseController
{
    static string smModuleName;
    
public:
    
    // move position
    void        setPos(const int x, const int y);
    inline void setPos(const ofPoint pos) { setPos(pos.x, pos.y); }
    
    // button
    void        click(const ofxMouseControllerButton button);
    
    inline void click()      { click(OFX_MOUSE_CONTROLLER_BUTTON_LEFT); }
    inline void clickLeft()  { click(OFX_MOUSE_CONTROLLER_BUTTON_LEFT); }
    inline void clickRight() { click(OFX_MOUSE_CONTROLLER_BUTTON_RIGHT); }
    
    // button down and up #
    void buttonDown (const ofxMouseControllerButton button);
    void buttonUp   (const ofxMouseControllerButton button);
    
    inline void buttonDown()        { buttonDown(OFX_MOUSE_CONTROLLER_BUTTON_LEFT); }
    inline void buttonUp()          { buttonUp(OFX_MOUSE_CONTROLLER_BUTTON_LEFT); }
    inline void leftButtonDown()    { buttonDown(OFX_MOUSE_CONTROLLER_BUTTON_LEFT); }
    inline void rightButtonDown()   { buttonDown(OFX_MOUSE_CONTROLLER_BUTTON_RIGHT);}
    inline void leftButtonUp()      { buttonUp(OFX_MOUSE_CONTROLLER_BUTTON_LEFT); }
    inline void rightButtonUp()     { buttonUp(OFX_MOUSE_CONTROLLER_BUTTON_RIGHT);}
    
};
