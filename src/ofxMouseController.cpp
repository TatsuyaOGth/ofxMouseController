#include "ofxMouseController.h"

string ofxMouseController::smModuleName("ofxMouseController");

// **************************************************************************** //
//                                  MAC                                         //
// **************************************************************************** //
#ifdef __APPLE__

/* 
 * README:
 * You need help? You must add CoreGraphics.framework to your project.
 */
#include <CoreGraphics/CGEvent.h>
#include <CoreGraphics/CGRemoteOperation.h>

void getEventType(const ofxMouseControllerButton button,
                  CGMouseButton & cgmousebutton,
                  CGEventType & cgeventtypedown,
                  CGEventType & cgeventtypeup,
                  string & log)
{
    switch (button) {
        case OFX_MOUSE_CONTROLLER_BUTTON_LEFT   :
            cgmousebutton = kCGMouseButtonLeft;
            cgeventtypedown = kCGEventLeftMouseDown;
            cgeventtypeup   = kCGEventLeftMouseUp;
            log = "left";
            break;
        case OFX_MOUSE_CONTROLLER_BUTTON_RIGHT  :
            cgmousebutton = kCGMouseButtonRight;
            cgeventtypedown = kCGEventRightMouseDown;
            cgeventtypeup   = kCGEventRightMouseUp;
            log = "right";
            break;
    }
}

void ofxMouseController::setPos(const int x, const int y)
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

void ofxMouseController::click(const ofxMouseControllerButton button)
{
    CGMouseButton cgbutton;
    CGEventType cgeventdown;
    CGEventType cgeventup;
    string log;
    getEventType(button, cgbutton, cgeventdown, cgeventup, log);
    CGPoint current_point = CGEventGetLocation(CGEventCreate(nil));
    
    // button down
    CGEventRef downEvent = CGEventCreateMouseEvent(NULL, cgeventdown, current_point, cgbutton);
    CGEventPost(kCGHIDEventTap, downEvent);
    
    // button up
    CGEventRef upEvent = CGEventCreateMouseEvent(NULL, cgeventup, current_point, cgbutton);
    CGEventPost(kCGHIDEventTap, upEvent);
    
    ofLogVerbose(smModuleName) << "perform mouse click " << log;
}

void ofxMouseController::buttonDown(const ofxMouseControllerButton button)
{
    CGMouseButton cgbutton;
    CGEventType cgeventdown;
    CGEventType cgeventup;
    string log;
    getEventType(button, cgbutton, cgeventdown, cgeventup, log);
    CGPoint current_point = CGEventGetLocation(CGEventCreate(nil));
    
    // button down
    CGEventRef downEvent = CGEventCreateMouseEvent(NULL, cgeventdown, current_point, cgbutton);
    CGEventPost(kCGHIDEventTap, downEvent);
}

void ofxMouseController::buttonUp(const ofxMouseControllerButton button)
{
    CGMouseButton cgbutton;
    CGEventType cgeventdown;
    CGEventType cgeventup;
    string log;
    getEventType(button, cgbutton, cgeventdown, cgeventup, log);
    CGPoint current_point = CGEventGetLocation(CGEventCreate(nil));
    
    // button up
    CGEventRef upEvent = CGEventCreateMouseEvent(NULL, cgeventup, current_point, cgbutton);
    CGEventPost(kCGHIDEventTap, upEvent);
}

// **************************************************************************** //
//                                  WIN32                                       //
// **************************************************************************** //
#elif defined _WIN32
#include <Windows.h>

void ofxMouseController::setPos(const int x, const int y)
{
    SetCursorPos(x, y);
}

void ofxMouseController::click(const ofxMouseControllerButton button)
{
    // sorry, It does not support yet.
}

void ofxMouseController::buttonDown(const ofxMouseControllerButton button)
{
    // sorry, It does not support yet.
}

void ofxMouseController::buttonUp(const ofxMouseControllerButton button)
{
    // sorry, It does not support yet.
}

#endif



