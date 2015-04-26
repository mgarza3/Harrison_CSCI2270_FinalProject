#include "PageTurner.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

Pages::Pages(){
    //initialize all class pointers
    origin = NULL;
    currentbuild = origin;
    current = demoRoot;
}

Pages::~Pages(){

}

void Pages::printMain(){
    string command;
    cout<<"WELCOME TO PAGETURNER (patent pending)"<<endl;
    cout<<"             Please enjoy"<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    while(command != "Quit")
    {
        cout << "======Main Menu=====" << endl;
        cout << "1. Play Pre-Built Game" << endl;
        cout << "2. Begin Building" << endl;
        cout << "3. Play Custom" <<	endl;
        cout << "4. Quit" << endl;
        cin >> command;

        if(command == "1")
        {
            playPrebuild();
        }
        if(command == "2")
        {
            printBuild();
        }
        if(command == "3")
        {
            printCustomGameMenu();
        }
        if(command == "4")
        {
            cout << "Goodbye!" << endl;
            command = "Quit";
            return;
        }
    }
}

void Pages::printBuild(){
    string choice;
    while(choice != "Quit")
    {
        bover = false;
        cout << "======Build Menu=====" << endl;
        cout << "0. Instructions" << endl;
        cout << "1. Go Left" << endl;
        cout << "2. Go Right" << endl;
        cout << "3. Go Up One Level" <<	endl;
        cout << "4. Return to Start" << endl;
        cout << "5. Build Left" << endl;
        cout << "6. Build Right" << endl;
        cout << "7. Check Current Position" << endl;
        cout << "8. Return to Main Menu" << endl;
        cout << "9. Print Game to text file" <<endl;
        cin >> choice;

        if(choice == "0")
        {
            instruction();
        }
        if(choice == "1")
        {
            goLeft();
        }
        if(choice == "2")
        {
            goRight();
        }
        if(choice == "3")
        {
            goUp();
        }
        if(choice == "4")
        {
            returnToStart();
        }
        if(choice == "5")
        {
            buildLeft();
        }
        if(choice == "6")
        {
            buildRight();
        }
        if(choice == "7")
        {
            checkPos();
        }
        if(choice == "8")
        {
            return;
        }
        if(choice == "9"){
            printGame();
        }
    }
}

