#include <cstdlib>
#include <cstdio>
#include <string.h>

#include "maks_node.h"

namespace MBT_r //MaxBinaryTree_read
    {
    int RecursRead(MNode_Binar_t* root, char* buffer);

    int Bracket(MNode_Binar_t* NowNode, char** buffer, char NowPath);
    // 'f' - first(root) path
    // 'r' - right path
    // 'l' - left path

    int Functions(MNode_Binar_t* NowNode, char** buffer);

    int PlusMinus(MNode_Binar_t* NowNode, char** buffer);

    int MultiplyDiv(MNode_Binar_t* NowNode, char** buffer);

    int Pow(MNode_Binar_t* NowNode, char** buffer);

    int ParseMain(MNode_Binar_t* NowNode, char** buffer);

    int Xes(MNode_Binar_t* NowNode, char** buffer);

    int Number(MNode_Binar_t* NowNode, char** buffer);

    int SinCos(MNode_Binar_t* NowNode, char** buffer);

    int TgCtg(MNode_Binar_t* NowNode, char** buffer);

    int ArcSinCos(MNode_Binar_t* NowNode, char** buffer);

    int Exponent(MNode_Binar_t* NowNode, char** buffer);

    int NaturalLog(MNode_Binar_t* NowNode, char** buffer);

    int ParseMain(MNode_Binar_t* NowNode, char** buffer);

    int Number(MNode_Binar_t* NowNode, char** buffer);

    bool SpaceEater(char** buffer);

    bool PlusNode(MNode_Binar_t* Parnt, bool IsRight);
    }

int MBT_r::RecursRead(MNode_Binar_t* root, char* buffer)
    {
    int TreeSize = 3;

    MBT_r::PlusNode(root, 1);
    MBT_r::PlusNode(root->Right, 1);
    while(*buffer != '\0')
        {
        MBT_r::SpaceEater(&buffer);
        TreeSize += MBT_r::PlusMinus(root->Right->Right, &buffer);
        }

    return TreeSize;
    }

int MBT_r::PlusMinus(MNode_Binar_t* NowNode, char** buffer)
    {
    printf("pkusr: %s \"apdasfasf\n\n", *buffer);
    MBT_r::SpaceEater(buffer);
    int TreeSize = 0;
    TreeSize += MBT_r::MultiplyDiv(NowNode, buffer);


    MBT_r::SpaceEater(buffer);
    while(**buffer == '+' || **buffer == '-')
        {
        char oper = **buffer;
        ++*buffer;
        MBT_r::SpaceEater(buffer);
        MNode_Binar_t* TmpNode = new MNode_Binar_t('d', NowNode->Parent);
        if(NowNode == NowNode->Parent->Left)
            {
            NowNode->Parent->Left = TmpNode;
            }
        else
            {
            NowNode->Parent->Right = TmpNode;
            }
        TmpNode->Left = NowNode;
        NowNode->Parent = TmpNode;
        if(oper == '+')
            {
            TmpNode->Mode = SUM;
            }
        else
            {
            TmpNode->Mode = SUB;
            }
        ++TreeSize;
        MBT_r::PlusNode(TmpNode, 1);
        NowNode = TmpNode->Right;
        ++TreeSize;
        TreeSize += MBT_r::MultiplyDiv(NowNode, buffer);

        }
    return TreeSize;
    }

int MBT_r::MultiplyDiv(MNode_Binar_t* NowNode, char** buffer)
    {
    printf("mulr: %s \"apdasfasf\n\n", *buffer);
    MBT_r::SpaceEater(buffer);
    int TreeSize = 0;
    TreeSize += MBT_r::Pow(NowNode, buffer);

    MBT_r::SpaceEater(buffer);
    while(**buffer == '*' || **buffer == '/')
        {
        char oper = **buffer;
        ++*buffer;
        MBT_r::SpaceEater(buffer);

        MNode_Binar_t* TmpNode = new MNode_Binar_t('d', NowNode->Parent);
        if(NowNode == NowNode->Parent->Left)
            {
            NowNode->Parent->Left = TmpNode;
            }
        else
            {
            NowNode->Parent->Right = TmpNode;
            }
        TmpNode->Left = NowNode;
        NowNode->Parent = TmpNode;
        if(oper == '*')
            {
            TmpNode->Mode = MUL;
            }
        else
            {
            TmpNode->Mode = DIV;
            }
        ++TreeSize;
        MBT_r::PlusNode(TmpNode, 1);
        NowNode = TmpNode->Right;
        ++TreeSize;
        TreeSize += MBT_r::Pow(NowNode, buffer);

        }

    return TreeSize;
    }

