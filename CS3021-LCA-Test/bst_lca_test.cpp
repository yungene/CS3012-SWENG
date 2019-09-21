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

	TreeNode<int>* result_node;
	result_node = bst.lca(15, 20);
	ASSERT_FALSE(result_node == nullptr);
	EXPECT_EQ(result_node->getData(), 20);

	EXPECT_EQ(bst.lca(15, 20)->getData(), 20);
	EXPECT_EQ(bst.lca(15, 15)->getData(), 15);
	EXPECT_EQ(bst.lca(1, 30)->getData(), 10);
	EXPECT_EQ(bst.lca(1, 20)->getData(), 10);
}

TEST(BstTest, EmptyLcaTest) {
	BST<int> bst;
	EXPECT_EQ(bst.lca(10, 15), nullptr);
}

TEST(BstTest, RootLcaTest) {
	BST<int> bst;
	bst.insertNode(10);
	EXPECT_EQ(bst.lca(10, 10)->getData(), 10);
}

TEST(BstTest, FailureLcaTest) {
	BST<int> bst;
	bst.insertNode(10);
	EXPECT_EQ(bst.lca(10, 5), nullptr);
	bst.insertNode(20);
	EXPECT_EQ(bst.lca(20, 5), nullptr);
}

TEST(BstTest, LinkedListLcaTest) {
	BST<int> bst;
	// create the following bst
	//      10
	//       \
	//        20
	//         \
	//          30
	//           \
	//            40
	bst.insertNode(10);
	bst.insertNode(20);
	bst.insertNode(30);
	bst.insertNode(40);

	EXPECT_EQ(bst.lca(10, 10)->getData(), 10);
	EXPECT_EQ(bst.lca(10, 20)->getData(), 10);
	EXPECT_EQ(bst.lca(10, 30)->getData(), 10);
	EXPECT_EQ(bst.lca(10, 40)->getData(), 40);
	EXPECT_EQ(bst.lca(30, 40)->getData(), 30);
}

TEST(BstTest, LcaSymmetryTest) {
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

	EXPECT_EQ(bst.lca(10, 20), bst.lca(20, 10));
	EXPECT_EQ(bst.lca(1, 20), bst.lca(20, 1));
	EXPECT_EQ(bst.lca(5, 15), bst.lca(15, 5));
}

TEST(BstTest, LcaNestingTest) {
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

	// lca of 15,30,20 is 20
	EXPECT_EQ(bst.lca(15, bst.lca(30,20))->getData(), 20);
	EXPECT_EQ(bst.lca(1, bst.lca(15, 30))->getData(), 10);
	EXPECT_EQ(bst.lca(1, bst.lca(5, 30))->getData(), 10);
}


}  // namespace