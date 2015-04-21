#include "PageTurner.h"
#include <iostream>

using namespace std;

void Pages::printMain()
{
    string command;
    while(command != "Quit")
    {
        cout << "======Main Menu=====" << endl;
        cout << "1. Play Pre-Built game" << endl;
        cout << "2. Begin Building" << endl;
        cout << "3. Play Custom" <<	endl;
        cout << "4. quit" << endl;
        cin >> command;

        if(command == "1")
        {
            playPrebuild();
        }
        if(command == "2")
        {

        }
        if(command == "3")
        {

        }
        if(command == "4")
        {
            cout << "Goodbye!" << endl;
            command = "quit";
        }
    }
}
void printBuild();
void Pages::printPlay()
{
    string command;
    while(command != "Quit")
    {
        cout << "======Main Menu=====" << endl;
        cout << "1. Choice A:" << current->left->info << endl;
        cout << "2. Choice B:" << current->right->info << endl;
        cout << "3. quit" << endl;
        cin >> command;

        if(command == "1")
        {
            choiceA();
        }
        else if(command == "2")
        {
            choiceB();
        }
    }
}
void checkPos(node *check);
void Pages::choiceA()
{
    current = current->left;
}
void Pages::choiceB()
{
    current = current->right;
}
void instruction();
void buildLeft();
void buildRight();
void returnMain();
void Pages::playPrebuild()
{
    node * root = demoRoot;
    root->info = "Welcome to Win or don't Win! Your goal is to find the treasure! Choose a path!";
    current = root;
    node * left1;
    left1->info = "Venture down towards the Ocean";
    node * left2;
    left2->info = "Venture down towards the forest";
    node * left3;
    node * left4;
    node * left5;
    node * left6;
    node * left7;
    node * left8;
    node * right1;
    node * right2;
    node * right3;
    node * right4;
    node * right5;
    node * right6;
    node * right7;

    root->left = left1;
    root->right = right1;
    left1->left = left2;
    left1->right = right2;
    right1->left = left3;
    right1->right = right3;
    left2->left = left4;
    left2->right = right4;
    right2->left = left5;
    right2->right = right5;
    left3->left = left6;
    left3->right = right6;
    right3->left = left7;
    right3->right = right7;

    printPlay();

}

void beginBuild();
void playCustom();
void printGame();
