/**
 * @file rules.h
 * @author Guillaume/Hendercraft Driss/SavageBlink
 * @date 21 december 2020
 * @brief header file of rules and propositions ,it also initialize constructors, modifiers and obser * vers algorithms of a rule.
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
  char * name;
} Rule;


/**
* @brief create an empty proposition
* @return A pointer on an empty proposition
*/
Proposition* createEmptyProposition();

/**
* @brief create an empty rule
* @return A pointer on an emty Rule
*/
Rule* createEmptyRule();

/**
* @param R - A pointer on the Rule you wish to modify
* @param P - A pointer on the Proposition yo wih to add to the premisse of the Rule 
* @brief add a proposition to the premisse of a rule
* @return The modified rule with the added Proposition to the premisse
*/
Rule* addPremisse(Rule* R, Proposition* P);

/**
* @param R - A pointer on the Rule you wish to modify
* @param P - on the Proposition yo wih to make the conclusion of the rule
* @brief create and assign the final proposition (conclusion) of a rule
* @return The modified rule with the added Proposition to the premisse
*/
Rule* addConclusion(Rule* R, Proposition* P);

/**
* @param R - A pointer on the Rule you wish to modify
* @param id - The id of the proposition you wish to remove
* @brief delete a proposition from the premisse of a rule
* @return The modified rule with the pointer to the Proposition removed from the premisse
*
*/
Rule* deleteProposition(Rule* R, char * id);

/**
* @param R - A pointer on the Rule you wish to modify
* @param id - The id of the proposition you're looking for
* @brief Search a proposition with a given id from a rule, and return a 
* pointer on the element
* @return A boolean - True if it has found the Proposition, False elsewise
*/
boolean SearchProposition(Rule* R, char * id);

/**
* @param R - A pointer on the Rule you're checking 
* @brief verify if a rule is empty
* @return A boolean - True if the premisse of the ruel is empty, false elsewise
*/
boolean isEmpty(Rule* R);

/**
* @param R - A pointer on the Rule you're checking
* @brief verify if the premisse of a rule is empty
* @return A boolean - True if the premisse of the ruel is empty, false elsewise
*/
boolean isEmptyPre(Rule* R);

/**
* @param R - A pointer on the rule you wish to get the head from 
* @brief return first proposition of a rule
* @return - A pointer on ruleElement, the head of the premisse
*/
ruleElement* headRule(Rule* R);

/**
* @param R - The rule you wish to get the tail from
* @brief return last proposition of a rule
* @return A pointer on ruleElement* , the tail of the premisse
*/
ruleElement* tailRule(Rule* R);

/**
* @param R - The rule the elem is from
* @param Elem - The element you wish to get the previous from 
* @brief Give the predecessor of a given Elem from a given rule, if it's the head, it will return itself
* @return - A pointer on ruleElement, The predessesor of Elem

*/
ruleElement* getprevious(Rule* R,ruleElement* Elem);

#endif
