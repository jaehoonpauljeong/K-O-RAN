
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "preferred_search.h"

OpenAPI_preferred_search_t *OpenAPI_preferred_search_create(
    bool is_preferred_tai_match_ind,
    int preferred_tai_match_ind,
    bool is_preferred_full_plmn_match_ind,
    int preferred_full_plmn_match_ind,
    bool is_preferred_api_versions_match_ind,
    int preferred_api_versions_match_ind,
    bool is_other_api_versions_ind,
    int other_api_versions_ind,
    bool is_preferred_locality_match_ind,
    int preferred_locality_match_ind,
    bool is_other_locality_ind,
    int other_locality_ind,
    bool is_preferred_vendor_specific_features_ind,
    int preferred_vendor_specific_features_ind,
    bool is_preferred_collocated_nf_type_ind,
    int preferred_collocated_nf_type_ind,
    bool is_preferred_pgw_match_ind,
    int preferred_pgw_match_ind,
    bool is_preferred_analytics_delays_ind,
    int preferred_analytics_delays_ind
)
{
    OpenAPI_preferred_search_t *preferred_search_local_var = ogs_malloc(sizeof(OpenAPI_preferred_search_t));
    ogs_assert(preferred_search_local_var);

    preferred_search_local_var->is_preferred_tai_match_ind = is_preferred_tai_match_ind;
    preferred_search_local_var->preferred_tai_match_ind = preferred_tai_match_ind;
    preferred_search_local_var->is_preferred_full_plmn_match_ind = is_preferred_full_plmn_match_ind;
    preferred_search_local_var->preferred_full_plmn_match_ind = preferred_full_plmn_match_ind;
    preferred_search_local_var->is_preferred_api_versions_match_ind = is_preferred_api_versions_match_ind;
    preferred_search_local_var->preferred_api_versions_match_ind = preferred_api_versions_match_ind;
    preferred_search_local_var->is_other_api_versions_ind = is_other_api_versions_ind;
    preferred_search_local_var->other_api_versions_ind = other_api_versions_ind;
    preferred_search_local_var->is_preferred_locality_match_ind = is_preferred_locality_match_ind;
    preferred_search_local_var->preferred_locality_match_ind = preferred_locality_match_ind;
    preferred_search_local_var->is_other_locality_ind = is_other_locality_ind;
    preferred_search_local_var->other_locality_ind = other_locality_ind;
    preferred_search_local_var->is_preferred_vendor_specific_features_ind = is_preferred_vendor_specific_features_ind;
    preferred_search_local_var->preferred_vendor_specific_features_ind = preferred_vendor_specific_features_ind;
    preferred_search_local_var->is_preferred_collocated_nf_type_ind = is_preferred_collocated_nf_type_ind;
    preferred_search_local_var->preferred_collocated_nf_type_ind = preferred_collocated_nf_type_ind;
    preferred_search_local_var->is_preferred_pgw_match_ind = is_preferred_pgw_match_ind;
    preferred_search_local_var->preferred_pgw_match_ind = preferred_pgw_match_ind;
    preferred_search_local_var->is_preferred_analytics_delays_ind = is_preferred_analytics_delays_ind;
    preferred_search_local_var->preferred_analytics_delays_ind = preferred_analytics_delays_ind;

    return preferred_search_local_var;
}

void OpenAPI_preferred_search_free(OpenAPI_preferred_search_t *preferred_search)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == preferred_search) {
        return;
    }
    ogs_free(preferred_search);
}

