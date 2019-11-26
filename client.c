#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"

int main()
{
    int numberofsubjects;
    printf("WELCOME TO PES UNIVERSITY\nBELOW ARE THE COURSES WE OFFER FOR CSE DEPARTMENT\n\n\n");
    printf("\n1) Physics\n2) Mathematics 1\n3) Python\n4) Electrical Engineering\n5) Mechanical Engineering\n");
    printf("6) Chemistry\n7) Mathematics 2\n8) C\n9) Electronic Engineering\n10) Mechanics\n11) Biotechnology\n");
    printf("12) Digital Design and Computer Organization\n13) Data Structures\n14) Introduction to Data Science\n15) Web Techonologies 1\n16) Discrete Mathematics and Logic\n17) Special Topic 1\n");
    printf("18) Linear Algebra and It's Application\n19) Design and Analysis of Algorithms\n20) Data Base Management Systems\n21) Microprocessor and Computer Architecture\n22) Theory of Computation\n23) Special Topic 2\n");
    printf("23) Computer Networks\n24) Introduction to Operating Systems\n25) Principles of Programming Languages\n");
    printf("26) Advanced Algorithms\n27) Advanded Data Base Management Systems\n28) Big Data\n29) Multimedia Computing\n");
    printf("30) Information Security\n31) Web Services\n32) Algorithms for Intelligent Web\n\n ");
    printf("\n\nEnter the number of subjects :\n");
    scanf("%d", &numberofsubjects);

    Graph *graph = createGraph(numberofsubjects + 1);
    printf("Enter the prerequisite in case there is any.");
    printf("Enter -1 -1 to end.\n");
    while (1)
    {
        int a, b;
        printf("Enter subject code and its pre-requisite :\n");
        scanf("%d %d", &a, &b);
        if (a == -1)
        {
            break;
        }
        addEdge(graph, b, a);
    }
    //here the final answer
    printf("All Topological Sort: \n");
    printAllTopologicalOrders(graph);

    return 0;
}
