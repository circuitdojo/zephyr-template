/*
 * Copyright (c) 2022 Circuit Dojo LLC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <string.h>

#include <app_version.h>

struct app_version app_version_get(void)
{
    enum app_version_build_type build_type = app_version_build_debug;

    // Determines if it's a release build
    if (strcmp(CONFIG_APP_RELEASE_TYPE, "release") == 0)
    {
        build_type = app_version_build_release;
    }

    // Then creates the app_version
    struct app_version version =
        {
            .major = CONFIG_APP_VERSION_MAJOR,
            .minior = CONFIG_APP_VERSION_MINOR,
            .patch = CONFIG_APP_VERSION_PATCH,
            .commit = CONFIG_APP_VERSION_COMMIT,
            .build_type = build_type};

    // Copy the hash
    memcpy(version.hash, CONFIG_APP_VERSION_HASH, sizeof(version.hash));

    return version;
}