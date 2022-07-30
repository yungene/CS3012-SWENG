#include "..//graph.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

// author: Jevgenijus Cistiakovas

namespace {

using namespace ::testing;

TEST(GraphTest, InsertDagTest) {
  Graph<int> graph;
  // create the following DAG ( assume direction from left to right)
  //    -----
  //  /       \
  // 0 -> 2 -> 3
  //  \       /
  //    - 1 -
  graph.addVertex(0);
  graph.addVertex(1);
  graph.addVertex(2);
  graph.addVertex(3);

  graph.addEdge(0, 1);
  graph.addEdge(0, 2);
  graph.addEdge(0, 3);
  graph.addEdge(1, 3);
  graph.addEdge(2, 3);
  EXPECT_TRUE(graph.isDag());
  // insert a loop 0 -> 3 -> 0
  graph.addEdge(3, 0);
  EXPECT_FALSE(graph.isDag());
}

TEST(GraphTest, EmptyLcaTest) {
  Graph<int> graph;
  EXPECT_TRUE(graph.isEmpty());
  EXPECT_THAT(graph.lca(0, 1), SizeIs(0));  // empty vector signifies that no lca was found
}

// Results in this test are strictly up to definition of lca.
// Definition used considers a node to an ancestor of itself.
TEST(GraphTest, SelfNodeLcaTest) {
  Graph<int> graph;
  graph.addVertex(0);
  EXPECT_THAT(graph.lca(0, 0), ElementsAreArray({0}));
}

TEST(GraphTest, FailureLcaTest) {
  // 0 -> 1
  Graph<int> graph;
  graph.addVertex(0);
  EXPECT_THAT(graph.lca(0, 1), SizeIs(0));
  graph.addVertex(1);
  graph.addEdge(0, 1);
  EXPECT_THAT(graph.lca(1, 2), SizeIs(0));
}

TEST(GraphTest, SingleLcaTest1) {
  // create the following bst
  //          0
  //        /   \
	//      1      2
  //     /      /  \
	//    4      5    3
  Graph<int> graph;
  graph.addVertex(0);
  graph.addVertex(1);
  graph.addVertex(2);
  graph.addVertex(3);
  graph.addVertex(4);
  graph.addVertex(5);

  graph.addEdge(0, 1);
  graph.addEdge(0, 2);
  graph.addEdge(1, 4);
  graph.addEdge(2, 5);
  graph.addEdge(2, 3);
  EXPECT_TRUE(graph.isDag());
  EXPECT_THAT(graph.lca(4, 5), ElementsAreArray({0}));
  EXPECT_THAT(graph.lca(4, 1), ElementsAreArray({1}));
  EXPECT_THAT(graph.lca(3, 5), ElementsAreArray({2}));
}

TEST(GraphTest, SingleLcaTest2) {
  Graph<int> graph;
  // create the following DAG ( assume direction from left to right)
  //    -----
  //  /       \
  // 0 -> 2 -> 3
  //  \       /
  //    - 1 -
  graph.addVertex(0);
  graph.addVertex(1);
  graph.addVertex(2);
  graph.addVertex(3);

  graph.addEdge(0, 1);
  graph.addEdge(0, 2);
  graph.addEdge(0, 3);
  graph.addEdge(1, 3);
  graph.addEdge(2, 3);
  EXPECT_THAT(graph.lca(0, 2), ElementsAreArray({0}));
  EXPECT_THAT(graph.lca(1, 2), ElementsAreArray({0}));
}

TEST(GraphTest, MultipleLcaTest1) {
  Graph<int> graph;
  // create the following DAG ( assume direction from left to right and top to bottom)
  //        0   1
  //        | / |
  //    2   3   4 
  //    |\/|  /
  //    |/\| /
  //    5  6
  graph.addVertex(0);
  graph.addVertex(1);
  graph.addVertex(2);
  graph.addVertex(3);
  graph.addVertex(4);
  graph.addVertex(5);
  graph.addVertex(6);

  graph.addEdge(0, 3);
  graph.addEdge(1, 3);
  graph.addEdge(1, 4);
  graph.addEdge(2, 5);
  graph.addEdge(2, 6);
  graph.addEdge(3, 5);
  graph.addEdge(3, 6);
  graph.addEdge(4, 6);

  EXPECT_THAT(graph.lca(5, 6), UnorderedElementsAreArray({2, 3}));
  EXPECT_THAT(graph.lca(5, 4), ElementsAreArray({1}));
}

}  // namespace