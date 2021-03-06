// KeyboardEvent_as.hx:  ActionScript 3 "KeyboardEvent" class, for Gnash.
//
// Generated by gen-as3.sh on: 20090515 by "rob". Remove this
// after any hand editing loosing changes.
//
//   Copyright (C) 2009, 2010 Free Software Foundation, Inc.
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
import flash.events.KeyboardEvent;
import flash.display.MovieClip;
#end
import flash.Lib;
import Type;
import Std;

// import our testing API
import DejaGnu;

// Class must be named with the _as suffix, as that's the same name as the file.
class KeyboardEvent_as {
    static function main() {
        #if !flash9
			DejaGnu.note("this class didn't exist in as2");
		#end
		
		#if flash9
		var x1:KeyboardEvent = new KeyboardEvent("keyboardevent");

        // Make sure we actually get a valid class        
        if (x1 != null) {
            DejaGnu.pass("KeyboardEvent class exists");
        } else {
            DejaGnu.fail("KeyboardEvent class doesn't exist");
        }
// Tests to see if all the properties exist. All these do is test for
// existance of a property, and don't test the functionality at all. This
// is primarily useful only to test completeness of the API implementation.
	if (Std.is(x1.altKey, Bool)) {
	    DejaGnu.pass("KeyboardEvent.altKey property exists");
	} else {
	    DejaGnu.fail("KeyboardEvent.altKey property doesn't exist");
	}
	if (Std.is(x1.charCode, Float)) {
	    DejaGnu.pass("KeyboardEvent.charCode property exists");
	} else {
	    DejaGnu.fail("KeyboardEvent.charCode property doesn't exist");
	}
	if (Std.is(x1.ctrlKey, Bool)) {
	    DejaGnu.pass("KeyboardEvent.ctrlKey property exists");
	} else {
	    DejaGnu.fail("KeyboardEvent.ctrlKey property doesn't exist");
	}
	if (Std.is(x1.keyCode, Float)) {
	    DejaGnu.pass("KeyboardEvent.keyCode property exists");
	} else {
	    DejaGnu.fail("KeyboardEvent.keyCode property doesn't exist");
	}
	if (Std.is(x1.keyLocation, Float)) {
	    DejaGnu.pass("KeyboardEvent.keyLocation property exists");
	} else {
	    DejaGnu.fail("KeyboardEvent.keyLocation property doesn't exist");
	}
	if (Std.is(x1.shiftKey, Bool)) {
	    DejaGnu.pass("KeyboardEvent.shiftKey property exists");
	} else {
	    DejaGnu.fail("KeyboardEvent.shiftKey property doesn't exist");
	}

// Tests to see if all the methods exist. All these do is test for
// existance of a method, and don't test the functionality at all. This
// is primarily useful only to test completeness of the API implementation.
	if (Type.typeof(x1.clone) == ValueType.TFunction) {
	    DejaGnu.pass("KeyboardEvent::clone() method exists");
	} else {
	    DejaGnu.fail("KeyboardEvent::clone() method doesn't exist");
	}
	if (Type.typeof(x1.toString) == ValueType.TFunction) {
	    DejaGnu.pass("KeyboardEvent::toString() method exists");
	} else {
	    DejaGnu.fail("KeyboardEvent::toString() method doesn't exist");
	}
	if (Type.typeof(x1.updateAfterEvent) == ValueType.TFunction) {
	    DejaGnu.pass("KeyboardEvent::updateAfterEvent() method exists");
	} else {
	    DejaGnu.fail("KeyboardEvent::updateAfterEvent() method doesn't exist");
	}
	if (Std.string(flash.events.KeyboardEvent.KEY_DOWN) == "keyDown") {
	    DejaGnu.pass("KeyboardEvent.KEY_DOWN property exists");
	} else {
	    DejaGnu.fail("KeyboardEvent.KEY_DOWN property doesn't exist");
	}
	if (Std.string(flash.events.KeyboardEvent.KEY_UP) == "keyUp") {
	    DejaGnu.pass("KeyboardEvent.KEY_UP property exists");
	} else {
	    DejaGnu.fail("KeyboardEvent.KEY_UP property doesn't exist");
	}
	#end
        // Call this after finishing all tests. It prints out the totals.
        DejaGnu.done();
    }
}

// local Variables:
// mode: C++
// indent-tabs-mode: t
// End:

