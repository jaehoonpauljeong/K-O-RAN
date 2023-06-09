/*
 * create_ue_context_request.h
 *
 * 
 */

#ifndef _OpenAPI_create_ue_context_request_H_
#define _OpenAPI_create_ue_context_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ue_context_create_data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_create_ue_context_request_s OpenAPI_create_ue_context_request_t;
typedef struct OpenAPI_create_ue_context_request_s {
    struct OpenAPI_ue_context_create_data_s *json_data;
    OpenAPI_binary_t* binary_data_n2_information;
    OpenAPI_binary_t* binary_data_n2_information_ext1;
    OpenAPI_binary_t* binary_data_n2_information_ext2;
    OpenAPI_binary_t* binary_data_n2_information_ext3;
    OpenAPI_binary_t* binary_data_n2_information_ext4;
    OpenAPI_binary_t* binary_data_n2_information_ext5;
    OpenAPI_binary_t* binary_data_n2_information_ext6;
    OpenAPI_binary_t* binary_data_n2_information_ext7;
    OpenAPI_binary_t* binary_data_n2_information_ext8;
    OpenAPI_binary_t* binary_data_n2_information_ext9;
    OpenAPI_binary_t* binary_data_n2_information_ext10;
    OpenAPI_binary_t* binary_data_n2_information_ext11;
    OpenAPI_binary_t* binary_data_n2_information_ext12;
    OpenAPI_binary_t* binary_data_n2_information_ext13;
    OpenAPI_binary_t* binary_data_n2_information_ext14;
    OpenAPI_binary_t* binary_data_n2_information_ext15;
    OpenAPI_binary_t* binary_data_n2_information_ext16;
    OpenAPI_binary_t* binary_data_n2_information_ext17;
} OpenAPI_create_ue_context_request_t;

OpenAPI_create_ue_context_request_t *OpenAPI_create_ue_context_request_create(
    OpenAPI_ue_context_create_data_t *json_data,
    OpenAPI_binary_t* binary_data_n2_information,
    OpenAPI_binary_t* binary_data_n2_information_ext1,
    OpenAPI_binary_t* binary_data_n2_information_ext2,
    OpenAPI_binary_t* binary_data_n2_information_ext3,
    OpenAPI_binary_t* binary_data_n2_information_ext4,
    OpenAPI_binary_t* binary_data_n2_information_ext5,
    OpenAPI_binary_t* binary_data_n2_information_ext6,
    OpenAPI_binary_t* binary_data_n2_information_ext7,
    OpenAPI_binary_t* binary_data_n2_information_ext8,
    OpenAPI_binary_t* binary_data_n2_information_ext9,
    OpenAPI_binary_t* binary_data_n2_information_ext10,
    OpenAPI_binary_t* binary_data_n2_information_ext11,
    OpenAPI_binary_t* binary_data_n2_information_ext12,
    OpenAPI_binary_t* binary_data_n2_information_ext13,
    OpenAPI_binary_t* binary_data_n2_information_ext14,
    OpenAPI_binary_t* binary_data_n2_information_ext15,
    OpenAPI_binary_t* binary_data_n2_information_ext16,
    OpenAPI_binary_t* binary_data_n2_information_ext17
);
void OpenAPI_create_ue_context_request_free(OpenAPI_create_ue_context_request_t *create_ue_context_request);
OpenAPI_create_ue_context_request_t *OpenAPI_create_ue_context_request_parseFromJSON(cJSON *create_ue_context_requestJSON);
cJSON *OpenAPI_create_ue_context_request_convertToJSON(OpenAPI_create_ue_context_request_t *create_ue_context_request);
OpenAPI_create_ue_context_request_t *OpenAPI_create_ue_context_request_copy(OpenAPI_create_ue_context_request_t *dst, OpenAPI_create_ue_context_request_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_create_ue_context_request_H_ */