int MBT_r::Pow(MNode_Binar_t* NowNode, char** buffer)
    {
    printf("powr: %s \"apdasfasf\n\n", *buffer);
    MBT_r::SpaceEater(buffer);
    int TreeSize = 0;
    TreeSize += MBT_r::ParseMain(NowNode, buffer);


    MBT_r::SpaceEater(buffer);

    if(**buffer == '^')
        {
        ++*buffer;
        MBT_r::SpaceEater(buffer);


        MNode_Binar_t* TmpNode = new MNode_Binar_t('d', NowNode->Parent);
        if(NowNode == NowNode->Parent->Left)
            {
            NowNode->Parent->Left = TmpNode;
            }
        else
            {
            NowNode->Parent->Right = TmpNode;
            }
        TmpNode->Left = NowNode;
        NowNode->Parent = TmpNode;
        TmpNode->Mode = POW;
        ++TreeSize;
        MBT_r::PlusNode(TmpNode, 1);
        NowNode = TmpNode->Right;
        ++TreeSize;
        TreeSize += MBT_r::Pow(NowNode, buffer);
        }

    return TreeSize;
    }


int MBT_r::ParseMain(MNode_Binar_t* NowNode, char** buffer)
    {
    int TreeSize = 0;
    printf("parser: %s \"apdasfasf\n\n", *buffer);
    if(**buffer == '(')
        {
        ++*buffer;
        MBT_r::SpaceEater(buffer);

        TreeSize += MBT_r::PlusMinus(NowNode, buffer);

        MBT_r::SpaceEater(buffer);
        if(**buffer != ')')
            {
            printf("Crit error!!! ¹2 no )");
            }
        else
            {
            ++*buffer;
            MBT_r::SpaceEater(buffer);
            }

        return TreeSize;
        }

    if(**buffer == '|')
        {
        ++*buffer;
        MBT_r::SpaceEater(buffer);

        NowNode->Mode = ABS;
        MNode_Binar_t* TmpNode = new MNode_Binar_t('d', NowNode);
        TmpNode->Left = NowNode->Left;
        NowNode->Left = TmpNode;
        NowNode = TmpNode;
        ++TreeSize;

        TreeSize += MBT_r::PlusMinus(NowNode, buffer);

        if(**buffer != '|')
            {
            printf("Crit error!!! ¹3 no |");
            }
        else
            {
            ++*buffer;
            MBT_r::SpaceEater(buffer);
            }

        return TreeSize;
        }

    if(**buffer == '-')
        {
        NowNode->Mode = MUL;
        MNode_Binar_t* TmpNode = new MNode_Binar_t('d', NowNode);
        MBT_r::PlusNode(NowNode, 1);
        NowNode->Right->Mode = NUM;
        TmpNode->Parent = NowNode;
        TmpNode->Left = NowNode->Left;
        NowNode->Left = TmpNode;
        NowNode = TmpNode;
        ++TreeSize;
        ++TreeSize;
        ++*buffer;
        MBT_r::SpaceEater(buffer);
        }
    TreeSize += MBT_r::Functions(NowNode, buffer);

    return TreeSize;
    }

int MBT_r::Functions(MNode_Binar_t* NowNode, char** buffer)
    {
    int TreeSize = 0;

    MBT_r::SpaceEater(buffer);
    bool flag = 1;
    printf("fync: %s \"apdasfasf\n\n", *buffer);
    while(flag)
        {
        flag = 0;

        int TmpInt = 0;
        if( (TmpInt = SinCos(NowNode, buffer)) != 0)
            {
            TreeSize += TmpInt;
            TmpInt = 0;
            flag = 1;
            }

        if( (TmpInt = TgCtg(NowNode, buffer)) != 0)
            {
            TreeSize += TmpInt;
            TmpInt = 0;
            flag = 1;
            }

        if( (TmpInt = ArcSinCos(NowNode, buffer)) != 0)
            {
            TreeSize += TmpInt;
            TmpInt = 0;
            flag = 1;
            }

        if( (TmpInt = NaturalLog(NowNode, buffer)) != 0)
            {
            TreeSize += TmpInt;
            TmpInt = 0;
            flag = 1;
            }

        if( (TmpInt = Number(NowNode, buffer)) != 0)
            {
            TreeSize += TmpInt;
            TmpInt = 0;
            flag = 1;
            }
        }

    return TreeSize;
    }

