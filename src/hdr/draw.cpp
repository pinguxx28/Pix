#include "draw.hpp"

void draw::rectangle(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color, float thickness)
{
    if (thickness == 0) al_draw_filled_rectangle(x1, y1, x2, y2, color);
    else al_draw_rectangle(x1, y1, x2, y2, color, thickness);
}

void draw::triangle(float x1, float y1, float x2, float y2, float x3, float y3, ALLEGRO_COLOR color, float thickness)
{
    if (thickness == 0) al_draw_filled_triangle(x1, y1, x2, y2, x3, y3, color);
    else al_draw_triangle(x1, y1, x2, y2, x3, y3, color, thickness);
}
void draw::ellipse(float cx, float cy, float rx, float ry, ALLEGRO_COLOR color, float thickness)
{
    if (thickness == 0) al_draw_filled_ellipse(cx, cy, rx, ry, color);
    else al_draw_ellipse(cx, cy, rx, ry, color, thickness);
}
void draw::circle(float cx, float cy, float r, ALLEGRO_COLOR color, float thickness)
{
    if (thickness == 0) al_draw_filled_circle(cx, cy, r, color);
    else al_draw_circle(cx, cy, r, color, thickness);
}

void draw::texture64 (const bool textureMap[64], float x, float y, float w, float h, ALLEGRO_COLOR color)
{
    for (register u_char i = 0; i < 8; i++)
        for (register u_char j = 0; j < 8; j++)
            if (textureMap[i * 8 + j])
                al_draw_filled_rectangle(x + j * (w / 8), y + i * (w / 8), x + (j + 1) * (w / 8) , y + (i + 1) * (w / 8), color);
}
void draw::string(char *str, float x, float y, float w, float h, ALLEGRO_COLOR color)
{
    for (register u_char c = 0; c < strlen(str); c++)
        draw::texture64(font::font[font::index(str[c])], x + c * 8, y, w, h, color);
}
