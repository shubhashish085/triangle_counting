//
// Created by antu on 2/12/24.
//

#include "matchingcommand.h"
#include "graph.h"
#include "backtracking.h"
#include "TriangleEnumeration.h"
#include "wtime.h"
#include <chrono>
#include <limits>
#include <fstream>

#define INVALID_VERTEX_ID 100000000
#define BYTESTOMB(memory_cost) ((memory_cost)/(double)(1024 * 1024))
#define NANOSECTOSEC(elapsed_time) ((elapsed_time)/(double)1000000000)




//For Triangle Counting
int main(int argc, char** argv) {

    MatchingCommand command(argc, argv);
    //std::string input_query_graph_file = command.getQueryGraphFilePath();
    std::string input_data_graph_file = command.getDataGraphFilePath();
    //std::string output_file_path = command.getOutputFilePath();

    size_t call_count = 0;
    size_t output_limit = std::numeric_limits<size_t>::max();


    Graph* data_graph = new Graph();
    data_graph->loadGraphFromFileForTriangle(input_data_graph_file);
    ui* result_array = new ui[data_graph->getVerticesCount()];

    double start_time, end_time;

    std::cout << "Counting Triangles" << std::endl;
    start_time = wtime();
    //size_t numberOfTriangles = TriangleEnumerate::enumerateTrianglesBySetIntersection(data_graph, data_graph->edge_vtr, result_array, output_limit, call_count);
    size_t numberOfTriangles = TriangleEnumerate::enumerateTrianglesInDistributedArch(data_graph, data_graph->edge_vtr, result_array, output_limit, call_count);
    end_time = wtime();
    //size_t numberOfTriangles = TriangleEnumerate::enumerateTrianglesBySetIntersection(data_graph, data_graph->edge_vtr, result_array, output_limit, call_count);

    std::cout << "Enumerate time (seconds) : " << end_time - start_time << std::endl;
    std::cout << "Number of Unique Triangles : " << numberOfTriangles << std::endl;

    /*std::ofstream outputfile;
    outputfile.open(output_file_path, std::ios::app);

    outputfile << "Enumerate time (seconds) : " << end_time - start_time << std::endl;
    outputfile << "Number of Unique Triangles : " << numberOfTriangles << std::endl;

    outputfile.flush();
    outputfile.close();

    std::cout << "Number of Triangles : " << numberOfTriangles << std::endl;*/

}