int MBT_r::Number(MNode_Binar_t* NowNode, char** buffer)
    {
    int TreeSize = 0;

    MBT_r::SpaceEater(buffer);
    double num  = 0;

    int dozens = 1;
    bool tch = 0;
    printf("buffer:%x %s \"apdasfasf\n\n", NowNode, *buffer);
    if((**buffer >= '0' && **buffer <= '9') || **buffer == ',')
        {
        while( (**buffer >= '0' && **buffer <= '9') || **buffer == ',')
            {
            if(tch)
                {
                dozens *= 10;
                num += ((double)(**buffer - '0'))/(double)dozens;
                }
            else
                {
                if(**buffer == ',')
                    {
                    tch = 1;
                    }
                else
                    {
                    num = num * 10 + (**buffer - '0');
                    }
                }
            ++*buffer;
            }
        NowNode->Mode = NUM;
        NowNode->type = 'd';
        free(NowNode->data);
        NowNode->data = calloc(1, sizeof(double));
        *(double*)NowNode->data = num;
        }
    return TreeSize;
    }

int MBT_r::NaturalLog(MNode_Binar_t* NowNode, char** buffer)
    {
    int TreeSize = 0;

    char nl[3] = "ln";
    if(strcmp(*buffer, nl) == 0)
        {
        *buffer += strlen(nl);
        MBT_r::PlusNode(NowNode, 1);
        NowNode->Mode = LN;
        NowNode = NowNode->Right;
        MBT_r::ParseMain(NowNode, buffer);
        }

    MBT_r::SpaceEater(buffer);

    return TreeSize;
    }

int MBT_r::ArcSinCos(MNode_Binar_t* NowNode, char** buffer)
    {
    int TreeSize = 0;

    char arcs[7] = "arcsin";
    char arcc[7] = "arccos";
    if(strcmp(*buffer, arcc) == 0)
        {
        *buffer += strlen(arcc);
        MBT_r::PlusNode(NowNode, 1);
        NowNode->Mode = ARCCOS;
        NowNode = NowNode->Right;
        MBT_r::ParseMain(NowNode, buffer);
        }

    if(strcmp(*buffer, arcs) == 0)
        {
        *buffer += strlen(arcs);
        MBT_r::PlusNode(NowNode, 1);
        NowNode->Mode = ARCSIN;
        NowNode = NowNode->Right;
        MBT_r::ParseMain(NowNode, buffer);
        }

    MBT_r::SpaceEater(buffer);

    return TreeSize;
    }

int MBT_r::SinCos(MNode_Binar_t* NowNode, char** buffer)
    {
    int TreeSize = 0;

    char s[4] = "sin";
    char c[4] = "cos";
    if(strcmp(*buffer, c) == 0)
        {
        *buffer += strlen(c);
        MBT_r::PlusNode(NowNode, 1);
        NowNode->Mode = COS;
        NowNode = NowNode->Right;
        MBT_r::ParseMain(NowNode, buffer);
        }

    if(strcmp(*buffer, s) == 0)
        {
        *buffer += strlen(s);
        MBT_r::PlusNode(NowNode, 1);
        NowNode->Mode = SIN;
        NowNode = NowNode->Right;
        MBT_r::ParseMain(NowNode, buffer);
        }

    MBT_r::SpaceEater(buffer);

    return TreeSize;
    }

int MBT_r::TgCtg(MNode_Binar_t* NowNode, char** buffer)
    {
    int TreeSize = 0;

    char t[3] = "tg";
    char c[4] = "ctg";
    if(strcmp(*buffer, c) == 0)
        {
        *buffer += strlen(c);
        MBT_r::PlusNode(NowNode, 1);
        NowNode->Mode = CTG;
        NowNode = NowNode->Right;
        MBT_r::ParseMain(NowNode, buffer);
        }

    if(strcmp(*buffer, t) == 0)
        {
        *buffer += strlen(t);
        MBT_r::PlusNode(NowNode, 1);
        NowNode->Mode = TG;
        NowNode = NowNode->Right;
        MBT_r::ParseMain(NowNode, buffer);
        }

    MBT_r::SpaceEater(buffer);

    return TreeSize;
    }

bool MBT_r::SpaceEater(char** buffer)
    {
    while(**buffer == ' ')
        {
        ++(*buffer);
        }

    return 1;
    }

bool MBT_r::PlusNode(MNode_Binar_t* Parnt, bool IsRight)
    {
    if(IsRight)
        {
        if(Parnt->Right == 0)
            {
            Parnt->Right = new MNode_Binar_t('d', Parnt);
            } else
            {
            return 0;
            }
        } else
        {
        if(Parnt->Left == 0)
            {
            Parnt->Left = new MNode_Binar_t('d', Parnt);
            } else
            {
            return 0;
            }
        }
    return 1;
    }
