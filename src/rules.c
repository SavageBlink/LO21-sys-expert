/**
 * @file rules.c
 * @author Driss/SavageBlink
 * @date 21 december 2020
 * @brief source file of rules and propositions ,it define constructors, modifiers and observers algorithms of a rule.
 */
#include "headers/rules.h"
#include <stdlib.h>
Proposition createEmptyProposition()
{
  Proposition* P = (Proposition*) malloc(sizeof(Proposition));
  P->id = (char*) malloc(15*sizeof(char));
  return P;
}

Rule createEmptyRule()
{
  Rule* R = (Rule*) malloc(sizeof(Rule));
  return R;
}

boolean isEmpty(Rule R)
{
  ruleElement E;
  boolean flag = true;

  E = headRule(R); 
  
  while (E.next != NULL) {
    if(E.value.id != NULL)
    {
      flag = false;
    }
    E.value = E.next->value;
    E.next = E.next->next;
  }
  return flag;
}
