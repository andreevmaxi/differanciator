#include "MTree.h"

int main()
{

    DEBMTree_t(DTree);
    FILE* fp = fopen("test.txt", "rb");
    fseek(fp, 0, SEEK_END);
    long SizeTree = ftell(fp);
    rewind(fp);
    char* DBuffer = (char*) calloc(SizeTree, sizeof(char));
    fread(DBuffer, sizeof(char), SizeTree, fp);
    DTree.ReadTree(DBuffer);
    fclose(fp);
    DTree.TDUMP(9);
    return 0;
}
