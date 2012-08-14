/*
 * Python object definition of the libevt record
 *
 * Copyright (c) 2011-2012, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _PYEVT_RECORD_H )
#define _PYEVT_RECORD_H

#include <common.h>
#include <types.h>

#include "pyevt_libevt.h"
#include "pyevt_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct pyevt_record pyevt_record_t;

struct pyevt_record
{
	/* Python object initialization
	 */
	PyObject_HEAD

	/* The libevt record
	 */
	libevt_record_t *record;
};

extern PyMethodDef pyevt_record_object_methods[];
extern PyTypeObject pyevt_record_type_object;

PyObject *pyevt_record_new(
           PyObject *self );

int pyevt_record_init(
     pyevt_record_t *pyevt_record );

void pyevt_record_free(
      pyevt_record_t *pyevt_record );

PyObject *pyevt_record_get_written_time(
           pyevt_record_t *pyevt_record );

PyObject *pyevt_record_get_event_identifier(
           pyevt_record_t *pyevt_record );

PyObject *pyevt_record_get_event_level(
           pyevt_record_t *pyevt_record );

PyObject *pyevt_record_get_source_name(
           pyevt_record_t *pyevt_record );

PyObject *pyevt_record_get_computer_name(
           pyevt_record_t *pyevt_record );

#if defined( __cplusplus )
}
#endif

#endif
