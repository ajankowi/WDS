/****************************************************************************

 Copyright (C) 2002-2014 Gilles Debunne. All rights reserved.

 This file is part of the QGLViewer library version 2.6.3.

 http://www.libqglviewer.com - contact@libqglviewer.com

 This file may be used under the terms of the GNU General Public License 
 versions 2.0 or 3.0 as published by the Free Software Foundation and
 appearing in the LICENSE file included in the packaging of this file.
 In addition, as a special exception, Gilles Debunne gives you certain 
 additional rights, described in the file GPL_EXCEPTION in this package.

 libQGLViewer uses dual licensing. Commercial/proprietary software must
 purchase a libQGLViewer Commercial License.

 This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

*****************************************************************************/
//-----------------------------
// Corrected by BK
//
#include "frustumCulling.hh"
#include "cullingCamera.hh"
#include "box.hh"
//-----------------------------

#include <QApplication>
#include <QGLViewer/manipulatedCameraFrame.h>

using namespace qglviewer;

int main(int argc, char** argv)
{
	QApplication application(argc,argv);

	// Create octree AABBox hierarchy
	const qglviewer::Vec p(1.0, 0.7f, 1.3f);
	Box::Root = new Box(-p, p);
	Box::Root->buildBoxHierarchy(4);

	// Instantiate the two viewers.
	Viewer viewer, observer;

	// Give v a cullingCamera;
	Camera* c = viewer.camera();
	CullingCamera* cc = new CullingCamera();
	viewer.setCamera(cc);
	delete c;

	// Both viewers share the culling camera
	viewer.setCullingCamera(cc);
	observer.setCullingCamera(cc);

	// Place observer
	observer.setSceneRadius(10.0);
	observer.camera()->setViewDirection(qglviewer::Vec(0.0, -1.0, 0.0));
	observer.showEntireScene();

	// Make sure every culling Camera movement updates the outer viewer
	QObject::connect(viewer.camera()->frame(), SIGNAL(manipulated()), &observer, SLOT(updateGL()));
	QObject::connect(viewer.camera()->frame(), SIGNAL(spun()), &observer, SLOT(updateGL()));


	viewer.setWindowTitle("frustumCulling");
	observer.setWindowTitle("scene observer");

	// Show the viewers' windows.
	viewer.show();
	observer.show();

	return application.exec();
}
