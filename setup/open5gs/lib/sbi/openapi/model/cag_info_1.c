
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cag_info_1.h"

OpenAPI_cag_info_1_t *OpenAPI_cag_info_1_create(
    OpenAPI_list_t *allowed_cag_list,
    bool is_cag_only_indicator,
    int cag_only_indicator
)
{
    OpenAPI_cag_info_1_t *cag_info_1_local_var = ogs_malloc(sizeof(OpenAPI_cag_info_1_t));
    ogs_assert(cag_info_1_local_var);

    cag_info_1_local_var->allowed_cag_list = allowed_cag_list;
    cag_info_1_local_var->is_cag_only_indicator = is_cag_only_indicator;
    cag_info_1_local_var->cag_only_indicator = cag_only_indicator;

    return cag_info_1_local_var;
}

void OpenAPI_cag_info_1_free(OpenAPI_cag_info_1_t *cag_info_1)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == cag_info_1) {
        return;
    }
    if (cag_info_1->allowed_cag_list) {
        OpenAPI_list_for_each(cag_info_1->allowed_cag_list, node) {
            ogs_free(node->data);
        }
        OpenAPI_list_free(cag_info_1->allowed_cag_list);
        cag_info_1->allowed_cag_list = NULL;
    }
    ogs_free(cag_info_1);
}

cJSON *OpenAPI_cag_info_1_convertToJSON(OpenAPI_cag_info_1_t *cag_info_1)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (cag_info_1 == NULL) {
        ogs_error("OpenAPI_cag_info_1_convertToJSON() failed [CagInfo_1]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (!cag_info_1->allowed_cag_list) {
        ogs_error("OpenAPI_cag_info_1_convertToJSON() failed [allowed_cag_list]");
        return NULL;
    }
    cJSON *allowed_cag_listList = cJSON_AddArrayToObject(item, "allowedCagList");
    if (allowed_cag_listList == NULL) {
        ogs_error("OpenAPI_cag_info_1_convertToJSON() failed [allowed_cag_list]");
        goto end;
    }
    OpenAPI_list_for_each(cag_info_1->allowed_cag_list, node) {
        if (cJSON_AddStringToObject(allowed_cag_listList, "", (char*)node->data) == NULL) {
            ogs_error("OpenAPI_cag_info_1_convertToJSON() failed [allowed_cag_list]");
            goto end;
        }
    }

    if (cag_info_1->is_cag_only_indicator) {
    if (cJSON_AddBoolToObject(item, "cagOnlyIndicator", cag_info_1->cag_only_indicator) == NULL) {
        ogs_error("OpenAPI_cag_info_1_convertToJSON() failed [cag_only_indicator]");
        goto end;
    }
    }

end:
    return item;
}

OpenAPI_cag_info_1_t *OpenAPI_cag_info_1_parseFromJSON(cJSON *cag_info_1JSON)
{
    OpenAPI_cag_info_1_t *cag_info_1_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    cJSON *allowed_cag_list = NULL;
    OpenAPI_list_t *allowed_cag_listList = NULL;
    cJSON *cag_only_indicator = NULL;
    allowed_cag_list = cJSON_GetObjectItemCaseSensitive(cag_info_1JSON, "allowedCagList");
    if (!allowed_cag_list) {
        ogs_error("OpenAPI_cag_info_1_parseFromJSON() failed [allowed_cag_list]");
        goto end;
    }
        cJSON *allowed_cag_list_local = NULL;
        if (!cJSON_IsArray(allowed_cag_list)) {
            ogs_error("OpenAPI_cag_info_1_parseFromJSON() failed [allowed_cag_list]");
            goto end;
        }

        allowed_cag_listList = OpenAPI_list_create();

        cJSON_ArrayForEach(allowed_cag_list_local, allowed_cag_list) {
            double *localDouble = NULL;
            int *localInt = NULL;
            if (!cJSON_IsString(allowed_cag_list_local)) {
                ogs_error("OpenAPI_cag_info_1_parseFromJSON() failed [allowed_cag_list]");
                goto end;
            }
            OpenAPI_list_add(allowed_cag_listList, ogs_strdup(allowed_cag_list_local->valuestring));
        }

    cag_only_indicator = cJSON_GetObjectItemCaseSensitive(cag_info_1JSON, "cagOnlyIndicator");
    if (cag_only_indicator) {
    if (!cJSON_IsBool(cag_only_indicator)) {
        ogs_error("OpenAPI_cag_info_1_parseFromJSON() failed [cag_only_indicator]");
        goto end;
    }
    }

    cag_info_1_local_var = OpenAPI_cag_info_1_create (
        allowed_cag_listList,
        cag_only_indicator ? true : false,
        cag_only_indicator ? cag_only_indicator->valueint : 0
    );

    return cag_info_1_local_var;
end:
    if (allowed_cag_listList) {
        OpenAPI_list_for_each(allowed_cag_listList, node) {
            ogs_free(node->data);
        }
        OpenAPI_list_free(allowed_cag_listList);
        allowed_cag_listList = NULL;
    }
    return NULL;
}

OpenAPI_cag_info_1_t *OpenAPI_cag_info_1_copy(OpenAPI_cag_info_1_t *dst, OpenAPI_cag_info_1_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_cag_info_1_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_cag_info_1_convertToJSON() failed");
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

    OpenAPI_cag_info_1_free(dst);
    dst = OpenAPI_cag_info_1_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

