/* FileMessenger.c generated by valac 0.40.25, the Vala compiler
 * generated from FileMessenger.vala, do not modify */

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
#include <gio/gio.h>
#include <float.h>
#include <math.h>


#define OFF_STRUCTURES_TYPE_MESSENGER (off_structures_messenger_get_type ())
#define OFF_STRUCTURES_MESSENGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), OFF_STRUCTURES_TYPE_MESSENGER, OFFStructuresMessenger))
#define OFF_STRUCTURES_MESSENGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), OFF_STRUCTURES_TYPE_MESSENGER, OFFStructuresMessengerClass))
#define OFF_STRUCTURES_IS_MESSENGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), OFF_STRUCTURES_TYPE_MESSENGER))
#define OFF_STRUCTURES_IS_MESSENGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), OFF_STRUCTURES_TYPE_MESSENGER))
#define OFF_STRUCTURES_MESSENGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), OFF_STRUCTURES_TYPE_MESSENGER, OFFStructuresMessengerClass))

typedef struct _OFFStructuresMessenger OFFStructuresMessenger;
typedef struct _OFFStructuresMessengerClass OFFStructuresMessengerClass;
typedef struct _OFFStructuresMessengerPrivate OFFStructuresMessengerPrivate;

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

#define OFF_STRUCTURES_TYPE_VERSION_MESSAGE (off_structures_version_message_get_type ())
#define OFF_STRUCTURES_VERSION_MESSAGE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), OFF_STRUCTURES_TYPE_VERSION_MESSAGE, OFFStructuresVersionMessage))
#define OFF_STRUCTURES_VERSION_MESSAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), OFF_STRUCTURES_TYPE_VERSION_MESSAGE, OFFStructuresVersionMessageClass))
#define OFF_STRUCTURES_IS_VERSION_MESSAGE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), OFF_STRUCTURES_TYPE_VERSION_MESSAGE))
#define OFF_STRUCTURES_IS_VERSION_MESSAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), OFF_STRUCTURES_TYPE_VERSION_MESSAGE))
#define OFF_STRUCTURES_VERSION_MESSAGE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), OFF_STRUCTURES_TYPE_VERSION_MESSAGE, OFFStructuresVersionMessageClass))

typedef struct _OFFStructuresVersionMessage OFFStructuresVersionMessage;
typedef struct _OFFStructuresVersionMessageClass OFFStructuresVersionMessageClass;

#define OFF_STRUCTURES_TYPE_COLOR_MESSAGE (off_structures_color_message_get_type ())
#define OFF_STRUCTURES_COLOR_MESSAGE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), OFF_STRUCTURES_TYPE_COLOR_MESSAGE, OFFStructuresColorMessage))
#define OFF_STRUCTURES_COLOR_MESSAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), OFF_STRUCTURES_TYPE_COLOR_MESSAGE, OFFStructuresColorMessageClass))
#define OFF_STRUCTURES_IS_COLOR_MESSAGE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), OFF_STRUCTURES_TYPE_COLOR_MESSAGE))
#define OFF_STRUCTURES_IS_COLOR_MESSAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), OFF_STRUCTURES_TYPE_COLOR_MESSAGE))
#define OFF_STRUCTURES_COLOR_MESSAGE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), OFF_STRUCTURES_TYPE_COLOR_MESSAGE, OFFStructuresColorMessageClass))

typedef struct _OFFStructuresColorMessage OFFStructuresColorMessage;
typedef struct _OFFStructuresColorMessageClass OFFStructuresColorMessageClass;

#define OFF_STRUCTURES_TYPE_PDF_SOURCE (off_structures_pdf_source_get_type ())
#define OFF_STRUCTURES_PDF_SOURCE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), OFF_STRUCTURES_TYPE_PDF_SOURCE, OFFStructuresPDFSource))
#define OFF_STRUCTURES_PDF_SOURCE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), OFF_STRUCTURES_TYPE_PDF_SOURCE, OFFStructuresPDFSourceClass))
#define OFF_STRUCTURES_IS_PDF_SOURCE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), OFF_STRUCTURES_TYPE_PDF_SOURCE))
#define OFF_STRUCTURES_IS_PDF_SOURCE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), OFF_STRUCTURES_TYPE_PDF_SOURCE))
#define OFF_STRUCTURES_PDF_SOURCE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), OFF_STRUCTURES_TYPE_PDF_SOURCE, OFFStructuresPDFSourceClass))

