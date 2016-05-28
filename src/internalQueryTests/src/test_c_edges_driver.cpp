/*PGR-GNU*****************************************************************
File: testXYedges_driver.cpp

Generated with Template by:
Copyright (c) 2015 pgRouting developers
Mail: project@pgrouting.org

Function's developer: 
Copyright (c) 2015 Rohith Reddy
Mail: 

------

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

********************************************************************PGR-GNU*/


#ifdef __MINGW32__
#include <winsock2.h>
#include <windows.h>
#endif


#include <sstream>
#include <iomanip>
#include <vector>
#include "./test_c_edges_driver.h"

extern "C" {
#include "./../../common/src/pgr_types.h"
}

#include "./../../dijkstra/src/pgr_dijkstra.hpp"
#include "./../../common/src/pgr_base_graph.hpp"
#include "./../../common/src/pgr_assert.h"


/************************************************************
  edges_sql TEXT
 ***********************************************************/
bool
do_pgr_test_c_edges(
        pgr_edge_t *data_edges,
        size_t total_edges,
        char ** log_msg,
        char ** err_msg){
    std::ostringstream log;
    std::ostringstream err;
    try {
        pgassert(!(*log_msg));
        pgassert(!(*err_msg));

        std::vector< pgr_edge_t > edges(data_edges, data_edges + total_edges);
        std::vector < pgRouting::contraction::Vertex > vertices(pgRouting::contraction::extract_vertices(edges));


        log << "Original: \n" <<
            std::setprecision(32);
        for (const auto edge: edges) {
            log << "id = " << edge.id
                << "\tsource = " << edge.source
                << "\ttarget = " << edge.target
                << "\tcost = " << edge.cost
                << "\treverse_cost = " << edge.reverse_cost
                << ")\n";
        }

        {
            log << "Testing Directed ,  insertion using vector\n";
            pgRouting::CDirectedGraph graph(DIRECTED);
            log << "  - Created graph:\n";
            log << graph;

            log << "  - Inserting Edges:\n";
            graph.graph_insert_data(edges);
            log << graph;

            log << "  - Can do a dijKstra:\n";
            Path path;
            pgr_dijkstra(graph, path, 2, 3, true);

        }
        {
            log << "Testing Directed ,  insertion using C array\n";
            pgRouting::CDirectedGraph graph(DIRECTED);
            log << "  - Created graph:\n";
            log << graph;

            log << "  - Inserting Edges:\n";
            graph.graph_insert_data(data_edges, total_edges);
            log << graph;

            log << "  - Can do a dijKstra:\n";
            Path path;
            pgr_dijkstra(graph, path, 2, 3, true);

        }
        {
            log << "Testing Directed ,  creating with vertices, insertion using vector\n";
            pgRouting::CDirectedGraph graph(vertices, DIRECTED);
            log << "  - Created graph:\n";
            log << graph;

            log << "  - Inserting Edges:\n";
            graph.graph_insert_data(edges);
            log << graph;

            log << "  - Can do a dijKstra:\n";
            Path path;
            pgr_dijkstra(graph, path, 2, 3, true);

        }
        {
            log << "Testing Directed ,  creating with vertices, insertion using C array\n";
            pgRouting::CDirectedGraph graph(vertices, DIRECTED);
            log << "  - Created graph:\n";
            log << graph;

            log << "  - Inserting Edges:\n";
            graph.graph_insert_data(data_edges, total_edges);
            log << graph;

            log << "  - Can do a dijKstra:\n";
            Path path;
            pgr_dijkstra(graph, path, 2, 3, true);

        }

        {
            log << "Testing Undirected ,  insertion using vector\n";
            pgRouting::CDirectedGraph graph(UNDIRECTED);
            log << "  - Created graph:\n";
            log << graph;

            log << "  - Inserting Edges:\n";
            graph.graph_insert_data(edges);
            log << graph;

            log << "  - Can do a dijKstra:\n";
            Path path;
            pgr_dijkstra(graph, path, 2, 3, true);

        }
        {
            log << "Testing Directed ,  insertion using C array\n";
            pgRouting::CDirectedGraph graph(UNDIRECTED);
            log << "  - Created graph:\n";
            log << graph;

            log << "  - Inserting Edges:\n";
            graph.graph_insert_data(data_edges, total_edges);
            log << graph;

            log << "  - Can do a dijKstra:\n";
            Path path;
            pgr_dijkstra(graph, path, 2, 3, true);

        }
        {
            log << "Testing Undirected ,  insertion using C array\n";
            pgRouting::CDirectedGraph graph(UNDIRECTED);
            log << "  - Created graph:\n";
            log << graph;

            log << "  - Inserting Edges:\n";
            graph.graph_insert_data(data_edges, total_edges);
            log << graph;

            log << "  - Can do a dijKstra:\n";
            Path path;
            pgr_dijkstra(graph, path, 2, 3, true);

        }
        {
            log << "Testing Undirected ,  creating with vertices, insertion using vector\n";
            pgRouting::CDirectedGraph graph(vertices, UNDIRECTED);
            log << "  - Created graph:\n";
            log << graph;

            log << "  - Inserting Edges:\n";
            graph.graph_insert_data(edges);
            log << graph;

            log << "  - Can do a dijKstra:\n";
            Path path;
            pgr_dijkstra(graph, path, 2, 3, true);

        }

        {
            log << "Testing Identifiers, creating with vertices, insertion using vector\n";
            log << "  - Created graph:\n";
            pgRouting::CDirectedGraph graph(vertices, UNDIRECTED);
            log << "  - Inserting Edges:\n";
            graph.graph_insert_data(edges);
            log << "  - All vertices:\n";
            Identifiers<int64_t> all_vertices, contracted_vertices, remaining_vertices;
            for (const auto vertex: vertices) {
                all_vertices.insert(graph.get_V(vertex.id));
                //log << vertex;
            }
            log << "    " << all_vertices;
            log << "\n";
            log << "  - Contracted vertices:\n";
            /*
             1, 7, 8, 13, 14, 16
            */
            contracted_vertices.insert(graph.get_V(1));
            contracted_vertices.insert(graph.get_V(7));
            contracted_vertices.insert(graph.get_V(8));
            contracted_vertices.insert(graph.get_V(13));
            contracted_vertices.insert(graph.get_V(14));
            contracted_vertices.insert(graph.get_V(16));
            log << "    " << contracted_vertices;
            log << "\n";
            log << "  - Remaining vertices:\n";
            remaining_vertices = all_vertices - contracted_vertices;
            log << "    " << remaining_vertices;
            log << "\n";
            #if 0
            
            Pgr_contract<pgRouting::CDirectedGraph>  contractor;
            contractor.getDeadEndSet(graph);
            log << "  - Dead end vertices:\n";
            contractor.print_dead_end_vertices(log);

            #endif
        }



        *err_msg = NULL;
        *log_msg = strdup(log.str().c_str());
        return true;

    } catch (AssertFailedException &exept) {
        log << exept.what() << "\n";
        *err_msg = strdup(log.str().c_str());
        return false;
    } catch (std::exception& exept) {
        log << exept.what() << "\n";
        *err_msg = strdup(log.str().c_str());
        return false;
    } catch(...) {
        log << "Caught unknown exception!\n";
        *err_msg = strdup(log.str().c_str());
        return false;
    }
}