cJSON *OpenAPI_preferred_search_convertToJSON(OpenAPI_preferred_search_t *preferred_search)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (preferred_search == NULL) {
        ogs_error("OpenAPI_preferred_search_convertToJSON() failed [PreferredSearch]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (preferred_search->is_preferred_tai_match_ind) {
    if (cJSON_AddBoolToObject(item, "preferredTaiMatchInd", preferred_search->preferred_tai_match_ind) == NULL) {
        ogs_error("OpenAPI_preferred_search_convertToJSON() failed [preferred_tai_match_ind]");
        goto end;
    }
    }

    if (preferred_search->is_preferred_full_plmn_match_ind) {
    if (cJSON_AddBoolToObject(item, "preferredFullPlmnMatchInd", preferred_search->preferred_full_plmn_match_ind) == NULL) {
        ogs_error("OpenAPI_preferred_search_convertToJSON() failed [preferred_full_plmn_match_ind]");
        goto end;
    }
    }

    if (preferred_search->is_preferred_api_versions_match_ind) {
    if (cJSON_AddBoolToObject(item, "preferredApiVersionsMatchInd", preferred_search->preferred_api_versions_match_ind) == NULL) {
        ogs_error("OpenAPI_preferred_search_convertToJSON() failed [preferred_api_versions_match_ind]");
        goto end;
    }
    }

    if (preferred_search->is_other_api_versions_ind) {
    if (cJSON_AddBoolToObject(item, "otherApiVersionsInd", preferred_search->other_api_versions_ind) == NULL) {
        ogs_error("OpenAPI_preferred_search_convertToJSON() failed [other_api_versions_ind]");
        goto end;
    }
    }

    if (preferred_search->is_preferred_locality_match_ind) {
    if (cJSON_AddBoolToObject(item, "preferredLocalityMatchInd", preferred_search->preferred_locality_match_ind) == NULL) {
        ogs_error("OpenAPI_preferred_search_convertToJSON() failed [preferred_locality_match_ind]");
        goto end;
    }
    }

    if (preferred_search->is_other_locality_ind) {
    if (cJSON_AddBoolToObject(item, "otherLocalityInd", preferred_search->other_locality_ind) == NULL) {
        ogs_error("OpenAPI_preferred_search_convertToJSON() failed [other_locality_ind]");
        goto end;
    }
    }

    if (preferred_search->is_preferred_vendor_specific_features_ind) {
    if (cJSON_AddBoolToObject(item, "preferredVendorSpecificFeaturesInd", preferred_search->preferred_vendor_specific_features_ind) == NULL) {
        ogs_error("OpenAPI_preferred_search_convertToJSON() failed [preferred_vendor_specific_features_ind]");
        goto end;
    }
    }

    if (preferred_search->is_preferred_collocated_nf_type_ind) {
    if (cJSON_AddBoolToObject(item, "preferredCollocatedNfTypeInd", preferred_search->preferred_collocated_nf_type_ind) == NULL) {
        ogs_error("OpenAPI_preferred_search_convertToJSON() failed [preferred_collocated_nf_type_ind]");
        goto end;
    }
    }

    if (preferred_search->is_preferred_pgw_match_ind) {
    if (cJSON_AddBoolToObject(item, "preferredPgwMatchInd", preferred_search->preferred_pgw_match_ind) == NULL) {
        ogs_error("OpenAPI_preferred_search_convertToJSON() failed [preferred_pgw_match_ind]");
        goto end;
    }
    }

    if (preferred_search->is_preferred_analytics_delays_ind) {
    if (cJSON_AddBoolToObject(item, "preferredAnalyticsDelaysInd", preferred_search->preferred_analytics_delays_ind) == NULL) {
        ogs_error("OpenAPI_preferred_search_convertToJSON() failed [preferred_analytics_delays_ind]");
        goto end;
    }
    }

end:
    return item;
}

