#pragma once
#ifndef MOUSECURSOR_HPP
#define MOUSECURSOR_HPP

#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#ifdef SFML_SYSTEM_WINDOWS
#include <windows.h>
#elif defined(SFML_SYSTEM_LINUX)
#include <X11/cursorfont.h>
#include <X11/Xlib.h>
#else
#error This OS is not yet supported by the cursor library.
#endif


class MouseCursor
{
private:
#ifdef SFML_SYSTEM_WINDOWS

	HCURSOR Cursor; /*Type of the Cursor with Windows*/

#else

	XID Cursor;
	Display* display;

#endif
public:
	enum TYPE { WAIT, TEXT, NORMAL, HAND /*,...*/ };
	MouseCursor(const TYPE t);
	void set(const sf::WindowHandle& aWindowHandle) const;
	~MouseCursor();
};
#endif // MouseCursor_HPP

