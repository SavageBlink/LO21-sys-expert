/**
 * @file knowledgeBase.c
 * @author Driss/SavageBlink
 * @date 30 december 2020
 * @brief Source file of uses and algorithms related to a knowledge base.
 */

#include "headers/knowledgeBase.h"

KB* createEmptyKB()
{
  KB* kb = (KB*)malloc(sizeof(KB));
  if (kb == NULL)
    {
      fprintf(stderr , "Seems there's a memory error while allocation of KB in createEmptyKB");
      return NULL;
    }
  return kb;
}

KB* addRule(KB* kb, Rule* R)
{
  KBElement* newel = (KBElement*)malloc(sizeof(KBElement));
  newel->KBrule = R;
  newel->next = NULL;
  if(kb == NULL || R == NULL)
    {
      fprintf(stderr, "You have a NULL pointer in addRule function, (kb = %p, R = %p)",kb,R);
      return NULL;
    }
  else
    {
      KBElement* pkb = *kb;
      while(pkb->next != NULL)
	      {
	        pkb = pkb->next;
      	}
      pkb->next = newel;
    }
  return kb;
}

Rule* headKB(KB* kb)
{
  return (*kb)->KBrule;
}
