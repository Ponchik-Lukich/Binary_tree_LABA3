#include <iostream>
#include <iomanip>
#include "complex.h"
#include "BinaryTree.h"
#include "Set.h"


using namespace std;

int main()
{
    cout << "Choose type: \nInt Tree -> 1 \nDouble Tree -> 2\nComplex Tree -> 3\nPerson Tree -> 4\n" << endl;

    int choice(0);
    cin >> choice;

    if ((choice > 4) || (choice < 1))
    {
        while ((choice > 4) || (choice < 1))
        {
            cout << "ERROR! WRONG NUMBER!\n Please, try again." << endl;
            cin >> choice;
        }
    }
    string s1,s2,s3;

    Tree<int>* Tree1;
    Tree1 = new Tree<int>();
    if (choice == 1) Tree1->entering();

    Tree<double>* Tree2;
    Tree2 = new Tree<double>();  
    if (choice == 2) Tree2->entering();

    Tree<complex>* Tree3 = new Tree<complex>();
    if (choice==3){
        int n = 0;
        cout << " Enter number of elements: " << endl;
        while(n<=0) {
            cin >> n;
        }
        cout << "Write complex like 'x1 SPACE x2':"<<endl;
        for (int i = 0; i < n; i++) {
            double a;
            double b;
            cin >> a;
            cin >> b;
            Tree3->insert_node(complex(a,b));
        }
    }

    Tree<Person>* Tree4;
    Tree4 = new Tree<Person>();
    if (choice == 4){
        Person Person;
        int what=0;
        int i;
        string ID;
        string f_name;
        string l_name;
        while(what<=0) {
            cout <<"Enter number of persons\n";
            cin >> what;
        }
        cout <<"Enter first name and last name through the space\n";
        for (i =0; i<what; i++) {
            cin >> f_name;
            cin >> l_name;
            cout <<"Group:";
            cin >> ID;
            Tree4->insert_node({f_name, l_name, ID});
        }
    }

    int ch = 0;
    do
    {
        cout << " \n Choose the operation : \n1. Find min and max \n2. Delete/add element \n3. Print \n4. Find Sub Tree \n5. Hight \n6. Sub tree \n7. Exit" << endl;
        cin >> ch;

        if ((ch > 6) || (ch < 1))
        {
            while ((ch > 8) || (ch < 1))
            {
                cout << "ERROR NUMBER!\nPlease, try again:";
                cin >> ch;
            }
        }

        switch (ch)
        {
        case 1:

            if (choice == 1)
            {
                cout << endl << "Minimum is: " << (Tree1->find_min(Tree1->get_root()))->get_data() << endl;
                cout << endl << "Maximum is: " << (Tree1->find_max(Tree1->get_root()))->get_data() << endl;
            }

            if (choice == 2)
            {
                cout << endl << "Minimum is: " << (Tree2->find_min(Tree2->get_root()))->get_data() << endl;
                cout << endl << "Maximum is: " << (Tree2->find_max(Tree2->get_root()))->get_data() << endl;
            }

            if (choice == 3)
            {
                cout << endl << "Minimum is: " << (Tree3->find_min(Tree3->get_root()))->get_data() << endl;
                cout << endl << "Maximum is: " << (Tree3->find_max(Tree3->get_root()))->get_data() << endl;
            }
            if (choice == 4)
            {
                cout << endl << "Minimum is: " << (Tree4->find_min(Tree4->get_root()))->get_data() << endl;
                cout << endl << "Maximum is: " << (Tree4->find_max(Tree4->get_root()))->get_data() << endl;
            }
            break;
        case 2:
            int a;
            int b;
            int c;
            cout << "Add -> 1\nDelete-> 2" << endl;
            cin >>c;
            if (c==1){
                cout << "Enter node value you want to add:";
                if (choice == 1)
                {
                    cin >> a;
                    Tree1->add(a);
                    cout << "Result:\n";
                    Tree1->inorder_walk(Tree1->get_root());
                }
                if (choice == 2)
                {
                    cin >> a;
                    Tree2->add(a);
                    cout << "Result:\n";
                    Tree2->inorder_walk(Tree2->get_root());
                }
                if (choice == 3)
                {
                    cout << "Write complex like 'x1 SPACE x2':";
                    cin >> a;
                    cin >> b;
                    Tree3->add(complex(a,b));
                    cout << "Result:\n";
                    Tree3->inorder_walk(Tree3->get_root());
                }
                if (choice == 4)
                {
                    cout << "Write complex like 'Firstname SPACE Lastname':";
                    cin >> s1;
                    cin >> s2;
                    cout << "Group: ";
                    cin >> s3;
                    Tree4->add({s1, s2, s3});
                    cout << "Result:\n";
                    Tree4->inorder_walk(Tree4->get_root());
                }
                break;
            } else{
                cout << "Enter node value you want to delete:";

                if (choice == 1)
                {
                    cin >> a;
                    Tree1->delete_node(Tree1->find_node(Tree1->get_root(), a));
                    cout << "Result:\n";
                    Tree1->inorder_walk(Tree1->get_root());
                }
                if (choice == 2)
                {
                    cin >> a;
                    Tree2->delete_node(Tree2->find_node(Tree2->get_root(), a));
                    cout << "Result:\n";
                    Tree2->inorder_walk(Tree2->get_root());
                }
                if (choice == 3)
                {
                    cout << "Write complex like 'x1 SPACE x2':";
                    cin >> a;
                    cin >> b;
                    Tree3->delete_node(Tree3->find_node(Tree3->get_root(), complex(a,b)));
                    cout << "Result:\n";
                    Tree3->inorder_walk(Tree3->get_root());
                }
                if (choice == 4)
                {
                    cout << "Write person like 'Firstname SPACE Lastname':";
                    cin >> s1;
                    cin >> s2;
                    cout << "Group: ";
                    cin >> s3;
                    Tree4->delete_node(Tree4->find_node(Tree4->get_root(), {s1, s2, s3}));
                    cout << "Result:\n";
                    Tree4->inorder_walk(Tree4->get_root());
                }
                break;
            }

        case 3:
            if (choice == 1) Tree1->print_tree(Tree1->get_root(), Tree1->height());
            if (choice == 2) Tree2->print_tree(Tree2->get_root(), Tree2->height());
            if (choice == 3) Tree3->print_tree(Tree3->get_root(), Tree3->height());
            if (choice == 4) Tree4->print_tree(Tree4->get_root(), Tree4->height());
            break;
        case 5:
            if (choice == 1) std::cout << Tree1->height();
            if (choice == 2) std::cout << Tree2->height();
            if (choice == 3) std::cout << Tree3->height();
            if (choice == 4) std::cout << Tree4->height();
            break;
        case 6:
            int ptr1,c1,c2;
            double ptr2;
            cout << "Enter element: ";
            if (choice==1) cin >> ptr1;
            if (choice==2) cin >> ptr2;
            if (choice==3) cin >> c1 >> c2;
            if (choice==4) {
                cout << "Enter firstname and lastname"<< endl;
                cin >> s1 >> s2;
                cout << "Enter group:";
                cin >> s3;
            }

            Tree<int>* sub1;
            sub1 = new Tree<int>();

            if (choice == 1)
            {
                sub1 = Tree1->sub_tree(ptr1);
                sub1->print_tree(sub1->get_root(), sub1->height());
            }

            Tree<double>* sub2;
            sub2 = new Tree<double>();

            if (choice == 2)
            {
                sub2 = Tree2->sub_tree(ptr2);
                sub2->print_tree(sub2->get_root(), sub2->height());
            }

            Tree<complex>* sub3;
            sub3 = new Tree<complex>();

            if (choice == 3)
            {
                sub3 = Tree3->sub_tree(complex(c1,c2));
                sub3->print_tree(sub3->get_root(), sub3->height());
            }

            Tree<Person>* sub4;
            sub4 = new Tree<Person>();
            if (choice == 4)
            {
                sub4 = Tree4->sub_tree({s1, s2, s3});
                sub4->print_tree(sub4->get_root(), sub4->height());
            }
            break;
        case 4:
            Tree<int> * f1;
            f1 = new Tree<int>();

            if (choice == 1)
            {
                f1->entering();
                if (Tree1->find_sub_tree(f1) == true) { cout << "\nTrue"; }
                else cout << "\nFalse";
            }

            Tree<double>* f2;
            f2 = new Tree<double>();

            if (choice == 2)
            {
                f2->entering();
                if (Tree2->find_sub_tree(f2) == true)
                {
                    cout << "\nTrue";
                }
                else cout << "\nFalse";
            }

            Tree<complex>* f3;
            f3 = new Tree<complex>();
            if (choice == 3)
            {
                int n = 0;
                cout << " Enter number of elements: " << endl;
                cin >> n;
                cout << "Write complex like 'x1 SPACE x2':"<<endl;
                for (int i = 0; i < n; i++) {
                    int k1;
                    int k2;
                    cin >> k1;
                    cin >> k2;
                    f3->insert_node(complex(k1, k2));
                }
                if (Tree3->find_sub_tree(f3) == true)
                {
                    cout << "\nTrue";
                }
                else cout << "\nFalse";
            }
            Tree<Person>* f4;
            f4 = new Tree<Person>();
            if (choice == 4)
            {
                Person Person;
                int what;
                int i;
                string ID;
                string f_name;
                string l_name;
                cout <<"How many persons?\n";
                cin >> what;
                cout <<"Please, enter first name and last name through the space\n";
                for (i =0; i<what; i++) {
                    cin >> f_name;
                    cin >> l_name;
                    cout <<"Group:";
                    cin >> ID;
                    f4->insert_node({f_name, l_name, ID});
                }
                if (Tree4->find_sub_tree(f4) == true)
                {
                    cout << "\nTrue";
                }
                else cout << "\nFalse";
            }
            break;
        case 7:
            cout << "\nBye";
            exit(1);
        }
    } while (ch != 7);


    return 0;

}
