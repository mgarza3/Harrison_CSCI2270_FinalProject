#ifndef PAGETURNER_H_INCLUDED
#define PAGETURNER_H_INCLUDED

#include <iostream>

using namespace std;

struct node{
    string info;
    node* left;
    node* right;
    node* parent;
};

class Pages{
    public:
        void printMain();
        void printBuild();
        void printPlay();
        void checkPos(node *check);
        void choiceA();
        void choiceB();
        void instruction();
        void buildLeft();
        void buildRight();
        void returnMain();
        void playPrebuild();
        void beginBuild();
        void playCustom();
        void printGame();
    protected:
    private:
        node* origin; //user built root
        node* current; //current location in tree
        node* demoRoot; //root of the prebuilt tree;
        node* buildLeft(node* parent);
        node* buildRight(node* parent);
};



#endif // PAGETURNER_H_INCLUDED
