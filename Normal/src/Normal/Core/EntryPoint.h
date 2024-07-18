#pragma once
#include <NormalEngine.h>

#ifndef __ENTRY_POINT_H__
#define __ENTRY_POINT_H__

	#ifdef NR_PLATFORM_WINDOWS

	extern Normal::Application* Normal::CreateApplication();

	#endif /*NR_PLATFORM_WINDOWS*/
#endif /*__ENTRY_POINT_H__*/