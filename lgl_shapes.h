/*
  Copyright 2015 Carter Turnbaugh

  This file is part of FutureGL.

  FutureGL is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  FutureGL is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with FutureGL.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#ifndef LGL_SHAPES
#define LGL_SHAPES 0

#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <cmath>

namespace lgl_shapes{
	void rectangle(int corner_x_left, int corner_x_right, int corner_y_bottom, int corner_y_top);
	void arc(int center_x, int center_y, int radius, int start_angle, int end_angle);
}

#endif
