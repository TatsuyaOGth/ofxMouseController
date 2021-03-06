/**
 ofxMouseController.cpp https://github.com/TatsuyaOGth/ofxMouseController
 
 Copyright (c) 2014 TatsuyaOGth http://ogsn.org
 
 This software is released under the MIT License.
 http://opensource.org/licenses/mit-license.php
 */
#include "ofxMouseController.h"

// **************************************************************************** //
//                                  MAC                                         //
// **************************************************************************** //
#ifdef __APPLE__

/* 
 * README:
 * You need help? You must add CoreGraphics.framework to your xcode project.
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

void ofxMouseController::setPos(const float x, const float y)
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
	buttonDown(button);
	buttonUp(button);
}

void ofxMouseController::buttonDown(const ofxMouseControllerButton button)
{
    switch (button) {
	case OFX_MOUSE_CONTROLLER_BUTTON_LEFT:
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		break;
	case OFX_MOUSE_CONTROLLER_BUTTON_RIGHT:
		mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
		break;
	}
}

void ofxMouseController::buttonUp(const ofxMouseControllerButton button)
{
    switch (button) {
	case OFX_MOUSE_CONTROLLER_BUTTON_LEFT:
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		break;
	case OFX_MOUSE_CONTROLLER_BUTTON_RIGHT:
		mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
		break;
	}    
}

// **************************************************************************** //
//                                  WIN32                                       //
// **************************************************************************** //
#elif defined __linux__

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>

void ofxMouseController::setPos(const float x, const float y)
{
    Display *display = XOpenDisplay(0);
    XTestFakeMotionEvent(display,0,x,y,2); //set pos relative to screen
    //XWarpPointer(display, None, None, 0, 0, 0, 0, x, y); //moove the cursor with a certain amount of pixels
    XCloseDisplay(display);
}

void ofxMouseController::click(const ofxMouseControllerButton button)
{
	buttonDown(button);
	buttonUp(button);
}

void ofxMouseController::buttonDown(const ofxMouseControllerButton button)
{
    Display *display = XOpenDisplay(0);
    switch (button) {
	case OFX_MOUSE_CONTROLLER_BUTTON_LEFT:
		XTestFakeButtonEvent(display,1,true,0);
		break;
	case OFX_MOUSE_CONTROLLER_BUTTON_RIGHT:
		XTestFakeButtonEvent(display,3,true,0);
		break;
    }
    XCloseDisplay(display);
}

void ofxMouseController::buttonUp(const ofxMouseControllerButton button)
{
    Display *display = XOpenDisplay(0);
    switch (button) {
	case OFX_MOUSE_CONTROLLER_BUTTON_LEFT:
		XTestFakeButtonEvent(display,1,false,0);
		break;
	case OFX_MOUSE_CONTROLLER_BUTTON_RIGHT:
		XTestFakeButtonEvent(display,3,false,0);
		break;
    }
    XCloseDisplay(display);
}

#endif



