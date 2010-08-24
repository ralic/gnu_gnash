// ASConversions.cpp	Conversions between AS and SWF types.
//
//   Copyright (C) 2005, 2006, 2007, 2008, 2009, 2010 Free Software
//   Foundation, Inc
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

#include "ASConversions.h"

#include <boost/cstdint.hpp>
#include <cmath>
#include <limits>

#include "as_object.h"
#include "log.h"
#include "Global_as.h"
#include "GnashNumeric.h"
#include "namedStrings.h"
#include "as_value.h"
#include "SWFMatrix.h"
#include "SWFCxForm.h"
#include "flash/geom/ColorTransform_as.h"

namespace gnash {

namespace {
    // Handle overflows from AS ColorTransform double.
    inline boost::int16_t truncateDouble(double d);
}

SWFMatrix
toSWFMatrix(as_object& m)
{
    // This is case sensitive.
    if (m.getMember(NSV::PROP_MATRIX_TYPE).to_string() == "box") {
        
        const double x = pixelsToTwips(m.getMember(NSV::PROP_X).to_number());
        const double y = pixelsToTwips(m.getMember(NSV::PROP_Y).to_number());
        const double w = pixelsToTwips(m.getMember(NSV::PROP_W).to_number());
        const double h = pixelsToTwips(m.getMember(NSV::PROP_H).to_number()); 
        const double r = m.getMember(NSV::PROP_R).to_number();
        const double a = std::cos(r) * w * 2;
        const double b = std::sin(r) * h * 2;
        const double c = -std::sin(r) * w * 2;
        const double d = std::cos(r) * h * 2;

        return SWFMatrix(a, b, c, d, x + w / 2.0, y + h / 2.0);
        
    }

    // Convert input matrix to SWFMatrix.
    const boost::int32_t a = truncateWithFactor<65536>(
            m.getMember(NSV::PROP_A).to_number());
    const boost::int32_t b = truncateWithFactor<65536>(
            m.getMember(NSV::PROP_B).to_number());
    const boost::int32_t c = truncateWithFactor<65536>(
            m.getMember(NSV::PROP_C).to_number());
    const boost::int32_t d = truncateWithFactor<65536>(
            m.getMember(NSV::PROP_D).to_number());

    const boost::int32_t tx = pixelsToTwips(
            m.getMember(NSV::PROP_TX).to_number());
    const boost::int32_t ty = pixelsToTwips(
            m.getMember(NSV::PROP_TY).to_number());
    return SWFMatrix(a, b, c, d, tx, ty);

}

SWFCxForm
toCxForm(const ColorTransform_as& tr)
{
    const int factor = 256;
    SWFCxForm c;
    c.ra = truncateDouble(tr.getRedMultiplier() * factor);
    c.ga = truncateDouble(tr.getGreenMultiplier() * factor);
    c.ba = truncateDouble(tr.getBlueMultiplier() * factor);
    c.aa = truncateDouble(tr.getAlphaMultiplier() * factor);
    c.rb = truncateDouble(tr.getRedOffset());
    c.gb = truncateDouble(tr.getGreenOffset());
    c.bb = truncateDouble(tr.getBlueOffset());
    c.ab = truncateDouble(tr.getAlphaOffset());
    return c;
}

namespace {

inline boost::int16_t
truncateDouble(double d)
{

    if (d > std::numeric_limits<boost::int16_t>::max() ||
        d < std::numeric_limits<boost::int16_t>::min())
    {
       return std::numeric_limits<boost::int16_t>::min();
    }
    return static_cast<boost::int16_t>(d);
}

}


} // namespace gnash 
