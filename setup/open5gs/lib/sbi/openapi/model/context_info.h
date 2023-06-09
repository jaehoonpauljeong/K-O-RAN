/*
 * context_info.h
 *
 * 
 */

#ifndef _OpenAPI_context_info_H_
#define _OpenAPI_context_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_context_info_s OpenAPI_context_info_t;
typedef struct OpenAPI_context_info_s {
    OpenAPI_list_t *orig_headers;
    OpenAPI_list_t *request_headers;
} OpenAPI_context_info_t;

OpenAPI_context_info_t *OpenAPI_context_info_create(
    OpenAPI_list_t *orig_headers,
    OpenAPI_list_t *request_headers
);
void OpenAPI_context_info_free(OpenAPI_context_info_t *context_info);
OpenAPI_context_info_t *OpenAPI_context_info_parseFromJSON(cJSON *context_infoJSON);
cJSON *OpenAPI_context_info_convertToJSON(OpenAPI_context_info_t *context_info);
OpenAPI_context_info_t *OpenAPI_context_info_copy(OpenAPI_context_info_t *dst, OpenAPI_context_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_context_info_H_ */

