/**
 * @file rules.h
 * @author Guillaume/Hendercraft Driss/SavageBlink
 * @date 21 december 2020
 * @brief header file of rules and propositions ,it also initialize constructors, modifiers and observers algorithms of a rule.
 */

#ifndef RULES
#define RULES

#include "bools.h"

/**
* Based on bools.h, it defines proposition structure as a couple id(char)
* and value(boolean).
*/
typedef struct prop{
    char * id;
    boolean value;
} Proposition;

/**
* Define elements of a rule which is implemented as a simply linked-list of propositions.
*/

typedef struct ruleElem{
    Proposition* value;
    struct ruleElem * next;
} ruleElement;

typedef struct rule{
  ruleElement* head;
  Proposition* Conclusion;
  
} Rule;

/**
 *Define a Knowledge Base which is implemented as a symply linked-list of rules.
 */
typedef struct KBElem{
  Rule*  KBrule;
  struct KBElem * next;
} KB;

/**
* @brief create an empty proposition
*/
Proposition* createEmptyProposition();

/**
* @brief create an empty rule
*/
Rule* createEmptyRule();

/**
* @brief add a proposition to the premisse of a rule
*/
Rule* addPremisse(Rule* R, Proposition* P);

/**
* @brief create and assign the final proposition (conclusion) of a rule
*/
Rule* addConclusion(Rule* R, Proposition* P);

/**
* @brief delete a proposition from the premisse of a rule
*/
Rule* deleteProposition(Rule* R, char * id);

/**
* @brief Search a proposition with a given id from a rule, and return a 
pointer on the element
*/
boolean SearchProposition(Rule* R, char * id);

/**
* @brief verify if a rule is empty
*/
boolean isEmpty(Rule* R);

/**
* @brief verify if the premisse of a rule is empty
*/
boolean isEmptyPre(Rule* R);

/**
* @brief return first proposition of a rule
*/
ruleElement* headRule(Rule* R);

/**
* @brief return last proposition of a rule
*/
ruleElement* tailRule(Rule* R);

/**
* @brief Give the predecessor of a given Elem from a given rule
*/
ruleElement* getprevious(Rule* R,ruleElement* Elem);

/**
 * @brief  create an empty KB
 */

KB* createEmptyKB();

/**
 * @brief Add a new rule at the end of a KB
 */

KB* addRule(KB* kb, Rule* R);

/**
 * @brief Return a pointer to the first rule of a KB
 */

Rule* headKB(KB* kb);
#endif