typedef struct _OFFStructuresPDFSource OFFStructuresPDFSource;
typedef struct _OFFStructuresPDFSourceClass OFFStructuresPDFSourceClass;

#define OFF_STRUCTURES_TYPE_FILE_MESSENGER (off_structures_file_messenger_get_type ())
#define OFF_STRUCTURES_FILE_MESSENGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), OFF_STRUCTURES_TYPE_FILE_MESSENGER, OFFStructuresFileMessenger))
#define OFF_STRUCTURES_FILE_MESSENGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), OFF_STRUCTURES_TYPE_FILE_MESSENGER, OFFStructuresFileMessengerClass))
#define OFF_STRUCTURES_IS_FILE_MESSENGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), OFF_STRUCTURES_TYPE_FILE_MESSENGER))
#define OFF_STRUCTURES_IS_FILE_MESSENGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), OFF_STRUCTURES_TYPE_FILE_MESSENGER))
#define OFF_STRUCTURES_FILE_MESSENGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), OFF_STRUCTURES_TYPE_FILE_MESSENGER, OFFStructuresFileMessengerClass))

typedef struct _OFFStructuresFileMessenger OFFStructuresFileMessenger;
typedef struct _OFFStructuresFileMessengerClass OFFStructuresFileMessengerClass;
typedef struct _OFFStructuresFileMessengerPrivate OFFStructuresFileMessengerPrivate;
enum  {
	OFF_STRUCTURES_FILE_MESSENGER_0_PROPERTY,
	OFF_STRUCTURES_FILE_MESSENGER_NUM_PROPERTIES
};
static GParamSpec* off_structures_file_messenger_properties[OFF_STRUCTURES_FILE_MESSENGER_NUM_PROPERTIES];
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _OFFStructuresMessageIface {
	GTypeInterface parent_iface;
	gchar* (*generate_message) (OFFStructuresMessage* self);
};

struct _OFFStructuresMessenger {
	GObject parent_instance;
	OFFStructuresMessengerPrivate * priv;
	OFFStructuresSizeMessage* _height_message;
	OFFStructuresSizeMessage* _width_message;
	OFFStructuresVersionMessage* _version_message;
	OFFStructuresColorMessage* _color_message;
	OFFStructuresPDFSource* pdf;
	GFileOutputStream* _dest_file;
	gchar* _dest_file_path;
	gdouble width;
	gdouble height;
	gint x;
	gint row_num;
	gboolean compress;
	guint8 red;
	guint8 green;
	guint8 blue;
	guint8 last_red;
	guint8 last_green;
	guint8 last_blue;
};

struct _OFFStructuresMessengerClass {
	GObjectClass parent_class;
	void (*send_message) (OFFStructuresMessenger* self, OFFStructuresMessage* message);
};

struct _OFFStructuresFileMessenger {
	OFFStructuresMessenger parent_instance;
	OFFStructuresFileMessengerPrivate * priv;
};

struct _OFFStructuresFileMessengerClass {
	OFFStructuresMessengerClass parent_class;
};


static gpointer off_structures_file_messenger_parent_class = NULL;

GType off_structures_messenger_get_type (void) G_GNUC_CONST;
GType off_structures_message_get_type (void) G_GNUC_CONST;
GType off_structures_size_message_get_type (void) G_GNUC_CONST;
GType off_structures_version_message_get_type (void) G_GNUC_CONST;
GType off_structures_color_message_get_type (void) G_GNUC_CONST;
GType off_structures_pdf_source_get_type (void) G_GNUC_CONST;
GType off_structures_file_messenger_get_type (void) G_GNUC_CONST;
void off_structures_messenger_send_message (OFFStructuresMessenger* self,
                                            OFFStructuresMessage* message);
OFFStructuresFileMessenger* off_structures_file_messenger_new (GFile* source_file,
                                                               gboolean compress,
                                                               GFileOutputStream* dest_file,
                                                               const gchar* dest_file_path);
OFFStructuresFileMessenger* off_structures_file_messenger_construct (GType object_type,
                                                                     GFile* source_file,
                                                                     gboolean compress,
                                                                     GFileOutputStream* dest_file,
                                                                     const gchar* dest_file_path);
