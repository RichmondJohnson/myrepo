#include <stdio.h>

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
    
    return 0;
}
