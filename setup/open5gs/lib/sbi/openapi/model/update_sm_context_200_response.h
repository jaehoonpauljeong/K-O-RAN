/*
 * update_sm_context_200_response.h
 *
 * 
 */

#ifndef _OpenAPI_update_sm_context_200_response_H_
#define _OpenAPI_update_sm_context_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "sm_context_updated_data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_update_sm_context_200_response_s OpenAPI_update_sm_context_200_response_t;
typedef struct OpenAPI_update_sm_context_200_response_s {
    struct OpenAPI_sm_context_updated_data_s *json_data;
    OpenAPI_binary_t* binary_data_n1_sm_message;
    OpenAPI_binary_t* binary_data_n2_sm_information;
} OpenAPI_update_sm_context_200_response_t;

OpenAPI_update_sm_context_200_response_t *OpenAPI_update_sm_context_200_response_create(
    OpenAPI_sm_context_updated_data_t *json_data,
    OpenAPI_binary_t* binary_data_n1_sm_message,
    OpenAPI_binary_t* binary_data_n2_sm_information
);
void OpenAPI_update_sm_context_200_response_free(OpenAPI_update_sm_context_200_response_t *update_sm_context_200_response);
OpenAPI_update_sm_context_200_response_t *OpenAPI_update_sm_context_200_response_parseFromJSON(cJSON *update_sm_context_200_responseJSON);
cJSON *OpenAPI_update_sm_context_200_response_convertToJSON(OpenAPI_update_sm_context_200_response_t *update_sm_context_200_response);
OpenAPI_update_sm_context_200_response_t *OpenAPI_update_sm_context_200_response_copy(OpenAPI_update_sm_context_200_response_t *dst, OpenAPI_update_sm_context_200_response_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_update_sm_context_200_response_H_ */