OFFStructuresMessenger* off_structures_messenger_construct (GType object_type);
OFFStructuresPDFSource* off_structures_pdf_source_new (const gchar* filename);
OFFStructuresPDFSource* off_structures_pdf_source_construct (GType object_type,
                                                             const gchar* filename);
void off_structures_pdf_source_get_size (OFFStructuresPDFSource* self,
                                         gdouble* width,
                                         gdouble* height);
OFFStructuresSizeMessage* off_structures_size_message_new (gdouble width_height);
OFFStructuresSizeMessage* off_structures_size_message_construct (GType object_type,
                                                                 gdouble width_height);
OFFStructuresVersionMessage* off_structures_version_message_new (void);
OFFStructuresVersionMessage* off_structures_version_message_construct (GType object_type);
gchar* off_structures_message_generate_message (OFFStructuresMessage* self);
static void off_structures_file_messenger_real_send_message (OFFStructuresMessenger* base,
                                                      OFFStructuresMessage* message);


static gpointer
_g_object_ref0 (gpointer self)
{
#line 33 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	return self ? g_object_ref (self) : NULL;
#line 196 "FileMessenger.c"
}


OFFStructuresFileMessenger*
off_structures_file_messenger_construct (GType object_type,
                                         GFile* source_file,
                                         gboolean compress,
                                         GFileOutputStream* dest_file,
                                         const gchar* dest_file_path)
{
	OFFStructuresFileMessenger * self = NULL;
	gchar* _tmp0_;
	gchar* _tmp1_;
	OFFStructuresPDFSource* _tmp2_;
	OFFStructuresPDFSource* _tmp3_;
	gdouble _tmp4_ = 0.0;
	gdouble _tmp5_ = 0.0;
	gdouble _tmp6_;
	OFFStructuresSizeMessage* _tmp7_;
	gdouble _tmp8_;
	OFFStructuresSizeMessage* _tmp9_;
	OFFStructuresVersionMessage* _tmp10_;
	GFileOutputStream* _tmp11_;
	gchar* _tmp12_;
	OFFStructuresVersionMessage* _tmp13_;
	gchar* _tmp14_;
	gchar* _tmp15_;
	gchar* _tmp16_;
	gchar* _tmp17_;
	OFFStructuresSizeMessage* _tmp18_;
	gchar* _tmp19_;
	gchar* _tmp20_;
	gchar* _tmp21_;
	gchar* _tmp22_;
	OFFStructuresSizeMessage* _tmp23_;
	gchar* _tmp24_;
	gchar* _tmp25_;
	gchar* _tmp26_;
	gchar* _tmp27_;
	OFFStructuresVersionMessage* _tmp28_;
	OFFStructuresSizeMessage* _tmp29_;
	OFFStructuresSizeMessage* _tmp30_;
#line 25 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	g_return_val_if_fail (source_file != NULL, NULL);
#line 25 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	g_return_val_if_fail (dest_file != NULL, NULL);
#line 25 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	g_return_val_if_fail (dest_file_path != NULL, NULL);
#line 25 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	self = (OFFStructuresFileMessenger*) off_structures_messenger_construct (object_type);
#line 26 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp0_ = g_file_get_uri (source_file);
#line 26 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp1_ = _tmp0_;
#line 26 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp2_ = off_structures_pdf_source_new (_tmp1_);
#line 26 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_g_object_unref0 (((OFFStructuresMessenger*) self)->pdf);
#line 26 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	((OFFStructuresMessenger*) self)->pdf = _tmp2_;
#line 26 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_g_free0 (_tmp1_);
#line 28 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp3_ = ((OFFStructuresMessenger*) self)->pdf;
#line 28 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	off_structures_pdf_source_get_size (_tmp3_, &_tmp4_, &_tmp5_);
#line 28 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	((OFFStructuresMessenger*) self)->width = _tmp4_;
#line 28 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	((OFFStructuresMessenger*) self)->height = _tmp5_;
#line 30 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp6_ = ((OFFStructuresMessenger*) self)->width;
#line 30 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp7_ = off_structures_size_message_new (_tmp6_);
#line 30 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_g_object_unref0 (((OFFStructuresMessenger*) self)->_width_message);
#line 30 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	((OFFStructuresMessenger*) self)->_width_message = _tmp7_;
#line 31 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp8_ = ((OFFStructuresMessenger*) self)->height;
#line 31 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp9_ = off_structures_size_message_new (_tmp8_);
#line 31 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_g_object_unref0 (((OFFStructuresMessenger*) self)->_height_message);
#line 31 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	((OFFStructuresMessenger*) self)->_height_message = _tmp9_;
#line 32 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp10_ = off_structures_version_message_new ();
#line 32 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_g_object_unref0 (((OFFStructuresMessenger*) self)->_version_message);
#line 32 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	((OFFStructuresMessenger*) self)->_version_message = _tmp10_;
#line 33 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp11_ = _g_object_ref0 (dest_file);
#line 33 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_g_object_unref0 (((OFFStructuresMessenger*) self)->_dest_file);
#line 33 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	((OFFStructuresMessenger*) self)->_dest_file = _tmp11_;
#line 34 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp12_ = g_strdup (dest_file_path);
#line 34 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_g_free0 (((OFFStructuresMessenger*) self)->_dest_file_path);
#line 34 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	((OFFStructuresMessenger*) self)->_dest_file_path = _tmp12_;
#line 36 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp13_ = ((OFFStructuresMessenger*) self)->_version_message;
#line 36 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp14_ = off_structures_message_generate_message ((OFFStructuresMessage*) _tmp13_);
#line 36 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp15_ = _tmp14_;
#line 36 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp16_ = g_strconcat ("Version message:\t\t\t", _tmp15_, NULL);
#line 36 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp17_ = _tmp16_;
#line 36 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	g_message ("FileMessenger.vala:36: %s", _tmp17_);
#line 36 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_g_free0 (_tmp17_);
#line 36 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_g_free0 (_tmp15_);
#line 37 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp18_ = ((OFFStructuresMessenger*) self)->_width_message;
#line 37 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp19_ = off_structures_message_generate_message ((OFFStructuresMessage*) _tmp18_);
#line 37 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp20_ = _tmp19_;
#line 37 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp21_ = g_strconcat ("Width message:  \t\t\t", _tmp20_, NULL);
#line 37 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp22_ = _tmp21_;
#line 37 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	g_message ("FileMessenger.vala:37: %s", _tmp22_);
#line 37 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_g_free0 (_tmp22_);
#line 37 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_g_free0 (_tmp20_);
#line 38 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp23_ = ((OFFStructuresMessenger*) self)->_height_message;
#line 38 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp24_ = off_structures_message_generate_message ((OFFStructuresMessage*) _tmp23_);
#line 38 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp25_ = _tmp24_;
#line 38 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp26_ = g_strconcat ("Height message: \t\t\t", _tmp25_, NULL);
#line 38 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp27_ = _tmp26_;
#line 38 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	g_message ("FileMessenger.vala:38: %s", _tmp27_);
#line 38 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_g_free0 (_tmp27_);
#line 38 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_g_free0 (_tmp25_);
#line 39 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp28_ = ((OFFStructuresMessenger*) self)->_version_message;
#line 39 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	off_structures_messenger_send_message ((OFFStructuresMessenger*) self, (OFFStructuresMessage*) _tmp28_);
#line 40 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp29_ = ((OFFStructuresMessenger*) self)->_width_message;
#line 40 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	off_structures_messenger_send_message ((OFFStructuresMessenger*) self, (OFFStructuresMessage*) _tmp29_);
#line 41 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp30_ = ((OFFStructuresMessenger*) self)->_height_message;
#line 41 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	off_structures_messenger_send_message ((OFFStructuresMessenger*) self, (OFFStructuresMessage*) _tmp30_);
#line 25 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	return self;
#line 363 "FileMessenger.c"
}


