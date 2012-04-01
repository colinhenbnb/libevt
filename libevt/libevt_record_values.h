/*
 * Record values functions
 *
 * Copyright (c) 2011-2012, Joachim Metz <jbmetz@users.sourceforge.net>
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

#if !defined( _LIBEVT_RECORD_VALUES_H )
#define _LIBEVT_RECORD_VALUES_H

#include <common.h>
#include <types.h>

#include <liberror.h>

#include "libevt_io_handle.h"
#include "libevt_libbfio.h"
#include "libevt_libfvalue.h"

#if defined( __cplusplus )
extern "C" {
#endif

enum LIBEVT_RECORD_TYPES
{
	LIBEVT_RECORD_TYPE_EVENT,
	LIBEVT_RECORD_TYPE_END_OF_FILE
};

extern const uint8_t evt_end_of_file_record_signature1[ 4 ];
extern const uint8_t evt_end_of_file_record_signature2[ 4 ];
extern const uint8_t evt_end_of_file_record_signature3[ 4 ];
extern const uint8_t evt_end_of_file_record_signature4[ 4 ];

typedef struct libevt_record_values libevt_record_values_t;

struct libevt_record_values
{
	/* The (record) type
	 */
	uint8_t type;

	/* The (record) number
	 */
	uint32_t number;

	/* The creation time
	 */
	uint32_t creation_time;

	/* The written time
	 */
	uint32_t written_time;

	/* The event identifier
	 */
	uint32_t event_identifier;

	/* The event type
	 */
	uint32_t event_type;

	/* The source name
	 */
	libfvalue_value_t *source_name;

	/* The computer name
	 */
	libfvalue_value_t *computer_name;

	/* The strings
	 */
	libfvalue_value_t *strings;

	/* The data
	 */
	libfvalue_value_t *data;
};

int libevt_record_values_initialize(
     libevt_record_values_t **record_values,
     liberror_error_t **error );

int libevt_record_values_free(
     libevt_record_values_t **record_values,
     liberror_error_t **error );

int libevt_record_values_clone(
     libevt_record_values_t **destination_record_values,
     libevt_record_values_t *source_record_values,
     liberror_error_t **error );

ssize_t libevt_record_values_read(
         libevt_record_values_t *record_values,
         libbfio_handle_t *file_io_handle,
         libevt_io_handle_t *io_handle,
         off64_t *file_offset,
         liberror_error_t **error );

int libevt_record_values_read_event(
     libevt_record_values_t *record_values,
     uint8_t *record_values_data,
     size_t record_values_data_size,
     liberror_error_t **error );

int libevt_record_values_read_end_of_file(
     libevt_record_values_t *record_values,
     uint8_t *record_values_data,
     size_t record_values_data_size,
     liberror_error_t **error );

int libevt_record_values_get_type(
     libevt_record_values_t *record_values,
     uint8_t *type,
     liberror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif
