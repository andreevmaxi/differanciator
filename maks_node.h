#include <cstdlib>

enum {NIL, SUM, SUB, MUL, DIV, POW, SIN, COS, TG, CTG, ARCSIN, ARCCOS, LN, EXP, ABS, SIGN, DIFF, VAR, NUM};

struct MNode_Binar_t
    {
    char type;
    MNode_Binar_t* Parent;
    void* data;
    MNode_Binar_t* Left;
    MNode_Binar_t* Right;

    int Mode;
    MNode_Binar_t(char T, MNode_Binar_t* Parnt);

    ~MNode_Binar_t();
    };

MNode_Binar_t::MNode_Binar_t(char T, MNode_Binar_t* Parnt)
    {
    type = T;
    Parent = Parnt; // if 0 then it's root
    Mode = NULL;
    switch(type)
        {
        case 'c': // it's char
            {
            data = calloc(1, sizeof(char));
            break;
            }
        case 'C': // it's char*
            {
            data = calloc(1, sizeof(char*));
            break;
            }
        case 'i': // it's int
            {
            data = calloc(1, sizeof(int));
            break;
            }
        case 'I': // it's int*
            {
            data = calloc(1, sizeof(int*));
            break;
            }
        case 'd': // it's double
            {
            data = calloc(1, sizeof(double));
            break;
            }
        }
    Left = 0;
    Right = 0;

    return;
    }

MNode_Binar_t::~MNode_Binar_t()
    {
    type = '\0'; // it's like deeaddd
    Parent = 0; // if 0 then it's not attached to

    free(data);
    if(Left != 0)
        {
        delete Left;
        }
    if(Right != 0)
        {
        delete Right;
        }
    Left = 0;
    Right = 0;
    return;
    }
