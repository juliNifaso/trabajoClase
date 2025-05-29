//Drawing a Line:

// 1. Move to starting point
MoveToEx(hdc, startX, startY, NULL);

// 2. Draw to ending point
LineTo(hdc, endX, endY);

//    hdc: Your drawing surface handle

//    startX/Y, endX/Y: Coordinates in pixels

//Drawing a Rectangle:

// Outline rectangle (no fill)
Rectangle(hdc, left, top, right, bottom);

// Filled rectangle
HBRUSH brush = CreateSolidBrush(RGB(red, green, blue));  // Create color
FillRect(hdc, &RECT{left, top, right, bottom}, brush);   // Draw filled rect
DeleteObject(brush);  // Clean up memory

//    left/top/right/bottom: Rectangle boundaries

//    RGB(): Creates a color from red, green, blue values (0-255)

//Drawing Text:

SetTextColor(hdc, RGB(255, 0, 0));  // Red text
SetBkColor(hdc, RGB(0, 0, 0));      // Black background
TextOut(hdc, x, y, "Your text", strlen("Your text"));

3//. Where to Put Drawing Code

//All drawing should happen in the WM_PAINT message handler:

case WM_PAINT: {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);  // Get drawing surface

    // ----- YOUR DRAWING CODE GOES HERE -----
    Rectangle(hdc, 50, 50, 150, 150);  // Example rectangle

    EndPaint(hwnd, &ps);  // Release drawing surface
    return 0;
}



//Keyboard Input in Win32 Applications

//In Windows GUI apps, you handle keyboard input through window messages. Here's what you need to know:

//    The WM_KEYDOWN Message
//    Windows sends this message to your window when any key is pressed.

//    Accessing Key Information
//    In your window procedure:

//        wParam contains the virtual key code of the pressed key

//        lParam contains additional info (like repeat count)

//    Important Virtual Key Codes:

//VK_LEFT    // Left arrow key
//VK_RIGHT   // Right arrow key
//VK_UP      // Up arrow key
//VK_DOWN    // Down arrow key
//VK_RETURN  // Enter key

//Implementation Steps

//Here's exactly how to implement keyboard controls without writing the code for you:

//    Add a WM_KEYDOWN case to your window procedure:

case WM_KEYDOWN:
    // Handle key press here
    break;

//Check which key was pressed using a switch statement:

switch (wParam) {
    case VK_LEFT:
        // Handle left arrow
        break;
    case VK_RIGHT:
        // Handle right arrow
        break;
    // Add other keys...
}

//Update your game state when keys are pressed:

//    For arrow keys: Change your cursor/grid position variables

//    For Enter: Call your selection/reveal function

//Force a redraw after handling input:


InvalidateRect(hwnd, NULL, TRUE);

//In your drawing code (WM_PAINT):

//    Draw your grid based on current positions

//    Highlight the selected cell



//Core Concepts

//    Window Messages
//    Windows sends messages to your program for every event:

//        WM_KEYDOWN: A key was pressed

//        WM_PAINT: Your window needs to be drawn

//        WM_DESTROY: Window is closing
//        Your window procedure receives these and decides how to respond.

//    HDC (Handle to Device Context)
//    Think of this as your "drawing permission slip." You get it when you start drawing (BeginPaint) and return it when done (EndPaint). All drawing functions need this handle.

//Drawing Functions Explained

    MoveToEx(hdc, x, y, NULL)
//    Positions your "drawing cursor" at (x,y) without drawing anything.

//        NULL means we don't care about previous position

    LineTo(hdc, x, y)
//    Draws a straight line from current position to (x,y) using current pen

    Rectangle(hdc, left, top, right, bottom)
//    Draws outline of rectangle from top-left to bottom-right corners

//    Brushes (Filling Shapes)

    HBRUSH brush = CreateSolidBrush(RGB(r,g,b));  // Create paint bucket
    FillRect(hdc, &rect, brush);                 // Fill area with color
    DeleteObject(brush);                         // Clean up bucket

    SetTextColor(hdc, RGB(r,g,b))
//    Changes text color for future TextOut calls

    TextOut(hdc, x, y, "Text", length)
//    Draws text at (x,y). Top-left is anchor point.

// Painting Process

    PAINTSTRUCT ps
//    A diary Windows gives you about what needs repainting

    BeginPaint(hwnd, &ps)

//        Gets drawing permission (HDC)
//        Checks what areas need redrawing
//        Prepares clean canvas

//    Drawing Operations
//    Call your drawing functions here

    EndPaint(hwnd, &ps)

//        Returns drawing permission
//        Tells Windows "I'm done repainting"

//Keyboard Input Handling

    WM_KEYDOWN // Message
//    Sent to your window procedure when any key is pressed


//    Reading Keys
case WM_KEYDOWN:
    switch(wParam) {  // wParam contains key code
        case VK_LEFT:  // Left arrow
            moveLeft();
            break;
        case VK_RETURN:  // Enter key
            selectCell();
            break;
    }

//Virtual Key Codes
//Special names for keys:

    VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN

    VK_RETURN (Enter)

    VK_SPACE (Spacebar)

//Forcing Redraw
//After handling key:


    InvalidateRect(hwnd, NULL, TRUE);  // "Please redraw entire window"

//How Everything Works Together

//    Windows sends WM_PAINT → You draw game state

//    User presses key → Windows sends WM_KEYDOWN

//    You update game state (move cursor/reveal cell)

//    You request redraw with InvalidateRect

//    Windows sends WM_PAINT again → You draw updated state
