#include "gtest/gtest.h"
#include "./../BinaryTree.h"
#include "./../complex.h"
#include "./../Set.h"
int plus1(int n) {
    return n + 1;
}
int Mapcheck(int n) {
    return n + 1;
}
double plus1(double n) {
    return n + 1;
}
complex plus1(complex n){
    return n+complex(1,0);
}
bool two(int n){
    return n % 2 == 0;
}
bool less_20(double n){
    return n < 20;
}
bool abs_more_5(complex n){
    return n.abs() > 5;
}
int ReduceCheck(int a, int b){
    return a + b;
}
double ReduceCheck(double a, double b){
    return a + b;
}
complex ReduceCheck(complex a, complex b){
    return a + b;
}


TEST(Tree_int, Functions){
Tree<int>* Test;
Test = new Tree<int>();
Test->insert_node(22);
Test->insert_node(14);
Test->insert_node(9);
Test->insert_node(1);
Test->insert_node(0);
Test->insert_node(10);
Test->insert_node(8);
ASSERT_EQ(4, Test->height());
ASSERT_FALSE((Test->find_node(10))== nullptr);
ASSERT_TRUE(Test->check_element(1) == true);
ASSERT_TRUE(Test->check_element(666) == false);
Test->delete_node(Test->find_node(Test->get_root(), 8));
ASSERT_TRUE(Test->check_element(8) == false);
Test->insert_node(8);

}
TEST(Tree_int, Subtrees){
Tree<int>* Test;
Test = new Tree<int>();
Test->insert_node(22);
Test->insert_node(14);
Test->insert_node(9);
Test->insert_node(1);
Test->insert_node(0);
Test->insert_node(10);
Test->insert_node(8);

Tree<int>* Test_i;
Test_i = new Tree<int>();

Test_i->insert_node(1);
Test_i->insert_node(8);
Test_i->insert_node(0);
ASSERT_TRUE(Test->find_sub_tree(Test_i) == true);

Tree<int>* tree1;
tree1 = new Tree<int>();

tree1 = Test->sub_tree(1);
ASSERT_TRUE(tree1->check_element(1) == true && tree1->check_element(8) == true && tree1->check_element(0) == true);
}

TEST(Tree_int, Map_Where_Reduce){
Tree<int>* Test;
Test = new Tree<int>();
Test->insert_node(25);
Test->insert_node(14);
Test->insert_node(9);

Test->map(plus1);
ASSERT_TRUE(Test->check_element(26) == true && Test->check_element(15) == true && Test->check_element(10) == true);
Test->where(two);
ASSERT_TRUE(Test->check_element(26) == true && Test->check_element(15) == false && Test->check_element(10) == true);
ASSERT_EQ(36,Test->Reduce(ReduceCheck,0));

}

TEST(Tree_int, Min_Max){
Tree<int>* Test;
Test = new Tree<int>();
Test->insert_node(22);
Test->insert_node(14);
Test->insert_node(9);
Test->insert_node(1);
Test->insert_node(0);
ASSERT_EQ(0, (Test->find_min(Test->get_root()))->get_data());
ASSERT_EQ(22, (Test->find_max(Test->get_root()))->get_data());
}


TEST(Tree_double, Functions){
Tree<double>* Test;
Test = new Tree<double>();
Test->insert_node(22.5);
Test->insert_node(14.5);
Test->insert_node(9.5);
Test->insert_node(1.5);
Test->insert_node(0.6);
Test->insert_node(10.1);
Test->insert_node(8.1);
ASSERT_EQ(4, Test->height());
ASSERT_FALSE((Test->find_node(1.5))== nullptr);
ASSERT_TRUE(Test->check_element(1.5) == true);
ASSERT_TRUE(Test->check_element(0.111) == false);
Test->delete_node(Test->find_node(Test->get_root(), 8.1));
ASSERT_TRUE(Test->check_element(8.1) == false);
Test->insert_node(8.1);

}
TEST(Tree_double, Subtrees){
Tree<double>* Test;
Test = new Tree<double>();
Test->insert_node(22.5);
Test->insert_node(14.5);
Test->insert_node(9.5);
Test->insert_node(1.5);
Test->insert_node(0.6);
Test->insert_node(10.1);
Test->insert_node(8.1);

Tree<double>* Test_i;
Test_i = new Tree<double>();

Test_i->insert_node(1.5);
Test_i->insert_node(8.1);
Test_i->insert_node(0.6);
ASSERT_TRUE(Test->find_sub_tree(Test_i) == true);

Tree<double>* tree1;
tree1 = new Tree<double>();

tree1 = Test->sub_tree(1.5);
ASSERT_TRUE(tree1->check_element(1.5) == true && tree1->check_element(8.1) == true && tree1->check_element(0.6) == true);
}

