/**
 * @file engine.c
 * @author Guillaume/Hendercraft Driss/SavageBlink
 * @date 30 december 2020
 * @brief C file of the main inferrence engine
 */ 

#include"headers/engine.h"

void printPtrue(FB* fb){
    if (fb = NULL){
        fprintf(stderr,"The argument given in printPtrue is NULL \n");
        return;
    }
    FB p = (*fb); //Creating a pointers to parse fb
    while (p->next != NULL)
    {
     printf("The Prosition that are true are : \n ( %s",p->value->id);
     p = p->next;
    }
    return;
}
    

    




