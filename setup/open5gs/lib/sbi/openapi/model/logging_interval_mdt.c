
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "logging_interval_mdt.h"

char* OpenAPI_logging_interval_mdt_ToString(OpenAPI_logging_interval_mdt_e logging_interval_mdt)
{
    const char *logging_interval_mdtArray[] =  { "NULL", "128", "256", "512", "1024", "2048", "3072", "4096", "6144" };
    size_t sizeofArray = sizeof(logging_interval_mdtArray) / sizeof(logging_interval_mdtArray[0]);
    if (logging_interval_mdt < sizeofArray)
        return (char *)logging_interval_mdtArray[logging_interval_mdt];
    else
        return (char *)"Unknown";
}

OpenAPI_logging_interval_mdt_e OpenAPI_logging_interval_mdt_FromString(char* logging_interval_mdt)
{
    int stringToReturn = 0;
    const char *logging_interval_mdtArray[] =  { "NULL", "128", "256", "512", "1024", "2048", "3072", "4096", "6144" };
    size_t sizeofArray = sizeof(logging_interval_mdtArray) / sizeof(logging_interval_mdtArray[0]);
    while (stringToReturn < sizeofArray) {
        if (strcmp(logging_interval_mdt, logging_interval_mdtArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