OFFStructuresFileMessenger*
off_structures_file_messenger_new (GFile* source_file,
                                   gboolean compress,
                                   GFileOutputStream* dest_file,
                                   const gchar* dest_file_path)
{
#line 25 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	return off_structures_file_messenger_construct (OFF_STRUCTURES_TYPE_FILE_MESSENGER, source_file, compress, dest_file, dest_file_path);
#line 375 "FileMessenger.c"
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
#line 419 "FileMessenger.c"
	}
#line 1503 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	result = _tmp3_;
#line 1503 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	return result;
#line 425 "FileMessenger.c"
}


static void
off_structures_file_messenger_real_send_message (OFFStructuresMessenger* base,
                                                 OFFStructuresMessage* message)
{
	OFFStructuresFileMessenger * self;
	gchar* string_message = NULL;
	gchar* _tmp0_;
	GError* _inner_error0_ = NULL;
#line 45 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	self = (OFFStructuresFileMessenger*) base;
#line 45 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	g_return_if_fail (message != NULL);
#line 46 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_tmp0_ = off_structures_message_generate_message (message);
#line 46 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	string_message = _tmp0_;
#line 445 "FileMessenger.c"
	{
		GFileOutputStream* _tmp1_;
		gchar* _tmp2_;
		gchar* _tmp3_;
		guint8* _tmp4_;
		gint _tmp4__length1;
		guint8* _tmp5_;
		gint _tmp5__length1;
#line 48 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
		_tmp1_ = ((OFFStructuresMessenger*) self)->_dest_file;
#line 48 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
		_tmp2_ = g_strconcat (string_message, "\n", NULL);
#line 48 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
		_tmp3_ = _tmp2_;
#line 48 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
		_tmp4_ = string_get_data (_tmp3_, &_tmp4__length1);
#line 48 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
		_tmp5_ = _tmp4_;
#line 48 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
		_tmp5__length1 = _tmp4__length1;
#line 48 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
		g_output_stream_write ((GOutputStream*) _tmp1_, _tmp5_, (gsize) _tmp5__length1, NULL, &_inner_error0_);
#line 48 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
		_g_free0 (_tmp3_);
#line 48 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
#line 472 "FileMessenger.c"
			goto __catch4_g_error;
		}
	}
	goto __finally4;
	__catch4_g_error:
	{
		GError* e = NULL;
		GError* _tmp6_;
		const gchar* _tmp7_;
#line 47 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
		e = _inner_error0_;
#line 47 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
		_inner_error0_ = NULL;
#line 51 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
		_tmp6_ = e;
#line 51 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
		_tmp7_ = _tmp6_->message;
#line 51 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
		g_critical ("FileMessenger.vala:51: Error writing to file:\t%s", _tmp7_);
#line 47 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
		_g_error_free0 (e);
#line 494 "FileMessenger.c"
	}
	__finally4:
