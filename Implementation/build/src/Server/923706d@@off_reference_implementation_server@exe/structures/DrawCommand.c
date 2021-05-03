/* DrawCommand.c generated by valac 0.40.25, the Vala compiler
 * generated from DrawCommand.vala, do not modify */

/*


    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/


#include <glib.h>
#include <glib-object.h>
#include <float.h>
#include <math.h>
#include <cairo.h>


#define OFF_STRUCTURES_TYPE_DRAW_COMMAND (off_structures_draw_command_get_type ())
#define OFF_STRUCTURES_DRAW_COMMAND(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), OFF_STRUCTURES_TYPE_DRAW_COMMAND, OFFStructuresDrawCommand))
#define OFF_STRUCTURES_DRAW_COMMAND_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), OFF_STRUCTURES_TYPE_DRAW_COMMAND, OFFStructuresDrawCommandClass))
#define OFF_STRUCTURES_IS_DRAW_COMMAND(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), OFF_STRUCTURES_TYPE_DRAW_COMMAND))
#define OFF_STRUCTURES_IS_DRAW_COMMAND_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), OFF_STRUCTURES_TYPE_DRAW_COMMAND))
#define OFF_STRUCTURES_DRAW_COMMAND_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), OFF_STRUCTURES_TYPE_DRAW_COMMAND, OFFStructuresDrawCommandClass))

typedef struct _OFFStructuresDrawCommand OFFStructuresDrawCommand;
typedef struct _OFFStructuresDrawCommandClass OFFStructuresDrawCommandClass;
typedef struct _OFFStructuresDrawCommandPrivate OFFStructuresDrawCommandPrivate;
enum  {
	OFF_STRUCTURES_DRAW_COMMAND_0_PROPERTY,
	OFF_STRUCTURES_DRAW_COMMAND_NUM_PROPERTIES
};
static GParamSpec* off_structures_draw_command_properties[OFF_STRUCTURES_DRAW_COMMAND_NUM_PROPERTIES];

struct _OFFStructuresDrawCommand {
	GObject parent_instance;
	OFFStructuresDrawCommandPrivate * priv;
};

struct _OFFStructuresDrawCommandClass {
	GObjectClass parent_class;
};

struct _OFFStructuresDrawCommandPrivate {
	gdouble red;
	gdouble green;
	gdouble blue;
	gint pixels;
};


static gpointer off_structures_draw_command_parent_class = NULL;
extern gint off_structures_draw_command_total_pixels;
gint off_structures_draw_command_total_pixels = 0;

GType off_structures_draw_command_get_type (void) G_GNUC_CONST;
#define OFF_STRUCTURES_DRAW_COMMAND_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), OFF_STRUCTURES_TYPE_DRAW_COMMAND, OFFStructuresDrawCommandPrivate))
OFFStructuresDrawCommand* off_structures_draw_command_new (gdouble red,
                                                           gdouble green,
                                                           gdouble blue,
                                                           gint pixels);
OFFStructuresDrawCommand* off_structures_draw_command_construct (GType object_type,
                                                                 gdouble red,
                                                                 gdouble green,
                                                                 gdouble blue,
                                                                 gint pixels);
void off_structures_draw_command_draw (OFFStructuresDrawCommand* self,
                                       cairo_t* context,
                                       gdouble* x_coord,
                                       gdouble* y_coord,
                                       gint width);
static void off_structures_draw_command_finalize (GObject * obj);


OFFStructuresDrawCommand*
off_structures_draw_command_construct (GType object_type,
                                       gdouble red,
                                       gdouble green,
                                       gdouble blue,
                                       gint pixels)
{
	OFFStructuresDrawCommand * self = NULL;
	gint _tmp0_;
#line 26 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
	self = (OFFStructuresDrawCommand*) g_object_new (object_type, NULL);
#line 27 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
	self->priv->red = red;
#line 28 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
	self->priv->green = green;
#line 29 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
	self->priv->blue = blue;
#line 30 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
	self->priv->pixels = pixels;
#line 31 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
	_tmp0_ = self->priv->pixels;
#line 31 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
	g_message ("DrawCommand.vala:31: Pixels: %d", _tmp0_);
#line 26 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
	return self;
#line 112 "DrawCommand.c"
}


OFFStructuresDrawCommand*
off_structures_draw_command_new (gdouble red,
                                 gdouble green,
                                 gdouble blue,
                                 gint pixels)
{
#line 26 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
	return off_structures_draw_command_construct (OFF_STRUCTURES_TYPE_DRAW_COMMAND, red, green, blue, pixels);
#line 124 "DrawCommand.c"
}


void
off_structures_draw_command_draw (OFFStructuresDrawCommand* self,
                                  cairo_t* context,
                                  gdouble* x_coord,
                                  gdouble* y_coord,
                                  gint width)
{
	gint _tmp0_;
#line 35 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
	g_return_if_fail (self != NULL);
#line 35 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
	g_return_if_fail (context != NULL);
#line 39 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
	_tmp0_ = self->priv->pixels;
#line 39 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
	if (_tmp0_ > 0) {
#line 144 "DrawCommand.c"
		gdouble _tmp1_;
		gdouble _tmp2_;
		gdouble _tmp3_;
		gint temp_pixels = 0;
		gint _tmp4_;
		gint _tmp5_;
		gint _tmp6_;
		gint _tmp11_;
		gint _tmp12_;
#line 41 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
		cairo_set_line_width (context, (gdouble) 1);
#line 42 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
		cairo_move_to (context, *x_coord, *y_coord);
#line 43 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
		_tmp1_ = self->priv->red;
#line 43 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
		_tmp2_ = self->priv->green;
#line 43 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
		_tmp3_ = self->priv->blue;
#line 43 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
		cairo_set_source_rgb (context, _tmp1_, _tmp2_, _tmp3_);
#line 44 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
		_tmp4_ = self->priv->pixels;
#line 44 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
		temp_pixels = _tmp4_;
#line 45 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
		_tmp5_ = off_structures_draw_command_total_pixels;
#line 45 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
		_tmp6_ = self->priv->pixels;
#line 45 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
		off_structures_draw_command_total_pixels = _tmp5_ + _tmp6_;
#line 49 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
		while (TRUE) {
#line 178 "DrawCommand.c"
			gint _tmp7_;
			gdouble _tmp10_;
#line 49 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
			_tmp7_ = temp_pixels;
#line 49 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
			if (!(((*x_coord) + _tmp7_) >= ((gdouble) width))) {
#line 49 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
				break;
#line 187 "DrawCommand.c"
			}
#line 51 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
			cairo_move_to (context, *x_coord, *y_coord);
#line 52 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
			cairo_line_to (context, (gdouble) width, *y_coord);
#line 55 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
			if ((*x_coord) != ((gdouble) 0)) {
#line 195 "DrawCommand.c"
				gint _tmp8_;
#line 57 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
				_tmp8_ = temp_pixels;
#line 57 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
				temp_pixels = _tmp8_ - (width - ((gint) (*x_coord)));
#line 58 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
				*x_coord = (gdouble) 0;
#line 203 "DrawCommand.c"
			} else {
				gint _tmp9_;
#line 62 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
				_tmp9_ = temp_pixels;
#line 62 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
				temp_pixels = _tmp9_ - width;
#line 63 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
				*x_coord = (gdouble) 0;
#line 212 "DrawCommand.c"
			}
#line 66 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
			_tmp10_ = *y_coord;
#line 66 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
			*y_coord = _tmp10_ + 1;
#line 218 "DrawCommand.c"
		}
#line 68 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
		cairo_move_to (context, *x_coord, *y_coord);
#line 70 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
		_tmp11_ = temp_pixels;
#line 70 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
		cairo_line_to (context, (*x_coord) + _tmp11_, *y_coord);
#line 72 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
		_tmp12_ = temp_pixels;
#line 72 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
		*x_coord = (*x_coord) + _tmp12_;
#line 74 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
		if ((*x_coord) >= ((gdouble) width)) {
#line 232 "DrawCommand.c"
			gdouble _tmp13_;
#line 75 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
			_tmp13_ = *y_coord;
#line 75 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
			*y_coord = _tmp13_ + 1;
#line 76 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
			*x_coord = (gdouble) 0;
#line 240 "DrawCommand.c"
		}
#line 79 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
		cairo_stroke (context);
#line 244 "DrawCommand.c"
	}
}


static void
off_structures_draw_command_class_init (OFFStructuresDrawCommandClass * klass)
{
#line 19 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
	off_structures_draw_command_parent_class = g_type_class_peek_parent (klass);
#line 19 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
	g_type_class_add_private (klass, sizeof (OFFStructuresDrawCommandPrivate));
#line 19 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
	G_OBJECT_CLASS (klass)->finalize = off_structures_draw_command_finalize;
#line 258 "DrawCommand.c"
}


static void
off_structures_draw_command_instance_init (OFFStructuresDrawCommand * self)
{
#line 19 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
	self->priv = OFF_STRUCTURES_DRAW_COMMAND_GET_PRIVATE (self);
#line 267 "DrawCommand.c"
}


static void
off_structures_draw_command_finalize (GObject * obj)
{
	OFFStructuresDrawCommand * self;
#line 19 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, OFF_STRUCTURES_TYPE_DRAW_COMMAND, OFFStructuresDrawCommand);
#line 19 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/DrawCommand.vala"
	G_OBJECT_CLASS (off_structures_draw_command_parent_class)->finalize (obj);
#line 279 "DrawCommand.c"
}


GType
off_structures_draw_command_get_type (void)
{
	static volatile gsize off_structures_draw_command_type_id__volatile = 0;
	if (g_once_init_enter (&off_structures_draw_command_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (OFFStructuresDrawCommandClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) off_structures_draw_command_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (OFFStructuresDrawCommand), 0, (GInstanceInitFunc) off_structures_draw_command_instance_init, NULL };
		GType off_structures_draw_command_type_id;
		off_structures_draw_command_type_id = g_type_register_static (G_TYPE_OBJECT, "OFFStructuresDrawCommand", &g_define_type_info, 0);
		g_once_init_leave (&off_structures_draw_command_type_id__volatile, off_structures_draw_command_type_id);
	}
	return off_structures_draw_command_type_id__volatile;
}



