/*
 * deregistration_info.h
 *
 * Contains the UE id (i.e. SUPI).
 */

#ifndef _OpenAPI_deregistration_info_H_
#define _OpenAPI_deregistration_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_deregistration_info_s OpenAPI_deregistration_info_t;
typedef struct OpenAPI_deregistration_info_s {
    char *supi;
    char *supported_features;
} OpenAPI_deregistration_info_t;

OpenAPI_deregistration_info_t *OpenAPI_deregistration_info_create(
    char *supi,
    char *supported_features
);
void OpenAPI_deregistration_info_free(OpenAPI_deregistration_info_t *deregistration_info);
OpenAPI_deregistration_info_t *OpenAPI_deregistration_info_parseFromJSON(cJSON *deregistration_infoJSON);
cJSON *OpenAPI_deregistration_info_convertToJSON(OpenAPI_deregistration_info_t *deregistration_info);
OpenAPI_deregistration_info_t *OpenAPI_deregistration_info_copy(OpenAPI_deregistration_info_t *dst, OpenAPI_deregistration_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_deregistration_info_H_ */

