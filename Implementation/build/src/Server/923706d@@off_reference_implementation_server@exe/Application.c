/* Application.c generated by valac 0.40.25, the Vala compiler
 * generated from Application.vala, do not modify */

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
#include <gtk/gtk.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>


#define OFF_TYPE_APPLICATION (off_application_get_type ())
#define OFF_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), OFF_TYPE_APPLICATION, OFFApplication))
#define OFF_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), OFF_TYPE_APPLICATION, OFFApplicationClass))
#define OFF_IS_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), OFF_TYPE_APPLICATION))
#define OFF_IS_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), OFF_TYPE_APPLICATION))
#define OFF_APPLICATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), OFF_TYPE_APPLICATION, OFFApplicationClass))

typedef struct _OFFApplication OFFApplication;
typedef struct _OFFApplicationClass OFFApplicationClass;
typedef struct _OFFApplicationPrivate OFFApplicationPrivate;

#define OFF_WIDGETS_TYPE_MAIN_WINDOW (off_widgets_main_window_get_type ())
#define OFF_WIDGETS_MAIN_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), OFF_WIDGETS_TYPE_MAIN_WINDOW, OFFWidgetsMainWindow))
#define OFF_WIDGETS_MAIN_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), OFF_WIDGETS_TYPE_MAIN_WINDOW, OFFWidgetsMainWindowClass))
#define OFF_WIDGETS_IS_MAIN_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), OFF_WIDGETS_TYPE_MAIN_WINDOW))
#define OFF_WIDGETS_IS_MAIN_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), OFF_WIDGETS_TYPE_MAIN_WINDOW))
#define OFF_WIDGETS_MAIN_WINDOW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), OFF_WIDGETS_TYPE_MAIN_WINDOW, OFFWidgetsMainWindowClass))

typedef struct _OFFWidgetsMainWindow OFFWidgetsMainWindow;
typedef struct _OFFWidgetsMainWindowClass OFFWidgetsMainWindowClass;
enum  {
	OFF_APPLICATION_0_PROPERTY,
	OFF_APPLICATION_NUM_PROPERTIES
};
static GParamSpec* off_application_properties[OFF_APPLICATION_NUM_PROPERTIES];
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _OFFApplication {
	GtkApplication parent_instance;
	OFFApplicationPrivate * priv;
};

struct _OFFApplicationClass {
	GtkApplicationClass parent_class;
};

struct _OFFApplicationPrivate {
	OFFWidgetsMainWindow* main_window;
};


static gpointer off_application_parent_class = NULL;
extern OFFApplication* off_application_instance;
OFFApplication* off_application_instance = NULL;

GType off_application_get_type (void) G_GNUC_CONST;
GType off_widgets_main_window_get_type (void) G_GNUC_CONST;
#define OFF_APPLICATION_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), OFF_TYPE_APPLICATION, OFFApplicationPrivate))
#define OFF_APPLICATION_VERSION "2021.03.03"
static void off_application_real_activate (GApplication* base);
OFFWidgetsMainWindow* off_widgets_main_window_new (GtkApplication* application);
OFFWidgetsMainWindow* off_widgets_main_window_construct (GType object_type,
                                                         GtkApplication* application);
gint off_application_main (gchar** args,
                           int args_length1);
OFFApplication* off_application_new (void);
OFFApplication* off_application_construct (GType object_type);
static GObject * off_application_constructor (GType type,
                                       guint n_construct_properties,
                                       GObjectConstructParam * construct_properties);
static void off_application_finalize (GObject * obj);


static void
off_application_real_activate (GApplication* base)
{
	OFFApplication * self;
	OFFWidgetsMainWindow* _tmp0_;
#line 36 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	self = (OFFApplication*) base;
#line 37 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	_tmp0_ = off_widgets_main_window_new ((GtkApplication*) self);
#line 37 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	g_object_ref_sink (_tmp0_);
#line 37 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	_g_object_unref0 (self->priv->main_window);
#line 37 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	self->priv->main_window = _tmp0_;
#line 110 "Application.c"
}


