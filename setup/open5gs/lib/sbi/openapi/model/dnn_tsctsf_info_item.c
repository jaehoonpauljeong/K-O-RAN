
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dnn_tsctsf_info_item.h"

OpenAPI_dnn_tsctsf_info_item_t *OpenAPI_dnn_tsctsf_info_item_create(
    char *dnn
)
{
    OpenAPI_dnn_tsctsf_info_item_t *dnn_tsctsf_info_item_local_var = ogs_malloc(sizeof(OpenAPI_dnn_tsctsf_info_item_t));
    ogs_assert(dnn_tsctsf_info_item_local_var);

    dnn_tsctsf_info_item_local_var->dnn = dnn;

    return dnn_tsctsf_info_item_local_var;
}

void OpenAPI_dnn_tsctsf_info_item_free(OpenAPI_dnn_tsctsf_info_item_t *dnn_tsctsf_info_item)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == dnn_tsctsf_info_item) {
        return;
    }
    if (dnn_tsctsf_info_item->dnn) {
        ogs_free(dnn_tsctsf_info_item->dnn);
        dnn_tsctsf_info_item->dnn = NULL;
    }
    ogs_free(dnn_tsctsf_info_item);
}

cJSON *OpenAPI_dnn_tsctsf_info_item_convertToJSON(OpenAPI_dnn_tsctsf_info_item_t *dnn_tsctsf_info_item)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (dnn_tsctsf_info_item == NULL) {
        ogs_error("OpenAPI_dnn_tsctsf_info_item_convertToJSON() failed [DnnTsctsfInfoItem]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (!dnn_tsctsf_info_item->dnn) {
        ogs_error("OpenAPI_dnn_tsctsf_info_item_convertToJSON() failed [dnn]");
        return NULL;
    }
    if (cJSON_AddStringToObject(item, "dnn", dnn_tsctsf_info_item->dnn) == NULL) {
        ogs_error("OpenAPI_dnn_tsctsf_info_item_convertToJSON() failed [dnn]");
        goto end;
    }

end:
    return item;
}

OpenAPI_dnn_tsctsf_info_item_t *OpenAPI_dnn_tsctsf_info_item_parseFromJSON(cJSON *dnn_tsctsf_info_itemJSON)
{
    OpenAPI_dnn_tsctsf_info_item_t *dnn_tsctsf_info_item_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    cJSON *dnn = NULL;
    dnn = cJSON_GetObjectItemCaseSensitive(dnn_tsctsf_info_itemJSON, "dnn");
    if (!dnn) {
        ogs_error("OpenAPI_dnn_tsctsf_info_item_parseFromJSON() failed [dnn]");
        goto end;
    }
    if (!cJSON_IsString(dnn)) {
        ogs_error("OpenAPI_dnn_tsctsf_info_item_parseFromJSON() failed [dnn]");
        goto end;
    }

    dnn_tsctsf_info_item_local_var = OpenAPI_dnn_tsctsf_info_item_create (
        ogs_strdup(dnn->valuestring)
    );

    return dnn_tsctsf_info_item_local_var;
end:
    return NULL;
}

OpenAPI_dnn_tsctsf_info_item_t *OpenAPI_dnn_tsctsf_info_item_copy(OpenAPI_dnn_tsctsf_info_item_t *dst, OpenAPI_dnn_tsctsf_info_item_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_dnn_tsctsf_info_item_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_dnn_tsctsf_info_item_convertToJSON() failed");
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

    OpenAPI_dnn_tsctsf_info_item_free(dst);
    dst = OpenAPI_dnn_tsctsf_info_item_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

