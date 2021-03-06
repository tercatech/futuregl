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

#include "lgl_utils.h"

using namespace std;

namespace lgl_utils{

	const int num_fonts = 5;
	const string fonts[] = {"/usr/share/fonts/oxygen/OxygenMono-Regular.ttf",
				"/usr/share/fonts/bitstream-vera/VeraMono.ttf",
				"/usr/share/fonts/dejavu/DejaVuSansMono.ttf",
				"/usr/share/fonts/liberation/LiberationMono-Regular.ttf",
				"/usr/share/fonts/gnu-free/FreeSans.ttf"};

	string its(int in){
		stringstream ss;
		ss << in;
		return ss.str();
	}
	
	void colors(int era, int choice){
		if(era == 1){
			if(choice == 1) glColor3f(0.5f, 0.5f, 0.5f);
			else if(choice == 2) glColor3f(1.0f, 1.0f, 0.6f);
			else if(choice == 3) glColor3f(1.0f, 0.8f, 0.6f);
			else if(choice == 4) glColor3f(1.0f, 0.6f, 0.2f);
			else if(choice == 5) glColor3f(0.4f, 0.267f, 0.4f);
			else if(choice == 6) glColor3f(0.8f, 0.6f, 0.8f);
			else if(choice == 7) glColor3f(0.6f, 0.8f, 1.0f);
			else if(choice == 8) glColor3f(0.2f, 0.4f, 0.8f);
			else if(choice == 9) glColor3f(0.0f, 0.4f, 0.6f);
			else if(choice == 10) glColor3f(0.0f, 0.0f, 0.0f);
		}
		else if(era == 2){
			if(choice == 1) glColor3f(0.5f, 0.5f, 0.5f);
			else if(choice == 2) glColor3f(0.6f, 0.6f, 0.9f);
			else if(choice == 3) glColor3f(0.6f, 0.6f, 0.8f);
			else if(choice == 4) glColor3f(0.8f, 0.6f, 0.8f);
			else if(choice == 5) glColor3f(0.8f, 0.0f, 0.6f);
			else if(choice == 6) glColor3f(0.8f, 0.4f, 0.4f);
			else if(choice == 7) glColor3f(1.0f, 0.6f, 0.4f);
			else if(choice == 8) glColor3f(1.0f, 0.6f, 0.0f);
			else if(choice == 9) glColor3f(1.0f, 0.8f, 0.4f);
			else if(choice == 10) glColor3f(0.0f, 0.0f, 0.0f);
		}
		else if(era == 3){
			if(choice == 1) glColor3f(0.5f, 0.5f, 0.5f);
			else if(choice == 2) glColor3f(0.4f, 0.533f, 0.8f);
			else if(choice == 3) glColor3f(0.267f, 0.333f, 0.722f);
			else if(choice == 4) glColor3f(0.6f, 0.467f, 0.667f);
			else if(choice == 5) glColor3f(0.467f, 0.267f, 0.4f);
			else if(choice == 6) glColor3f(0.867f, 0.4f, 0.267f);
			else if(choice == 7) glColor3f(0.667f, 0.333f, 0.2f);
			else if(choice == 8) glColor3f(0.722f, 0.4f, 0.133f);
			else if(choice == 9) glColor3f(0.933f, 0.6f, 0.333f);
			else if(choice == 10) glColor3f(0.0f, 0.0f, 0.0f);
		}
		else if(era == 4){
			if(choice == 1) glColor3f(0.5f, 0.5f, 0.5f);
			else if(choice == 2) glColor3f(0.8f, 0.867f, 1.0f);
			else if(choice == 3) glColor3f(0.333f, 0.6f, 1.0f);
			else if(choice == 4) glColor3f(0.2f, 0.4f, 1.0f);
			else if(choice == 5) glColor3f(0.0f, 0.067f, 0.933f);
			else if(choice == 6) glColor3f(0.0f, 0.0f, 0.533f);
			else if(choice == 7) glColor3f(0.733f, 0.667f, 0.333f);
			else if(choice == 8) glColor3f(0.733f, 0.267f, 0.067f);
			else if(choice == 9) glColor3f(0.533f, 0.133f, 0.067f);
			else if(choice == 10) glColor3f(0.0f, 0.0f, 0.0f);
		}
		else {
			cout << "Coloring is null\n";
		}
	}
	
	int draw_text(int corner_x, int corner_y, int size, string text, int color){
	
		if((size > 4 || size < 1) && size < 10 ){
			cerr << "FutureGL Error: FutureGL only supports 4 core font sizes\nPlease adapt your code. Sorry.\n";
			return -1;
		}
	
		colors(1, color);
		glTranslated(corner_x, corner_y, 0);
	
		// Create a texture font from a TrueType file.

		FTFont *font;
		bool font_loaded = false;

		for(int i = 0; i < num_fonts; i++){
			font = new FTTextureFont(fonts[i].c_str());
			if(!(font->Error())){
				font_loaded = true;
				break;
			}
		}

		
		if(!font_loaded){
			cerr << "FutureGL Error: Font not found\nTried:\n";
			for(int i = 0; i < num_fonts; i++) cerr << "\t" << fonts[i] << "\n";
			return -1;
		}
	
		// Set the font size and render a small text.
		
		if(size == 1) font->FaceSize(60);
		else if(size == 2) font->FaceSize(29);
		else if(size == 3) font->FaceSize(10);
		else if(size == 4) font->FaceSize(10);
		else font->FaceSize(size);
		font->Render(text.c_str());

		delete(font);

		glTranslated(-corner_x, -corner_y, 0);
	
		return 0;
	}
}
