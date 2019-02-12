#ifndef CPU_GRAPH_TRAVERSAL_SOURCE_H
#define CPU_GRAPH_TRAVERSAL_SOURCE_H

#include "GraphTraversalSource.h"
#include "CPUGraphTraversal.h"
#include "GPUGraphTraversal.h"
#include "GraphStep.h"
#include "AddVertexStartStep.h"
#include "AddEdgeStartStep.h"
class CPUGraph;

class CPUGraphTraversalSource : public GraphTraversalSource {
	private:
		bool with_gpu;

	public:
		CPUGraphTraversalSource(CPUGraph* gr)
		: GraphTraversalSource(gr) {
			with_gpu = false;
		}

		CPUGraphTraversalSource* withGPU() {
			with_gpu = true;
			return this;
		}

		GraphTraversal* V() {
			GraphTraversal* trv = this->with_gpu ? new GPUGraphTraversal(this) : new CPUGraphTraversal(this);
			trv->appendStep(new GraphStep(VERTEX, {}));
			return trv;
		}

		GraphTraversal* V(Vertex* v) {
			GraphTraversal* trv = this->with_gpu ? new GPUGraphTraversal(this) : new CPUGraphTraversal(this);
			trv->appendStep(new GraphStep(VERTEX, {v->id()}));
			return trv;
		}

		/*
			Although the API allows for making this a special call,
			CPUGraph treats this as shorthand for g.V().outE()
		*/
		GraphTraversal* E() {
			return (GraphTraversal*)this->V()->outE();
		}
		
		GraphTraversal* addV() {
			GraphTraversal* trv = this->with_gpu ? new GPUGraphTraversal(this) : new CPUGraphTraversal(this);
			trv->appendStep(new AddVertexStartStep());
			return trv;
		}
		
		GraphTraversal* addV(std::string label) {
			GraphTraversal* trv = this->with_gpu ? new GPUGraphTraversal(this) : new CPUGraphTraversal(this);
			trv->appendStep(new AddVertexStartStep(label));
			return trv;
		}

		GraphTraversal* addE(std::string label) {
			GraphTraversal* trv = this->with_gpu ? new GPUGraphTraversal(this) : new CPUGraphTraversal(this);
			trv->appendStep(new AddEdgeStartStep(label));
			return trv;
		}
};

#endif