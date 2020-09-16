/* This entire file is licensed under MIT
 *
 * Copyright 2020 William Wold
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "test-client-common.h"

static GtkWindow* window;

static void set_anchors(GtkWindow* window, gboolean top, gboolean bottom, gboolean left, gboolean right)
{
    gtk_layer_set_anchor(window, GTK_LAYER_SHELL_EDGE_TOP, top);
    gtk_layer_set_anchor(window, GTK_LAYER_SHELL_EDGE_BOTTOM, bottom);
    gtk_layer_set_anchor(window, GTK_LAYER_SHELL_EDGE_LEFT, left);
    gtk_layer_set_anchor(window, GTK_LAYER_SHELL_EDGE_RIGHT, right);
}

static void callback_0()
{
    EXPECT_MESSAGE(zwlr_layer_surface_v1 .set_anchor 1);
    EXPECT_MESSAGE(zwlr_layer_surface_v1 .set_anchor 2);
    EXPECT_MESSAGE(zwlr_layer_surface_v1 .set_anchor 4);
    EXPECT_MESSAGE(zwlr_layer_surface_v1 .set_anchor 8);
    EXPECT_MESSAGE(zwlr_layer_surface_v1 .set_anchor 0);
    EXPECT_MESSAGE(zwlr_layer_surface_v1 .set_anchor 3);
    EXPECT_MESSAGE(zwlr_layer_surface_v1 .set_anchor 15);
    EXPECT_MESSAGE(zwlr_layer_surface_v1 .set_anchor 0);

    window = create_default_window();
    gtk_layer_init_for_window(window);
    gtk_widget_show_all(GTK_WIDGET(window));

    set_anchors(window, TRUE, FALSE, FALSE, FALSE);
    set_anchors(window, FALSE, TRUE, FALSE, FALSE);
    set_anchors(window, FALSE, FALSE, TRUE, FALSE);
    set_anchors(window, FALSE, FALSE, FALSE, TRUE);
    set_anchors(window, FALSE, FALSE, FALSE, FALSE);
    set_anchors(window, TRUE, TRUE, FALSE, FALSE);
    set_anchors(window, TRUE, FALSE, TRUE, TRUE);
    set_anchors(window, TRUE, TRUE, TRUE, TRUE);
    set_anchors(window, FALSE, FALSE, FALSE, FALSE);
}

TEST_CALLBACKS(
    callback_0,
)