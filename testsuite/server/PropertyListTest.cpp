// 
//   Copyright (C) 2005, 2006, 2007 Free Software Foundation, Inc.
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "PropertyList.h"
#include "DummyMovieDefinition.h"
#include "VM.h"
#include "as_object.h" // need to set as owner of PropertyList
#include "as_value.h"
#include "log.h"
#include "smart_ptr.h"
#include "as_prop_flags.h"

#include <iostream>
#include <sstream>
#include <cassert>
#include <string>
#include <utility> // for make_pair

#include "check.h"

using namespace std;
using namespace gnash;

int
main(int /*argc*/, char** /*argv*/)
{
	gnash::LogFile& dbglogfile = gnash::LogFile::getDefaultInstance();
	dbglogfile.setVerbosity();

	// Initialize gnash lib
	gnashInit();

	boost::intrusive_ptr<movie_definition> md5 ( new DummyMovieDefinition(5) );
	boost::intrusive_ptr<movie_definition> md6 ( new DummyMovieDefinition(6) );

	VM& vm = VM::init(*md5);
    	vm.getRoot().setRootMovie( md5->create_movie_instance() );

	log_debug("VM version %d", vm.getSWFVersion());

	as_object obj;
	PropertyList props;

	as_value val("value");
	as_value val2("value2");
	as_value val3("value3");
	as_value ret;

	check_equals(props.size(), 0);
	check ( props.setValue(string_table::find("Var0"), val, obj) );
	check_equals(props.size(), 1);

	check ( props.getValue(string_table::find("Var0"), ret, obj) );
	check_equals ( ret, val );

	// search should be case-sensitive
	check ( ! props.getValue(string_table::find("var0"), ret, obj) );

	// new value overrides existing value
	check ( props.setValue(string_table::find("Var0"), val2, obj) );
	check_equals(props.size(), 1);
	check ( props.getValue(string_table::find("Var0"), ret, obj) );
	check_equals ( ret, val2 );

	// case-sensitive setting value doesn't overrides existing value
	check ( props.setValue(string_table::find("var0"), val3, obj) );
	check_equals(props.size(), 2);
	check ( ! props.getValue(string_table::find("vAr0"), ret, obj) );

	// Now add some new labels
	check ( props.setValue(string_table::find("var1"), val, obj) );
	check_equals(props.size(), 3);
	check ( props.setValue(string_table::find("var2"), val, obj) );
	check_equals(props.size(), 4);
	check ( props.setValue(string_table::find("var3"), val, obj) );
	check_equals(props.size(), 5);

	// Test deletion of properties

	// this succeeds
	check(props.delProperty(string_table::find("var3")).second);
	check_equals(props.size(), 4);

	// this fails (non existent property)
	check(!props.delProperty(string_table::find("non-existent")).first);
	check_equals(props.size(), 4);

	// Set property var2 as protected from deletion!
	check(props.setFlags(string_table::find("var2"), as_prop_flags::dontDelete, 0));
	// this fails (protected from deletion)
	std::pair<bool, bool> delpair = props.delProperty(string_table::find("var2"));
	check_equals(delpair.first, true); // property was found
	check_equals(delpair.second, false); // property was NOT deleted
	check_equals(props.size(), 4);

	std::map<std::string, std::string> vals;
	props.enumerateKeyValue(obj, vals);
	check_equals( vals.size(), 4 );
	check_equals( vals["var0"], "value3" );
	check_equals( vals["Var0"], "value2" );
	check_equals( vals["var1"], "value" );

}

