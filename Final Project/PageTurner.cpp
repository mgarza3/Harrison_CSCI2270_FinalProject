#include "PageTurner.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <queue>
#include <json/json.h>

using namespace std;

Pages::Pages(){
    //initialize all class pointers
    origin = NULL;
    currentbuild = origin;
    current = demoRoot;
}

Pages::~Pages(){

}
/*
Function Prototype:
void Pages::printMain();
Function Description:
This function is the function called in main and calls the first output the user will see.
Its job is to call the other menus based on the users desire.
Example:
BinaryTree classObject
classObject.printMain();
Pre-conditions:
Program is compiled and run in a c++ IDE. Receives valid input.
Post-conditions:
New menu will be displayed or it will display the menu again upon invalid input.
*/
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
/*
Function Prototype:
void Pages::printBuild();
Function Description:
This function brings up the menu for the user to call other build functions.
Example:
BinaryTree classObject
classObject.printBuild();
Pre-conditions:
Valid function call and valid input.
Post-conditions:
Other build functions will be called or same menu displayed upon invalid input
*/
void Pages::printBuild(){
    bool first_choice=false;
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
            first_choice=true;
        }
        if(choice == "1" && first_choice==true)
        {
            goLeft();
        }
        if(choice == "2" && first_choice ==true)
        {
            goRight();
        }
        if(choice =="2" && first_choice == false)
            cout<<"There is no option B."<<endl;
        if(choice =="1" && first_choice ==false)
            cout<<"There is no option A."<<endl;
        if(choice == "3")
        {
            goUp();
            first_choice=true;
        }
        if(choice == "4")
        {
            returnToStart();
            first_choice=true;
        }
        if(choice == "5")
        {
            buildLeft();
            first_choice=true;
        }
        if(choice == "6")
        {
            buildRight();
            first_choice=true;
        }
        if(choice == "7")
        {
            checkPos();
            first_choice=true;
        }
        if(choice == "8")
        {
            return;
            first_choice =true;
        }
        if(choice == "9"){
            printGame();
        }
    }
}
/*
Function Prototype:
void Pages::printPlay();
Function Description:
This function allows the user to play the pre-built page turner by receiving a user command and calling functions to
traverse down the pre-built tree based on user input.
Example:
BinaryTree classObject
classObject.printPlay();
Pre-conditions:
User has called playPreBuilt and given a valid input.
Post-conditions:
Either function ChoiceA or ChoiceB will be called or the program will output the same menu upon invalid input.
If user has traversed down the pre-built tree the function will display the proper end game output.
*/
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
/*
Function Prototype:
void Pages::printCustomGameMenu();
Function Description:
This function displays a menu for the user to play their custom built game by calling
the correct functions to move the currentBuild pointer along their custom tree.
Example:
BinaryTree classObject
classObject.printCustomGameMenu();
Pre-conditions:
User has built a tree using the build menu. User enters valid input.
Post-conditions:
Either function customChoiceA or customChoiceB will be called or the program will output the same menu upon invalid input.
If user has traversed down their custom tree the function will display the proper end game output.
*/
void Pages::printCustomGameMenu(){
    if(origin == NULL){
        cout<<"A custom game has not been built"<<endl;
        return;
    }
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
/*
Function Prototype:
void Pages::customChoiceA();
Function Description:
This function will move the currentBuild pointer to its left child if it exist. This is one
of the functions the user will call to traverse along their custom tree.
Example:
BinaryTree classObject
classObject.customChoiceA();
Pre-conditions:
User has built a tree using the build menu.
Post-conditions:
Function will move pointer or display main menu after outputting end game response if no child exist.
*/
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
/*
Function Prototype:
void Pages::customChoiceB();
Function Description:
This function will move the currentBuild pointer to its right child if it exist. This is one
of the functions the user will call to traverse along their custom tree.
Example:
BinaryTree classObject
classObject.customChoiceB();
Pre-conditions:
User has built a tree using the build menu.
Post-conditions:
Function will move pointer or display main menu after outputting end game response if no child exist.
*/
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
/*
Function Prototype:
void Pages::checkPos();
Function Description:
This function allows the user to check their current position in their custom tree by outputting the information
of their currentBuild pointer, its parent, and its children.
Example:
BinaryTree classObject
classObject.checkPos();
Pre-conditions:
User has added a node using the build tree menu.
Post-conditions:
Function will output the users current node information along with its parent's and children's information.*/
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
/*
Function Prototype:
void Pages::choiceA();
Function Description:
This function will move the current pointer to its left child if it exist. This is one
of the functions the user will call to traverse along the pre-built tree.
Example:
BinaryTree classObject
classObject.choiceA();
Pre-conditions:
User has called the playPreBuild function.
Post-conditions:
Function will move pointer or display main menu after outputting end game response if no child exist.
*/
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
/*
Function Prototype:
void Pages::choiceB();
Function Description:
This function will move the current pointer to its right child if it exist. This is one
of the functions the user will call to traverse along the pre-built tree.
Example:
BinaryTree classObject
classObject.choiceB();
Pre-conditions:
User has called the playPreBuild function.
Post-conditions:
Function will move pointer or display main menu after outputting end game response if no child exist.
*/
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
/*
Function Prototype:
void Pages::instruction();
Function Description:
This function will display a instruction menu that a user can use to learn how to use the build functions.
Example:
BinaryTree classObject
classObject.instruction();
Pre-conditions:
Program has compiled and valid input is entered.
Post-conditions:
Function will display a new menu for user interaction or display menu again if invalid input is given.
*/
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
/*
Function Prototype:
void Pages::buildLeft();
Function Description:
This function will build a node as the left child of the currentBuild node
Example:
BinaryTree classObject
classObject.buildLeft();
Pre-conditions:
Program has compiled and valid input is entered.
Post-conditions:
A node will now exist at the left child of the currentBuild node, with the user provided text as the info for that node.
The currentBuild node will remain in the same position as when the function was called.
*/
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
/*
Function Prototype:
void Pages::buildRight();
Function Description:
This function will build a node as the right child of the currentBuild node
Example:
BinaryTree classObject
classObject.buildRight();
Pre-conditions:
Program has compiled and valid input is entered.
Post-conditions:
A node will now exist at the right child of the currentBuild node, with the user provided text as the info for that node.
The currentBuild node will remain in the same position as when the function was called.
*/
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
/*
Function Prototype:
void Pages::playPrebuild();
Function Description:
This function builds the pre-built game in the program for use by the user.
Example:
BinaryTree classObject
classObject.playPrebuilt();
Pre-conditions:
Program has compiled and valid input is entered.
Post-conditions:
The Pre-built game will have all nodes in it's tree built and the game will be ready to play.
*/
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
/*
Function Prototype:
void Pages::playCustom();
Function Description:
This function checks to make sure a custom game has been built within the project, if it has it calls printCustomGameMenu
and allows the user to being playing the custom game.
Example:
BinaryTree classObject
classObject.playCustom();
Pre-conditions:
Program has compiled and valid input is entered.
Post-conditions:
If a custom game exists the game will begin playing, if not the user will be returned to the main menu.
*/
void Pages::playCustom(){
    //being the custom game play
    if(origin == NULL){
        cout<<"A custom game has not been built."<<endl;
        return;
    }
    cout << "Loaded Custom Game" << endl;
    printCustomGameMenu();
}
/*
Function Prototype:
void Pages::printGame();
Function Description:
This function prints out the custom game into a text file using JSON
Example:
BinaryTree classObject
classObject.printGame();
Pre-conditions:
Program has compiled and valid input is entered.
Post-conditions:
A text file called PageTurner.txt will be created with all nodes in the Custom game, if a custom game exits.
*/
void Pages::printGame(){
    //check for custom game
    if(origin == NULL){
        cout<<"A custom game has not been built"<<endl;
        return;
    }
    //make two temp variables
    node* temp = origin;
    node* v;
    //initiate JSON array for all nodes in tree
    json_object *addOutput = json_object_new_array();
    //initiate the queue
    queue<node*> bfq;
    //add the origin tot he queue
    bfq.push(temp);
    //use breadth first search to print out all nodes level by level
    while (!bfq.empty()) {
        v = bfq.front(); //assign the front value of the queue to v
        //maybe make this a json type deal, or just to straight text, we can talk about it
        cout<<v->info<<endl;
        //pop off the head of the queue
        bfq.pop();
        //add node info to JSON string
        json_object *newNode = json_object_new_string(v->info.c_str());
        //add JSON string with node info to JSON array
        json_object_array_add(addOutput, newNode);

        //check for a left child
        if(v->left != NULL){
            //add to the queue
            bfq.push(v->left);
        }
        //check for a right child
        if(v->right != NULL){
            //add to the queue
            bfq.push(v->right);
        }
    }
    //create JSON object to store everything
    json_object *Oper = json_object_new_object();
    //string to denote operation
    json_object *jBuild = json_object_new_string("Build");
    //add string with operation to object
    json_object_object_add(Oper, "operation", jBuild);
    //add array to object
    json_object_object_add(Oper, "output", addOutput);

    //output object to text file using string pretty format
    ofstream myfile;
    myfile.open ("PageTurner.txt");
    myfile << json_object_to_json_string_ext(Oper, JSON_C_TO_STRING_PRETTY);
    myfile.close();
}
/*
Function Prototype:
void Pages::goLeft();
Function Description:
This function will move the current pointer to its left child if it exist. This is one
of the functions the user will call to traverse the custom game tree.
Example:
BinaryTree classObject
classObject.goLeft();
Pre-conditions:
User is currently in the Build mode.
Post-conditions:
Function will move pointer or inform user that they are at the bottom of the tree.
*/
void Pages::goLeft(){
    //make sure that not at bottom of the tree before going there
    if(currentbuild->left != NULL)
        currentbuild = currentbuild->left;
    else
        cout << "There are no more options on the left side." << endl;
}
/*
Function Prototype:
void Pages::goRight();
Function Description:
This function will move the current pointer to its right child if it exist. This is one
of the functions the user will call to traverse the custom game tree.
Example:
BinaryTree classObject
classObject.goRight();
Pre-conditions:
User is currently in the Build mode.
Post-conditions:
Function will move pointer or inform user that they are at the bottom of the tree.
*/
void Pages::goRight(){
    //make sure that not at bottom of the tree before going there
    if(currentbuild->right != NULL)
        currentbuild = currentbuild->right;
    else
        cout << "There are no more options on the right side." << endl;

}
/*
Function Prototype:
void Pages::goUp();
Function Description:
This function will move the current pointer to its parent pointer if not at the origin. This is one
of the functions the user will call to traverse the custom game tree.
Example:
BinaryTree classObject
classObject.goUp();
Pre-conditions:
User is currently in the Build mode.
Post-conditions:
Function will move pointer or inform user that they are at the origin.
*/
void Pages::goUp(){
    //make sure a parent pointer exists
    if(currentbuild != origin)
        currentbuild = currentbuild->parent;
    else
        cout << "You are at the origin of the story" << endl;
}
/*
Function Prototype:
void Pages::returnToStart();
Function Description:
This function moves the currentBuild pointer/user position to the root of their custom built tree (origin).
Example:
BinaryTree classObject
classObject.returnToStart();
Pre-conditions:
User has built a custom tree by at least calling buildLeft() or buildRight().
Post-conditions:
Function will move currentBuild pointer to origin point or the root of the custom tree.
*/
void Pages::returnToStart(){
    //make sure not already at the origin
    if(currentbuild != origin){
        //if not go there
        currentbuild = origin;
    }
    else
        cout << "You are at the origin of the story" << endl;
}
/*
Function Prototype:
void Pages::goOverwrite();
Function Description:
This function allows the user to overwrite the information in a node in the custom game while in build mode.
Example:
BinaryTree classObject
classObject.goOverwrite();
Pre-conditions:
User is calling buildLeft or buildRight, but there is already a node in the desired build position.
Post-conditions:
If the user enters y they will be able to overwrite the node that buildLeft or buildRight was trying to access.
If they enter n then the program will return the build function without editing the node that buildLeft or buildRight
was trying to access.
*/
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
