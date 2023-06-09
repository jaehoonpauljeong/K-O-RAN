/*
 * ee_group_profile_data.h
 *
 * 
 */

#ifndef _OpenAPI_ee_group_profile_data_H_
#define _OpenAPI_ee_group_profile_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "event_type.h"
#include "mtc_provider.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_ee_group_profile_data_s OpenAPI_ee_group_profile_data_t;
typedef struct OpenAPI_ee_group_profile_data_s {
    OpenAPI_list_t *restricted_event_types;
    OpenAPI_list_t* allowed_mtc_provider;
    char *supported_features;
    bool is_iwk_epc_restricted;
    int iwk_epc_restricted;
    char *ext_group_id;
    char *hss_group_id;
} OpenAPI_ee_group_profile_data_t;

OpenAPI_ee_group_profile_data_t *OpenAPI_ee_group_profile_data_create(
    OpenAPI_list_t *restricted_event_types,
    OpenAPI_list_t* allowed_mtc_provider,
    char *supported_features,
    bool is_iwk_epc_restricted,
    int iwk_epc_restricted,
    char *ext_group_id,
    char *hss_group_id
);
void OpenAPI_ee_group_profile_data_free(OpenAPI_ee_group_profile_data_t *ee_group_profile_data);
OpenAPI_ee_group_profile_data_t *OpenAPI_ee_group_profile_data_parseFromJSON(cJSON *ee_group_profile_dataJSON);
cJSON *OpenAPI_ee_group_profile_data_convertToJSON(OpenAPI_ee_group_profile_data_t *ee_group_profile_data);
OpenAPI_ee_group_profile_data_t *OpenAPI_ee_group_profile_data_copy(OpenAPI_ee_group_profile_data_t *dst, OpenAPI_ee_group_profile_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_ee_group_profile_data_H_ */

