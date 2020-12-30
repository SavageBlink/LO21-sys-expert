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

boolean computeRule(Rule* R)
{
  if(isEmpty(R))
    {
      fprintf(stderr,"Error while computing Rule (R : %p)",(void*) R);
      return NULL;
    }
  else if(R->Conclusion == NULL)
    {
      fprintf(stderr, "Error while computing Rule (R->Conclusion : %p)",(void*) R->Conclusion);
      return NULL;
    }

  if(R->Conclusion->value == true)
    {
      return false;
    }
  else if(isEmptyPre(R))
    {
      return true;
    }
  
}

FB* RuNEnGiNe(KB* kb, FB* fb)
{
  if(kb == NULL || fb == NULL)
    {
      fprintf(stderr,"Error while computing pointers might be NULL in RuNEnGiNe (kb : %p, fb %p)\n",(void*) kb,(void*)fb);
      return NULL;
    }

  KBElement * pkb = *kb; /*Pointer on kb*/
  factElement * pfb = *fb; /*Pointer on fb*/
  
  
}
    




