#ifndef PAGETURNER_H_INCLUDED
#define PAGETURNER_H_INCLUDED

#include <iostream>

using namespace std;

struct node{
    string info = "empty";
    node* left = NULL; //initialize all pointers to NULL for later checking
    node* right = NULL;
    node* parent = NULL;
    int level = 0;
};

class Pages{
    public:
        Pages();
        virtual ~Pages();
        void printMain(); //function to print main and run main game
        void printBuild(); //function to enable the building of a custom game
        void printPlay(); //function to enable the playing of a custom game
        void printCustomGameMenu(); //function to all the playing of the prebuilt custom game
        void checkPos(); //during building allows user to check their current position and all adjacent nodes
        void customChoiceA(); //allows the user to pick option A in a custom game
        void customChoiceB(); // allows the user to pick option B in a custom game
        void choiceA(); //allows choice A to be selected in the prebuilt game
        void choiceB(); //allows choice B to be selected in the prebuilt game
        void instruction(); //A function to bring up the list of selectable instructions
        void buildLeft(); //allows for the building of option A in a custom game
        void buildRight(); //allows for the building of option B in a custom game
        void returnMain(); //function to return to the main menu
        void playPrebuild(); //allows for the playing of the prebuilt game
        void beginBuild(); //initiates the building of a custom game
        void playCustom(); //initiates the playing of the custom game
        void printGame(); //prints out the game to a text file
        void goLeft(); //allows for movement down one level to the left child in building
        void goRight(); //allows for movement down one level to the right child in building
        void goUp(); //move the current build location up to the parent
        void returnToStart(); //allows for the returning to the start of a game
        void overwrite(); //allows for the overwriting of a node that has already been built



    protected:
    private:
        node* origin; //user built root
        node* currentbuild; //current location in custom tree
        node* demoRoot = new node; //root of the prebuilt tree;
        node* current; //current location in prebuild game
        node* buildLeft(node* parent);
        node* buildRight(node* parent);
        bool bover = false; //boolean used for overwriting values
};



#endif // PAGETURNER_H_INCLUDED
