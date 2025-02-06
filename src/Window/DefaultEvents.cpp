#include "Events.h"
#include "window.h"
#include "Camera/camera.h"

void RegisterDefaultEvents()
{
    RegisterEvent(BlitEventType::EngineShutdown, nullptr, OnEvent);
    RegisterEvent(BlitEventType::KeyPressed, nullptr, OnKeyPress);
    RegisterEvent(BlitEventType::KeyReleased, nullptr, OnKeyPress);
    RegisterEvent(BlitEventType::WindowResize, nullptr, OnResize);
    RegisterEvent(BlitEventType::MouseMoved, nullptr, OnMouseMove);
}

uint8_t OnEvent(BlitEventType eventType, void* pSender, void* pListener, EventContext data)
{
    if(eventType == BlitEventType::EngineShutdown)
    {
        SetRunningState(0);
        return 1; 
    }

    return 0;
}

uint8_t OnKeyPress(BlitEventType eventType, void* pSender, void* pListener, EventContext data)
{
    //Get the key pressed from the event context
    BlitKey key = static_cast<BlitKey>(data.data.ui16[0]);

    if(eventType == BlitEventType::KeyPressed)
    {
        switch(key)
        {
            case BlitKey::__ESCAPE:
            {
                EventContext newContext = {};
                FireEvent(BlitEventType::EngineShutdown, nullptr, newContext);
                return 1;
            }
            // The four keys below control basic camera movement. They set a velocity and tell it that it should be updated based on that velocity
            case BlitKey::__W:
            {
                Camera* pCamera = Camera::GetCamera();
                pCamera->movement = CameraMovement::Forward;
                break;
            }
            case BlitKey::__S:
            {
                Camera* pCamera = Camera::GetCamera();
                pCamera->movement = CameraMovement::Backward;
                break;
            }
            case BlitKey::__A:
            {
                Camera* pCamera = Camera::GetCamera();
                pCamera->movement = CameraMovement::Left;
                break;
            }
            case BlitKey::__D:
            {
                Camera* pCamera = Camera::GetCamera();
                pCamera->movement = CameraMovement::Right;
                break;
            }
            default:
            {
                return 1;
            }
        }
    }
    else if (eventType == BlitEventType::KeyReleased)
    {
        switch (key)
        {
            case BlitKey::__W:
            case BlitKey::__S:
            case BlitKey::__A:
            case BlitKey::__D:
            {
                Camera* pCamera = Camera::GetCamera();
                pCamera->movement = CameraMovement::None;
                break;
            }
            default:
            {
                break;
            }
        }
    }
    return 0;
}

uint8_t OnResize(BlitEventType eventType, void* pSender, void* pListener, EventContext data)
{
    uint32_t newWidth = data.data.ui32[0];
    uint32_t newHeight = data.data.ui32[1];

    glViewport(0, 0, newWidth, newHeight);
    Camera::GetCamera()->UpdatePerspective();

    return 1;
}

uint8_t OnMouseMove(BlitEventType eventType, void* pSender, void* pListener, EventContext data)
{
    Camera& camera = *(Camera::GetCamera());
    float deltaTime = static_cast<float>(GetDeltaTime());

    
    camera.Rotate(data.data.si16[0], data.data.si16[1]);

    return 1;
}