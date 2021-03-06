/* ATK - The Accessibility Toolkit for GTK+
 * Copyright 2001 Sun Microsystems Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */


#ifndef __ATK_TEXT_H__
#define __ATK_TEXT_H__

#include <glib-object.h>
#include <atk/atkobject.h>
#include <atk/atkutil.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * AtkAttributeSet:
 *
 * This is a singly-linked list (a #GSList) of #AtkAttribute. It is
 * used by atk_text_get_run_attributes(), atk_text_get_default_attributes()
 * and atk_editable_text_set_run_attributes()
 **/
typedef GSList AtkAttributeSet;

/**
 * AtkAttribute:
 * @name: The attribute name. Call atk_text_attr_get_name()
 * @value: the value of the attribute, represented as a string. 
 * Call atk_text_attr_get_value() for those which are strings.
 * For values which are numbers, the string representation of the number 
 * is in value.
 *
 * A string name/value pair representing a text attribute. 
 **/
typedef struct _AtkAttribute AtkAttribute;

struct _AtkAttribute {
  gchar* name;
  gchar* value;
};

/**
 *AtkTextAttribute
 *@ATK_TEXT_ATTR_INVALID: Invalid attribute
 *@ATK_TEXT_ATTR_LEFT_MARGIN: The pixel width of the left margin
 *@ATK_TEXT_ATTR_RIGHT_MARGIN: The pixel width of the right margin
 *@ATK_TEXT_ATTR_INDENT: The number of pixels that the text is indented
 *@ATK_TEXT_ATTR_INVISIBLE: Either "true" or "false" indicating whether text is visible or not
 *@ATK_TEXT_ATTR_EDITABLE: Either "true" or "false" indicating whether text is editable or not
 *@ATK_TEXT_ATTR_PIXELS_ABOVE_LINES: Pixels of blank space to leave above each newline-terminated line. 
 *@ATK_TEXT_ATTR_PIXELS_BELOW_LINES: Pixels of blank space to leave below each newline-terminated line.
 *@ATK_TEXT_ATTR_PIXELS_INSIDE_WRAP: Pixels of blank space to leave between wrapped lines inside the same newline-terminated line (paragraph).
 *@ATK_TEXT_ATTR_BG_FULL_HEIGHT: "true" or "false" whether to make the background color for each character the height of the highest font used on the current line, or the height of the font used for the current character.
 *@ATK_TEXT_ATTR_RISE: Number of pixels that the characters are risen above the baseline
 *@ATK_TEXT_ATTR_UNDERLINE: "none", "single", "double" or "low"
 *@ATK_TEXT_ATTR_STRIKETHROUGH: "true" or "false" whether the text is strikethrough 
 *@ATK_TEXT_ATTR_SIZE: The size of the characters. 
 *@ATK_TEXT_ATTR_SCALE: The scale of the characters. The value is a string representation of a double 
 *@ATK_TEXT_ATTR_WEIGHT: The weight of the characters.
 *@ATK_TEXT_ATTR_LANGUAGE: The language used
 *@ATK_TEXT_ATTR_FAMILY_NAME: The font family name
 *@ATK_TEXT_ATTR_BG_COLOR: The background color. The value is an RGB value of the format "%u,%u,%u"
 *@ATK_TEXT_ATTR_FG_COLOR:The foreground color. The value is an RGB value of the format "%u,%u,%u"
 *@ATK_TEXT_ATTR_BG_STIPPLE: "true" if a #GdkBitmap is set for stippling the background color.
 *@ATK_TEXT_ATTR_FG_STIPPLE: "true" if a #GdkBitmap is set for stippling the foreground color.
 *@ATK_TEXT_ATTR_WRAP_MODE: The wrap mode of the text, if any. Values are "none", "char" or "word" 
 *@ATK_TEXT_ATTR_DIRECTION: The direction of the text, if set. Values are "none", "ltr" or "rtl" 
 *@ATK_TEXT_ATTR_JUSTIFICATION: The justification of the text, if set. Values are "left", "right", "center" or "fill" 
 *@ATK_TEXT_ATTR_STRETCH: The stretch of the text, if set. Values are "ultra_condensed", "extra_condensed", "condensed", "semi_condensed", "normal", "semi_expanded", "expanded", "extra_expanded" or "ultra_expanded"
 *@ATK_TEXT_ATTR_VARIANT: The capitalization variant of the text, if set. Values are "normal" or "small_caps"
 *@ATK_TEXT_ATTR_STYLE: The slant style of the text, if set. Values are "normal", "oblique" or "italic"
 *@ATK_TEXT_ATTR_LAST_DEFINED: not a valid text attribute, used for finding end of enumeration
 *
 * Describes the text attributes supported
 **/
typedef enum
{
  ATK_TEXT_ATTR_INVALID = 0,
  ATK_TEXT_ATTR_LEFT_MARGIN,
  ATK_TEXT_ATTR_RIGHT_MARGIN,
  ATK_TEXT_ATTR_INDENT,
  ATK_TEXT_ATTR_INVISIBLE,
  ATK_TEXT_ATTR_EDITABLE,
  ATK_TEXT_ATTR_PIXELS_ABOVE_LINES,
  ATK_TEXT_ATTR_PIXELS_BELOW_LINES,
  ATK_TEXT_ATTR_PIXELS_INSIDE_WRAP,
  ATK_TEXT_ATTR_BG_FULL_HEIGHT,
  ATK_TEXT_ATTR_RISE,
  ATK_TEXT_ATTR_UNDERLINE,
  ATK_TEXT_ATTR_STRIKETHROUGH,
  ATK_TEXT_ATTR_SIZE,
  ATK_TEXT_ATTR_SCALE,
  ATK_TEXT_ATTR_WEIGHT,
  ATK_TEXT_ATTR_LANGUAGE,
  ATK_TEXT_ATTR_FAMILY_NAME,
  ATK_TEXT_ATTR_BG_COLOR,
  ATK_TEXT_ATTR_FG_COLOR,
  ATK_TEXT_ATTR_BG_STIPPLE,
  ATK_TEXT_ATTR_FG_STIPPLE,
  ATK_TEXT_ATTR_WRAP_MODE,
  ATK_TEXT_ATTR_DIRECTION,
  ATK_TEXT_ATTR_JUSTIFICATION,
  ATK_TEXT_ATTR_STRETCH,
  ATK_TEXT_ATTR_VARIANT,
  ATK_TEXT_ATTR_STYLE,
  ATK_TEXT_ATTR_LAST_DEFINED
} AtkTextAttribute;

AtkTextAttribute         atk_text_attribute_register   (const gchar *name);


#define ATK_TYPE_TEXT                    (atk_text_get_type ())
#define ATK_IS_TEXT(obj)                 G_TYPE_CHECK_INSTANCE_TYPE ((obj), ATK_TYPE_TEXT)
#define ATK_TEXT(obj)                    G_TYPE_CHECK_INSTANCE_CAST ((obj), ATK_TYPE_TEXT, AtkText)
#define ATK_TEXT_GET_IFACE(obj)          (G_TYPE_INSTANCE_GET_INTERFACE ((obj), ATK_TYPE_TEXT, AtkTextIface))

#ifndef _TYPEDEF_ATK_TEXT_
#define _TYPEDEF_ATK_TEXT_
typedef struct _AtkText AtkText;
#endif
typedef struct _AtkTextIface AtkTextIface;

/**
 *AtkTextBoundary:
 *@ATK_TEXT_BOUNDARY_CHAR:
 *@ATK_TEXT_BOUNDARY_WORD_START:
 *@ATK_TEXT_BOUNDARY_WORD_END:
 *@ATK_TEXT_BOUNDARY_SENTENCE_START:
 *@ATK_TEXT_BOUNDARY_SENTENCE_END:
 *@ATK_TEXT_BOUNDARY_LINE_START:
 *@ATK_TEXT_BOUNDARY_LINE_END:
 *
 *Text boundary types used for specifying boundaries for regions of text
 **/
typedef enum {
  ATK_TEXT_BOUNDARY_CHAR,
  ATK_TEXT_BOUNDARY_WORD_START,
  ATK_TEXT_BOUNDARY_WORD_END,
  ATK_TEXT_BOUNDARY_SENTENCE_START,
  ATK_TEXT_BOUNDARY_SENTENCE_END,
  ATK_TEXT_BOUNDARY_LINE_START,
  ATK_TEXT_BOUNDARY_LINE_END
} AtkTextBoundary;

struct _AtkTextIface
{
  GTypeInterface parent;

  gchar*         (* get_text)                     (AtkText          *text,
                                                   gint             start_offset,
                                                   gint             end_offset);
  gchar*         (* get_text_after_offset)        (AtkText          *text,
                                                   gint             offset,
                                                   AtkTextBoundary  boundary_type,
						   gint             *start_offset,
						   gint             *end_offset);
  gchar*         (* get_text_at_offset)           (AtkText          *text,
                                                   gint             offset,
                                                   AtkTextBoundary  boundary_type,
						   gint             *start_offset,
						   gint             *end_offset);
  gunichar       (* get_character_at_offset)      (AtkText          *text,
                                                   gint             offset);
  gchar*         (* get_text_before_offset)       (AtkText          *text,
                                                   gint             offset,
                                                   AtkTextBoundary  boundary_type,
 						   gint             *start_offset,
						   gint             *end_offset);
  gint           (* get_caret_offset)             (AtkText          *text);
  AtkAttributeSet* (* get_run_attributes)         (AtkText	    *text,
						   gint	  	    offset,
						   gint             *start_offset,
						   gint	 	    *end_offset);
  AtkAttributeSet* (* get_default_attributes)     (AtkText	    *text);
  void           (* get_character_extents)        (AtkText          *text,
                                                   gint             offset,
                                                   gint             *x,
                                                   gint             *y,
                                                   gint             *width,
                                                   gint             *height,
                                                   AtkCoordType	    coords);
  gint           (* get_character_count)          (AtkText          *text);
  gint           (* get_offset_at_point)          (AtkText          *text,
                                                   gint             x,
                                                   gint             y,
                                                   AtkCoordType	    coords);
  gint		 (* get_n_selections)		  (AtkText          *text);
  gchar*         (* get_selection)	          (AtkText          *text,
						   gint		    selection_num,
						   gint		    *start_offset,
						   gint		    *end_offset);
  gboolean       (* add_selection)		  (AtkText          *text,
						   gint		    start_offset,
						   gint		    end_offset);
  gboolean       (* remove_selection)		  (AtkText          *text,
						   gint             selection_num);
  gboolean       (* set_selection)		  (AtkText          *text,
						   gint		    selection_num,
						   gint		    start_offset,
						   gint		    end_offset);
  gboolean       (* set_caret_offset)             (AtkText          *text,
                                                   gint             offset);

  /*
   * signal handlers
   */
  void		 (* text_changed)                 (AtkText          *text,
                                                   gint             position,
                                                   gint             length);
  void           (* text_caret_moved)             (AtkText          *text,
                                                   gint             location);
  void           (* text_selection_changed)       (AtkText          *text);

  AtkFunction    pad1;
  AtkFunction    pad2;
  AtkFunction    pad3;
  AtkFunction    pad4;
};

GType            atk_text_get_type (void);


/*
 * Additional AtkObject properties used by AtkText:
 *    "accessible_text" (accessible text has changed)
 *    "accessible_caret" (accessible text cursor position changed:
 *                         editable text only)
 */

gchar*        atk_text_get_text                           (AtkText          *text,
                                                           gint             start_offset,
                                                           gint             end_offset);
gunichar      atk_text_get_character_at_offset            (AtkText          *text,
                                                           gint             offset);
gchar*        atk_text_get_text_after_offset              (AtkText          *text,
                                                           gint             offset,
                                                           AtkTextBoundary  boundary_type,
							   gint             *start_offset,
							   gint	            *end_offset);
gchar*        atk_text_get_text_at_offset                 (AtkText          *text,
                                                           gint             offset,
                                                           AtkTextBoundary  boundary_type,
							   gint             *start_offset,
							   gint             *end_offset);
gchar*        atk_text_get_text_before_offset             (AtkText          *text,
                                                           gint             offset,
                                                           AtkTextBoundary  boundary_type,
							   gint             *start_offset,
							   gint	            *end_offset);
gint          atk_text_get_caret_offset                   (AtkText          *text);
void          atk_text_get_character_extents              (AtkText          *text,
                                                           gint             offset,
                                                           gint             *x,
                                                           gint             *y,
                                                           gint             *width,
                                                           gint             *height,
                                                           AtkCoordType	    coords);
AtkAttributeSet* atk_text_get_run_attributes              (AtkText	    *text,
						           gint	  	    offset,
						           gint             *start_offset,
						           gint	 	    *end_offset);
AtkAttributeSet* atk_text_get_default_attributes          (AtkText	    *text);
gint          atk_text_get_character_count                (AtkText          *text);
gint          atk_text_get_offset_at_point                (AtkText          *text,
                                                           gint             x,
                                                           gint             y,
                                                           AtkCoordType	    coords);
gint          atk_text_get_n_selections			  (AtkText          *text);
gchar*        atk_text_get_selection			  (AtkText          *text,
							   gint		    selection_num,
							   gint             *start_offset,
							   gint             *end_offset);
gboolean      atk_text_add_selection                      (AtkText          *text,
							   gint             start_offset,
							   gint             end_offset);
gboolean      atk_text_remove_selection                   (AtkText          *text,
							   gint		    selection_num);
gboolean      atk_text_set_selection                      (AtkText          *text,
							   gint		    selection_num,
							   gint             start_offset,
							   gint             end_offset);
gboolean      atk_text_set_caret_offset                   (AtkText          *text,
                                                           gint             offset);
void 	      atk_attribute_set_free                      (AtkAttributeSet  *attrib_set);
G_CONST_RETURN gchar*  atk_text_attribute_get_name        (AtkTextAttribute attr);
AtkTextAttribute       atk_text_attribute_for_name        (const gchar      *name);
G_CONST_RETURN gchar*  atk_text_attribute_get_value       (AtkTextAttribute attr,
                                                           gint             index);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* __ATK_TEXT_H__ */
