#include "window.h"
#include "Events.h"

#include <windows.h>
#include <Windows.h>
#include <windowsx.h>
#include <WinUser.h>
#include <windowsx.h>
// Necessary for some wgl function pointers
#include <GL/wglew.h>

#define GLREN_WINDOW_WIDTH            1280
#define GLREN_WINDOW_HEIGHT           768

struct PlatformState
{
    HINSTANCE winInstance;
    HWND winWindow;

    // gl render context
    HGLRC hglrc;
};

inline uint8_t isRunning = 1;
uint8_t GetRunningState() { return isRunning; }
void SetRunningState(uint8_t set) { isRunning = set; }

inline unsigned int windowWidth = GLREN_WINDOW_WIDTH;
inline unsigned int windowHeight = GLREN_WINDOW_HEIGHT;

unsigned int GetWindowWidth() { return windowWidth; }
void SetWindowWidth(unsigned int width) { windowWidth = width; }

unsigned int GetWindowHeight() { return windowHeight; }
void SetWindowHeight(unsigned int height) { windowHeight = height; }

inline double deltaTime;
inline double elapsedTime = 0;
inline double inl_startTime;
inline double previousTime;

double GetDeltaTime() {return deltaTime; }
void ClockSet() { inl_startTime = PlatformGetAbsoluteTime(); }

void UpdateTime()
{
    elapsedTime = PlatformGetAbsoluteTime() - inl_startTime;
    deltaTime = elapsedTime - previousTime;
    previousTime = elapsedTime;
}

inline PlatformState s_pPlatformState;

inline double clockFrequency;
inline LARGE_INTEGER startTime;

LRESULT CALLBACK Win32ProcessMessage(HWND winWindow, uint32_t msg, WPARAM w_param, LPARAM l_param);

size_t GetPlatformMemoryRequirements()
{
    return sizeof(PlatformState);
}

