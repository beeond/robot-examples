/* ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                        COPYRIGHT (c) 2009 - 2016
                                         HONEYWELL INC.,
                                        ALL RIGHTS RESERVED

            This software is a copyrighted work and/or information protected as a trade
            secret. Legal rights of Honeywell Inc. in this software are distinct from
            ownership of any medium in which the software is embodied. Copyright or trade
            secret notices included must be reproduced in any copies authorized by
            Honeywell Inc. The information in this software is subject to change without
            notice and should not be considered as a commitment by Honeywell Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

#ifndef _UASDK_CUSTOM_BUILD_CONFIG_
#define _UASDK_CUSTOM_BUILD_CONFIG_

#define UASDK_INCLUDE_SECURITY  0
#define UASDK_USE_MBEDTLS       0
#define UASDK_INCLUDE_SERVER_WINDOWS_LINUX_MT 1
#define UASDK_INCLUDE_TIMERS_CPP11 1
#define UASDK_INCLUDE_ATOMIC_CPP11 1
#define UASDK_INCLUDE_REF_COUNT_CPP11 1
#define UASDK_INCLUDE_THREAD_POOL_CPP11 1
#define UASDK_INCLUDE_LOCKS_WINDOWS 1
#define UASDK_INCLUDE_FILE_WINDOWS_LINUX 1
#define UASDK_INCLUDE_LIBRARY_WINDOWS_LINUX 1
#define UASDK_INCLUDE_TCPIP_WINDOWS_LINUX_SOCKETS_SELECT_MT 1
#define UASDK_INCLUDE_XML_SUPPORT 1
#define UASDK_USE_TINYXML2 1
#define UASDK_USE_HELPERS 1

#define UASDK_DEBUG 1
#define UASDK_DEBUG_SESSIONS 0
#define UASDK_DEBUG_CHANNELS 0
#define UASDK_DEBUG_CONNECTIONS 0

#define UASDK_INCLUDE_SERVER 1
#define UASDK_INCLUDE_CLIENT 0

#endif /*_UASDK_CUSTOM_BUILD_CONFIG_*/