TEST(Tree_double, Map_Where_Reduce){
Tree<double>* Test;
Test = new Tree<double>();
Test->insert_node(25.5);
Test->insert_node(14.5);
Test->insert_node(9.5);

Test->map(plus1);
ASSERT_TRUE(Test->check_element(26.5) == true && Test->check_element(15.5) == true && Test->check_element(10.5) == true);
Test->where(less_20);
ASSERT_TRUE(Test->check_element(26.5) == false && Test->check_element(15.5) == true && Test->check_element(10.5) == true);
EXPECT_FLOAT_EQ(26,Test->Reduce(ReduceCheck,0));
}

TEST(Tree_double, Min_Max){
Tree<double>* Test;
Test = new Tree<double>();
Test->insert_node(0.1);
Test->insert_node(14.5);
Test->insert_node(9.2);
Test->insert_node(111.21);
Test->insert_node(0.555);
EXPECT_FLOAT_EQ(0.1, (Test->find_min(Test->get_root()))->get_data());
EXPECT_FLOAT_EQ(111.21, (Test->find_max(Test->get_root()))->get_data());
}

TEST(Tree_complex, Functions){
Tree<complex>* Test;
Test = new Tree<complex>();
Test->insert_node(complex(5,5));
Test->insert_node(complex(10,10));
Test->insert_node(complex(6,6));
Test->insert_node(complex(1,1));
Test->insert_node(complex(3,3));
ASSERT_EQ(2, Test->height());
ASSERT_FALSE((Test->find_node(complex(1,1)))== nullptr);
ASSERT_TRUE(Test->check_element(complex(1,1)) == true);
ASSERT_TRUE(Test->check_element(complex(11,11)) == false);
Test->delete_node(Test->find_node(Test->get_root(), complex(1,1)));
ASSERT_TRUE(Test->check_element(complex(1,1)) == false);
Test->insert_node(complex(1,1));

}
TEST(Tree_complex, Subtrees){
Tree<complex>* Test;
Test = new Tree<complex>();
Test->insert_node(complex(5,5));
Test->insert_node(complex(10,10));
Test->insert_node(complex(15,15));
Test->insert_node(complex(6,6));
Test->insert_node(complex(1,1));
Test->insert_node(complex(3,3));

Tree<complex>* Test_i;
Test_i = new Tree<complex>();

Test_i->insert_node(complex(10,10));
Test_i->insert_node(complex(15,15));
Test_i->insert_node(complex(6,6));
ASSERT_TRUE(Test->find_sub_tree(Test_i) == true);

Tree<complex>* tree1;
tree1 = new Tree<complex>();

tree1 = Test->sub_tree(complex(10,10));
ASSERT_TRUE(tree1->check_element(complex(10,10)) == true && tree1->check_element(complex(15,15)) == true && tree1->check_element(complex(6,6)) == true);
}

TEST(Tree_complex, Map_Where_Reduce){
Tree<complex>* Test;
Test = new Tree<complex>();
Test->insert_node(complex(1,1));
Test->insert_node(complex(5,5));
Test->insert_node(complex(10,10));

Test->map(plus1);
ASSERT_TRUE(Test->check_element(complex(2,1)) == true && Test->check_element(complex(6,5)) == true && Test->check_element(complex(11,10)) == true);
Test->where(abs_more_5);
ASSERT_TRUE(Test->check_element(complex(2,1)) == false && Test->check_element(complex(6,5)) == true && Test->check_element(complex(11,10)) == true);
ASSERT_EQ(complex(17,15),Test->Reduce(ReduceCheck,0));
}

