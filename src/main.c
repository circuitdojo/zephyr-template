/*
 * Copyright Circuit Dojo (c) 2021
 * 
 * SPDX-License-Identifier: LicenseRef-Circuit-Dojo-5-Clause
 */

#include <zephyr.h>

#include <logging/log.h>
LOG_MODULE_REGISTER(app_main);

void main(void)
{
	LOG_INF("Hello World! %s", CONFIG_BOARD);
	LOG_INF("Version: %s", CONFIG_APP_VERSION);
}
