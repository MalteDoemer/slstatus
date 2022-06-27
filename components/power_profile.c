#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../util.h"

#define LOCAL_BUFFER_SIZE 32

const char* power_profile(void) 
{
    FILE *p = popen("powerprofilesctl get", "r");

    char buffer[LOCAL_BUFFER_SIZE];

    if (!fgets(buffer, LOCAL_BUFFER_SIZE, p)) 
    {
        warn("power_profile(): fgets() failed");
        pclose(p);
        return NULL;
    }

    const char *res = NULL;

    if (!strcmp(buffer, "performance\n"))
        res = "";
    else if (!strcmp(buffer, "balanced\n"))
        res = "";
    else if (!strcmp(buffer, "power-saver\n"))
        res = "\x04\x01";
    else
        warn("power_profile(): unable to parse output: '%s'", buffer);

    pclose(p);
    return res;
}