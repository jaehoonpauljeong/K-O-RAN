
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "session_rule_failure_code.h"

char* OpenAPI_session_rule_failure_code_ToString(OpenAPI_session_rule_failure_code_e session_rule_failure_code)
{
    const char *session_rule_failure_codeArray[] =  { "NULL", "NF_MAL", "RES_LIM", "SESSION_RESOURCE_ALLOCATION_FAILURE", "UNSUCC_QOS_VAL", "INCORRECT_UM", "UE_STA_SUSP", "UNKNOWN_REF_ID", "INCORRECT_COND_DATA", "REF_ID_COLLISION", "AN_GW_FAILED" };
    size_t sizeofArray = sizeof(session_rule_failure_codeArray) / sizeof(session_rule_failure_codeArray[0]);
    if (session_rule_failure_code < sizeofArray)
        return (char *)session_rule_failure_codeArray[session_rule_failure_code];
    else
        return (char *)"Unknown";
}

OpenAPI_session_rule_failure_code_e OpenAPI_session_rule_failure_code_FromString(char* session_rule_failure_code)
{
    int stringToReturn = 0;
    const char *session_rule_failure_codeArray[] =  { "NULL", "NF_MAL", "RES_LIM", "SESSION_RESOURCE_ALLOCATION_FAILURE", "UNSUCC_QOS_VAL", "INCORRECT_UM", "UE_STA_SUSP", "UNKNOWN_REF_ID", "INCORRECT_COND_DATA", "REF_ID_COLLISION", "AN_GW_FAILED" };
    size_t sizeofArray = sizeof(session_rule_failure_codeArray) / sizeof(session_rule_failure_codeArray[0]);
    while (stringToReturn < sizeofArray) {
        if (strcmp(session_rule_failure_code, session_rule_failure_codeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