TEST(Tree_complex, Min_Max){
Tree<complex>* Test;
Test = new Tree<complex>();
Test->insert_node(complex(3,3));
Test->insert_node(complex(1,1));
Test->insert_node(complex(5,5));
Test->insert_node(complex(10,10));
ASSERT_EQ(complex(1,1), (Test->find_min(Test->get_root()))->get_data());
ASSERT_EQ(complex(10,10), (Test->find_max(Test->get_root()))->get_data());
}


TEST(Tree_person, Functions){
Tree<Person>* Test;
Test = new Tree<Person>();
Test->insert_node({"Марк", "Корначук", "Б20-524" });
Test->insert_node({"Артемий", "Лукичев", "Б20-524" });
Test->insert_node({"Никита", "Косенко", "Б20-524" });
Test->insert_node({"Носов", "Артем", "Б20-514" });
ASSERT_EQ(2, Test->height());
ASSERT_FALSE((Test->find_node({"Марк", "Корначук", "Б20-524" })== nullptr));
ASSERT_TRUE(Test->check_element({"Никита", "Косенко", "Б20-524" }) == true);
ASSERT_TRUE(Test->check_element({"Карк", "Морначук", "Б20-524" }) == false);
Test->delete_node(Test->find_node(Test->get_root(), {"Носов", "Артем", "Б20-514" }));
ASSERT_TRUE(Test->check_element({"Носов", "Артем", "Б20-514" }) == false);
Test->insert_node({"Носов", "Артем", "Б20-514" });
}

TEST(Tree_person, Subtrees){
Tree<Person>* Test;
Test = new Tree<Person>();
Test->insert_node({"Марк", "Корначук", "Б20-524" });
Test->insert_node({"Артемий", "Лукичев", "Б20-524" });
Test->insert_node({"Никита", "Косенко", "Б20-524" });
Test->insert_node({"Святослав", "Устинченко", "Б20-524" });

Tree<Person>* Test_i;
Test_i = new Tree<Person>();

Test_i->insert_node({"Артемий", "Лукичев", "Б20-524" });
Test_i->insert_node({"Святослав", "Устинченко", "Б20-524" });
Test_i->insert_node({"Никита", "Косенко", "Б20-524" });
ASSERT_TRUE(Test->find_sub_tree(Test_i) == true);

Tree<Person>* tree1;
tree1 = new Tree<Person>();

tree1 = Test->sub_tree({"Артемий", "Лукичев", "Б20-524" });
ASSERT_TRUE(tree1->check_element({"Артемий", "Лукичев", "Б20-524" }) == true && tree1->check_element({"Святослав", "Устинченко", "Б20-524" }) == true && tree1->check_element({"Никита", "Косенко", "Б20-524" }) == true);
}

TEST(Tree_person, Min_Max){
Tree<Person>* Test;
Person max = {"Артемий", "Лукичев", "Б20-524" };
Person min = {"Носов", "Артем", "Б20-514" };
Test = new Tree<Person>();
Test->insert_node({"Марк", "Корначук", "Б20-524" });
Test->insert_node({"Артемий", "Лукичев", "Б20-524" });
Test->insert_node({"Никита", "Косенко", "Б20-524" });
Test->insert_node({"Носов", "Артем", "Б20-514" });
ASSERT_EQ(min, (Test->find_min(Test->get_root()))->get_data());
ASSERT_EQ(max, (Test->find_max(Test->get_root()))->get_data());
}
TEST(Set, Functions ){
Set<int> set(5);
ASSERT_TRUE(set.exist(5) == true);

set.add(4);
set.add(6);
ASSERT_TRUE(set.exist(4) == true);

set.delete_el(5);
ASSERT_TRUE(set.exist(5) == false);

}
