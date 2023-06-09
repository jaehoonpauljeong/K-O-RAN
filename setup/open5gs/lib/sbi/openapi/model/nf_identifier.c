
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nf_identifier.h"

OpenAPI_nf_identifier_t *OpenAPI_nf_identifier_create(
    OpenAPI_nf_type_e nf_type,
    char *nf_instance_id
)
{
    OpenAPI_nf_identifier_t *nf_identifier_local_var = ogs_malloc(sizeof(OpenAPI_nf_identifier_t));
    ogs_assert(nf_identifier_local_var);

    nf_identifier_local_var->nf_type = nf_type;
    nf_identifier_local_var->nf_instance_id = nf_instance_id;

    return nf_identifier_local_var;
}

void OpenAPI_nf_identifier_free(OpenAPI_nf_identifier_t *nf_identifier)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == nf_identifier) {
        return;
    }
    if (nf_identifier->nf_instance_id) {
        ogs_free(nf_identifier->nf_instance_id);
        nf_identifier->nf_instance_id = NULL;
    }
    ogs_free(nf_identifier);
}

cJSON *OpenAPI_nf_identifier_convertToJSON(OpenAPI_nf_identifier_t *nf_identifier)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (nf_identifier == NULL) {
        ogs_error("OpenAPI_nf_identifier_convertToJSON() failed [NfIdentifier]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (nf_identifier->nf_type == OpenAPI_nf_type_NULL) {
        ogs_error("OpenAPI_nf_identifier_convertToJSON() failed [nf_type]");
        return NULL;
    }
    if (cJSON_AddStringToObject(item, "nfType", OpenAPI_nf_type_ToString(nf_identifier->nf_type)) == NULL) {
        ogs_error("OpenAPI_nf_identifier_convertToJSON() failed [nf_type]");
        goto end;
    }

    if (nf_identifier->nf_instance_id) {
    if (cJSON_AddStringToObject(item, "nfInstanceId", nf_identifier->nf_instance_id) == NULL) {
        ogs_error("OpenAPI_nf_identifier_convertToJSON() failed [nf_instance_id]");
        goto end;
    }
    }

end:
    return item;
}

OpenAPI_nf_identifier_t *OpenAPI_nf_identifier_parseFromJSON(cJSON *nf_identifierJSON)
{
    OpenAPI_nf_identifier_t *nf_identifier_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    cJSON *nf_type = NULL;
    OpenAPI_nf_type_e nf_typeVariable = 0;
    cJSON *nf_instance_id = NULL;
    nf_type = cJSON_GetObjectItemCaseSensitive(nf_identifierJSON, "nfType");
    if (!nf_type) {
        ogs_error("OpenAPI_nf_identifier_parseFromJSON() failed [nf_type]");
        goto end;
    }
    if (!cJSON_IsString(nf_type)) {
        ogs_error("OpenAPI_nf_identifier_parseFromJSON() failed [nf_type]");
        goto end;
    }
    nf_typeVariable = OpenAPI_nf_type_FromString(nf_type->valuestring);

    nf_instance_id = cJSON_GetObjectItemCaseSensitive(nf_identifierJSON, "nfInstanceId");
    if (nf_instance_id) {
    if (!cJSON_IsString(nf_instance_id) && !cJSON_IsNull(nf_instance_id)) {
        ogs_error("OpenAPI_nf_identifier_parseFromJSON() failed [nf_instance_id]");
        goto end;
    }
    }

    nf_identifier_local_var = OpenAPI_nf_identifier_create (
        nf_typeVariable,
        nf_instance_id && !cJSON_IsNull(nf_instance_id) ? ogs_strdup(nf_instance_id->valuestring) : NULL
    );

    return nf_identifier_local_var;
end:
    return NULL;
}

OpenAPI_nf_identifier_t *OpenAPI_nf_identifier_copy(OpenAPI_nf_identifier_t *dst, OpenAPI_nf_identifier_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_nf_identifier_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_nf_identifier_convertToJSON() failed");
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

    OpenAPI_nf_identifier_free(dst);
    dst = OpenAPI_nf_identifier_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

