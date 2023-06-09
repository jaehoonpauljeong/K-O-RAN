
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "measurement_period_lte_mdt.h"

char* OpenAPI_measurement_period_lte_mdt_ToString(OpenAPI_measurement_period_lte_mdt_e measurement_period_lte_mdt)
{
    const char *measurement_period_lte_mdtArray[] =  { "NULL", "1024", "1280", "2048", "2560", "5120", "10240", "60000" };
    size_t sizeofArray = sizeof(measurement_period_lte_mdtArray) / sizeof(measurement_period_lte_mdtArray[0]);
    if (measurement_period_lte_mdt < sizeofArray)
        return (char *)measurement_period_lte_mdtArray[measurement_period_lte_mdt];
    else
        return (char *)"Unknown";
}

OpenAPI_measurement_period_lte_mdt_e OpenAPI_measurement_period_lte_mdt_FromString(char* measurement_period_lte_mdt)
{
    int stringToReturn = 0;
    const char *measurement_period_lte_mdtArray[] =  { "NULL", "1024", "1280", "2048", "2560", "5120", "10240", "60000" };
    size_t sizeofArray = sizeof(measurement_period_lte_mdtArray) / sizeof(measurement_period_lte_mdtArray[0]);
    while (stringToReturn < sizeofArray) {
        if (strcmp(measurement_period_lte_mdt, measurement_period_lte_mdtArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

