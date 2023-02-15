#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "blossom.h"

void matching(std::string path, std::vector<std::vector<int>>& graph, std::vector<int>& match) {
	std::ifstream infile(path);
	std::string line;
	while (getline(infile, line)) {
		std::vector<int> vertex;
		std::istringstream iss(line);
		int adjacent_vertex;
		while (iss >> adjacent_vertex) {
			vertex.push_back(adjacent_vertex);
		}
		graph.push_back(vertex);
	}
	get_match(graph, match);
}

bool edges_existence(std::vector<std::vector<int>>& graph, std::vector<int>& match) {
	for (int i = 0; i < match.size(); i++) {
		if (std::find(graph[i].begin(), graph[i].end(), match[i]) != graph[i].end()) {
			break;
		}
		else {
			return false;
		}
	}
	return true;
}

bool uniqueness_vertices(std::vector<int>& match) {
	std::vector<int> repeats;
	repeats.resize(match.size(), 0);
	for (int i = 0; i < match.size(); i++) {
		if (match[i] != -1) {
			repeats[i]++;
		}
		if (repeats[i] > 1) {
			return false;
		}
	}
	return true;
}

BOOST_AUTO_TEST_CASE(small_fullyconnected_graph_1) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/1/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 2, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(odd_stem_1) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/2/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 5, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(even_stem_1) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/3/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 4, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(even_stem_2) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/4/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 4, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(even_stem_3) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/5/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 5, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(forest_even_stem_1) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/6/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 5, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(odd_stem_2) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/7/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 4, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(several_odd_cycles_1) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/8/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 5, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(forest_odd_stem_1) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/9/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 7, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(several_odd_cycles_2) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/10/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 4, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(without_stem_1) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/11/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 4, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(without_stem_2) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/12/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 4, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(without_stem_3) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/13/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 4, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(several_odd_cycles_3) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/14/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 8, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(forest_even_stem_2) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/15/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 8, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(several_odd_cycles_4) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/16/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 9, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(several_odd_cycles_5) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/17/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 9, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(large_forest_1) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;
	// check this test
	matching("tests/18/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 9, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(large_forest_2) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/19/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 9, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(large_forest_3) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/20/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 14, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(fullyconnected_star) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/21/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 3, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(several_odd_cycles_without_stem_1) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/22/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 5, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(several_odd_cycles_without_stem_2) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/23/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 10, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(large_several_odd_cycles_1) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/24/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 22, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(forest_with_difficult_graph_1) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/25/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 49, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(difficult_graph_1) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/26/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 98, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(forest_with_difficult_graph_2) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/27/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 231, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(forest_with_very_difficult_graph_1) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/28/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 464, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(difficult_fullyconnected_graph_1) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/29/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 100, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(difficult_fullyconnected_graph_2) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/30/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 250, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(nothing) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/31/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 0, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(one_edge) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/32/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 1, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(two_edge) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/33/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 1, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(three_edge_cycle) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/34/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 1, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(nothin_3) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/35/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 0, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(cycle_with_edge) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/36/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 2, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}

BOOST_AUTO_TEST_CASE(two_cycle) {
	std::vector<std::vector<int>> graph;
	std::vector<int> match;

	matching("tests/37/input.txt", graph, match);
	bool arg1 = edges_existence(graph, match), arg2 = match.size() != 2, arg3 = uniqueness_vertices(match);
	BOOST_REQUIRE_MESSAGE(arg1 && arg2 && arg3,
		"failed with arg1=" << arg1 << " arg2=" << arg2 << " arg3= " << arg3);
}