#line 47 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	if (G_UNLIKELY (_inner_error0_ != NULL)) {
#line 47 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
		_g_free0 (string_message);
#line 47 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
#line 47 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
		g_clear_error (&_inner_error0_);
#line 47 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
		return;
#line 507 "FileMessenger.c"
	}
#line 45 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	_g_free0 (string_message);
#line 511 "FileMessenger.c"
}


static void
off_structures_file_messenger_class_init (OFFStructuresFileMessengerClass * klass)
{
#line 19 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	off_structures_file_messenger_parent_class = g_type_class_peek_parent (klass);
#line 19 "/home/nick/Desktop/School Work/CIS 488 - Capstone/Open Fax Format/Implementation/src/Client/structures/FileMessenger.vala"
	((OFFStructuresMessengerClass *) klass)->send_message = (void (*) (OFFStructuresMessenger*, OFFStructuresMessage*)) off_structures_file_messenger_real_send_message;
#line 522 "FileMessenger.c"
}


static void
off_structures_file_messenger_instance_init (OFFStructuresFileMessenger * self)
{
}


GType
off_structures_file_messenger_get_type (void)
{
	static volatile gsize off_structures_file_messenger_type_id__volatile = 0;
	if (g_once_init_enter (&off_structures_file_messenger_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (OFFStructuresFileMessengerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) off_structures_file_messenger_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (OFFStructuresFileMessenger), 0, (GInstanceInitFunc) off_structures_file_messenger_instance_init, NULL };
		GType off_structures_file_messenger_type_id;
		off_structures_file_messenger_type_id = g_type_register_static (OFF_STRUCTURES_TYPE_MESSENGER, "OFFStructuresFileMessenger", &g_define_type_info, 0);
		g_once_init_leave (&off_structures_file_messenger_type_id__volatile, off_structures_file_messenger_type_id);
	}
	return off_structures_file_messenger_type_id__volatile;
}