uint8_t PlatformStartup(const char* appName, int32_t x, int32_t y, uint32_t width, uint32_t height)
{
    s_pPlatformState.winInstance = GetModuleHandleA(0);

    HICON icon = LoadIcon(s_pPlatformState.winInstance, IDI_APPLICATION);
    tagWNDCLASSA wc;
    memset(&wc, 0, sizeof(wc));
    wc.style = CS_DBLCLKS;
    // Pass the function that will get called when events get triggered
    wc.lpfnWndProc = Win32ProcessMessage;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = s_pPlatformState.winInstance;
    wc.hIcon = icon;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = nullptr;

    // !This must be the exact same as the 2nd parameter of CreateWindowExA
    wc.lpszClassName = "BlitzenWindowClass";

    if(!RegisterClassA(&wc))
    {
        MessageBoxA(s_pPlatformState.winWindow, "Window registration failed", "Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Set the window's client size
    uint32_t clientX = x;
    uint32_t clientY = y;
    uint32_t clientWidth = width;
    uint32_t clientHeight = height;

    // Set the size of the window to be the same as the client momentarily
    uint32_t windowX = clientX;
    uint32_t windowY = clientY;
    uint32_t windowWidth = clientWidth;
    uint32_t windowHeight = clientHeight;

    uint32_t windowStyle = WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION;
    uint32_t windowExStyle = WS_EX_APPWINDOW;

    windowStyle |= WS_MAXIMIZEBOX;
    windowStyle |= WS_MINIMIZEBOX;
    windowStyle |= WS_THICKFRAME;

    RECT borderRect = {0, 0, 0, 0};
    AdjustWindowRectEx(&borderRect, windowStyle, 0, windowExStyle);

    // Set the true size of the window
    windowX += borderRect.left;
    windowY += borderRect.top;
    windowWidth += borderRect.right - borderRect.left;
    windowHeight -= borderRect.top - borderRect.bottom;

    //Create the window
    HWND handle = CreateWindowExA(windowExStyle, "BlitzenWindowClass", appName, windowStyle, windowX, windowY, windowWidth, windowHeight, 0, 0,
    s_pPlatformState.winInstance, 0);

    // Only assign the handle if it was actually created, otherwise the application should fail
    if(!handle)
    {
        MessageBoxA(nullptr, "Window creation failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }
    else
    {
        s_pPlatformState.winWindow = handle;
    }

    //Tell the window to show
    uint8_t shouldActivate = 1;
    int32_t show = shouldActivate ? SW_SHOW : SW_SHOWNOACTIVATE;
    ShowWindow(s_pPlatformState.winWindow, show);

    // Clock setup, similar thing to glfwGetTime
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);
    clockFrequency = 1.0 / static_cast<double>(frequency.QuadPart);// The quad part is just a 64 bit integer
    QueryPerformanceCounter(&startTime);

    return 1;
}

uint8_t PlatformPumpMessages()
{
    MSG message;
    while(PeekMessageA(&message, nullptr, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    return 1;
}

void PlatformShutdown()
{
    // Delete the gl render context
    if(s_pPlatformState.hglrc)
    {
        wglDeleteContext(s_pPlatformState.hglrc);
    }

    if(s_pPlatformState.winWindow)
    {
        DestroyWindow(s_pPlatformState.winWindow);
    }
}

double PlatformGetAbsoluteTime()
{
    LARGE_INTEGER nowTime;
    QueryPerformanceCounter(&nowTime);
    return static_cast<double>(nowTime.QuadPart) * clockFrequency;
}

void PlatformSleep(uint64_t ms)
{
    Sleep(static_cast<DWORD>(ms));
}

uint8_t CreateOpenglDrawContext()
{
    // Get the device context of the window
    HDC hdc = GetDC(s_pPlatformState.winWindow);

    // Pixel format
    PIXELFORMATDESCRIPTOR pfd;
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_SUPPORT_COMPOSITION | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cAlphaBits = 8;
    pfd.iLayerType = PFD_MAIN_PLANE;

    // Setup a dummy pixel format 
    int formatIndex = ChoosePixelFormat(hdc, &pfd);
    if(!formatIndex)
    {
        return 0;
    }
    if(!SetPixelFormat(hdc, formatIndex, &pfd))
    {
        return 0;
    }
    if (!DescribePixelFormat(hdc, formatIndex, sizeof(pfd), &pfd))
    {
        return 0;
    }

    if ((pfd.dwFlags & PFD_SUPPORT_OPENGL) != PFD_SUPPORT_OPENGL)
    {
        return 0;
    }

    // Create the dummy render context
    s_pPlatformState.hglrc = wglCreateContext(hdc);

    // Make this the current context so that glew can be initialized
    if(!wglMakeCurrent(hdc, s_pPlatformState.hglrc))
    {
        return 0;
    }

    // Initializes glew
    if (glewInit() != GLEW_OK)
    {
        return 0;
    }

    // With glew now available, extension function pointers can be accessed and a better gl context can be retrieved
    // So the old render context is deleted and the device is released
    wglDeleteContext(s_pPlatformState.hglrc);
    ReleaseDC(s_pPlatformState.winWindow, hdc);

    // Get a new device context
    hdc = GetDC(s_pPlatformState.winWindow);

    // Choose a pixel format with attributes
    const int attribList[] =
    {
        WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
        WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
        WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
        WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
        WGL_COLOR_BITS_ARB, 32,
        WGL_DEPTH_BITS_ARB, 24,
        WGL_STENCIL_BITS_ARB, 8,
        0, // End
    };
    int pixelFormat;
    UINT numFormats;
    wglChoosePixelFormatARB(hdc, attribList, NULL, 1, &pixelFormat, &numFormats);

    // Set the pixel format
    PIXELFORMATDESCRIPTOR pixelFormatDesc = {};
    DescribePixelFormat(hdc, pixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pixelFormatDesc);
    SetPixelFormat(hdc, pixelFormat, &pixelFormatDesc);

    // Create a new render context with attributes (latest opengl version)
    int const createAttribs[] = {WGL_CONTEXT_MAJOR_VERSION_ARB, 4, WGL_CONTEXT_MINOR_VERSION_ARB,  6,
    WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB, 0};
    s_pPlatformState.hglrc = wglCreateContextAttribsARB(hdc, 0, createAttribs);

    // Set the gl render context as the new one
    return (wglMakeCurrent(hdc, s_pPlatformState.hglrc));
}

void OpenglSwapBuffers()
{
    wglSwapIntervalEXT(0);
    wglSwapLayerBuffers(GetDC(s_pPlatformState.winWindow), WGL_SWAP_MAIN_PLANE);
}

LRESULT CALLBACK Win32ProcessMessage(HWND winWindow, uint32_t msg, WPARAM w_param, LPARAM l_param)
{
    switch(msg)
    {
        case WM_ERASEBKGND:
        {
            // Notify the OS that erasing will be handled by the application to prevent flicker
            return 1;
        }

        case WM_CLOSE:
        {
            EventContext context{};
            FireEvent(BlitEventType::EngineShutdown, nullptr, context);
            return 1;
        }

        case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
        }
        case WM_SIZE:
        {
            // Get the updated size.
            RECT rect;
            GetClientRect(winWindow, &rect);
            uint32_t width = rect.right - rect.left;
            uint32_t height = rect.bottom - rect.top;

            windowWidth = width;
            windowHeight = height;

            EventContext context;
            context.data.ui32[0] = width;
            context.data.ui32[1] = height;
            FireEvent(BlitEventType::WindowResize, nullptr, context);
            break;
        }
        case WM_KEYDOWN:
        case WM_SYSKEYDOWN:
        case WM_KEYUP:
        case WM_SYSKEYUP: 
        {
            // Key pressed/released
            uint8_t pressed = (msg == WM_KEYDOWN || msg == WM_SYSKEYDOWN);
            BlitKey key = static_cast<BlitKey>(w_param);
            InputProcessKey(key, pressed);
            break;
        } 
        case WM_MOUSEMOVE: 
        {
            // Mouse move
            int32_t mouseX = GET_X_LPARAM(l_param);
            int32_t mouseY = GET_Y_LPARAM(l_param);
            InputProcessMouseMove(mouseX, mouseY);
            break;
        } 
        case WM_MOUSEWHEEL: 
        {
            int32_t zDelta = GET_WHEEL_DELTA_WPARAM(w_param);
            if (zDelta != 0) 
            {
                // Flatten the input to an OS-independent (-1, 1)
                zDelta = (zDelta < 0) ? -1 : 1;
                InputProcessMouseWheel(zDelta);
                break;
            }
        }
        case WM_LBUTTONDOWN:
        case WM_MBUTTONDOWN:
        case WM_RBUTTONDOWN:
        case WM_LBUTTONUP:
        case WM_MBUTTONUP:
        case WM_RBUTTONUP: 
        {
            uint8_t bPressed = (msg == WM_LBUTTONDOWN || msg == WM_RBUTTONDOWN || msg == WM_MBUTTONDOWN);
            MouseButton button = MouseButton::MaxButtons;
            switch(msg)
            {
                case WM_LBUTTONDOWN:
                case WM_LBUTTONUP:
                {
                    button = MouseButton::Left;
                    break;
                }
                case WM_RBUTTONDOWN:
                case WM_RBUTTONUP:
                {
                    button = MouseButton::Right;
                    break;
                }
                case WM_MBUTTONDOWN:
                case WM_MBUTTONUP:
                {
                    button = MouseButton::Middle;
                    break;
                }
            }
            if(button != MouseButton::MaxButtons)
                InputProcessButton(button, bPressed);
            break;
        } 
    }
    // For any events that were not included above, windows can go ahead and handle them like it normally would
    return DefWindowProcA(winWindow, msg, w_param, l_param); 
}