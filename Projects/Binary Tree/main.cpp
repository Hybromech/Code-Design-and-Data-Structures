/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

//Binary Tree Created by Andrew Jonas 26/09/2021
#define _CRT_SECURE_NO_WARNINGS
#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include <raygui.h>
#include "BinaryTree.h"
#include<iostream>;

void Command(BinaryTree*);

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);
    std::cout << "\n\n\n";//add space after output logs
    std::cout << "Binary Tree Program by Andrew Jonas" << std::endl;
    std::cout << "\nPress space to type in a command" << std::endl;

    BinaryTree* binaryTree = new BinaryTree();
    binaryTree->Insert(100);
    binaryTree->Insert(25);
    binaryTree->Insert(13);
    binaryTree->Insert(82);
    binaryTree->Insert(54);
    //binaryTree->Remove(25);
    //binaryTree->Remove(82);
    binaryTree->Insert(19);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        if(GetKeyPressed() == KEY_SPACE)
        Command(binaryTree);
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        binaryTree->Draw();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
void Command(BinaryTree* bt)
{
    int choice;
    int value;
    std::cout << "\nWhat would you like to do?" << std::endl;
    std::cout << "1 Insert a node, 2 remove a node" << std::endl;
    std::cin >> choice;
    if (choice == 1)
    {
        std::cout << "Type the value of the node you would like to insert" << std::endl;
        std::cin >> value;
        std::cout << "Inserting node..." << std::endl;
        bt->Insert(value);
    }
    if (choice == 2)
    {
        std::cout << "Type the value of the node you would like to remove" << std::endl;
        std::cin >> value;
        std::cout << "Vanquishing node..." << std::endl;
        bt->Remove(value);
    }
}