// GnashVaapiTexture.cpp: GnashImage class used for VA/GLX rendering
// 
//   Copyright (C) 2007, 2008, 2009, 2010, 2011, 2012
//   Free Software Foundation, Inc.
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

#include "GnashVaapiTexture.h"
#include "VaapiSurface.h"
#include "VaapiSurfaceGLX.h"
#include <GL/gl.h>

namespace gnash {

GnashVaapiTexture::GnashVaapiTexture(unsigned int width, unsigned int height,
        image::ImageType type)
    :
    GnashTexture(width, height, type)
{
    _flags |= GNASH_TEXTURE_VAAPI;

    _surface.reset(new VaapiSurfaceGLX(GL_TEXTURE_2D, texture()));
}

GnashVaapiTexture::~GnashVaapiTexture()
{
}

void GnashVaapiTexture::update(std::shared_ptr<VaapiSurface> surface)
{
    _surface->update(surface);
}

} // gnash namespace

// local Variables:
// mode: C++
// indent-tabs-mode: t
// End:
