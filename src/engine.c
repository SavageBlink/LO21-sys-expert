/**
 * @file engine.c
 * @author Guillaume/Hendercraft Driss/SavageBlink
 * @date 30 december 2020
 * @brief C file of the main inferrence engine
 */ 

#include"headers/engine.h"

FB* createEmptyFB()
{
  FB* fb = (FB*)malloc(sizeof(FB));
  if(fb == NULL)
    {
      fprintf(stderr, "Error while creating facts base (fb : %p)",(void *) fb);
      return NULL;
    }
  return fb;
}


FB* addFact(FB* fb, Proposition* P)
{
  if(fb == NULL || P == NULL)
    {
      fprintf(stderr, "Error while adding facts to facts base (fb : %p, P : %p",(void *) fb, (void *) P);
      return NULL;
    }
  factElement * newel = (factElement*)malloc(sizeof(factElement));
  factElement * pfb = *fb;

  if(newel == NULL)
    {
      fprintf(stderr,"Memory error in addFact (newel : %p)",(void *) newel);
      return NULL;
    }
  newel->next  = NULL;
  newel->value = P;
  if(pfb == NULL)
    {
      *fb = newel;
      return fb;
    }
  while(pfb->next != NULL)
    {
      pfb = pfb->next;
    }
  pfb->next = newel;
  return fb;
}

void printPtrue(FB* fb){
    if (fb == NULL){
        fprintf(stderr,"The argument given in printPtrue is NULL \n");
        return;
    }
    FB p = (*fb); //Creating a pointers to parse fb
    while (p != NULL)
    {
     printf("%s is true \n ",p->value->id);
     p = p->next;
    }
    return;
}

boolean computeRule(Rule* R)
{
  if(isEmpty(R))
    {
      fprintf(stderr,"Error while computing Rule (R : %p)",(void*) R);
      return false;
    }
  else if(R->Conclusion == NULL)
    {
      fprintf(stderr, "Error while computing Rule (R->Conclusion : %p)",(void*) R->Conclusion);
      return false;
    }

  if(R->Conclusion->value == true)
    {
      return false;
    }
  else if(isEmptyPre(R))
    {
      return true;
    }
  ruleElement * pR = R->head;
  while(pR->value->value != false && pR->next != NULL)
    {
      pR = pR->next;
    }
  return pR->value->value; /*We exit the loop either because the value is false so we return false or we or at the last proposition of the premisse so the conclusion is true then we return true */
}

FB* RuNEnGiNe(KB* kb, FB* fb)
{
  if(kb == NULL || fb == NULL)
    {
      fprintf(stderr,"Error while computing pointers might be NULL in RuNEnGiNe (kb : %p, fb %p)\n",(void*) kb,(void*)fb);
      return NULL;
    }

  
  //factElement * pfb = *fb; /*Pointer on fb*/
  boolean modified;
  do
    {
      modified = false;
      KBElement * pkb = *kb; /*Pointer on kb*/
      if(pkb->next == NULL) /*Testing if kb has only one rule*/
	{
	  if(computeRule(pkb->KBrule) == true)
	    {
	      pkb->KBrule->Conclusion->value = true;
	      addFact(fb, pkb->KBrule->Conclusion);
	    }
	  return fb; /*return fb because there is only one rule*/
	}
      while(pkb->next != NULL) /*We go through all the knowledge base*/
	{
	  if(computeRule(pkb->KBrule) == true) 
	    {
	      pkb->KBrule->Conclusion->value = true;
	      addFact(fb, pkb->KBrule->Conclusion);
	      modified = true;
	    }
	  pkb = pkb->next;
	}
    }while(modified == true); /*if fb has been modified we have to check again kb's rules*/
  return fb;
}
    




