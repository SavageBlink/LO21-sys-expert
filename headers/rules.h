/**
 * @file rules.h
 * @author Driss/SavageBlink
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
    bool value;
} Proposition;

/**
* Define elements of a rule which is implemented as a simply linked-list of propositions.
*/

typedef struct ruleElem{
    Proposition value;
    struct Proposition * next;
} ruleElement;

typedef ruleElement * Rule;

/**
*@brief create an empty proposition
*/
Proposition createEmptyProposition();

/**
*@brief create an empty rule
*/
Rule createEmptyRule();

/**
*@brief add a proposition to the premisse of a rule
*/
Rule addPremisse(Rule R, Proposition P);

/**
*@brief create and assign the final proposition (conclusion) of a rule
*/
Rule addConclusion(Rule R, Proposition P);

/**
*@brief delete a proposition from the premisse of a rule
*/
Rule deleteProposition(Rule R, char * id);

/**
*@brief verify if a rule is empty
*/
boolean isEmpty(Rule R);

/**
*@brief verify if the premisse of a rule is empty
*/
boolean isEmptyPre(Rule R);

/**
*@brief return first proposition of a rule
*/
Proposition headRule(Rule R);

/**
*@brief return last proposition of a rule
*/
Proposition tailRule(Rule R);


#endif
