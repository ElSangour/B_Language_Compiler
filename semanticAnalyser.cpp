#include <stdio.h>

int symbole;

int symbole_suivant(void);
void accepter(int a);
void erreur(void);

void type(void);
void dcl(void);
void pro(void);
void L_id(void);
void lprim(void);
void dprim(void);
void inst_comp(void);
void exp(void);
void exp_simple(void);
void dprim(void);
void es(void);
void terme(void);
void fact(void);
void eprim(void);
void L_inst(void);
void inst(void);

int main()
{
    printf("Donner une ligne : ");
    scanf("%d", &symbole);
    pro();
    return 0;
}

void erreur()
{
    printf("\nERREUR\n");
}

int symbole_suivant(void)
{
    int s;
    printf("Donner le caractère suivant : ");
    scanf("%d", &s);
    return s;
}

void accepter(int a)
{
    if (symbole == a)
        symbole = symbole_suivant();
    else
        erreur();
}

void type()
{
    switch (symbole)
    {
        case 7:
        case 8:
            accepter(symbole);
            break;
        default:
            erreur();
    }
}

void dcl()
{
    if (symbole == 5)
        dprim();
}

void pro()
{
    accepter(1);
    accepter(2);
    accepter(3);
    dcl();
    inst_comp();
}

void L_id()
{
    if (symbole == 2)
    {
        accepter(2);
        lprim();
    }
    else
        erreur();
}

void lprim()
{
    if (symbole == 11)
    {
        accepter(11);
        accepter(2);
        lprim();
    }
}

void dprim()
{
    accepter(5);
    L_id();
    accepter(6);
    type();
    accepter(3);

    if (symbole == 5)
        dprim();
}

void inst_comp()
{
    if (symbole == 9)
    {
        accepter(9);
        inst();
        accepter(10);
        accepter(4);
    }
    else
        erreur();
}

void exp()
{
    exp_simple();

    if (symbole == 26)
        eprim();
}

void exp_simple()
{
    terme();

    if (symbole == 24)
        es();
}

void es()
{
    if (symbole == 24)
    {
        accepter(24);
        terme();

        if (symbole == 24)
            es();
    }
    else
        erreur();
}

void terme()
{
    accepter(26);
    fact();

    if (symbole == 26)
        lprim();
}

void fact()
{
    switch (symbole)
    {
        case 27:
        case 2:
        case 22:
            accepter(symbole);
            break;
        default:
            erreur();
    }
}

void eprim()
{
    if (symbole == 26)
    {
        accepter(26);
        exp_simple();
    }
}

void L_inst()
{
    inst();
}

void inst()
{
    switch (symbole)
    {
        case 13:
            accepter(13);
            accepter(22);
            exp();
            accepter(23);
            accepter(14);
            accepter(9);
            L_inst();
            accepter(15);
            L_inst();
            accepter(10);
            break;
        case 16:
            accepter(16);
            accepter(22);
            exp();
            accepter(23);
            accepter(9);
            L_inst();
            accepter(10);
            break;
        case 2:
            accepter(2);
            accepter(12);
            exp_simple();
            break;

        case 17:
            accepter(9);
            L_inst();
            accepter(10);
            accepter(16);
            break;
        case 20:
            accepter(20);
            accepter(22);
            L_inst();
            accepter(23);
            break;
        case 21:
            accepter(21);
            accepter(22);
            L_inst();
            accepter(23);
            break;
        case 18:
            accepter(18);
            accepter(22);
            exp();
            accepter(23);
            break;
        case 19:
            accepter(19);
            accepter(22);
            exp();
            accepter(23);
            break;
        case 11:
            accepter(11);
            break;
        case 4:
            accepter(4);
            break;
        case 6:
            accepter(6);
            break;
        case 12:
            accepter(12);
            break;
        case 3:
            accepter(3);
            break;
        default:
            erreur();
    }
}
