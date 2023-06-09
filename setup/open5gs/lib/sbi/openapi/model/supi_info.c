
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "supi_info.h"

OpenAPI_supi_info_t *OpenAPI_supi_info_create(
    OpenAPI_list_t *supi_list
)
{
    OpenAPI_supi_info_t *supi_info_local_var = ogs_malloc(sizeof(OpenAPI_supi_info_t));
    ogs_assert(supi_info_local_var);

    supi_info_local_var->supi_list = supi_list;

    return supi_info_local_var;
}

void OpenAPI_supi_info_free(OpenAPI_supi_info_t *supi_info)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == supi_info) {
        return;
    }
    if (supi_info->supi_list) {
        OpenAPI_list_for_each(supi_info->supi_list, node) {
            ogs_free(node->data);
        }
        OpenAPI_list_free(supi_info->supi_list);
        supi_info->supi_list = NULL;
    }
    ogs_free(supi_info);
}

cJSON *OpenAPI_supi_info_convertToJSON(OpenAPI_supi_info_t *supi_info)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (supi_info == NULL) {
        ogs_error("OpenAPI_supi_info_convertToJSON() failed [SupiInfo]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (!supi_info->supi_list) {
        ogs_error("OpenAPI_supi_info_convertToJSON() failed [supi_list]");
        return NULL;
    }
    cJSON *supi_listList = cJSON_AddArrayToObject(item, "supiList");
    if (supi_listList == NULL) {
        ogs_error("OpenAPI_supi_info_convertToJSON() failed [supi_list]");
        goto end;
    }
    OpenAPI_list_for_each(supi_info->supi_list, node) {
        if (cJSON_AddStringToObject(supi_listList, "", (char*)node->data) == NULL) {
            ogs_error("OpenAPI_supi_info_convertToJSON() failed [supi_list]");
            goto end;
        }
    }

end:
    return item;
}

OpenAPI_supi_info_t *OpenAPI_supi_info_parseFromJSON(cJSON *supi_infoJSON)
{
    OpenAPI_supi_info_t *supi_info_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    cJSON *supi_list = NULL;
    OpenAPI_list_t *supi_listList = NULL;
    supi_list = cJSON_GetObjectItemCaseSensitive(supi_infoJSON, "supiList");
    if (!supi_list) {
        ogs_error("OpenAPI_supi_info_parseFromJSON() failed [supi_list]");
        goto end;
    }
        cJSON *supi_list_local = NULL;
        if (!cJSON_IsArray(supi_list)) {
            ogs_error("OpenAPI_supi_info_parseFromJSON() failed [supi_list]");
            goto end;
        }

        supi_listList = OpenAPI_list_create();

        cJSON_ArrayForEach(supi_list_local, supi_list) {
            double *localDouble = NULL;
            int *localInt = NULL;
            if (!cJSON_IsString(supi_list_local)) {
                ogs_error("OpenAPI_supi_info_parseFromJSON() failed [supi_list]");
                goto end;
            }
            OpenAPI_list_add(supi_listList, ogs_strdup(supi_list_local->valuestring));
        }

    supi_info_local_var = OpenAPI_supi_info_create (
        supi_listList
    );

    return supi_info_local_var;
end:
    if (supi_listList) {
        OpenAPI_list_for_each(supi_listList, node) {
            ogs_free(node->data);
        }
        OpenAPI_list_free(supi_listList);
        supi_listList = NULL;
    }
    return NULL;
}

OpenAPI_supi_info_t *OpenAPI_supi_info_copy(OpenAPI_supi_info_t *dst, OpenAPI_supi_info_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_supi_info_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_supi_info_convertToJSON() failed");
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

    OpenAPI_supi_info_free(dst);
    dst = OpenAPI_supi_info_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

