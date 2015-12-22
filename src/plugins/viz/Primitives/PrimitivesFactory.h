/*
 * Primitives.h
 *
 *  Created on: 09.01.2015
 *      Author: planthaber
 */

#ifndef GUI_OSGVIZ_SRC_PLUGINS_VIZ_PRIMITIVES_PRIMITIVESFACTORY_H_
#define GUI_OSGVIZ_SRC_PLUGINS_VIZ_PRIMITIVES_PRIMITIVESFACTORY_H_

#include "../../OsgVizVisualizerPlugin.h"

#include <osg/Shape>
#include <osg/ShapeDrawable>

#include "Primitives/ShapeNode.h"

namespace osgviz {

class PrimitivesFactory: public OsgVizVisualizerPlugin {
public:
	PrimitivesFactory(lib_manager::LibManager *theManager);
	virtual ~PrimitivesFactory();

	virtual int getLibVersion() const {return 0;};

	virtual const std::string getLibName() const { return "PrimitivesFactory"; };


	virtual osg::ref_ptr<Object> createAxes(float scale=1.0,bool blabels=true);
	virtual osg::ref_ptr<Object> createGrid(int rows = 20,int cols = 20,float dx =1, float dy=1, bool show_coordinates=false, const ::osg::Vec4 &color = ::osg::Vec4(120,120,120,255));
	virtual osg::ref_ptr<Object> createArrow();

	enum Shapes{BOX,CAPSULE,CONE,CYLINDER,SPHERE};

	struct Shape : public osgviz::Object{
	    osg::ref_ptr<osg::Geode> geode;
	    osg::ref_ptr<osg::Shape> shape;
	    osg::ref_ptr<osg::ShapeDrawable> drawable;
	};

	/**
	 * These Spabes cannot receive click events
	 * @param shape
	 * @param sizex
	 * @param sizey
	 * @param sizez
	 * @return
	 */
	virtual osg::ref_ptr<Shape> createShape(Shapes shape,const float &sizex,const float &sizey,const float &sizez);


	virtual osg::ref_ptr<ShapeNode> createInteractiveBox(const float &sizex,const float &sizey,const float &sizez);

	struct BoundingBox : public osgviz::Object{
	    osg::ref_ptr<osg::Geometry> selectionBox;
	    osg::ref_ptr<osg::Geode> selectionBoxGeode;
	    osg::ref_ptr<osg::Vec3Array> points;
	    osg::ref_ptr<osg::Vec4Array> colors;
	    osg::ref_ptr<osg::Vec3Array> normals;
	};
	virtual osg::ref_ptr<BoundingBox> createBoundingBox(osg::Group* object);


};

} /* namespace osgviz */

#endif /* GUI_OSGVIZ_SRC_PLUGINS_VIZ_PRIMITIVES_PRIMITIVESFACTORY_H_ */