OpenAPI_preferred_search_t *OpenAPI_preferred_search_parseFromJSON(cJSON *preferred_searchJSON)
{
    OpenAPI_preferred_search_t *preferred_search_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    cJSON *preferred_tai_match_ind = NULL;
    cJSON *preferred_full_plmn_match_ind = NULL;
    cJSON *preferred_api_versions_match_ind = NULL;
    cJSON *other_api_versions_ind = NULL;
    cJSON *preferred_locality_match_ind = NULL;
    cJSON *other_locality_ind = NULL;
    cJSON *preferred_vendor_specific_features_ind = NULL;
    cJSON *preferred_collocated_nf_type_ind = NULL;
    cJSON *preferred_pgw_match_ind = NULL;
    cJSON *preferred_analytics_delays_ind = NULL;
    preferred_tai_match_ind = cJSON_GetObjectItemCaseSensitive(preferred_searchJSON, "preferredTaiMatchInd");
    if (preferred_tai_match_ind) {
    if (!cJSON_IsBool(preferred_tai_match_ind)) {
        ogs_error("OpenAPI_preferred_search_parseFromJSON() failed [preferred_tai_match_ind]");
        goto end;
    }
    }

    preferred_full_plmn_match_ind = cJSON_GetObjectItemCaseSensitive(preferred_searchJSON, "preferredFullPlmnMatchInd");
    if (preferred_full_plmn_match_ind) {
    if (!cJSON_IsBool(preferred_full_plmn_match_ind)) {
        ogs_error("OpenAPI_preferred_search_parseFromJSON() failed [preferred_full_plmn_match_ind]");
        goto end;
    }
    }

    preferred_api_versions_match_ind = cJSON_GetObjectItemCaseSensitive(preferred_searchJSON, "preferredApiVersionsMatchInd");
    if (preferred_api_versions_match_ind) {
    if (!cJSON_IsBool(preferred_api_versions_match_ind)) {
        ogs_error("OpenAPI_preferred_search_parseFromJSON() failed [preferred_api_versions_match_ind]");
        goto end;
    }
    }

    other_api_versions_ind = cJSON_GetObjectItemCaseSensitive(preferred_searchJSON, "otherApiVersionsInd");
    if (other_api_versions_ind) {
    if (!cJSON_IsBool(other_api_versions_ind)) {
        ogs_error("OpenAPI_preferred_search_parseFromJSON() failed [other_api_versions_ind]");
        goto end;
    }
    }

    preferred_locality_match_ind = cJSON_GetObjectItemCaseSensitive(preferred_searchJSON, "preferredLocalityMatchInd");
    if (preferred_locality_match_ind) {
    if (!cJSON_IsBool(preferred_locality_match_ind)) {
        ogs_error("OpenAPI_preferred_search_parseFromJSON() failed [preferred_locality_match_ind]");
        goto end;
    }
    }

    other_locality_ind = cJSON_GetObjectItemCaseSensitive(preferred_searchJSON, "otherLocalityInd");
    if (other_locality_ind) {
    if (!cJSON_IsBool(other_locality_ind)) {
        ogs_error("OpenAPI_preferred_search_parseFromJSON() failed [other_locality_ind]");
        goto end;
    }
    }

    preferred_vendor_specific_features_ind = cJSON_GetObjectItemCaseSensitive(preferred_searchJSON, "preferredVendorSpecificFeaturesInd");
    if (preferred_vendor_specific_features_ind) {
    if (!cJSON_IsBool(preferred_vendor_specific_features_ind)) {
        ogs_error("OpenAPI_preferred_search_parseFromJSON() failed [preferred_vendor_specific_features_ind]");
        goto end;
    }
    }

    preferred_collocated_nf_type_ind = cJSON_GetObjectItemCaseSensitive(preferred_searchJSON, "preferredCollocatedNfTypeInd");
    if (preferred_collocated_nf_type_ind) {
    if (!cJSON_IsBool(preferred_collocated_nf_type_ind)) {
        ogs_error("OpenAPI_preferred_search_parseFromJSON() failed [preferred_collocated_nf_type_ind]");
        goto end;
    }
    }

    preferred_pgw_match_ind = cJSON_GetObjectItemCaseSensitive(preferred_searchJSON, "preferredPgwMatchInd");
    if (preferred_pgw_match_ind) {
    if (!cJSON_IsBool(preferred_pgw_match_ind)) {
        ogs_error("OpenAPI_preferred_search_parseFromJSON() failed [preferred_pgw_match_ind]");
        goto end;
    }
    }

    preferred_analytics_delays_ind = cJSON_GetObjectItemCaseSensitive(preferred_searchJSON, "preferredAnalyticsDelaysInd");
    if (preferred_analytics_delays_ind) {
    if (!cJSON_IsBool(preferred_analytics_delays_ind)) {
        ogs_error("OpenAPI_preferred_search_parseFromJSON() failed [preferred_analytics_delays_ind]");
        goto end;
    }
    }

    preferred_search_local_var = OpenAPI_preferred_search_create (
        preferred_tai_match_ind ? true : false,
        preferred_tai_match_ind ? preferred_tai_match_ind->valueint : 0,
        preferred_full_plmn_match_ind ? true : false,
        preferred_full_plmn_match_ind ? preferred_full_plmn_match_ind->valueint : 0,
        preferred_api_versions_match_ind ? true : false,
        preferred_api_versions_match_ind ? preferred_api_versions_match_ind->valueint : 0,
        other_api_versions_ind ? true : false,
        other_api_versions_ind ? other_api_versions_ind->valueint : 0,
        preferred_locality_match_ind ? true : false,
        preferred_locality_match_ind ? preferred_locality_match_ind->valueint : 0,
        other_locality_ind ? true : false,
        other_locality_ind ? other_locality_ind->valueint : 0,
        preferred_vendor_specific_features_ind ? true : false,
        preferred_vendor_specific_features_ind ? preferred_vendor_specific_features_ind->valueint : 0,
        preferred_collocated_nf_type_ind ? true : false,
        preferred_collocated_nf_type_ind ? preferred_collocated_nf_type_ind->valueint : 0,
        preferred_pgw_match_ind ? true : false,
        preferred_pgw_match_ind ? preferred_pgw_match_ind->valueint : 0,
        preferred_analytics_delays_ind ? true : false,
        preferred_analytics_delays_ind ? preferred_analytics_delays_ind->valueint : 0
    );

    return preferred_search_local_var;
end:
    return NULL;
}

OpenAPI_preferred_search_t *OpenAPI_preferred_search_copy(OpenAPI_preferred_search_t *dst, OpenAPI_preferred_search_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_preferred_search_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_preferred_search_convertToJSON() failed");
        return NULL;
    }

    content = cJSON_Print(item);
    cJSON_Delete(item);

    if (!content) {
        ogs_error("cJSON_Print() failed");
        return NULL;
    }

    item = cJSON_Parse(content);
    ogs_free(content);
    if (!item) {
        ogs_error("cJSON_Parse() failed");
        return NULL;
    }

    OpenAPI_preferred_search_free(dst);
    dst = OpenAPI_preferred_search_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

