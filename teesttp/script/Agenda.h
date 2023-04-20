#pragma once
#ifndef _AGENDA_H_ 
#define _AGENDA_H_ 0
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Date
{
    int JJ;
    int MM;
    int AAAA;
} Date;
typedef struct Tempe
{
    int Heur;
    int Min;
} Tempe;
typedef struct Duration
{
    Tempe Debut;
    Tempe Fin;
} Duration;
typedef struct RDV
{
    Date date;
    Duration duration;
    char Titer[30];
    char Desc[150];
    
} RDV;

typedef struct noeud *List;
typedef struct noeud
{
    RDV Val;
    List Suiv;
} noeud;


// #define _31 {1 ,3 ,5 ,7 ,8, 10 ,12}

void Get_String(char *);

int Date_Test(const Date date);
int Temp_Test(const Tempe temp);
int Duration_test(const Duration duration);
int To_min(Tempe tempe);
int Includ(int Start, int date, int End);
int Date_Comper(Date a, Date b);
void Scane_Date(Date *date);
void Scane_Duration(Duration *duration);
void Scane(RDV *Val);
void Print(RDV Val);
List Inserer(RDV rdv, List L);
void Afficher(List L);
List Delete( int index, List L);
void test(List L);
void modifier(List L  , int index);
void Vider(List *L);
#endif