#pragma once

enum ofxMouseControllerButton
{
    OFX_MOUSE_CONTROLLER_BUTTON_LEFT = 0,
    OFX_MOUSE_CONTROLLER_BUTTON_RIGHT,
    OFX_MOUSE_CONTROLLER_BUTTON_CENTER,
};

class ofxMouseController
{
public:
    void setMousePos(const int x, const int y);
    void setMouseButton(const ofxMouseControllerButton button);
};

