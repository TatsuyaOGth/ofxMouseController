#include "ofxMouseController.h"

#include "ofMain.h"
using namespace std;

// **************************************************************************** //
//                                  MAC                                         //
// **************************************************************************** //
#ifdef __APPLE__
#include <CoreGraphics/CGEvent.h>
#include <CoreGraphics/CGRemoteOperation.h>

void ofxMouseController::setMousePos(const int x, const int y)
{
    CGPoint point;
    point.x = (CGFloat)x;
    point.y = (CGFloat)y;
    CGMouseButton button = kCGMouseButtonLeft;
    CGEventType type = kCGEventMouseMoved;
    
    CGEventRef theEvent = CGEventCreateMouseEvent(NULL, type, point, button);
    CGEventSetType(theEvent, type);
    CGEventPost(kCGHIDEventTap, theEvent);
    
}

void ofxMouseController::setMouseButton(const ofxMouseControllerButton button)
{
    CGMouseButton cgbutton;
    switch (button) {
        case OFX_MOUSE_CONTROLLER_BUTTON_LEFT   : cgbutton = kCGMouseButtonLeft; break;
        case OFX_MOUSE_CONTROLLER_BUTTON_RIGHT  : cgbutton = kCGMouseButtonRight; break;
        case OFX_MOUSE_CONTROLLER_BUTTON_CENTER : cgbutton = kCGMouseButtonCenter; break;
        default: return;
    }
    CGEventType type = kCGMouseEventButtonNumber;
    
    CGPoint current_point = CGEventGetLocation(CGEventCreate(nil));
    CGEventRef theEvent = CGEventCreateMouseEvent(NULL, type, current_point, cgbutton);
    CGEventSetType(theEvent, type);
    CGEventPost(kCGHIDEventTap, theEvent);

}

// **************************************************************************** //
//                                  WIN32                                       //
// **************************************************************************** //
#elif defined __WIN32__
#include <Windows.h>

void ofxMouseController::setMousePos(const int x, const int y)
{
    SetCursorPos(x, y);
}

void setMouseButton(const ofxMouseControllerButton)
{
    
}

#endif



