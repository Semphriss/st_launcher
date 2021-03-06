//  SuperTux Debug Helper Functions
//  Copyright (C) 2006 Christoph Sommer <christoph.sommer@2006.expires.deltadevelopment.de>
//  Copyright (C) 2010 Florian Forster <supertux at octo.it>
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

#include "util/log.hpp"

#include <iostream>

LogLevel g_log_level = LOG_WARNING;


static std::ostream& log_generic_f (const char *prefix, const char* file, int line)
{
  std::cerr << prefix << " " << file << ":" << line << " ";
  return std::cerr;
}

std::ostream& log_debug_f(const char* file, int line)
{
  return (log_generic_f ("[DEBUG]", file, line));
}

std::ostream& log_info_f(const char* file, int line)
{
  return (log_generic_f ("[INFO]", file, line));
}

std::ostream& log_warning_f(const char* file, int line)
{
  return (log_generic_f ("[WARNING]", file, line));
}

std::ostream& log_fatal_f(const char* file, int line)
{
  return (log_generic_f ("[FATAL]", file, line));
}

/* EOF */
