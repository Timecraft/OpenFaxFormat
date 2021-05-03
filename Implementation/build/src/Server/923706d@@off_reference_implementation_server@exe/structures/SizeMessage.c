/* SizeMessage.c generated by valac 0.40.25, the Vala compiler
 * generated from SizeMessage.vala, do not modify */

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
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>


#define OFF_STRUCTURES_TYPE_MESSAGE (off_structures_message_get_type ())
#define OFF_STRUCTURES_MESSAGE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), OFF_STRUCTURES_TYPE_MESSAGE, OFFStructuresMessage))
#define OFF_STRUCTURES_IS_MESSAGE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), OFF_STRUCTURES_TYPE_MESSAGE))
#define OFF_STRUCTURES_MESSAGE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), OFF_STRUCTURES_TYPE_MESSAGE, OFFStructuresMessageIface))

typedef struct _OFFStructuresMessage OFFStructuresMessage;
typedef struct _OFFStructuresMessageIface OFFStructuresMessageIface;

#define OFF_STRUCTURES_TYPE_SIZE_MESSAGE (off_structures_size_message_get_type ())
#define OFF_STRUCTURES_SIZE_MESSAGE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), OFF_STRUCTURES_TYPE_SIZE_MESSAGE, OFFStructuresSizeMessage))
#define OFF_STRUCTURES_SIZE_MESSAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), OFF_STRUCTURES_TYPE_SIZE_MESSAGE, OFFStructuresSizeMessageClass))
#define OFF_STRUCTURES_IS_SIZE_MESSAGE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), OFF_STRUCTURES_TYPE_SIZE_MESSAGE))
#define OFF_STRUCTURES_IS_SIZE_MESSAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), OFF_STRUCTURES_TYPE_SIZE_MESSAGE))
#define OFF_STRUCTURES_SIZE_MESSAGE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), OFF_STRUCTURES_TYPE_SIZE_MESSAGE, OFFStructuresSizeMessageClass))

typedef struct _OFFStructuresSizeMessage OFFStructuresSizeMessage;
typedef struct _OFFStructuresSizeMessageClass OFFStructuresSizeMessageClass;
typedef struct _OFFStructuresSizeMessagePrivate OFFStructuresSizeMessagePrivate;
enum  {
	OFF_STRUCTURES_SIZE_MESSAGE_0_PROPERTY,
	OFF_STRUCTURES_SIZE_MESSAGE_NUM_PROPERTIES
};
static GParamSpec* off_structures_size_message_properties[OFF_STRUCTURES_SIZE_MESSAGE_NUM_PROPERTIES];
#define _g_free0(var) (var = (g_free (var), NULL))

struct _OFFStructuresMessageIface {
	GTypeInterface parent_iface;
	gchar* (*generate_message) (OFFStructuresMessage* self);
};

struct _OFFStructuresSizeMessage {
	GObject parent_instance;
	OFFStructuresSizeMessagePrivate * priv;
	gboolean did_send;
};

struct _OFFStructuresSizeMessageClass {
	GObjectClass parent_class;
};

struct _OFFStructuresSizeMessagePrivate {
	gdouble width_height;
};


static gpointer off_structures_size_message_parent_class = NULL;
static OFFStructuresMessageIface * off_structures_size_message_off_structures_message_parent_iface = NULL;

GType off_structures_message_get_type (void) G_GNUC_CONST;
GType off_structures_size_message_get_type (void) G_GNUC_CONST;
#define OFF_STRUCTURES_SIZE_MESSAGE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), OFF_STRUCTURES_TYPE_SIZE_MESSAGE, OFFStructuresSizeMessagePrivate))
OFFStructuresSizeMessage* off_structures_size_message_new (gdouble width_height);
OFFStructuresSizeMessage* off_structures_size_message_construct (GType object_type,
                                                                 gdouble width_height);
static gchar* off_structures_size_message_real_generate_message (OFFStructuresMessage* base);
static gchar* off_structures_size_message_get_width_height_string (OFFStructuresSizeMessage* self);
static void _vala_array_add4 (guchar* * array,
                       int* length,
                       int* size,
                       guchar value);
gchar* off_structures_message_generate_message (OFFStructuresMessage* self);
static void off_structures_size_message_finalize (GObject * obj);
static void _vala_off_structures_size_message_get_property (GObject * object,
                                                     guint property_id,
                                                     GValue * value,
                                                     GParamSpec * pspec);


OFFStructuresSizeMessage*
off_structures_size_message_construct (GType object_type,
                                       gdouble width_height)
{
	OFFStructuresSizeMessage * self = NULL;
#line 26 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	self = (OFFStructuresSizeMessage*) g_object_new (object_type, NULL);
#line 27 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	self->priv->width_height = width_height;
#line 28 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	g_message ("SizeMessage.vala:28: %f", width_height);
#line 26 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	return self;
#line 113 "SizeMessage.c"
}


OFFStructuresSizeMessage*
off_structures_size_message_new (gdouble width_height)
{
#line 26 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	return off_structures_size_message_construct (OFF_STRUCTURES_TYPE_SIZE_MESSAGE, width_height);
#line 122 "SizeMessage.c"
}


