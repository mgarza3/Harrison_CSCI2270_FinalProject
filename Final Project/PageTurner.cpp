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
            return;
        }
    }
}
void printBuild();
void Pages::printPlay()
{
    string response;
    while(response != "Quit")
    {
        cout << "======Main Menu=====" << endl;
        cout << "1. Choice A:" << current->left->info << endl;
        cout << "2. Choice B:" << current->right->info << endl;
        cout << "3. quit" << endl;
        cin >> response;

        if(response == "1")
        {
            choiceA();
        }
        else if(response == "2")
        {
            choiceB();
        }
        else if(response == "3")
        {
            response = "Quit";
            return;
        }
    }
}
void checkPos(node *check);
void Pages::choiceA()
{
    if(current->left != NULL)
        current = current->left;
    else
        cout << "You made a faulty decision. Goodbye!" << endl;
}
void Pages::choiceB()
{
    if(current->right !=NULL)
        current = current->right;
    else
        cout << "You made a faulty decision. Goodbye!" << endl;
}
void instruction();
void buildLeft();
void buildRight();
void returnMain();
void Pages::playPrebuild()
{
    cout << "WELCOME";
    node * root = new node;
    root->info = "Welcome to Win or don't Win! Your goal is to find the treasure! Choose a path!";
    demoRoot = root;
    current = root;
    node * left1 = new node;
    left1->info = "Venture down towards the ocean";
    node * left2 = new node;
    left2->info = "Walk down the beach";
    node * left3 = new node;
    left3->info = "Cross a safe looking bridge";
    node * left4 = new node;
    left4->info = "Enter a nearby cave";
    node * left5 = new node;
    left5->info = "Swim out to boat"
    node * left6 = new node;
    left6->info = "use the handrail";
    node * left7 = new node;
    left7->info = "You begin to fall off the bridge! Grab the rope."
    node * left8 = new node;
    node * right1 = new node;
    right1->info = "Venture down towards the forest";
    node * right2 = new node;
    node * right3 = new node;
    node * right4 = new node;
    node * right5 = new node;
    right5->info = "Dive into the ocean";
    node * right6 = new node;
    node * right7 = new node;

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
    /*left4->left = NULL;
    left4->right = NULL;
    right4->left = NULL;
    right4->right = NULL;
    left5->left=NULL;
    left5->right = NULL;
    right5->left = NULL;
    right5->right = NULL;
    left6->left =*/

    printPlay();

}

void beginBuild();
void playCustom();
void printGame();
