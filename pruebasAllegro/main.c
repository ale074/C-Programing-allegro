#include <allegro5/allegro.h>

int main()
{
    allegro_init();
   
set_color_depth(32);

set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);

    readkey();
   
return 0;
}
END_OF_MAIN()