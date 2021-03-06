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

#include "lgl_multibutton.h"
#include "lgl_utils.h"
#include "lgl_shapes.h"

using namespace std;

int lgl_multibutton::setvalue(int value){
	this->value = value;
}

int lgl_multibutton::draw(){

	if(value < 0) value = 0;
	if(value > 99) value = 99;

	lgl_utils::colors(era, color);
	
	lgl_shapes::rectangle(data.x1, data.x1+10, data.y1, data.y2);
	lgl_shapes::rectangle(data.x1+54, data.x1+lgl_const::button_width, data.y1, data.y2+lgl_const::gap*extend);
	
	string number = lgl_utils::its(value);
	if(value < 10) number = "0"+number;
	
	lgl_utils::draw_text(data.x1+15, data.y1+lgl_const::gap, 2, number, 0);

	return 0;
}
