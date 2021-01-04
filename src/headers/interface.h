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



#endif
