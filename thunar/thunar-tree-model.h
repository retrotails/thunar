/* $Id$ */
/*-
 * Copyright (c) 2006 Benedikt Meurer <benny@xfce.org>.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __THUNAR_TREE_MODEL_H__
#define __THUNAR_TREE_MODEL_H__

#include <thunar/thunar-file.h>

G_BEGIN_DECLS;

typedef struct _ThunarTreeModelClass ThunarTreeModelClass;
typedef struct _ThunarTreeModel      ThunarTreeModel;

#define THUNAR_TYPE_TREE_MODEL            (thunar_tree_model_get_type ())
#define THUNAR_TREE_MODEL(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), THUNAR_TYPE_TREE_MODEL, ThunarTreeModel))
#define THUNAR_TREE_MODEL_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), THUNAR_TYPE_TREE_MODEL, ThunarTreeModelClass))
#define THUNAR_IS_TREE_MODEL(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THUNAR_TYPE_TREE_MODEL))
#define THUNAR_IS_TREE_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), THUNAR_TYPE_TREE_MODEL))
#define THUNAR_TREE_MODEL_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), THUNAR_TYPE_TREE_MODEL, ThunarTreeModelClass))

/**
 * ThunarTreeModelColumn:
 * @THUNAR_TREE_MODEL_COLUMN_FILE   : the index of the file column.
 * @THUNAR_TREE_MODEL_COLUMN_NAME   : the index of the name column.
 * @THUNAR_TREE_MODEL_COLUMN_ATTR   : the index of the #PangoAttrList column.
 * @THUNAR_TREE_MODEL_COLUMN_VOLUME : the index of the #ThunarVfsVolume column.
 *
 * Columns exported by the #ThunarTreeModel using the
 * #GtkTreeModel interface.
 **/
typedef enum
{
  THUNAR_TREE_MODEL_COLUMN_FILE,
  THUNAR_TREE_MODEL_COLUMN_NAME,
  THUNAR_TREE_MODEL_COLUMN_ATTR,
  THUNAR_TREE_MODEL_COLUMN_VOLUME,
  THUNAR_TREE_MODEL_N_COLUMNS,
} ThunarTreeModelColumn;

GType            thunar_tree_model_get_type           (void) G_GNUC_CONST;

ThunarTreeModel *thunar_tree_model_get_default        (void);

gboolean         thunar_tree_model_get_case_sensitive (ThunarTreeModel *model);
void             thunar_tree_model_set_case_sensitive (ThunarTreeModel *model,
                                                       gboolean         case_sensitive);

G_END_DECLS;

#endif /* !__THUNAR_TREE_MODEL_H__ */
