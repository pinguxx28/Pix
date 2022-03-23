#include "draw.hpp"

void draw::rectangle(u_char x, u_char y, ALLEGRO_COLOR color)
{
    al_draw_filled_rectangle(x, y, x + 8, y + 8, color);
}

void draw::texture64 (const bool textureMap[64], u_char x, u_char y, ALLEGRO_COLOR color)
{
    for (register u_char i = 0; i < 8; i++)
        for (register u_char j = 0; j < 8; j++)
            if (textureMap[i * 8 + j])
                al_draw_filled_rectangle(x + j, y + i, x + j + 1, y + i + 1, color);
}

void draw::string(char *str, u_char x, u_char y, ALLEGRO_COLOR color)
{
    for (register u_char c = 0; c < strlen(str); c++)
    {
        draw::texture64(font::font[font::index(str[c])], x + c * 8, y, color);
    }
}
