//  SuperTux Debug Helper Functions
//  Copyright (C) 2006 Christoph Sommer <christoph.sommer@2006.expires.deltadevelopment.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_STLAUNCHER_UTIL_LOG_HPP
#define HEADER_STLAUNCHER_UTIL_LOG_HPP

#include <ostream>

enum LogLevel { LOG_NONE, LOG_FATAL, LOG_WARNING, LOG_INFO, LOG_DEBUG };
extern LogLevel g_log_level;

std::ostream& log_debug_f(const char* file, int line);
#define log_debug if (g_log_level >= LOG_DEBUG) log_debug_f(__FILE__, __LINE__)

std::ostream& log_info_f(const char* file, int line);
#define log_info if (g_log_level >= LOG_INFO) log_info_f(__FILE__, __LINE__)

std::ostream& log_warning_f(const char* file, int line);
#define log_warning if (g_log_level >= LOG_WARNING) log_warning_f(__FILE__, __LINE__)

std::ostream& log_fatal_f(const char* file, int line);
#define log_fatal if (g_log_level >= LOG_FATAL) log_fatal_f(__FILE__, __LINE__)


#endif

/* EOF */
