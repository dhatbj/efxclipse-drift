/*
 * Copyright (c) 2019 BestSolution.at and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     Christoph Caks <ccaks@bestsolution.at> - initial API and implementation
 */
#ifndef DRIFTFX_INTERNAL_GL_GLX_GLXGLCONTEXT_H_
#define DRIFTFX_INTERNAL_GL_GLX_GLXGLCONTEXT_H_

#include <DriftFX/GL/GLContext.h>

#include <X11/Xlib.h>
//#include <GL/glx.h>
#include <GL/glxew.h>

namespace driftfx {
using namespace gl;
namespace internal {
namespace gl {
namespace glx {


class GLXGLContext : public GLContext {

public:
	GLXGLContext(GLXContext* context, Drawable* drawable);

	GLXGLContext();
	GLXGLContext(GLXGLContext* shared);
	GLXGLContext(GLXContext glxContext);
	virtual ~GLXGLContext();

	virtual void SetCurrent();
	virtual void UnsetCurrent();

	virtual GLContext* CreateSharedContext();
	virtual GLXContext GetHandle();

private:
	Display* display;
	GLXContext glxContext;
	GLXPbuffer pBuffer;
};

}
}
}
}

#endif /* DRIFTFX_INTERNAL_GL_GLX_GLXGLCONTEXT_H_ */
