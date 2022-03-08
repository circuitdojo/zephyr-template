/*
 * Copyright (c) 2022 Circuit Dojo LLC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>

#include <logging/log.h>
LOG_MODULE_REGISTER(app_main);

void main(void)
{
	LOG_INF("Hello World! %s", CONFIG_BOARD);
	LOG_INF("Version: %s", CONFIG_APP_VERSION);
}
