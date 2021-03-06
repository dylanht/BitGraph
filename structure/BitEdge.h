#ifndef BIT_EDGE_H
#define BIT_EDGE_H

#include "structure/Edge.h"
#include <inttypes.h>
#include <boost/any.hpp>

class BitEdge : public Edge {
	private:
		// The Graph this Edge belongs to
		CPUGraph* graph;

		// The unique id of this BitEdge
		uint64_t edge_id;

		// The out-vertex of this BitEdge
		Vertex* out_vertex;

		// The in-vertex of this BitEdge
		Vertex* in_vertex;

		// The label of this BitEdge
		std::string edge_label;

	public:
		/*
			Construct a new BitEdge with the given in and
			out vertices and the given label.  Per TP3
			standard, all Edges must have a label.
		*/
		BitEdge(CPUGraph* graph, uint64_t id, Vertex* out, Vertex* in, std::string label) {
			this->graph = graph;
			this->edge_id = id;
			this->out_vertex = out;
			this->in_vertex = in;
			this->edge_label = label;
		}

		/*
			Get a pointer to the id of the given Edge.
		*/
		virtual boost::any id() { return boost::any(this->edge_id); }
		virtual Graph* getGraph() { return static_cast<Graph*>(this->graph); }
		virtual std::string label() { return this->edge_label; }
		virtual Vertex* outV() { return this->out_vertex; }
		virtual Vertex* inV() { return this->in_vertex; }
};

#endif