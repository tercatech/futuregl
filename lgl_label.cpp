/*
  Copyright 2017 Carter Turnbaugh

  This file is part of LGL.

  LGL is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  LGL is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with LGL.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "lgl_label.h"

using namespace lgl;

label::label(int color, int column, int row, int height, string text)
	: object(color), m_column(column), m_row(row), m_height(height), m_text(text) {}

void label::draw_shapes(){
	full_rectangle(m_column, m_column, m_row, m_row + m_height);

	draw_text(m_column, m_row, m_text);
}
