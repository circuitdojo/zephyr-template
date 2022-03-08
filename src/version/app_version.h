/*
 * Copyright (c) 2022 Circuit Dojo LLC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _APP_VERSION_H
#define _APP_VERSION_H

#include <zephyr.h>

enum app_version_build_type
{
    app_version_build_debug,
    app_version_build_release
};

struct app_version
{
    uint8_t major;
    uint8_t minior;
    uint8_t patch;
    uint8_t commit;
    char hash[8];
    enum app_version_build_type build_type;
};

struct app_version app_version_get(void);

#endif