static guint8*
string_get_data (const gchar* self,
                 int* result_length1)
{
	guint8* result;
	guint8* res = NULL;
	gint res_length1;
	gint _res_size_;
	gint _tmp0_;
	gint _tmp1_;
	guint8* _tmp2_;
	gint _tmp2__length1;
	guint8* _tmp3_;
	gint _tmp3__length1;
#line 1500 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	g_return_val_if_fail (self != NULL, NULL);
#line 1501 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	res = (guint8*) self;
#line 1501 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	res_length1 = -1;
#line 1501 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_res_size_ = res_length1;
#line 1502 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp0_ = strlen (self);
#line 1502 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp1_ = _tmp0_;
#line 1502 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	res_length1 = (gint) _tmp1_;
#line 1503 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp2_ = res;
#line 1503 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp2__length1 = res_length1;
#line 1503 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp3_ = _tmp2_;
#line 1503 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp3__length1 = _tmp2__length1;
#line 1503 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	if (result_length1) {
#line 1503 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		*result_length1 = _tmp3__length1;
#line 166 "SizeMessage.c"
	}
#line 1503 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	result = _tmp3_;
#line 1503 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	return result;
#line 172 "SizeMessage.c"
}


static void
_vala_array_add4 (guchar* * array,
                  int* length,
                  int* size,
                  guchar value)
{
#line 34 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	if ((*length) == (*size)) {
#line 34 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
		*size = (*size) ? (2 * (*size)) : 4;
#line 34 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
		*array = g_renew (guchar, *array, *size);
#line 188 "SizeMessage.c"
	}
#line 34 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	(*array)[(*length)++] = value;
#line 192 "SizeMessage.c"
}


static gchar*
off_structures_size_message_real_generate_message (OFFStructuresMessage* base)
{
	OFFStructuresSizeMessage * self;
	gchar* result = NULL;
	guchar* data = NULL;
	guchar* _tmp0_;
	gint data_length1;
	gint _data_size_;
	guchar* _tmp18_;
	gint _tmp18__length1;
	gchar* _tmp19_;
#line 31 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	self = (OFFStructuresSizeMessage*) base;
#line 32 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	_tmp0_ = g_new0 (guchar, 0);
#line 32 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	data = _tmp0_;
#line 32 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	data_length1 = 0;
#line 32 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	_data_size_ = data_length1;
#line 218 "SizeMessage.c"
	{
		gint i = 0;
#line 33 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
		i = 0;
#line 223 "SizeMessage.c"
		{
			gboolean _tmp1_ = FALSE;
#line 33 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
			_tmp1_ = TRUE;
#line 33 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
			while (TRUE) {
#line 230 "SizeMessage.c"
				gint _tmp3_;
				gchar* _tmp4_;
				gchar* _tmp5_;
				gchar* _tmp6_;
				gint _tmp7_;
				gint _tmp8_;
				gboolean _tmp9_;
				guchar* _tmp10_;
				gint _tmp10__length1;
				gchar* _tmp11_;
				gchar* _tmp12_;
				gchar* _tmp13_;
				guint8* _tmp14_;
				gint _tmp14__length1;
				guint8* _tmp15_;
				gint _tmp15__length1;
				gint _tmp16_;
				guint8 _tmp17_;
#line 33 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
				if (!_tmp1_) {
#line 251 "SizeMessage.c"
					gint _tmp2_;
#line 33 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
					_tmp2_ = i;
#line 33 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
					i = _tmp2_ + 1;
#line 257 "SizeMessage.c"
				}
#line 33 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
				_tmp1_ = FALSE;
#line 33 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
				_tmp3_ = i;
#line 33 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
				_tmp4_ = off_structures_size_message_get_width_height_string (self);
#line 33 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
				_tmp5_ = _tmp4_;
#line 33 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
				_tmp6_ = _tmp5_;
#line 33 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
				_tmp7_ = strlen (_tmp6_);
#line 33 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
				_tmp8_ = _tmp7_;
#line 33 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
				_tmp9_ = !(_tmp3_ < _tmp8_);
#line 33 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
				_g_free0 (_tmp6_);
#line 33 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
				if (_tmp9_) {
#line 33 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
					break;
#line 281 "SizeMessage.c"
				}
#line 34 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
				_tmp10_ = data;
#line 34 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
				_tmp10__length1 = data_length1;
#line 34 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
				_tmp11_ = off_structures_size_message_get_width_height_string (self);
#line 34 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
				_tmp12_ = _tmp11_;
#line 34 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
				_tmp13_ = _tmp12_;
#line 34 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
				_tmp14_ = string_get_data (_tmp13_, &_tmp14__length1);
#line 34 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
				_tmp15_ = _tmp14_;
#line 34 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
				_tmp15__length1 = _tmp14__length1;
#line 34 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
				_tmp16_ = i;
#line 34 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
				_tmp17_ = _tmp15_[_tmp16_];
#line 34 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
				_vala_array_add4 (&data, &data_length1, &_data_size_, (guchar) _tmp17_);
#line 34 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
				_g_free0 (_tmp13_);
#line 307 "SizeMessage.c"
			}
		}
	}
#line 36 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	self->did_send = TRUE;
#line 37 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	_tmp18_ = data;
#line 37 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	_tmp18__length1 = data_length1;
#line 37 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	_tmp19_ = g_base64_encode (_tmp18_, _tmp18__length1);
#line 37 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	result = _tmp19_;
#line 37 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	data = (g_free (data), NULL);
#line 37 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	return result;
#line 325 "SizeMessage.c"
}


