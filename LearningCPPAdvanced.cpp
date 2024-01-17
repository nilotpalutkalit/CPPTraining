// LearningCPPAdvanced.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ClassBehavior.h"
#include "ProducerConsumer.h"
#include "SharedPointer.h"
#include "CustomString.h"


int main()
{
    //ClassBehavior cb;
    //std::cout << cb.GetInstanceVariable();

    // ______________________________________________________________________________________________________

    //ProducerConsumer<float> pc;
    //pc.Execute();

    // ______________________________________________________________________________________________________


    //SharedPointer<ProducerConsumer<float>> pc_ptr(new ProducerConsumer<float>());
    //pc_ptr.Display();
    //{
    //    {
    //        SharedPointer<ProducerConsumer<float>> ptr2(nullptr);
    //        ptr2 = pc_ptr;
    //        ptr2.Display();
    //    }

    //    pc_ptr.Display();

    //    auto pc_ptrCopy(pc_ptr);
    //    pc_ptrCopy.Display();

    //    pc_ptrCopy->Execute();
    //}

    // ______________________________________________________________________________________________________

    // {
    //    CustomString string1;
    //    cout << "________________________" << endl;
    //    {
    //        CustomString string2("String 2");
    //        cout << "________________________" << endl;
    //        CustomString stringCopy(string2);
    //        cout << "________________________" << endl;
    //        CustomString stringAssign("Assign");
    //        cout << "________________________" << endl;
    //        string2 = stringAssign;
    //        cout << "________________________" << endl;
    //    }
    // }


    getchar();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
