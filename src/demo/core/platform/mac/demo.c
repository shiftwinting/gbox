/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */ 
#include "../../demo.h"

/* //////////////////////////////////////////////////////////////////////////////////////
 * macros
 */

// the width
#define GB_DEMO_WIDTH           (640)

// the height
#define GB_DEMO_HEIGHT          (480)

/* //////////////////////////////////////////////////////////////////////////////////////
 * main
 */
tb_int_t main(tb_int_t argc, tb_char_t** argv)
{
    // init tbox
#if 0
    if (!tb_init(tb_null, (tb_byte_t*)malloc(300 * 1024 * 1024), 300 * 1024 * 1024)) return 0;
#else
    if (!tb_init(tb_null, tb_null, 0)) return 0;
#endif

    // init gbox
    if (!gb_init()) return 0;

    // init window info
    gb_window_info_t info = {0};
    info.title      = "demo";
    info.framerate  = gb_long_to_float(60);
    info.init       = gb_demo_init_func;
    info.exit       = gb_demo_exit_func;
    info.draw       = gb_demo_draw_func;
    info.resize     = gb_demo_resize_func;

    // init window
    gb_window_ref_t window = gb_window_init_glut(&info, GB_DEMO_WIDTH, GB_DEMO_HEIGHT);
    if (window)
    {
        // loop window
        gb_window_loop(window);

        // exit window
        gb_window_exit(window);
    }

    // exit gbox
    gb_exit();

    // exit tbox
    tb_exit();

    // ok?
    return 0;
}
