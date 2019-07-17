/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

typedef enum _retLevels
{
    SUCCESS = 0,
    INPUTS_IN_TWOS = 1,
    INPUTS_IN_THREES = 2,
} retLevels;

int rect (int a, int b)
{
    return (a * b);
}


float rect2 (float a, float b)
{
    return (a * b);
}

int cube(int a)
{
    return (a * a * a);
}

retLevels find1and2Relation(int input1, int input2)
{
    retLevels retval = SUCCESS;
    retval = (input1 == (2 * input2)) ? INPUTS_IN_TWOS : retval;
    retval = (input1 == (3 * input2)) ? INPUTS_IN_THREES : retval;
    return retval;
}

typedef struct _FPtrs
{
    int (*rectPtr) (int, int);
    float (*rect2Ptr) (float, float);
    int (*cubePtr) (int);
} FPtrs;

void FPtrsInit(FPtrs *incfptr)
{
    incfptr->rectPtr = rect;
    incfptr->rect2Ptr = rect2;
    incfptr->cubePtr = cube;
}

int main()
{
    printf("Hello World");
    
    FPtrs areaFPtrStruct;
    FPtrs *areaFPtrs = &areaFPtrStruct;
    
    FPtrsInit(areaFPtrs);
    
    int (*intFuncPtrs[])() = {rect, cube};
    
    int (*compareFuncPtrs)() = find1and2Relation;
    
    printf("\nInit Success");
    
    int intRectArea = areaFPtrs->rectPtr(5, 10);
    float floatRectArea = areaFPtrs->rect2Ptr(5.0, 10.0);
    int intCubeArea = areaFPtrs->cubePtr(5);
    
    printf("Integer Rectangle Area: %d\n", intRectArea);
    printf("Float Rectangle Area: %f\n", floatRectArea);
    printf("Integer Cube Area: %d\n", intCubeArea);
    
    printf("\n\n\n");
    
    printf("Integer Rectangle Area: %d\n", intFuncPtrs[0](10, 50));
    printf("Integer Cube Area: %d\n", intFuncPtrs[1](10));
    
    
    if(compareFuncPtrs(10, 5) != 0)
        printf("SOMETHING IS SERIOSLY WRONG HERE\n");
    
    
    return 0;
}
