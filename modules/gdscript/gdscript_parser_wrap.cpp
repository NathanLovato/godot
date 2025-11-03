/*************************************************************************/
/*  gdscript_parser_wrap.cpp                                             */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2022 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2022 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#include "gdscript_parser_wrap.h"

void GDScriptParserWrap::_bind_methods() {
	ClassDB::bind_method(D_METHOD("parse_script"), &GDScriptParserWrap::parse_script);
	ClassDB::bind_method(D_METHOD("has_error"), &GDScriptParserWrap::has_error);
	ClassDB::bind_method(D_METHOD("get_error"), &GDScriptParserWrap::get_error);
	ClassDB::bind_method(D_METHOD("get_error_line"), &GDScriptParserWrap::get_error_line);
	ClassDB::bind_method(D_METHOD("get_error_column"), &GDScriptParserWrap::get_error_column);
}

Error GDScriptParserWrap::parse_script(String p_content) {
	parser = memnew(GDScriptParser);
	return parser->parse(p_content);
}

bool GDScriptParserWrap::has_error() const {
	if (parser != nullptr) {
		return parser->has_error();
	}
	return true;
}

String GDScriptParserWrap::get_error() const {
	if (parser != nullptr) {
		return parser->get_error();
	}
	return "No script!";
}

int GDScriptParserWrap::get_error_line() const {
	if (parser != nullptr) {
		return parser->get_error_line();
	}
	return -1;
}

int GDScriptParserWrap::get_error_column() const {
	if (parser != nullptr) {
		return parser->get_error_column();
	}
	return -1;
}

GDScriptParserWrap::GDScriptParserWrap() {
	parser = nullptr;
}

GDScriptParserWrap::~GDScriptParserWrap() {
	if (parser != nullptr) {
		memdelete(parser);
		parser = nullptr;
	}
}
