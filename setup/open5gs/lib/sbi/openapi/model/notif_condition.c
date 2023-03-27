
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "notif_condition.h"

OpenAPI_notif_condition_t *OpenAPI_notif_condition_create(
    OpenAPI_list_t *monitored_attributes,
    OpenAPI_list_t *unmonitored_attributes
)
{
    OpenAPI_notif_condition_t *notif_condition_local_var = ogs_malloc(sizeof(OpenAPI_notif_condition_t));
    ogs_assert(notif_condition_local_var);

    notif_condition_local_var->monitored_attributes = monitored_attributes;
    notif_condition_local_var->unmonitored_attributes = unmonitored_attributes;

    return notif_condition_local_var;
}

void OpenAPI_notif_condition_free(OpenAPI_notif_condition_t *notif_condition)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == notif_condition) {
        return;
    }
    if (notif_condition->monitored_attributes) {
        OpenAPI_list_for_each(notif_condition->monitored_attributes, node) {
            ogs_free(node->data);
        }
        OpenAPI_list_free(notif_condition->monitored_attributes);
        notif_condition->monitored_attributes = NULL;
    }
    if (notif_condition->unmonitored_attributes) {
        OpenAPI_list_for_each(notif_condition->unmonitored_attributes, node) {
            ogs_free(node->data);
        }
        OpenAPI_list_free(notif_condition->unmonitored_attributes);
        notif_condition->unmonitored_attributes = NULL;
    }
    ogs_free(notif_condition);
}

cJSON *OpenAPI_notif_condition_convertToJSON(OpenAPI_notif_condition_t *notif_condition)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (notif_condition == NULL) {
        ogs_error("OpenAPI_notif_condition_convertToJSON() failed [NotifCondition]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (notif_condition->monitored_attributes) {
    cJSON *monitored_attributesList = cJSON_AddArrayToObject(item, "monitoredAttributes");
    if (monitored_attributesList == NULL) {
        ogs_error("OpenAPI_notif_condition_convertToJSON() failed [monitored_attributes]");
        goto end;
    }
    OpenAPI_list_for_each(notif_condition->monitored_attributes, node) {
        if (cJSON_AddStringToObject(monitored_attributesList, "", (char*)node->data) == NULL) {
            ogs_error("OpenAPI_notif_condition_convertToJSON() failed [monitored_attributes]");
            goto end;
        }
    }
    }

    if (notif_condition->unmonitored_attributes) {
    cJSON *unmonitored_attributesList = cJSON_AddArrayToObject(item, "unmonitoredAttributes");
    if (unmonitored_attributesList == NULL) {
        ogs_error("OpenAPI_notif_condition_convertToJSON() failed [unmonitored_attributes]");
        goto end;
    }
    OpenAPI_list_for_each(notif_condition->unmonitored_attributes, node) {
        if (cJSON_AddStringToObject(unmonitored_attributesList, "", (char*)node->data) == NULL) {
            ogs_error("OpenAPI_notif_condition_convertToJSON() failed [unmonitored_attributes]");
            goto end;
        }
    }
    }

end:
    return item;
}

OpenAPI_notif_condition_t *OpenAPI_notif_condition_parseFromJSON(cJSON *notif_conditionJSON)
{
    OpenAPI_notif_condition_t *notif_condition_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    cJSON *monitored_attributes = NULL;
    OpenAPI_list_t *monitored_attributesList = NULL;
    cJSON *unmonitored_attributes = NULL;
    OpenAPI_list_t *unmonitored_attributesList = NULL;
    monitored_attributes = cJSON_GetObjectItemCaseSensitive(notif_conditionJSON, "monitoredAttributes");
    if (monitored_attributes) {
        cJSON *monitored_attributes_local = NULL;
        if (!cJSON_IsArray(monitored_attributes)) {
            ogs_error("OpenAPI_notif_condition_parseFromJSON() failed [monitored_attributes]");
            goto end;
        }

        monitored_attributesList = OpenAPI_list_create();

        cJSON_ArrayForEach(monitored_attributes_local, monitored_attributes) {
            double *localDouble = NULL;
            int *localInt = NULL;
            if (!cJSON_IsString(monitored_attributes_local)) {
                ogs_error("OpenAPI_notif_condition_parseFromJSON() failed [monitored_attributes]");
                goto end;
            }
            OpenAPI_list_add(monitored_attributesList, ogs_strdup(monitored_attributes_local->valuestring));
        }
    }

    unmonitored_attributes = cJSON_GetObjectItemCaseSensitive(notif_conditionJSON, "unmonitoredAttributes");
    if (unmonitored_attributes) {
        cJSON *unmonitored_attributes_local = NULL;
        if (!cJSON_IsArray(unmonitored_attributes)) {
            ogs_error("OpenAPI_notif_condition_parseFromJSON() failed [unmonitored_attributes]");
            goto end;
        }

        unmonitored_attributesList = OpenAPI_list_create();

        cJSON_ArrayForEach(unmonitored_attributes_local, unmonitored_attributes) {
            double *localDouble = NULL;
            int *localInt = NULL;
            if (!cJSON_IsString(unmonitored_attributes_local)) {
                ogs_error("OpenAPI_notif_condition_parseFromJSON() failed [unmonitored_attributes]");
                goto end;
            }
            OpenAPI_list_add(unmonitored_attributesList, ogs_strdup(unmonitored_attributes_local->valuestring));
        }
    }

    notif_condition_local_var = OpenAPI_notif_condition_create (
        monitored_attributes ? monitored_attributesList : NULL,
        unmonitored_attributes ? unmonitored_attributesList : NULL
    );

    return notif_condition_local_var;
end:
    if (monitored_attributesList) {
        OpenAPI_list_for_each(monitored_attributesList, node) {
            ogs_free(node->data);
        }
        OpenAPI_list_free(monitored_attributesList);
        monitored_attributesList = NULL;
    }
    if (unmonitored_attributesList) {
        OpenAPI_list_for_each(unmonitored_attributesList, node) {
            ogs_free(node->data);
        }
        OpenAPI_list_free(unmonitored_attributesList);
        unmonitored_attributesList = NULL;
    }
    return NULL;
}

OpenAPI_notif_condition_t *OpenAPI_notif_condition_copy(OpenAPI_notif_condition_t *dst, OpenAPI_notif_condition_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_notif_condition_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_notif_condition_convertToJSON() failed");
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

    OpenAPI_notif_condition_free(dst);
    dst = OpenAPI_notif_condition_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

