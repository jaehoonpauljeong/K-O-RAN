
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "steering_container.h"

OpenAPI_steering_container_t *OpenAPI_steering_container_create(
)
{
    OpenAPI_steering_container_t *steering_container_local_var = ogs_malloc(sizeof(OpenAPI_steering_container_t));
    ogs_assert(steering_container_local_var);


    return steering_container_local_var;
}

void OpenAPI_steering_container_free(OpenAPI_steering_container_t *steering_container)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == steering_container) {
        return;
    }
    ogs_free(steering_container);
}

cJSON *OpenAPI_steering_container_convertToJSON(OpenAPI_steering_container_t *steering_container)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (steering_container == NULL) {
        ogs_error("OpenAPI_steering_container_convertToJSON() failed [SteeringContainer]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_steering_container_t *OpenAPI_steering_container_parseFromJSON(cJSON *steering_containerJSON)
{
    OpenAPI_steering_container_t *steering_container_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    steering_container_local_var = OpenAPI_steering_container_create (
    );

    return steering_container_local_var;
end:
    return NULL;
}

OpenAPI_steering_container_t *OpenAPI_steering_container_copy(OpenAPI_steering_container_t *dst, OpenAPI_steering_container_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_steering_container_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_steering_container_convertToJSON() failed");
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

    OpenAPI_steering_container_free(dst);
    dst = OpenAPI_steering_container_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

