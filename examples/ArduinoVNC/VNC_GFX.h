#ifndef _VNC_GFX_H_
#define _VNC_GFX_H_

#include "Arduino_GFX_Library.h"
#include "VNC.h"
#include "VNC_config.h"

class VNC_GFX : public VNCdisplay
{
public:
    VNC_GFX(Arduino_GFX *gfx)
    {
        _gfx = gfx;
    }

    bool hasCopyRect(void)
    {
        return false;
    }

    uint32_t getHeight(void)
    {
        return _gfx->height();
    }
    uint32_t getWidth(void)
    {
        return _gfx->width();
    }

    void draw_area(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint8_t *data)
    {
        // DEBUG_VNC("draw_area(%d, %d, %d, %d, data)\n", x, y, w, h);
        _gfx->draw16bitBeRGBBitmap(x, y, (uint16_t *)data, w, h);
    }

    void draw_rect(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint16_t color)
    {
        // DEBUG_VNC("draw_rect(%d, %d, %d, %d, color)\n", x, y, w, h);
        MSB_16_SET(color, color);
        _gfx->fillRect(x, y, w, h, color);
    }

    void vnc_options_override(dfb_vnc_options * opt) {
        opt->client.bigendian = 1;
    }

private:
    Arduino_GFX *_gfx;
};

#endif /* _VNC_GFX_H_ */
