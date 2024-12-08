#pragma once
#include <cassert>
#include "Precision.h"

#ifdef RAGON_EXPORTS
#define RAGON_DLL _declspec(dllexport)
#else
#define RAGON_DLL _declspec(dllimport)
#endif

#define BEGIN(name)					namespace name {
#define END							}

#define RIGHT_HANDED

using namespace Ragon;
