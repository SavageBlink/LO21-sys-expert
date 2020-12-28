/**
 * @file rules.c
 * @author Driss/SavageBlink
 * @date 21 december 2020
 * @brief source file of rules and propositions ,it define constructors, modifiers and observers algorithms of a rule.
 */
 #include "headers/rules.h"

Proposition createEmptyProposition()
{
  Proposition P;
  return P;
}

Rule createEmptyRule()
{
  Rule R;
  return R;
}

boolean isEmpty(Rule R)
{
  ruleElement E;
  boolean flag = true;

  E = R;
  while (E.next != NULL) {
    if(E != NULL)
    {
      flag = false;
    }
    E = E.next;
  }
  return flag;
}