static gchar*
double_to_string (gdouble self)
{
	gchar* result = NULL;
	gchar* _tmp0_;
	gchar* _tmp1_;
	gint _tmp1__length1;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* _tmp4_;
#line 938 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp0_ = g_new0 (gchar, G_ASCII_DTOSTR_BUF_SIZE);
#line 938 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp1_ = _tmp0_;
#line 938 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp1__length1 = G_ASCII_DTOSTR_BUF_SIZE;
#line 938 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp2_ = g_ascii_dtostr (_tmp1_, G_ASCII_DTOSTR_BUF_SIZE, self);
#line 938 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp3_ = g_strdup (_tmp2_);
#line 938 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp4_ = _tmp3_;
#line 938 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp1_ = (g_free (_tmp1_), NULL);
#line 938 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	result = _tmp4_;
#line 938 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	return result;
#line 357 "SizeMessage.c"
}


static gchar*
off_structures_size_message_get_width_height_string (OFFStructuresSizeMessage* self)
{
	gchar* result;
	gdouble _tmp0_;
	gchar* _tmp1_;
#line 21 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 21 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	_tmp0_ = self->priv->width_height;
#line 21 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	_tmp1_ = double_to_string (_tmp0_);
#line 21 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	result = _tmp1_;
#line 21 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	return result;
#line 377 "SizeMessage.c"
}


static void
off_structures_size_message_class_init (OFFStructuresSizeMessageClass * klass)
{
#line 18 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	off_structures_size_message_parent_class = g_type_class_peek_parent (klass);
#line 18 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	g_type_class_add_private (klass, sizeof (OFFStructuresSizeMessagePrivate));
#line 18 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	G_OBJECT_CLASS (klass)->get_property = _vala_off_structures_size_message_get_property;
#line 18 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	G_OBJECT_CLASS (klass)->finalize = off_structures_size_message_finalize;
#line 392 "SizeMessage.c"
}


static void
off_structures_size_message_off_structures_message_interface_init (OFFStructuresMessageIface * iface)
{
#line 18 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	off_structures_size_message_off_structures_message_parent_iface = g_type_interface_peek_parent (iface);
#line 18 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	iface->generate_message = (gchar* (*) (OFFStructuresMessage*)) off_structures_size_message_real_generate_message;
#line 403 "SizeMessage.c"
}


static void
off_structures_size_message_instance_init (OFFStructuresSizeMessage * self)
{
#line 18 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	self->priv = OFF_STRUCTURES_SIZE_MESSAGE_GET_PRIVATE (self);
#line 23 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	self->did_send = FALSE;
#line 414 "SizeMessage.c"
}


static void
off_structures_size_message_finalize (GObject * obj)
{
	OFFStructuresSizeMessage * self;
#line 18 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, OFF_STRUCTURES_TYPE_SIZE_MESSAGE, OFFStructuresSizeMessage);
#line 18 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	G_OBJECT_CLASS (off_structures_size_message_parent_class)->finalize (obj);
#line 426 "SizeMessage.c"
}


GType
off_structures_size_message_get_type (void)
{
	static volatile gsize off_structures_size_message_type_id__volatile = 0;
	if (g_once_init_enter (&off_structures_size_message_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (OFFStructuresSizeMessageClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) off_structures_size_message_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (OFFStructuresSizeMessage), 0, (GInstanceInitFunc) off_structures_size_message_instance_init, NULL };
		static const GInterfaceInfo off_structures_message_info = { (GInterfaceInitFunc) off_structures_size_message_off_structures_message_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType off_structures_size_message_type_id;
		off_structures_size_message_type_id = g_type_register_static (G_TYPE_OBJECT, "OFFStructuresSizeMessage", &g_define_type_info, 0);
		g_type_add_interface_static (off_structures_size_message_type_id, OFF_STRUCTURES_TYPE_MESSAGE, &off_structures_message_info);
		g_once_init_leave (&off_structures_size_message_type_id__volatile, off_structures_size_message_type_id);
	}
	return off_structures_size_message_type_id__volatile;
}


static void
_vala_off_structures_size_message_get_property (GObject * object,
                                                guint property_id,
                                                GValue * value,
                                                GParamSpec * pspec)
{
	OFFStructuresSizeMessage * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, OFF_STRUCTURES_TYPE_SIZE_MESSAGE, OFFStructuresSizeMessage);
#line 18 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
	switch (property_id) {
#line 456 "SizeMessage.c"
		default:
#line 18 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
#line 18 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Server/structures/SizeMessage.vala"
		break;
#line 462 "SizeMessage.c"
	}
}



