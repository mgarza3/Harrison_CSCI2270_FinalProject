#ifndef PAGETURNER_H_INCLUDED
#define PAGETURNER_H_INCLUDED

#include <iostream>

using namespace std;

struct node{
    string info = "empty";
    node* left = NULL;
    node* right = NULL;
    node* parent = NULL;
};

class Pages{
    public:
        Pages();
        virtual ~Pages();
        void printMain();
        void printBuild();
        void printPlay();
        void printCustomGameMenu();
        void checkPos();
        void customChoiceA();
        void customChoiceB();
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
        void goLeft();
        void goRight();

    protected:
    private:
        node* origin; //user built root
        node* currentbuild; //current location in tree
        node* demoRoot = new node; //root of the prebuilt tree;
        node* current;
        node* buildLeft(node* parent);
        node* buildRight(node* parent);
};



#endif // PAGETURNER_H_INCLUDED
