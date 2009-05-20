// IME_as3.hx:  ActionScript 3 "IME" class, for Gnash.
//
// Generated by gen-as3.sh on: 20090514 by "rob". Remove this
// after any hand editing loosing changes.
//
//   Copyright (C) 2009 Free Software Foundation, Inc.
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
//

// This test case must be processed by CPP before compiling to include the
//  DejaGnu.hx header file for the testing framework support.

#if flash9
import flash.system.IME;
import flash.display.MovieClip;
#else
import flash.IME;
import flash.MovieClip;
#end
import flash.Lib;
import Type;

// import our testing API
import DejaGnu;

// Class must be named with the _as3 suffix, as that's the same name as the file.
class IME_as {
    static function main() {
// Tests to see if all the properties exist. All these do is test for
// existance of a property, and don't test the functionality at all. This
// is primarily useful only to test completeness of the API implementation.
	if (IME.conversionMode == null) {
	    DejaGnu.pass("IME.conversionMode property exists");
	} else {
	    DejaGnu.fail("IME.conversionMode property doesn't exist");
	}
	if (IME.enabled == false) {
	    DejaGnu.pass("IME.enabled property exists");
	} else {
	    DejaGnu.fail("IME.enabled property doesn't exist");
	}

// Tests to see if all the methods exist. All these do is test for
// existance of a method, and don't test the functionality at all. This
// is primarily useful only to test completeness of the API implementation.
	if (IME.doConversion == null) {
	    DejaGnu.pass("IME::doConversion() method exists");
	} else {
	    DejaGnu.fail("IME::doConversion() method doesn't exist");
	}
	if (IME.setCompositionString == null) {
	    DejaGnu.pass("IME::setCompositionString() method exists");
	} else {
	    DejaGnu.fail("IME::setCompositionString() method doesn't exist");
	}

        // Call this after finishing all tests. It prints out the totals.
        DejaGnu.done();
    }
}

// local Variables:
// mode: C++
// indent-tabs-mode: t
// End:

