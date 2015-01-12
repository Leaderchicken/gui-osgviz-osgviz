/*
 * Object.h
 *
 *  Created on: 08.01.2015
 *      Author: planthaber
 */

#include "../../OsgVizVisualizerPlugin.h"
#include "../../Object.h"


#ifndef SRC_PLUGINS_MODELVIEWFACTORY_H_
#define SRC_PLUGINS_MODELVIEWFACTORY_H_

namespace osgviz {


class ModelViewFactory : public OsgVizVisualizerPlugin {
public:
	ModelViewFactory(mars::lib_manager::LibManager *theManager);
	~ModelViewFactory();

	virtual Object* createInstance(){
		Object *instance = new Object();
		instance->setRootNode(getRootNode());
		instances.push_back(instance);
		return instance;
	}

	virtual int getLibVersion() const {return 0;};

	virtual const std::string getLibName() const { return "ModelViewFactory"; };

private:
	std::vector< Object* > instances;
};

} /* namespace osgviz */

#endif /* SRC_PLUGINS_MODELVIEW_H_ */