/**
 * @file rules.c
 * @author Driss/SavageBlink
 * @date 21 december 2020
 * @brief source file of rules and propositions ,it define constructors, modifiers and observers algorithms of a rule.
 */
#include "headers/rules.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Proposition* createEmptyProposition()
{
  Proposition* P = (Proposition*) malloc(sizeof(Proposition));
  if (P == NULL){
    fprintf(stderr,"Seems there's a an memorry error allocation in createEmptyProposition for the P allocation");
    return NULL;
  }
  P->id = (char*) malloc(15*sizeof(char));
  if (P->id == NULL){
    free(P);
    fprintf(stderr,"Seems there's a an memorry error allocation in createEmptyProposition for the P id allocation");
    return NULL;
  }

  return P;
}

Rule* createEmptyRule()
{
  Rule* R = (Rule*) malloc(sizeof(Rule));
  if (R == NULL){
    fprintf( stderr ,"Seems there's a an memorry error allocation in createEmptyRules");
    return NULL;
  }
  return R;
}

boolean isEmpty(Rule* R)
{
  ruleElement E;
  boolean flag = true;

  E = *headRule(R); 
  
  while (E.next != NULL) {
    if(E.value->id != NULL)
    {
      flag = false;
    }
    E.value = E.next->value;
    E.next = E.next->next;
  }
  return flag;
}

ruleElement* headRule(Rule* R)
{
  return R->head;
}

ruleElement* tailRule(Rule* R)
{
  ruleElement* E;
  if(isEmpty(R))
    {
      return NULL;
    }
  else
    {
      E = headRule(R);
      while(E->next != NULL)
	{
	  E = E->next;
	}
      return E;
    }
}


Rule* addPremisse(Rule* R, Proposition* P){
  //Checking input
  if (R == NULL || P == NULL){
    fprintf(stderr,"You passed R = %p and P = %p one is null in addPremisse \n",R,P);
    return NULL;
  }
  //Generating the new elemement from the Given proposition
  ruleElement* Newelem = (ruleElement*) malloc (sizeof(ruleElement));
  if (Newelem == NULL) {
    fprintf(stderr,"There is an memorry allocation error in add premisse for R = %p and P = %p in addPremisse \n",R,P);
    return NULL;
  }
  ruleElement* Rtail = tailRule(R); //getting the tail
  //Attribuing the value to the newel
  Newelem->value = P;
  Newelem->next = NULL;

  //Adding it to the list
  if (Rtail == NULL){
    R->head = Newelem;
  }else{
    Rtail->next = Newelem;
  }
  return R;
}


Rule* addConclusion(Rule* R, Proposition* P){
  if (R == NULL || P == NULL){
    fprintf(stderr,"You passed R = %p and P = %p one is null in addConclusion \n",R,P);
    return NULL;
  }
 R->Conclusion = P;
 return R;
}

boolean searchProposition(Rule* R, char * id)
{
  
  
  if(isEmpty(R) || id == NULL)
    {
      return false;
    }
  if(isEmptyPre(R))
    {
      return false;
    }
  else if(strcmp(headRule(R)->value->id,id) == 0)
    {
      return true;
    }
  else
    {
      Rule* nR = createEmptyRule();
      nR->head = headRule(R)->next;
      addConclusion(nR, R->Conclusion);
      return searchProposition(nR,id);
    }
}

Rule* deleteProposition(Rule* R, char * id){
  if (R == NULL || id == NULL){
    fprintf(stderr,"You passed R = %p and id = %p one is null in deleteProposition \n",R,id);
    return NULL;
  }
  ruleElement* Ptemp = headRule(R); //Fetching the head
  if (strcmp((Ptemp->value)->id ,id)==0) { //If the value is the head
    R->head = Ptemp->next;
    free(Ptemp);
    return R;
  }
  while(strcmp((Ptemp->next->value)->id ,id)!=0){
    Ptemp = Ptemp->next;
  }
  //The elem to remove a the end it ptemp->next
  ruleElement* TempNext = Ptemp->next->next; //We save to keep the next of the elem to remove
  free(Ptemp->next); // We remove the elem
  Ptemp->next = TempNext; //We forge back the link
  return R;
}


ruleElement* getprevious(Rule* R,ruleElement* Elem){
  if (R == NULL || Elem == NULL){
    fprintf(stderr,"You passed R = %p and id = %p one is null in getprevious \n",R,Elem);
    return NULL;
  }
  ruleElement* p = headRule(R);

  while(p->next != Elem){
    p = p->next;
  }
  return p;
}
