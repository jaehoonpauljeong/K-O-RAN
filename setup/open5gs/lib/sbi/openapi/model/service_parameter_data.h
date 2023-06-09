/*
 * service_parameter_data.h
 *
 * Represents the service parameter data.
 */

#ifndef _OpenAPI_service_parameter_data_H_
#define _OpenAPI_service_parameter_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "event.h"
#include "snssai.h"
#include "ursp_rule_request.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_service_parameter_data_s OpenAPI_service_parameter_data_t;
typedef struct OpenAPI_service_parameter_data_s {
    char *app_id;
    char *dnn;
    struct OpenAPI_snssai_s *snssai;
    char *inter_group_id;
    char *supi;
    char *ue_ipv4;
    char *ue_ipv6;
    char *ue_mac;
    bool is_any_ue_ind;
    int any_ue_ind;
    char *param_over_pc5;
    char *param_over_uu;
    char *param_for_pro_se_dd;
    char *param_for_pro_se_dc;
    char *param_for_pro_se_u2_n_rel_ue;
    char *param_for_pro_se_rem_ue;
    OpenAPI_list_t *ursp_guidance;
    OpenAPI_list_t *delivery_events;
    char *polic_deliv_notif_corre_id;
    char *polic_deliv_notif_uri;
    char *supp_feat;
    char *res_uri;
    OpenAPI_list_t *headers;
    OpenAPI_list_t *reset_ids;
} OpenAPI_service_parameter_data_t;

OpenAPI_service_parameter_data_t *OpenAPI_service_parameter_data_create(
    char *app_id,
    char *dnn,
    OpenAPI_snssai_t *snssai,
    char *inter_group_id,
    char *supi,
    char *ue_ipv4,
    char *ue_ipv6,
    char *ue_mac,
    bool is_any_ue_ind,
    int any_ue_ind,
    char *param_over_pc5,
    char *param_over_uu,
    char *param_for_pro_se_dd,
    char *param_for_pro_se_dc,
    char *param_for_pro_se_u2_n_rel_ue,
    char *param_for_pro_se_rem_ue,
    OpenAPI_list_t *ursp_guidance,
    OpenAPI_list_t *delivery_events,
    char *polic_deliv_notif_corre_id,
    char *polic_deliv_notif_uri,
    char *supp_feat,
    char *res_uri,
    OpenAPI_list_t *headers,
    OpenAPI_list_t *reset_ids
);
void OpenAPI_service_parameter_data_free(OpenAPI_service_parameter_data_t *service_parameter_data);
OpenAPI_service_parameter_data_t *OpenAPI_service_parameter_data_parseFromJSON(cJSON *service_parameter_dataJSON);
cJSON *OpenAPI_service_parameter_data_convertToJSON(OpenAPI_service_parameter_data_t *service_parameter_data);
OpenAPI_service_parameter_data_t *OpenAPI_service_parameter_data_copy(OpenAPI_service_parameter_data_t *dst, OpenAPI_service_parameter_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_service_parameter_data_H_ */

