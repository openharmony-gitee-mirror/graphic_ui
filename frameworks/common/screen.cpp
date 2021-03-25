/*
 * Copyright (c) 2020-2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "common/screen.h"
#include "core/render_manager.h"
#include "dock/screen_device_proxy.h"
#include "draw/draw_utils.h"

namespace OHOS {
uint16_t Screen::GetWidth()
{
    return ScreenDeviceProxy::GetInstance()->GetScreenWidth();
}

uint16_t Screen::GetHeight()
{
    return ScreenDeviceProxy::GetInstance()->GetScreenHeight();
}

bool Screen::GetCurrentScreenBitmap(ImageInfo& info)
{
    uint16_t screenWidth = ScreenDeviceProxy::GetInstance()->GetScreenWidth();
    uint16_t screenHeight = ScreenDeviceProxy::GetInstance()->GetScreenHeight();
    info.data = ScreenDeviceProxy::GetInstance()->GetScreenBitmapBuffer();
    if (info.data == nullptr) {
        return false;
    }
    info.header.colorMode = ScreenDeviceProxy::GetInstance()->GetBufferMode();
    info.dataSize = screenWidth * screenHeight * DrawUtils::GetByteSizeByColorMode(info.header.colorMode);
    info.header.width = screenWidth;
    info.header.height = screenHeight;
    info.header.reserved = 0;
    info.header.compressMode = 0;
    return true;
}
} // namespace OHOS
