/**
 * @file engine.h
 * @author Guillaume/Hendercraft Driss/SavageBlink
 * @date 30 december 2020
 * @brief Header file of the interface, manage prints and user input
 */

#ifndef INTERFACE
#define INTERFACE
#include "engine.h"





/**
 * @param R - A pointer on the Rule you wish to print
 * @return NONE
 * @brief Print the premisse and the conclusion of a given rule
 */
void printRule(Rule * R);


/**
 * @param R - A pointer on the Kb you wish to print
 * @return NONE
 * @brief Print all the rule of a knowleadgebase
 */
void printKnowledgeBase(KB* kb);

/**
 * @param R - A pointer on the FB you wish to print
 * @return NONE
 * @brief Print all the proposition of a FactBase
 */
void printFactBase(FB* fb);


/**
 * @param id - The name of the rule, must be 15 char lor less
 * @return The KB with the rule added
 * @brief Create and add a rule with a given name to the Kb
 */
KB* UseraddRule(KB* kb,char* id);

/**
 * @param kb - The KB you want to modify the rule from
 * @param idR - The id of the rule you want to modify
 * @param idP - The id of the proposition you want to add to the premisse
 * @param POOL - THe pool of FB the proposition come from
 * @return The KB with the proposition to on of it's rule added
 * @brief Look for a rule from a kb an a proposition from the pool, if there's a match add the proposition to the premisse of the rule
 * 
 */
KB* UseraddPremisse(KB* kb,char* idR,char* idP,FB* pool);

/**
 * @param kb - The KB you want to modify the rule from
 * @param idR - The id of the rule you want to modify
 * @param idP - The id of the proposition you want to add as the conclusion
 * @param POOL - THe pool of FB the proposition come from
 * @return The KB with the proposition to on of it's rule added
 * @brief Look for a rule from a kb an a proposition from the pool, if there's a match add the proposition to the premisse of the rule
 * 
 */
KB* UseraddConclusion(KB* kb,char* idR,char* idP,FB* pool);

/**
 * @param kb - A pointer on the kb you want to analyse
 * @param id - The name of the rule you're looking for
 * @brief Return a the rule with the same name as id, or NULL if the rule wasn't found
 * @return A pointer on the rule with name = id,
 */
Rule* GetRule(KB* kb,char * id);

/**
 * @param kb - The Fb you want to add the Proposition to, might be the FB of the system or a proposition POOL
 * @return The FB with the proposition added
 * @brief Create and add a premisse with a given name to a list of proposition aka a FB
 */
FB* UseraddProposition(FB* fb,char* id);


/**
 * @param kb - The Fb you want to get the proposition from, might be the FB of the system or a proposition POOL
 * @return A pointer on the proposition withe the given id, else NULL
 * @brief Look for an return a proposiotn with a given id from a POOL
 */
Proposition* GetProposition(FB* fb,char* id);




#endif