void Pages::printPlay(){


    string response;
    while(response != "Quit")
    {
        if(current != NULL)
        {
            if(current->left != NULL && current->right != NULL){

                cout << "======Game Menu=====" << endl;
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
            else if(current->info == "Enter a nearby cave")
            {
                cout << "Congratulations you have found the treasure and are a real winner!" << endl;
                current = demoRoot;
                return;
            }
            else{
                cout << "GAME OVER" << endl;
                return;
            }
        }
        else{
            return;
        }
    }
}

void Pages::printCustomGameMenu(){
   cout << "Loaded Custom Game" << endl;
   if(currentbuild != origin)
    currentbuild = origin;

    string customAnswer;
    while(customAnswer != "Quit")
    {
        if(currentbuild != NULL)
        {
            if(currentbuild->left != NULL && currentbuild->right != NULL){
                cout << currentbuild->info << endl;
                cout << "======Game Menu=====" << endl;
                cout << "1. Choice A:" << currentbuild->left->info << endl;
                cout << "2. Choice B:" << currentbuild->right->info << endl;
                cout << "3. quit" << endl;
                cin >> customAnswer;

                if(customAnswer == "1")
                {
                    customChoiceA();
                }
                else if(customAnswer == "2")
                {
                    customChoiceB();
                }
                else if(customAnswer == "3")
                {
                    customAnswer = "Quit";
                    return;
                }
            }
            else if(currentbuild->left != NULL)
            {
                cout << "======Game Menu=====" << endl;
                cout << "1. Choice A:" << currentbuild->left->info << endl;
                cout << "2. quit" << endl;
                cin >> customAnswer;

                if(customAnswer == "1")
                {
                    customChoiceA();
                }
                else if(customAnswer == "2")
                {
                    customAnswer = "Quit";
                    return;
                }
            }
             else if(currentbuild->right != NULL)
            {
                cout << "======Game Menu=====" << endl;
                cout << "1. Choice A:" << currentbuild->right->info << endl;
                cout << "2. quit" << endl;
                cin >> customAnswer;

                if(customAnswer == "1")
                {
                    customChoiceA();
                }
                else if(customAnswer == "2")
                {
                    customAnswer = "Quit";
                    return;
                }
            }
            else
            {
                cout << currentbuild->info << endl;
                cout<<"GAME OVER!!!"<<endl;
                return;
            }
        }
        else
            return;
    }
}

void Pages::customChoiceA(){
    //make sure that not at bottom of the tree before going there
    if(currentbuild->left != NULL)
        currentbuild = currentbuild->left;
    else
    {
        //the game is over, at the bottom of the tree
        cout << "GAME OVER!" << endl;
        //return to the main menu
        printMain();
    }
}

void Pages::customChoiceB(){
    //make sure that not at bottom of the tree before going there
    if(currentbuild->right != NULL)
        currentbuild = currentbuild->right;
    else
    {
        //the game is over, at the bottom of the tree
        cout << "GAME OVER!" << endl;
        //return to the main menu
        printMain();
    }
}

void Pages::checkPos(){
    //make sure something has been build before running the check position function
    if(currentbuild == NULL){
        return;
    }
    //print out where currently at
    cout<<"Current Location:"<<currentbuild->info<<endl;
    //check to see if at the origin to not print out the parent pointer
    if(currentbuild == origin)
    {
        cout << "Origin" << endl;
        //check which children actually exist
        if(currentbuild->left != NULL)
            cout<<"Option A is:"<<currentbuild->left->info<<endl;

        else
            cout<<"There is no option A."<<endl;

        if(currentbuild->right != NULL)
            cout<<"Option B is:"<<currentbuild->right->info<<endl;

        else
            cout<<"There is no option B."<<endl;
        return;
    }

    if(currentbuild->parent != NULL)
        cout<<"One level up is:"<<currentbuild->parent->info<<endl;

    else{
        cout<<"You are at the origin of the story"<<endl;
    }

    if(currentbuild->left != NULL)
        cout<<"Option A is:"<<currentbuild->left->info<<endl;

    else
        cout<<"There is no option A."<<endl;

    if(currentbuild->right != NULL)
        cout<<"Option B is:"<<currentbuild->right->info<<endl;

    else
        cout<<"There is no option B."<<endl;
}

void Pages::choiceA(){
    //make sure that not at bottom of the tree before going there
    if(current->left != NULL){
        current = current->left;
    }
    else
    {
        //let player know the game is over
        cout << "GAME OVER!" << endl;
        //return to main menu
        printMain();
    }
}

void Pages::choiceB(){
    //make sure that not at bottom of the tree before going there
    if(current->right !=NULL)
        current = current->right;
    else{
        //let player know the game is over
        cout << "GAME OVER!" << endl;
        //return to main menu
        printMain();
    }
}

void Pages::instruction(){
    cout << "This is the build menu. By selecting these different options you can construct  your own page turner. The page turner is constructed similar to a Binary Tree" << endl;
    cout << "Is there anything specific I can help you with?" << endl;
    string helpChoice;
    while(helpChoice != "Quit")
    {
        cout << "======Help Menu=====" << endl;
        cout << "1. Explain: Go Left" << endl;
        cout << "2. Explain: Go Right" << endl;
        cout << "3. Explain: Go Up One Level" <<	endl;
        cout << "4. Explain: Return to Start" << endl;
        cout << "5. Explain: Build Left" << endl;
        cout << "6. Explain: Build Right" << endl;
        cout << "7. Explain: Check Current Position" << endl;
        cout << "8. Explain: Print Game to text file" <<endl;
        cout << "9. Return to Build Menu" << endl;
        cin >> helpChoice;

        if(helpChoice == "1")
        {
            cout << "\n1. Go Left \nThis option moves your position in the tree/story\nto the next option on the left side\n" << endl;
        }
        if(helpChoice == "2")
        {
            cout << "\n2. Go Right \nThis option moves your position in the tree/story\nto the next option on the  right side\n" << endl;
        }
        if(helpChoice == "3")
        {
            cout << "\n3. Go Up One Level\nThis option moves your position in the tree/story back to the \nprevious option or parent node\n" << endl;
        }
        if(helpChoice == "4")
        {
            cout << "\n4. Return to Start \nThis option brings your position back the beginning of the tree/story.\n" << endl;
        }
        if(helpChoice == "5")
        {
            cout << "\n5. Build Left\nThis option allows you to create the next option of the story and place it\non the left side of your current position." << endl;
        }
        if(helpChoice == "6")
        {
            cout << "\n6. Build right\nThis option allows you to create the next option of the story and place it\non the right side of your current position." << endl;
        }
        if(helpChoice == "7")
        {
            cout << "\n7. Check Current Position\nThis option will display where your current position is in the story/tree\nby printing the node your on along with its parent and children.\n" << endl;
        }
        if(helpChoice == "8")
        {
            cout << "\n8. Print Game to text file\nThis option exports the content of the custom game to a text file named PageTurner.txt.\n" << endl;
        }
        if(helpChoice == "9")
        {
            return;
        }
    }
}

void Pages::buildLeft(){
    cout<<"Enter choice for option A:"<<endl;
    //bring in the text for the option
    string data;
    cin.ignore(1000, '\n');
    getline(cin, data);
    //initiate a new node for the new option
    node* New = new node;
    //put the info in the new node
    New->info = data;
    //check to see if the origin has been built or not yet
    if(currentbuild == origin && origin == NULL){
        //set the origin to the new node
        origin = New;
        currentbuild = New;
        return;
    }
    //check to see if something is already in the build position
    else if(currentbuild->left != NULL){
        cout<<"An option already exists here"<<endl;
        cout<<"Would you like to overwrite? (y/n)"<<endl;
        //give the user the option to overwrite if they want to
        overwrite();
        if(bover == true){
            New->parent = currentbuild;
            currentbuild->left = New;
        }
        return;
    }
    //put the new node in place
    New->parent = currentbuild;
    currentbuild->left = New;
}

void Pages::buildRight(){
    cout<<"Enter choice for option B:"<<endl;
    //bring in the text for the option
    string data;
    cin.ignore(1000, '\n');
    getline(cin, data);
    //initiate a new node for the new option
    node* New = new node;
    //put the info in the new node
    New->info = data;
    //check to see if the origin has been built or not yet
    if(currentbuild == origin && origin == NULL){
        //set the origin to the new nod
        origin = New;
        currentbuild = New;
        return;
    }
    //check to see if something is already in the build position
    else if(currentbuild->right != NULL){
        cout<<"An option already exists here"<<endl;
        cout<<"Would you like to overwrite? (y/n)"<<endl;
        //give the user the option to overwrite if they want to
        overwrite();
        if(bover == true){
            New->parent = currentbuild;
            currentbuild->left = New;
        }
        return;
    }
    //put the new node in place
    New->parent = currentbuild;
    currentbuild->right = New;
}

//void returnMain();

void Pages::playPrebuild(){
    //cout << "WELCOME";

    //INITIATE THE PREBUILT GAME

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
    left5->info = "Swim out to boat";
    node * left6 = new node;
    left6->info = "use the handrail";
    node * left7 = new node;
    left7->info = "You begin to fall off the bridge! Grab the rope.";
    node * right1 = new node;
    right1->info = "Venture down towards the forest";
    node * right2 = new node;
    right2->info = "Walk down a nearby peer";
    node * right3 = new node;
    right3->info = "Cross a rickety looking bridge";
    node * right4 = new node;
    right4->info = "Climb up a nearby rock structure";
    node * right5 = new node;
    right5->info = "Dive into the ocean";
    node * right6 = new node;
    right6->info = "Don't use handrail";
    node * right7 = new node;
    right7->info = "Grab a rock ledge";

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
    left6->left = NULL;
    right6->left = NULL;
    right6->right = NULL;
    left7->left = NULL;
    left7->right = NULL;
    right7->left = NULL;
    right7->right = NULL;*/

    printPlay();

}

void beginBuild();

void Pages::playCustom(){
    //being the custom game play
    cout << "Loaded Custom Game" << endl;
    printCustomGameMenu();
}

void Pages::printGame(){
    //CURRENTLY SEG FAULTS
    //make two temp variables
    node* temp = origin;
    node* v;
    //initiate the queue
    queue<node*> bfq;
    //add the origin tot he queue
    bfq.push(temp);

    while (!bfq.empty()) {
        v = bfq.front(); //assign the front value of the queue to v
        //maybe make this a json type deal, or just to straight text, we can talk about it
        cout<<v->info<<endl;//v->level<<endl;
        //pop off the head of the queue
        bfq.pop();
        //check for a left child
        if(temp->left != NULL){
            //add to the queue
            bfq.push(v->left);
        }
        //check for a right child
        if(v->right != NULL){
            //add to the queue
            bfq.push(v->right);
        }
    }
}

void Pages::goLeft(){
    //make sure that not at bottom of the tree before going there
    if(currentbuild->left != NULL)
        currentbuild = currentbuild->left;
    else
        cout << "There are no more options on the left side." << endl;
}

void Pages::goRight(){
    //make sure that not at bottom of the tree before going there
    if(currentbuild->right != NULL)
        currentbuild = currentbuild->right;
    else
        cout << "There are no more options on the right side." << endl;

}

void Pages::goUp(){
    //make sure a parent pointer exists
    if(currentbuild != origin)
        currentbuild = currentbuild->parent;
    else
        cout << "You are at the origin of the story" << endl;
}

void Pages::returnToStart(){
    //make sure not already at the origin
    if(currentbuild != origin){
        //if not go there
        currentbuild = origin;
    }
    else
        cout << "You are at the origin of the story" << endl;
}

void Pages::overwrite(){
    //bring in option from user
    string answer;
    cin >> answer;
    //check to see if user wants to overwrite
    if(answer == "y"){
        //set boolean to allow overwriting
        bover = true;
    }
    return;
}