gint
off_application_main (gchar** args,
                      int args_length1)
{
	gint result = 0;
	OFFApplication* app = NULL;
	OFFApplication* _tmp0_;
#line 41 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	_tmp0_ = off_application_new ();
#line 41 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	app = _tmp0_;
#line 42 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	result = g_application_run ((GApplication*) app, args_length1, args);
#line 42 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	_g_object_unref0 (app);
#line 42 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	return result;
#line 131 "Application.c"
}


int
main (int argc,
      char ** argv)
{
#line 40 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	return off_application_main (argv, argc);
#line 141 "Application.c"
}


OFFApplication*
off_application_construct (GType object_type)
{
	OFFApplication * self = NULL;
#line 19 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	self = (OFFApplication*) g_object_new (object_type, NULL);
#line 19 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	return self;
#line 153 "Application.c"
}


OFFApplication*
off_application_new (void)
{
#line 19 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	return off_application_construct (OFF_TYPE_APPLICATION);
#line 162 "Application.c"
}


static gpointer
_g_object_ref0 (gpointer self)
{
#line 30 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	return self ? g_object_ref (self) : NULL;
#line 171 "Application.c"
}


static GObject *
off_application_constructor (GType type,
                             guint n_construct_properties,
                             GObjectConstructParam * construct_properties)
{
	GObject * obj;
	GObjectClass * parent_class;
	OFFApplication * self;
	OFFApplication* _tmp0_;
#line 26 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	parent_class = G_OBJECT_CLASS (off_application_parent_class);
#line 26 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
#line 26 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, OFF_TYPE_APPLICATION, OFFApplication);
#line 28 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	g_application_set_application_id ((GApplication*) self, "com.github.timecraft.off_reference_implementation_client");
#line 29 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	g_application_set_flags ((GApplication*) self, G_APPLICATION_FLAGS_NONE);
#line 30 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	_tmp0_ = _g_object_ref0 (self);
#line 30 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	_g_object_unref0 (off_application_instance);
#line 30 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	off_application_instance = _tmp0_;
#line 31 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	g_message ("Application.vala:31: Open File Format Reference Implementation.");
#line 32 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	g_message ("Application.vala:32: Implementing version %s", OFF_APPLICATION_VERSION);
#line 26 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	return obj;
#line 206 "Application.c"
}


static void
off_application_class_init (OFFApplicationClass * klass)
{
#line 19 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	off_application_parent_class = g_type_class_peek_parent (klass);
#line 19 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	g_type_class_add_private (klass, sizeof (OFFApplicationPrivate));
#line 19 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	((GApplicationClass *) klass)->activate = (void (*) (GApplication*)) off_application_real_activate;
#line 19 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	G_OBJECT_CLASS (klass)->constructor = off_application_constructor;
#line 19 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	G_OBJECT_CLASS (klass)->finalize = off_application_finalize;
#line 223 "Application.c"
}


static void
off_application_instance_init (OFFApplication * self)
{
#line 19 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	self->priv = OFF_APPLICATION_GET_PRIVATE (self);
#line 232 "Application.c"
}


static void
off_application_finalize (GObject * obj)
{
	OFFApplication * self;
#line 19 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, OFF_TYPE_APPLICATION, OFFApplication);
#line 23 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	_g_object_unref0 (self->priv->main_window);
#line 19 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/Application.vala"
	G_OBJECT_CLASS (off_application_parent_class)->finalize (obj);
#line 246 "Application.c"
}


GType
off_application_get_type (void)
{
	static volatile gsize off_application_type_id__volatile = 0;
	if (g_once_init_enter (&off_application_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (OFFApplicationClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) off_application_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (OFFApplication), 0, (GInstanceInitFunc) off_application_instance_init, NULL };
		GType off_application_type_id;
		off_application_type_id = g_type_register_static (gtk_application_get_type (), "OFFApplication", &g_define_type_info, 0);
		g_once_init_leave (&off_application_type_id__volatile, off_application_type_id);
	}
	return off_application_type_id__volatile;
}



