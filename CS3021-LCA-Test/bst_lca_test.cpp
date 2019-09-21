#include "gtest/gtest.h"
#include "..//bst.h"
#include "..//tree_node.h"

namespace {

TEST(BstTest, BasicInsertSearchTest) {
	BST<int> bst;
	// create the following bst
	//          10
	//        /    \
	//      5      20
	//     /      /    \
	//    1      15    30
 	bst.insertNode(10);
	bst.insertNode(5);
	bst.insertNode(20);
	bst.insertNode(15);
	bst.insertNode(30);
	bst.insertNode(1);

	EXPECT_FALSE(bst.contains(50));
	EXPECT_TRUE(bst.contains(5));

}

TEST(BstTest, LcaTest1) {
	BST<int> bst;
	// create the following bst
	//          10
	//        /    \
	//      5      20
	//     /      /    \
	//    1      15    30
	bst.insertNode(10);
	bst.insertNode(5);
	bst.insertNode(20);
	bst.insertNode(15);
	bst.insertNode(30);
	bst.insertNode(1);

	EXPECT_EQ(bst.lca(15, 30), 20);
	EXPECT_EQ(bst.lca(15, 20), 20);
	EXPECT_EQ(bst.lca(15, 15), 15);
	EXPECT_EQ(bst.lca(1, 30), 10);
	EXPECT_EQ(bst.lca(1, 20), 10);
}

}  // namespace